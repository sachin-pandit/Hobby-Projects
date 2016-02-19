#!/bin/sh


i=1
while [ $i -lt $1 ]
do

	n=`i * 123 % 26 + 'a'` 
        echo $n >> "text.text" 
        i=`expr $i + 1`
done	 
