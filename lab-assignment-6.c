// Julie Bolling
// COP 3502 
// Assignment 6
#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (numbers[mid] == value) {
    return mid;
  } else if (value < numbers[mid]) {
    return search(numbers, low, mid - 1, value);
  } else {
    return search(numbers, mid + 1, high, value);
  }
}

void printArray(int numbers[], int sz) {
  int i;
  printf("Number array: ");
  for (i = 0; i < sz; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

int main(void) {
  int i, numInputs;
  int value, index;
  int *numArray = NULL;
  int countOfNums;
  FILE *inFile = fopen("input.txt", "r");
  fscanf(inFile, "%d", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &countOfNums);
    numArray = (int *)malloc(countOfNums * sizeof(int));
    for (i = 0; i < countOfNums; i++) {
      fscanf(inFile, " %d", &value);
      numArray[i] = value;
    }

    printArray(numArray, countOfNums);
    index = search(numArray, 0, countOfNums - 1, countOfNums / 2);
    if (index >= 0) {
      printf("Item %d exists in the number array at index %d!\n",
             numArray[index], index);
    } else {
      printf("Item not found in the number array!\n");
    }

    free(numArray);
  }

  fclose(inFile);
  return 0;
}
