#include <stdio.h>
 
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver's code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    int result = search(arr, N, x);
    if(result!=-1){
      printf("The element is present at position %d",result+1);
    }else{
      printf("The element is not present in the array");
    }
    return 0;
}