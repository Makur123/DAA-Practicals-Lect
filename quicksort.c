#include<stdio.h>
#include<stdlib.h>
static int count = 0;

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int start, int end){
   int pivot = a[end];
   int i = start-1;

   for(int j = 0; j < end; j++){
    if(a[j]<=pivot){
        i++;
        swap(&a[i], &a[j]);
    }
   }
  swap(&a[i+1], &a[end]);
  return i+1;
}

void sort(int a[], int start, int end){
    if(start < end){
        int pt = partition(a,start,end);
        sort(a,start,pt-1);
        sort(a,pt+1,end);
    }
}


int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
     
     int *a = (int *)malloc(n*sizeof(int));

    printf("Enter the elements\n");
    for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
    }
    sort(a,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
        }
        return 0; 

        free(a);      
}