#!/bin/bash
pwd=`pwd`
echo Enter the directory name from which you want to copy files
read dir1
echo Enter the name of directory where you want to copy files
read dir2
mkdir $dir2
cp -a $pwd/$dir1/* $pwd/$dir2/
echo Files copied
cd $pwd/$dir2
for file in *
do
mv $file ${file^}
done
echo Files renamed
echo These are files which is available
for file in *
do
echo $file
done
echo Now choose file name from above list:-
read fname 
echo Now give set of permissions 
echo For Read give - r
echo For write give - w
echo For execute give - x
read permission
echo Now choose the users:-
echo For user - u
echo For group - g
echo For others - o
read users
chmod $users+$permission $fname
