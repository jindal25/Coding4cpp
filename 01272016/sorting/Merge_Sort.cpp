#include <iostream>


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge( int arr[], int start , int mid , int end) {
    
    int k = 0, i =0, j=0;
    int n2,n1;
    
    n2 = end - mid ;
    n1 = mid - start + 1;
    
    int arr1[n1];
    int arr2[n2];
    
    for (;i< n1;i++)
        arr1[i] = arr[i];
    
    for (;j< n2;j++)
        arr2[j] = arr[mid + j +1];
    
    i=0; j=0;
    
    while( i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    
    for(;i<n1;i++)
        arr[k++]=arr1[i];
    
    for(;j<n2;j++)
        arr[k++]=arr2[j];
    
    printArray(arr,sizeof(arr)/sizeof(arr[0]));
}

void mergeSort(int arr[] , int l , int r) {
    
    if ( l< r) {
        int mid = (l + r)/2;
        
        mergeSort (arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid , r);
        
    }
    
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, arr_size-1);
    for ( int i =0; i< 6 ; i++)
        printf(" %d\n", arr[i]);
}