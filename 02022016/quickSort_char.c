#include <stdio.h>
#include <string.h>

int partition ( char arr[], int st, int end);
void swap(char * a, char *b);

void quickSort(char str[], int st, int end){

	int i;
	if(st< end){
    i = partition( str , st, end);
    quickSort( str, st, i-1);
    quickSort( str , i+1, end);
	}
	
}

int partition ( char arr[], int st, int end){
	int i = st ;
	char x = arr[end];
	int j = st;


	for( ;i<= end-1;i++){
	    if ( arr[i] <= x ){
	     	swap(&arr[i],&arr[j]);
	     	j++;
	     }
	}
 	swap(&arr[j],&arr[end]);

 	return j;
}

void swap(char * a, char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int len;
	int i =0;
	char  str[] = "thisisthestring";
	len = strlen(str);
	quickSort(str, 0, len -1);

	while(str[i]!='\0')
        printf("%c", str[i++]);



}