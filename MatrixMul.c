#include <stdio.h>

void multiply_matrices(int a[][10], int b[][10], int c[][10], int m, int n, int p) {
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < p; j++) {
      for (k = 0; k < n; k++) {
        if (k < n - 1) {
          c[i][j] += a[i][k] * b[k][j];
        } else {
          c[i][j] += a[i][k] * b[k][j] + a[i][n - 1] * b[n - 1][j];
        }
      }
    }
  }
}

int main() {
  int m, n, p;
  int a[10][10], b[10][10], c[10][10];

  printf("Enter the number of rows in the first matrix: ");
  scanf("%d", &m);
  printf("Enter the number of columns in the first matrix: ");
  scanf("%d", &n);
  printf("Enter the number of columns in the second matrix: ");
  scanf("%d", &p);

  printf("Enter the elements of the first matrix: ");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of the second matrix: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  multiply_matrices(a, b, c, m, n, p);

  printf("The product of the two matrices is: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}
