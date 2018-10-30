#!/bin/sh
echo "Enter the numeber for table: "
read num;
for i in 1 2 3 4 5 6 7 8 9
do
	echo "$num*$i = $((num*i))"
done
