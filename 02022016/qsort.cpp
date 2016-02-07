// C/C++ program to check whether two strings are anagrams
// of each other
#include <stdio.h>
#include <string.h>
 
/* Function prototype for string a given string using 
   quick sort */
void quickSort(char *arr, int si, int ei);
 

 
// Following functions (exchange and partition are needed
// for quickSort)
void exchange(char *a, char *b)
{
    char temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 
int partition(char A[], int si, int ei)
{
    char x = A[ei];
    int i = (si - 1);
    int j;
 
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(char A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
 
/* Driver program to test to print printDups*/
int main()
{
    int i=0;
    char str1[] = "testisthis";
    char str2[] = "ttew";
    quickSort(str1,0 , strlen(str1)-1);

    while(str1[i]!='\0')
        printf("%s\n", );("%c", str1[i++]);
    
    return 0;
}