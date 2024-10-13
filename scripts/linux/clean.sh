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
	popd > /dev/null
	exit 0
fi

rm -r build

popd > /dev/null
