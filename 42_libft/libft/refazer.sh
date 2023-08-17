#!/bin/bash

make
make clean
cc ../testes/main.c libft.a
cd ../testes
make fclean
make clean
make
make clean
clear
./test_executable



