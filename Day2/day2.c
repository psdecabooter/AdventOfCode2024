#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  while(fgets(line, sizeof(line), fp)) {
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
    bool safe = true;
    bool increasing;
    if (size > 0) {
      increasing = nums[1] > nums[0];
    }
    for (int i = 1; i < size; i++) {
      // check that it matches order
      if (increasing != nums[i] > nums[i-1]) {
        safe = false;
        break;
      }
      // check that the difference isn't high
      if (1 > abs(nums[i]-nums[i-1]) || 3 < abs(nums[i] - nums[i-1])) {
        safe = false;
        break;
      }
    }
    if (safe) {
      numSafe++;
    }
  }
  printf("parsed\n");

  printf("numSafe = %d\n", numSafe);

  return EXIT_SUCCESS;
}
