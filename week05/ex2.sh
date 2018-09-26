#!/bin/sh
echo Starting script
while :
do
 if ln testfile.txt testfile.txt.lock
 then
  number=$(tail -n 1 testfile.txt)
  echo "$(expr $number + 1)" >> testfile.txt
  rm testfile.txt.lock
 fi
done
