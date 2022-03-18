#!/bin/bash

a=1
if [[ $a -eq 1 ]]; then
	echo 'equality'
else
	echo 'no'
fi;

# -eq   Равно
# -ne   Не равно
# -lt   Меньше
# -le   Меньше или равно
# -gt   Больше
# -ge   Больше или равно

str="hello"
if [[ "$str" = "hello" ]] && [[ $a -eq 1 ]]; then
	echo $str
else 
	echo "unknown value"
fi;

# emptyness check for string
if [[ -z "$str" ]]; then
	echo "string is empty"
elif [ -n "$str" ]; then
	echo "string is not empty"
fi


# циклы
# https://habr.com/ru/company/ruvds/blog/325928/
border=10
for (( i=1; i <= border; i++ ))
do
	echo $i
done


files=`ls`
IFS=$'\n' #set separator
for file in $files
do
	echo 'file: '$file
done

file=`cat example.sh | head -5`
for line in $file
do
	echo $line | grep http
done

# case
name="helio"
case $name in

  "helio")
    echo "helio"
    ;;

  *)
    echo "unknown"
    ;;
esac


# functions
# https://linuxize.com/post/bash-functions/
function sum {
	a=$1
	b=$2
	sum=$(expr $a + $b)
	return $sum
}

function sum1 {
	local a=$1
	local b=$2

	echo $(expr $a + $b)
}

# first way
sum 1 2
result=$?
echo $a $b $sum

# second way
new_result=`sum1 1 5`
echo $new_result


#arrays
function smart_sum {
	local s=0
	for val in "$@"
	do
		 s=$(expr $s + $val)
	done
	echo $s
}
array=(1 2 3 4)
array_sum=`smart_sum "${array[@]}"`
echo $array_sum
