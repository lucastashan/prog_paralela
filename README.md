# prog_paralela

## Run sequential

```
gcc merger_sort.c -o merge_sort
./merge_sort
```

## Run parallel with MPI

```
mpicc ms_mpi.c -o ms_mpi
mpirun -np 2 ./ms_mpi 32 32000000 msort
```
