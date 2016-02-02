#include <stdio.h>

void printstr( int i, int j, char * str){

	//printf( " %d and %d is \n", i,j);
	for( int k =i;k<=j;k++){
		printf("%c", str[k]);
	}
	printf("%c", ' ');
	
}
int main(){

	int len=0,last_space;
	char str[21] ="Practise make perfect";
	char *ptr = str;

	while(*ptr!='\0'){
		len++;ptr++;
	}

	len--;
    //printf("this");
	last_space=len;
	while(len > 0){
		if(str[len] ==' '){
			printstr(len+1,last_space,str);
			last_space = len;
		}
		len--;
	}
	if(len ==0){
		printstr(0,last_space,str);
	}

	return 0;
}