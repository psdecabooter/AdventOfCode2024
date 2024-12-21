#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
  bool enabled = true;
  while((c = fgetc(fp)) != EOF) {
    printf("%c", c);
    void firstCase() {
      if (c=='m' && enabled) {
        state = 1;
      } else if (c=='d') {
        state = 6;
      } else {
        state = 0;
      }
      num1 = 0;
      num2 = 0;
    }
    switch (state) {
      case 0:
          firstCase();
        break;
      case 1:
        if (c=='u') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 2:
        if (c=='l') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 3:
        if (c=='(') {
          state++;
        } else {
          firstCase();
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
          firstCase();
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
          firstCase();
        } else {
          firstCase();
        }
        break;
      case 6:
        if(c=='o') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 7:
        if(c=='(') {
          state++;
        } else if (c=='n') {
          state = 9;
        } else {
          firstCase();
        }
        break;
      case 8:
        if(c==')') {
          enabled = true;
          printf("\nDO\n");
          firstCase();
        } else {
          firstCase();
        }
        break;
      case 9:
        if(c=='\'') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 10:
        if(c=='t') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 11:
        if(c=='(') {
          state++;
        } else {
          firstCase();
        }
        break;
      case 12:
        if(c==')') {
          enabled = false;
          printf("\nDON'T\n");
          firstCase();
        } else {
          firstCase();
        }
        break;
    }
  }
  printf("total = %d\n", total);

  return EXIT_SUCCESS;
}
