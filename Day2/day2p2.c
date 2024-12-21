#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkVals(bool increasing, int first, int second) {
  // check that it matches order
  if (increasing != first < second) return false;

  // check that the difference isn't high
  int delta = abs(first-second);
  if (delta < 1) return false;
  if (delta > 3) return false;

  return true;
}

bool isSafe(int* nums, int size) {
  bool increasing = true;
  if (size > 1) {
    increasing = nums[0] < nums[1];
  }
  for (int i = 1; i < size; i++) {
    if (!checkVals(increasing, nums[i-1], nums[i])) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  FILE *fp;
  fp = fopen("input.txt", "r");

  if (fp == NULL) {
    printf("no such file\n");
    return 0;
  }

  int numSafe = 0;
  char line[256];
  int lineNum = 0;
  while(fgets(line, sizeof(line), fp)) {
    lineNum++;
    int *nums;
    int size = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
      //printf("token = %s\n", token);
      size++;
      int* oldNums = nums;
      nums = (int*) malloc(size * sizeof(int));
      for (int i = 0; i < size-1; i++) {
        nums[i] = oldNums[i];
      }
      nums[size-1] = atoi(token);
      token = strtok(NULL, " ");
    }

    for (int i= 0; i < size; i++) {
      int tempNums[size-1];
      int count = 0;
      for (int g = 0; g < size; g++) {
        if (i==g) continue;
        //printf("%d ", nums[g]);
        tempNums[count] = nums[g];
        count++;
      }
      if (isSafe(tempNums, count)) {
        //printf("SAFE\n");
        numSafe++;
        break;
      } 
      //printf("\n");
    }

  }
  printf("parsed\n");

  printf("lineNum = %d\n", lineNum);
  printf("numSafe = %d\n", numSafe);

  return EXIT_SUCCESS;
}
