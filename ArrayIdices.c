//Given an unsorted array you need to fetch the indices in ascending order.
//example: 5,3,9, 8,2
#include <stdio.h>
#define INT_MAX 1000

void sortIndex(int arr[], int n){
    
    int arr2[n],min, k;
   
    for(int i = 0; i<n; i++)
    arr2[i] = 0;

    for(int i = 0; i<n; i++){
        for(k=0;arr2[k]!=0;k++);
        min = k;
        for(int j = 0; j < n; j++){
            if(arr[j]<arr[min] && arr2[j]==0){
                min = j;
            }
        }
        arr2[min]=1;
        printf("%d\t", min);
    }

}
int main(){
    int arr[] = {5,3,9,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortIndex(arr,n);
    return 0;
}