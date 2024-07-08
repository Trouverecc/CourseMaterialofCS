#!/bin/bash
time yhrun -p thcp1 -n 1 -c 1 try.o 2 16 1&>>run2.log
time yhrun -p thcp1 -n 1 -c 2 try.o 2 16 2&>>run2.log
time yhrun -p thcp1 -n 1 -c 4 try.o 2 16 4&>>run2.log
time yhrun -p thcp1 -n 1 -c 8 try.o 2 16 8&>>run2.log
time yhrun -p thcp1 -n 1 -c 16 try.o 2 16 16&>>run2.log

time yhrun -p thcp1 -n 1 -c 1 try.o 20 16 1&>>run2.log
time yhrun -p thcp1 -n 1 -c 2 try.o 20 16 2&>>run2.log
time yhrun -p thcp1 -n 1 -c 4 try.o 20 16 4&>>run2.log
time yhrun -p thcp1 -n 1 -c 8 try.o 20 16 8&>>run2.log
time yhrun -p thcp1 -n 1 -c 16 try.o 20 16 16&>>run2.log

time yhrun -p thcp1 -n 1 -c 1 try.o 2 32 1&>>run2.log
time yhrun -p thcp1 -n 1 -c 2 try.o 2 32 2&>>run2.log
time yhrun -p thcp1 -n 1 -c 4 try.o 2 32 4&>>run2.log
time yhrun -p thcp1 -n 1 -c 8 try.o 2 32 8&>>run2.log
time yhrun -p thcp1 -n 1 -c 16 try.o 2 32 16&>>run2.log