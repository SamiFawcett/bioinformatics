#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int size(int *arr)
{
 int i = 0;
 while (arr[i])
 {
  i++;
 }
 return i;
}

void readFile(const char *filename, char ***data)
{
 FILE *fptr = fopen(filename, "r");
 char buffer[50];
 char **t = *data;
 int dataIndex = 0;
 while (fgets(buffer, 50, fptr))
 {
  char *data = malloc(strlen(buffer) + 1);
  strcpy(data, buffer);
  *(t + dataIndex) = data;
  dataIndex++;
 }

 fclose(fptr);
}

int binarySearch(int *arr, int target)
{
 int left = 0;
 int right = size(arr) - 1;

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
 int *searchArray = (int *)calloc(strlen(*(data + 2)), sizeof(int));
 int searchArrayIndex = 0;
 const char delim[2] = " ";
 char *token;
 token = strtok(*(data + 2), delim);
 while (token != NULL)
 {
  *(searchArray + searchArrayIndex) = atoi(token);
  token = strtok(NULL, delim);
  searchArrayIndex++;
 }

 int *kIntegers = (int *)calloc(strlen(*(data + 3)), sizeof(int));
 int kIntegersIndex = 0;
 token = strtok(*(data + 3), delim);
 while (token != NULL)
 {
  *(kIntegers + kIntegersIndex) = atoi(token);
  token = strtok(NULL, delim);
  kIntegersIndex++;
 }

 /* problem */
 //int *result = (int *)calloc(strlen(*(data + 3)), sizeof(int));
 int i = 0;
 while (kIntegers[i])
 {
  int targetIdx = binarySearch(searchArray, kIntegers[i]);
  printf("%d ", targetIdx);
  //*(result + i) = targetIdx;
  i++;
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