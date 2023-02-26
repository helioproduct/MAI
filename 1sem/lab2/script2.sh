#!/bin/bash

path=$1	
cd $path

for arg in "$@"; do
	rm $arg 2>/dev/null
done
