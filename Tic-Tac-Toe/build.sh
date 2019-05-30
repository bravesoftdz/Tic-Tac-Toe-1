#!/bin/bash

if ! [ -e "bin" ]
then
{
    mkdir bin
}
fi

if [ -f "src/main.c" ]
then
{
    gcc src/main.c -o bin/Tic-Tac-Toe
}
else
{
    echo "[-] Error! Source code not found."
}
fi
