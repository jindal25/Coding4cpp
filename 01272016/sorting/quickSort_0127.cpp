#include <iostream>

using namespace std;

void print(int *a, int n)
{
    int i=0;
    while(i<n){
        cout<<a[i]<<",";
        i++;
    }
}

int partition(int arr[], int start, int end)
{
    int i = 0, j = 0;
    int x = arr[end];
    int temp;
    
    for( j=start ; j< end; j++)
    {
        if(arr[j] <= x)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
        
    }
    temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;
    print(arr,5);
    return i;
    
}

void quickSort(int arr[], int start, int end )
{
    if(start < end){
        int i = partition(arr, start, end);
        quickSort(arr,start, i-1);
        quickSort(arr, i+1,end);
    }
}

int main() {
    int arr[] = {2,1,5,4,6};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0,4);
    
    print(arr,5);
    
}