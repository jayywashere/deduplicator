@echo off

REM Define macros
set "LOG=echo"
set "SAFE="
for %%A in (%*) do (
    if /i "%%~A"=="--silent" set "LOG=rem"
    if /i "%%~A"=="--unsafe" set "SAFE=rem"
)

REM === CHECK ===

%SAFE% %LOG% Checking if executable path exists...
%SAFE% if not exist ".\build\deduplicator.exe" (
    %LOG% Executable path is missing; cannot run the program.
    exit /b 1
)

REM === RUN ===

%LOG% Running...
.\build\deduplicator.exe
if %errorlevel% neq 0 (
    %LOG% Running failed. The program may have exited with code 1.
    exit /b %errorlevel%
)

%LOG% Run success.