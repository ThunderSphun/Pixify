#!/bin/bash

currentPath=`pwd`

if [[ "$currentPath" == */scripts/linux ]] then
	pushd ../.. > /dev/null
elif [[ "$currentPath" == */scripts ]] then
	pushd .. > /dev/null
else
	pushd . > /dev/null
fi

if [[ ! -d "build" ]] then
	echo "no build directory exists"
	exit -1
fi

cd build

./pixify

popd > /dev/null
