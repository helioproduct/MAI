#!/bin/bash
source=$1
output=$2

mkdir $output
ls $source | xargs -I element cp -r element $output/element_backup
