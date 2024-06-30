#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    
            }
            
        }
    }
    printf("sorted array is:\n");
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}