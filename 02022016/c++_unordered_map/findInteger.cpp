#include <iostream>
#include <unordered_map>
#include <vector>

int main(){
	bool notFound = true;
	int j =0;
	std::vector<int> arr {0,1,2,3,5,6,7,8,9,4,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,100};
	std::unordered_map<int,int> hash_table;

	for(int i=0; i< arr.size(); i++)
	{
		hash_table[arr[i]] = i;
	}

	while(notFound){
		if(hash_table.find(j) != hash_table.end()){
			j++;
		}
		else {
			std::cout << j << std::endl;
		    notFound = false;
		}
	}
}