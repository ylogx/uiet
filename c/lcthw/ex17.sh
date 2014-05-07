#!/bin/bash -e
make ex17
./ex17 db.dat l
./ex17 db.dat c
./ex17 db.dat s 1 Shubham mails2chaudhary@gmail.com
./ex17 db.dat s 2 Tanjot charmingtanjot@yahoo.com
./ex17 db.dat s 3 Rezul rezulsetia@gmail.com
./ex17 db.dat s 4 Simran ambitious.sim@gmail.com
./ex17 db.dat s 5 Chaudhary shubhamchaudhary92@gmail.com
./ex17 db.dat l
./ex17 db.dat g 2
./ex17 db.dat g 4
./ex17 db.dat g 3
valgrind --leak-check=yes ./ex17 db.dat g 2
