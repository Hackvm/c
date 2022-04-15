#!/bin/bash

echo "Enter the Number:"
read num
num1=$num
fac=1

while [ $num -gt 1 ] 
do
fac=$((fac * num))
num=$((num - 1))
done

echo "Factorial of" $num1 = $fac
