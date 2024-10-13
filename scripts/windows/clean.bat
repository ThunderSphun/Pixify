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
    EXIT /b 0
)

RMDIR /S /Q build

POPD