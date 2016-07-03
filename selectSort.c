#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
#define swap(x, y, z) { z = *x; *x = *y; *y = z; }

int main(void)
{
  int n, i, j, bf, min, x[MAXSIZE];

  printf("Input the number of array: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    x[i] = rand();
    printf("x[%5d] = %10d\n", i, x[i]);
  }

  for (i = 0; i < n; i++) {
    min = x[i];
    for (j = i; j < n; j++)
      if (x[j] < min) {
        min = x[j];
        swap(&x[i], &x[j], bf);
      }
  }

  printf("Select Sorted:\n");
  for(i = 0; i < n; i++)
    printf("x[%5d] = %10d\n", i, x[i]);

  return 0;
}
