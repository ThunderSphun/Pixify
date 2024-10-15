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

IF EXIST "pixify.sln" goto MSVC

CD Pixify
PixifyEditor.exe

POPD
EXIT /b 0

:MSVC
CD Pixify/Debug
PixifyEditor.exe
POPD