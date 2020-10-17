#!/bin/bash

rm -f output.txt
IFS=$' '

for unit1 in units/*
do
  for unit2 in units/*
  do
    if [ $unit1 != $unit2 ]
    then
	./a.out $unit1 $unit2>> output.txt
    fi
   done
done