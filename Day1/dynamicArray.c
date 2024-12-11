#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct varArray {
  int* list;
  int capacity;
  int size;
};

struct varArray createVarArray(int capacity) {
  struct varArray list;
  list.list = calloc(capacity, sizeof(int));
  list.capacity = capacity;
  list.size = 0;
  return list;
}

int get(int index, struct varArray* list) {
  assert(index < list->size);
  return list->list[index];
}

void append(int data, struct varArray* list) {
  if (list->size == list->capacity) {
    struct varArray newList = createVarArray(list->capacity*2);
    for (int i = 1; i < list->capacity; i++) {
      append(list->list[i], &newList);
    }
  }
  list->list[list->size] = data;
  list->size = list->size + 1;
}

void insert(int data, int index, struct varArray* list) {
  if(index >= list->capacity) {
    struct varArray newList = createVarArray(index);
    for (int i = 1; i < list->capacity; i++) {
      append(list->list[i], &newList);
    }
  }
  list->list[index] = data;
  if (index >= list->size) {
    list->size = index+1;
  }
}

int main()
{
  struct varArray list = createVarArray(2);
  append(45, &list);
  append(321, &list);
  append(94, &list);
  append(4, &list);
  append(103, &list);
  insert(140,2,&list);
  for (int i = 0; i<list.size; i++) {
    printf("%d\n", get(i, &list));
  }
  return 0;
}
