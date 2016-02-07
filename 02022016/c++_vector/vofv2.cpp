#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


int main()
{
	vector< vector<int> > buff(10);

	for(int i=0; i<10; i++){
		int y = rand()%10;
		buff[y].push_back(1); // Fixes the compiler error
	}

	for(int i=0; i<buff.size(); i++) // Ensure that you don't access any elements that don't exist
		for(int p=0; p<buff[i].size(); p++) // You may not have had 10 in here before, only go to size().
		cout << buff[i][p] << " ";


return 0;
}