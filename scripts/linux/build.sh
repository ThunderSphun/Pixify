#!/bin/bash

currentPath=`pwd`

if [[ "$currentPath" == */scripts/linux ]] then
	pushd ../.. > /dev/null
elif [[ "$currentPath" == */scripts ]] then
	pushd .. > /dev/null
else
	pushd . > /dev/null
fi

echo "detecting build dir"
if [[ ! -d "build" ]] then
	echo "did not detect build dir, creating one"
	mkdir build
else
	echo "detected build dir"
fi

cd build

echo ""
echo "running CMake"
cmake ..
result=$?
if [[ $result -ne 0 ]] then
	echo "CMake failed, exit code $result"
	popd > /dev/null
	exit $result
fi

echo ""
echo "running Make"
make
result=$?
if [[ $result -ne 0 ]] then
	echo "Make failed, exit code $result"
	popd > /dev/null
	exit $result
fi

popd > /dev/null