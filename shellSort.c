#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 100000

void shellsort (int a[], int n)
{
	int  i,  j,  h,  v;
	for (h = 1; h <= n/9; h = 3*h+1);
	for (; h > 0; h /= 3)
		for (i = h+1; i <= n; i += h) {
			v = a[i];
			for (j = i; j > h && a[j-h] > v; j -= h) 
				a[j] = a[j-h];
			a[j] = v;
		}
}

int main(void)
{
  int n, i, x[MAXSIZE];

  printf("Input the number of array: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    x[i] = rand();
    printf("x[%5d] = %10d\n", i, x[i]);
  }

	shellsort(x, n);

  printf("shellsort done:\n");
  for(i = 0; i < n; i++)
    printf("x[%5d] = %10d\n", i, x[i]);

  return 0;
}
