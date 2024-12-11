#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void sort(int* nums, int size) {
  for (int i = 0; i < size; i++) {
    //printf("%d\n", i);
    int smallest = nums[i];
    int smallI = i;
    for (int g = i+1; g < size; g++) {
      int curr = nums[g];
      if (curr < smallest) {
        smallest = curr;
        smallI = g;
      }
    }
    int temp = nums[i];
    nums[i] = smallest;
    nums[smallI] = temp;
  }
}

bool sorted(int* nums, int size) {
  int last = nums[0];
  for (int i = 0; i < size; i++) {
    if(last>nums[i]) {
      return false;
    }
  }
  return true;
}

int main() {

  FILE *fp;
  fp = fopen("input.txt", "r");

  if (fp == NULL) {
    printf("no such file\n");
    return 0;
  }

  int l[1000], r[1000];

  int num1;
  int num2;
  int i = 0;
  while (fscanf(fp, "%d %d", &num1, &num2) == 2) {
    l[i] = num1;
    r[i] = num2;
    i++;
  }
  printf("parsed\n");

  // I tried using a long array, but it didn't work
  // so now im doing the dumb ass O(n^2) solution
  int similarity = 0;
  for (int i = 0; i < 1000; i++) {
    int count = 0;
    int numf = l[i];
    for (int g = 0; g<1000; g++) {
      if (numf == r[g]) {
        printf("found one\n");
        count++;
      }
    }
    similarity += numf * count;
  }
  printf("similarity = %d\n", similarity);
}

// main for the first part of the day
int main1()
{
  FILE *fp;
  fp = fopen("input.txt", "r");

  if (fp == NULL) {
    printf("no such file\n");
    return 0;
  }

  int a[1000], b[1000];

  int num1;
  int num2;
  int i = 0;
  while (fscanf(fp, "%d %d", &num1, &num2) == 2) {
    a[i] = num1;
    b[i] = num2;
    i++;
    // print output to confirm
    /*
    printf("%d", num1);
    printf("%s", "    ");
    printf("%d", num2);
    printf("\n");
    */
  }
  printf("parsed\n");

  sort(a, 1000);
  assert(sorted(a, 1000));
  printf("sorted one\n");
  sort(b, 1000);
  assert(sorted(b, 1000));
  printf("sorted both\n");

  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += abs(a[i]-b[i]);
  }

  printf("sum = %d\n", sum);
  
  fclose(fp);

  return 0;
}
