#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char c;
  //fp = fopen("day3TestInput.txt", "r");
  fp = fopen("day3Input.txt", "r");

  if (fp == NULL) {
    printf("no such file\n");
    return 0;
  }
  int total = 0;
  int num1 = 0;
  int num2 = 0;

  int state = 0;
  while((c = fgetc(fp)) != EOF) {
    printf("%c", c);
    switch (state) {
      case 0:
        if (c=='m') state++;
        num1 = 0;
        num2 = 0;
        break;
      case 1:
        if (c=='u') {
          state++;
        } else {
          state = 0;
        }
        break;
      case 2:
        if (c=='l') {
          state++;
        } else {
          state = 0;
        }
        break;
      case 3:
        if (c=='(') {
          state++;
        } else {
          state = 0;
        }
        break;
      case 4:
        if (c >= '0' && c <= '9') {
          //printf("add1\n");
          num1 = num1 * 10;
          num1 += (int)(c-'0');
        } else if (c==',' && num1 > 0 && num1 < 1000) {
          state++;
        } else {
          state = 0;
        }
        break;
      case 5:
        if (c >= '0' && c <= '9') {
          //printf("add2\n");
          num2 = num2 * 10;
          num2 += (int)(c-'0');
        } else if (c==')' && num2 > 0 && num2 < 1000) {
          printf("\nNum1: %d, Num2: %d\n", num1, num2);
          total += num1*num2;
          state = 0;
        } else {
          state = 0;
        }
        break;
    }
  }
  printf("total = %d\n", total);

  return EXIT_SUCCESS;
}
