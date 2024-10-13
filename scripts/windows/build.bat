@ECHO OFF

SET "currentPath=%cd%"

IF "%currentPath:~-16%"=="\scripts\windows" (
    PUSHD ..\..
) ELSE IF "%currentPath:~-8%"=="\scripts" (
    PUSHD ..
) ELSE (
    PUSHD .
)

ECHO Detecting build dir
IF NOT EXIST "build" (
    ECHO Did not detect build dir, creating one
    MKDIR build
) ELSE (
    ECHO Detected build dir
)

CD build

ECHO.
ECHO Running CMake
cmake ..
SET result=%errorlevel%
IF %result% NEQ 0 (
    ECHO CMake failed, exit code %result%
    POPD
    EXIT /b %result%
)

IF EXIST "pixify.sln" goto MSVC

REM no solution file detected, assuming makefile is present
ECHO.
ECHO Running Make
make
SET result=%errorlevel%
IF %result% NEQ 0 (
    ECHO MSBuild failed, exit code %result%
    POPD
    EXIT /b %result%
)

POPD
EXIT /b 0

:MSVC
ECHO.
ECHO detected Visual Studio solution file
ECHO Running MSBuild
MSBuild pixify.sln
SET result=%errorlevel%
IF %result% EQU 9009 goto MSBuildNotPresent

IF %result% NEQ 0 (
    ECHO MSBuild failed, exit code %result%
    POPD
    EXIT /b %result%
)

POPD
EXIT /b 0

:MSBuildNotPresent
ECHO MSBuild is not found, try running from a Visual Studio CMD
CHOICE /M "want to open the solution file instead"
SET answer=%errorlevel%
IF %answer% EQU 1 (
	pixify.sln
)
POPD
EXIT /b %result%