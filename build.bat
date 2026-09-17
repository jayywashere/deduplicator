@echo off

REM Define macros
set "LOG=echo"
for %%A in (%*) do if /i "%%~A"=="--silent" set "LOG=rem"

REM === CONFIGURATION ===

%LOG% Configuring...
cmake -S . -B build
if %errorlevel% neq 0 (
    %LOG% Configuration failed. Check the syntax of CMakeLists.txt.
    exit /b %errorlevel%
)

%LOG% Configuration successful.

REM === BUILD ===

%LOG% Building...
cmake --build build --parallel
if %errorlevel% neq 0 (
    %LOG% Build failed. Check the source code for compilation errors.
    exit /b %errorlevel%
)

%LOG% Build successful.