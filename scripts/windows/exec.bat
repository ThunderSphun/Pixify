@ECHO OFF

SET "currentPath=%cd%"

IF "%currentPath:~-16%"=="\scripts\windows" (
    PUSHD ..\..
) ELSE IF "%currentPath:~-8%"=="\scripts" (
    PUSHD ..
) ELSE (
    PUSHD .
)

IF NOT EXIST "build" (
    ECHO no build directory exists
    POPD
    EXIT /b -1
)

CD build

IF NOT EXIST "pixify.sln" goto noMSVC

REM assume msvc is used
REM change to build directory

CD Debug
REM rest is normal

:noMSVC
pixify.exe

POPD