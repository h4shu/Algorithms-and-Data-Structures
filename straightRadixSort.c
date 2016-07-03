#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
#define bits(a,b,k) ((a >> b) & ~(~0 << k))

void straightRadixSort (int a[],int n, int b[])
{
	int i, j, pass, count[256];
	for (pass = 0; pass < 4; pass++) {
    for (j = 0; j < 256; j++)
      count[j] = 0;
    if (pass % 2 == 0) {
      for (i = 1; i <= n; i++)
        count[bits(a[i], pass*8, 8)]++;
      for (j = 1; j < 256; j++)
        count[j] = count[j-1] + count[j];
      for (i = n; i >= 1; i--)
        b[count[bits(a[i], pass*8, 8)]--] = a[i];
    } else {
      for (i = 1; i <= n; i++)
        count[bits(b[i], pass*8, 8)]++;
      for (j = 1; j < 256; j++)
        count[j] = count[j-1] + count[j];
      for (i = n; i >= 1; i--)
        a[count[bits(b[i], pass*8, 8)]--] = b[i];
    }
	}
}

int main(void)
{
	int n, i, x[MAXSIZE], bf[MAXSIZE];
  printf("Input the number of array: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    x[i] = rand();
    printf("x[%5d] = %10d\n", i, x[i]);
  }
	straightRadixSort(x, n, bf);
  printf("straight radix sort done:\n");
  for(i = 0; i < n; i++)
    printf("x[%5d] = %10d\n", i, x[i]);
	return 0;
}
