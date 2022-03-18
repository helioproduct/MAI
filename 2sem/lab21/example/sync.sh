#!/bin/zsh

declare -A sync_parameters

function help
{
	echo 'usage: ./sync --src=[] --dst=[]'
	echo '--src - source directory sync from'
	echo '--dst - destination directory sync to'
}	

function parse_args 
{
	for arg in "$@"
	do
		case $arg in 
			--src=*|--dst=*)
				flag=`echo $arg|cut -d'=' -f1|cut -c 3-`
				echo "$flag"	
				sync_parameters[$flag]=`echo $arg|cut -d'=' -f2`
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

function copy_unique_files 
{
	uniq_files=(`diff -rq ${sync_parameters[src]} ${sync_parameters[dst]} |
				grep ${sync_parameters[src]} |
				grep Only |
				cut -d':' -f2 | 
				xargs`)

	for fname in $uniq_files
	do
		echo 'transfering new '$fname
		cp ${sync_parameters[src]}/$fname ${sync_parameters[dst]}/
	done
}

function update_common_files
{
	src_files=(`ls ${sync_parameters[src]}/`)

	for fname in $src_files
	do
		if [[ -f ${sync_parameters[dst]}/$fname ]]; then
			srcFileHash=`md5 ${sync_parameters[src]}/$fname -q`
			dstFileHash=`md5 ${sync_parameters[dst]}/$fname -q`

			if [[ $srcFileHash != $dstFileHash ]]; then
				echo 'transfering differ '$fname
				cp ${sync_parameters[src]}/$fname ${sync_parameters[dst]}/
			fi

		fi 
	done

}

parse_args "$@"
echo ${sync_parameters[src]}
