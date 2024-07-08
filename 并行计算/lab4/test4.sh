#!/bin/bash
module load GCC/9.3.0 mpich/mpi-x-gcc9.3.0
time yhrun -p thcp1 -N 2 -n 1 -c 16 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 1 -c 8 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 1 -c 4 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 1 -c 2 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 1 -c 1 test4.o &> run.log

time yhrun -p thcp1 -N 2 -n 2 -c 16 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 2 -c 8 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 2 -c 4 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 2 -c 2 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 2 -c 1 test4.o &> run.log

time yhrun -p thcp1 -N 2 -n 4 -c 16 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 4 -c 8 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 4 -c 4 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 4 -c 2 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 4 -c 1 test4.o &> run.log

time yhrun -p thcp1 -N 2 -n 8 -c 16 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 8 -c 8 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 8 -c 4 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 8 -c 2 test4.o &> run.log
time yhrun -p thcp1 -N 2 -n 8 -c 1 test4.o &> run.log