#!/bin/bash

path=$1
cd $path
ls -p | grep -v / | sort -r | xargs wc -l 2>/dev/null
