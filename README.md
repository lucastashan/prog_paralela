# prog_paralela

## Run sequential

```
gcc merger_sort.c -o merge_sort
./merge_sort
```

## Run parallel with MPI

```
mpicc ms_mpi.c -o ms_mpi
mpirun -np 2 ./ms_mpi 80 32000000 msort
```

O "-np" é o número de nodos 1-32
