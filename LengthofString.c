#include <stdio.h>

int main() {
  // Get the string from the user
  char str[100];
  printf("Enter a string: ");
  gets(str);

  // Find the length of the string
  int length = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    length++;
  }

  // Print the length of the string
  printf("The length of the string is: %d\n", length);

  return 0;
}
