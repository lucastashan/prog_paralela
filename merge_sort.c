#include <stdio.h>
#include <stdlib.h>

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main (void) {
  int i,j;
  int num_vect = 32;
  int size_vect = 32000000; // 32 milhoes

  int (*bag)[size_vect] = malloc (num_vect * sizeof *bag);

  for ( i=0 ; i < num_vect ; i++ )    // initialize bag of tasks
	  for ( j=0 ; j < size_vect ; j++ )
	    bag[i][j] = size_vect-j;

  for ( i=0 ; i < num_vect ; i++ ){
    mergesort(bag[i], size_vect);
  }

  putchar('\n');

  return 0;
}

void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}

void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}
