#!/bin/bash

rm -f output.txt
IFS=$'\n'

./$1 scenario3.json< input.txt >> good_output1.txt
