@echo off

if not exist "bin" (
    mkdir bin
)

if exist "src\main.c" (
    gcc src\main.c -o bin\Tic-Tac-Toe.exe
) else (
    echo [-] Error! Source code not found.
)
