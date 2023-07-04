#include <stdio.h>

void bubble_sort(int* arr , int arrlen);
int main()
{
  int arrlen = 5;
  int arr[5] = {1,4,3,8,5};
  bubble_sort(arr , 5);
  int i =0;

  printf("Sorted array\n");
  for (int k=0; k < arrlen; ++k) {
    printf("%d " , arr[k]);
  }
  return 0;
}

 void bubble_sort(int* arr , int arrlen)
{
  int i=0;
  int j=0;
  // -1 is for indexing, if not specified, it will access the next memory position which causes problems
  for (; i < arrlen - 1; i++) {
    // The -i is because at each iteration, the largest arr member is moved to the last location,
    // So it is not necessary to include those members which are ordered by now.
    for (; j < arrlen - 1 - i; j++) {
      if (arr[j] > arr[j+1]) {
        printf("Swapping %d at position %d with %d at position %d\n" , arr[j] , j , arr[j+1] , j+1);

        int temp  = arr[j]; 
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
