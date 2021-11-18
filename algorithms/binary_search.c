#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printIArr(int *arr, int arrSize)
{
 printf("[");
 for (int i = 0; i < arrSize; i++)
 {
  if (i < arrSize - 1)
  {
   printf("%d ", *(arr + i));
  }
  else
  {
   printf("%d", *(arr + i));
  }
 }
 printf("]");
}

int size_astr(const char *arr)
{
 char *copy = malloc(strlen(arr) + 1);
 strcpy(copy, arr);
 int size = 0;
 const char delim[2] = " ";
 char *token;
 token = strtok(copy, delim);
 while (token != NULL)
 {
  size++;
  token = strtok(NULL, delim);
 }
 free(copy);
 return size;
}
int size(int *arr)
{
}

int *catoia(char *arr, int arrLength)
{
 int *ret = (int *)malloc(arrLength * sizeof(int));
 char *copy = malloc(strlen(arr) + 1);
 strcpy(copy, arr);

 const char delim[2] = " ";
 char *token;
 token = strtok(copy, delim);
 int index = 0;
 while (token != NULL)
 {
  *(ret + index) = atoi(token);
  token = strtok(NULL, delim);
  index++;
 }

 free(copy);
 return ret;
}

void readFile(const char *filename, char ***data)
{

 FILE *fptr = fopen(filename, "r");
 fseek(fptr, 0, SEEK_END);
 int fileSize = ftell(fptr);
 fseek(fptr, 0, SEEK_SET);

 char buffer[fileSize];
 char **t = *data;
 int dataIndex = 0;
 while (fgets(buffer, fileSize, fptr))
 {
  char *data = malloc(strlen(buffer) + 1);
  strcpy(data, buffer);
  *(t + dataIndex) = data;
  dataIndex++;
 }

 fclose(fptr);
}

int binarySearch(int *arr, int arrSize, int target)
{
 int left = 0;
 int right = arrSize - 1;

 while (left <= right)
 {
  int middle = left + ((right - left) / 2);
  int atArr = *(arr + middle);
  if (atArr == target)
  {
   return middle + 1;
  }
  if (target > atArr)
  {
   left = middle + 1;
  }
  else
  {
   right = middle - 1;
  }
 }

 return -1;
}

int main(int argc, char **argv)
{
 /* parse input */
 char *filename = *(argv + 1);
 int numberOfLines = 4;
 char **data = calloc(numberOfLines, sizeof(char *));
 readFile(filename, &data);
 int n = atoi(*(data));
 int m = atoi(*(data + 1));
 int searchArraySize = size_astr(*(data + 2));
 int kIntegersSize = size_astr(*(data + 3));
 int *searchArray = catoia(*(data + 2), searchArraySize);
 int *kIntegers = catoia(*(data + 3), kIntegersSize);

 for (int i = 0; i < kIntegersSize; i++)
 {
  int indx = binarySearch(searchArray, searchArraySize, *(kIntegers + i));
  printf("%d ", indx);
 }

 /* free memory */

 for (int i = 0; i < numberOfLines; i++)
 {
  free(*(data + i));
 }
 free(data);
 free(searchArray);
 free(kIntegers);
 //free(result);
 return 1;
}