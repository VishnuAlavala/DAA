#include <stdio.h>

void printPascalTriangle(int n) {
  int i, j, row[n][n];

  // Initialize the first row.
  for (i = 0; i < n; i++) {
    row[0][i] = 1;
  }

  // Fill the remaining rows.
  for (i = 1; i < n; i++) {
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        row[i][j] = 1;
      } else {
        row[i][j] = row[i - 1][j - 1] + row[i - 1][j];
      }
    }
  }

  // Print the triangle.
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      printf("%d ", row[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n;

  // Get the number of rows.
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Print Pascal's triangle.
  printPascalTriangle(n);

  return 0;
}
