#!/bin/bash

rm -rf $1
clear
echo "Creating Contest $1....."
echo "Number of Problems : $2"
pwd

#creating structure
mkdir $1
touch $1/def.cpp
touch $1/genp.sh
cat template.cpp >> $1/def.cpp
cat genp.sh >> $1/genp.sh

cd $1
chmod +x genp.sh
pwd
for((i=1;i<=$2;i++))
do
  #echo "Creating Solution $i..."
  if ((i == 1)); then
    bash genp.sh A 5 
  elif ((i == 2)); then
    bash genp.sh B 5
  elif ((i == 3)); then
    bash genp.sh C 5
  elif ((i == 4)); then
    bash genp.sh D 5
  elif ((i == 5)); then
    bash genp.sh E 5
  elif ((i == 6)); then
    bash genp.sh F 5
  elif ((i == 7)); then
    bash genp.sh G 5
  elif ((i == 8)); then
    bash genp.sh H 5
  elif ((i == 9)); then
    bash genp.sh I 5
  elif ((i == 10)); then
    bash genp.sh J 5
  elif ((i == 11)); then
    bash genp.sh K 5
  elif ((i == 12)); then
    bash genp.sh L 5
  fi
done
echo "=======Done======="
ls
echo "=================="
