#!/bin/bash

declare -A sync_parameters

function help
{
	echo "Usage: ./copy_wt.sh --src=[] --dst=[] --prefix=[]"
	echo "--src    - Directory with source files"
	echo "--dst    - Destination directory"
	echo "--prefix - Prefix for new files"
}

function get_write_protected_files
{
	string=`ls ${sync_parameters[src]} -l | grep -E "^[-rx]{8}-[-rx]" | awk '{print $9}'`
	files_to_copy=(`echo $string | tr '\n' ' '`)
}

function copy_files
{
	for file in "${files_to_copy[@]}"
	do
		# cp ${sync_parameters[src]}"/"$file ${sync_parameters[dst]}"/"${sync_parameters[prefix]}$file
		# touch ${sync_parameters[dst]}"/"${sync_parameters[prefix]}$file
		# echo "${sync_parameters[dst]}"/"${sync_parameters[prefix]}$file"
    	cat ${sync_parameters[src]}"/"$file > ${sync_parameters[dst]}"/"${sync_parameters[prefix]}$file
	done
}

function change_files_permissions
{
	for file in "${files_to_copy[@]}"	
	do
		chmod ugo+w ${sync_parameters[dst]}"/"${sync_parameters[prefix]}$file
	done
}

function parse_args 
{
	for arg in "$@"
	do
		case $arg in 
			--src=* | --dst=* | --prefix=*)
				flag=`echo $arg | cut -d'=' -f1 | cut -c 3-`
				sync_parameters[$flag]=`echo $arg | cut -d'=' -f2`
				;;
			--help)
				help
				exit
				;;
			*)
				echo "unknown parameter: "$arg
				help
				exit
		esac
	done
}

parse_args "$@"
get_write_protected_files
copy_files
change_files_permissions

