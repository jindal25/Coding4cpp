#include <stdio.h>

void swap(char *a , char *b)
{
    char tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}
int partition(char * str, int start, int end){
    int i,j,x;
    char tmp;
    
    x = str[end];
    i = start -1;
    
    for(j=start; j<end; j++){
        if(str[j] <=str[end]){
            i++;
            //swap(&str[i],&str[j]);
            tmp=str[i];
            str[i]=str[j];
            str[j]=tmp;
        }
    }
    tmp=str[i+1];
    str[i+1]=str[end];
    str[end]=tmp;
    //swap(&str[i+1],&str[end]);
    return i+1;
}


void quicksort(char *str, int start, int end) {
    if (start < end){
        int pivot = partition(str, start, end);
        quicksort(str,start,pivot-1);
        quicksort(str,pivot+1,end);
    }
}


int main(){
    int i=0;
    char str[13] = "thisisstring";
    
    quicksort(str,0,11);

    while (str[i]!='\0') {
        printf("%c", str[i++]);
    }
}