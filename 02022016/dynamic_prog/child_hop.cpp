#include <iostream>

using namespace std;

int mat[3][3];

int X=3;
int Y=3;


int childHop( int n){
	if( n < 0 )
		return 0;
	else if (n==0)
		return 1;
	else 
		return childHop(n-3) + childHop(n-2) + childHop(n-1);
}


int go2grid(int x,int y)
{
	 int t1,k1,t2,k2;
	if(x < X || y < Y) {
		if (x >=X)
			t= X;
		else
			t=x+1;

		if (y >=Y)
			k=y;
		else
			k=y+1;

		return go2grid(t, y) + 1 + go2grid(x, k) ;
	}
	
}



int main(){
	cout <<" Child hop for 1 is " << childHop(1) << endl;
	cout <<" Child hop for 2 is " << childHop(2) << endl;
	cout <<" Child hop for 3 is " << childHop(3) << endl;
	cout <<" Child hop for 4 is " << childHop(4) << endl;
	cout <<" Child hop for 5 is " << childHop(5) << endl;

	for( int i =0 ;i< 3;i++)
		for( int j =0 ;j< 3;j++)
			mat[i][j]=-1;


	go2grid(0, 0 , 2, 2 );
 
}