#!/bin/sh
echo Starting script
while :
do
 number=$(tail -n 1 testfile.txt)
 if ln testfile.txt testfile.txt.lock
 then
  echo "$(expr $number + 1)" >> testfile.txt
  rm testfile.txt.lock
 fi
done
