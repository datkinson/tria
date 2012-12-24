#!/bin/zsh
MY_PATH="`dirname \"$0\"`"              # relative
MY_PATH="`( cd \"$MY_PATH\" && pwd )`"  # absolutized and normalized
if [ -z "$MY_PATH" ] ; then
  # error; for some reason, the path is not accessible
  # to the script (e.g. permissions re-evaled after suid)
  echo "Unable to determine path"
  exit 1  # fail
fi

#echo "$MY_PATH"
#get full path of passed parameter
FILE_PATH=$(readlink -f "$1")
#echo "$FILE_PATH"
#end of path after last slash "/"
#echo "${FILE_PATH##*/}"
#begining of path, everything before last slash "/"
#echo "${FILE_PATH%/*}"

MAIN_CLASS="$FILE_PATH/${FILE_PATH##*/}.ino"
#echo $MAIN_CLASS
if [ -z "$MAIN_CLASS" ] ; then
  echo "Invalid folder structure, main class missing"
  exit 1
fi

echo "Removing old build file"
rm $FILE_PATH/build.ino
echo "Creating build file"
touch $FILE_PATH/build.ino
echo "Adding main class to the start of build file"
cat "$MAIN_CLASS" > $FILE_PATH/build.ino
echo "Creating temp directory"
mkdir $MY_PATH/tmp
echo "Making temp copy of classes"
cp $FILE_PATH/*.ino $MY_PATH/tmp/
echo "Removing junk"
rm $MY_PATH/tmp/${FILE_PATH##*/}.ino
rm $MY_PATH/tmp/build.ino
echo "Adding all other classes to build file"
cat $MY_PATH/tmp/*.ino >> $FILE_PATH/build.ino

echo "Creating project directory"
NEW_PROJECT="$MY_PATH/projects/${FILE_PATH##*/}"
mkdir $MY_PATH/projects/${FILE_PATH##*/}
cd $MY_PATH/projects/${FILE_PATH##*/}
ino init
rm src/sketch.ino
cd src
rm build.ino
mv $FILE_PATH/build.ino sketch.ino
cd ..
ino build

