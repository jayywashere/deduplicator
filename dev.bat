@echo off

REM Define macros
set "LOG=echo"
set "SAFE="
for %%A in (%*) do (
    if /i "%%~A"=="--silent" set "LOG=rem"
    if /i "%%~A"=="--unsafe" set "SAFE=rem"
)

REM === CONFIGURATION + BUILD ===

%SAFE% if not exist "build.bat" (
    %LOG% File 'build.bat' does not exist.
    exit /b
)

call "build.bat" %*

REM === CHECK + RUN ===

%SAFE% if not exist "run.bat" (
    %LOG% File 'run.bat' does not exist.
    exit /b
)

call "run.bat" %*