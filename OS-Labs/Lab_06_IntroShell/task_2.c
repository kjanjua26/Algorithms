#!/bin/sh
while true;
do
	echo "Enter Number 1: "
	read num1
	echo "Enter Number 2: "
	read num2
	echo "Multiplying $num1, $num2 = $((num1*num2))"
	echo "Adding $num1, $num2 = $((num1+num2))"
	echo "Subtracting $num1, $num2 = $((num1-num2))"
	echo "Dividing $num1, $num2 = $((num1/num2))"
done
