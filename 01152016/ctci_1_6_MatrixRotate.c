#include <stdio.h>

void rotate(int mat[][], int layers){
	int i,j,first,last,top,offset; 
	for(int j =0; j<layers/2;j++){
		first = j;
		last = layers - j - 1;
		for (int i =first ;i<last;i++)
		{
			offset = i-first;
			top=mat[first][i];
			mat[first][i]=mat[last-offset][first];
			mat[last-offset][first] = mat[last][last-offset];
			mat[last][last-offset]=mat[i][last];
			mat[i][last]=top;
		}
	}
}

int main()
{
	int i=0,j=0;
	int mat[4][4]={1,2,3,4,
	                1,2,3,4,
	                1,2,3,4,
	                1,2,3,4,
	                 };

	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		   printf("%d",mat[i][j]);
		printf("\n");
	}

	rotate(mat,4);

	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		   printf("%d",mat[i][j]);
		printf("\n");
	}
}