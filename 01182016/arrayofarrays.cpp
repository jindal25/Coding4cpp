#include <iostream>

using namespace std;

int find(char  aoa[5][5], char * str )
{
	int i =0, j=0;
	while(aoa[i][j] != '\0')
	{
		if(aoa[i][0] == str[0]){
			return i;
		}
		i++;
	}
}

int main() {
	int a=0;
	char aoa[5][5] = {"test","" , "read", "is", "a"};
	a = find (aoa, "is");
	cout << a << endl;

	return 0;
}