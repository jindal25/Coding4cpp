#include <stdio.h>

int main() {
    char arr[27] = "this is the string         ";
    int i =0,len=0,actualLength=0, charLength=0;

    
    while(arr[len] !='\0')
    	len++;

    actualLength = len-1;
    i=len-1;

    while(!((arr[i] >='a' && arr[i]<='z') || (arr[i] >='A' && arr[i]<='Z'))) {
    	i--;
    }

    charLength = i;

    printf(" the length is %d %d \n", charLength, actualLength );

    while ( charLength > 0)
    {
    	if(arr[charLength] == ' ') {
    		arr[actualLength--] = '%'; arr[actualLength--] = '2'; arr[actualLength--] = '0';charLength--;
    	}
    	else 
    		arr[actualLength--]= arr[charLength--];

    }
    len=0;

    while(arr[len] !='\0'){
    	printf(" %c ",arr[len++]);
    }

    printf(" the length is %d\n", len);
	
	return 0;
}
