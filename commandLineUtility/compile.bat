@echo off

REM Print the current directory
echo Current directory: %cd%

REM Print the PATH environment variable
echo PATH: %PATH%

REM Compile the source code
echo Running: g++ -o compute src\compute.cpp
g++ -o compute src\compute.cpp

REM Check if the compilation succeeded
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b 1
)

echo Compilation succeeded.
