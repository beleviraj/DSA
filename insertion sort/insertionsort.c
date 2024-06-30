#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //array={7,3,2,5,1} array={3,7,2,5,1}
    //  array={3,7,2,5,1} array={3,2,7,5,1} array={2,3,7,5,1}
    for(int i=1;i<n;i++){
      int j=i;
       while(j>=0 && (arr[j]<arr[j-1])){
       int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
      }
     }
    printf("sorted array is:\n");
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    return 0;
    
 }