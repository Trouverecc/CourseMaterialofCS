#!/bin/bash
module load GCC/9.3.0 mpich/mpi-x-gcc9.3.0
time yhrun -p thcp1 -N 2 -n 16 test3.o &>run.log
time yhrun -p thcp1 -N 2 -n 8 test3.o &>run.log
time yhrun -p thcp1 -N 2 -n 4 test3.o &>run.log
time yhrun -p thcp1 -N 2 -n 2 test3.o &>run.log
time yhrun -p thcp1 -N 2 -n 1 test3.o &> run.log