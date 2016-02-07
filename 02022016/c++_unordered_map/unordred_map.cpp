#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<int, int> mergeTwoPackages(const std::vector<int>& arr, const int limit){
   std::unordered_map<int, int> hash_table;   
   int size = arr.size();                 
   for(int i = 0 ;i< size;i++){
      if (hash_table.find(limit-arr.at(i)) != hash_table.end()){
         return std::make_pair(i, hash_table[limit-arr.at(i)]);
      } else {
         hash_table[arr.at(i)] = i; 
      }
   }
   return std::make_pair( -1, -1);   
}


int main() {
	std::pair<int,int> pa;
	std::vector<int> test(4,400);
	pa = mergeTwoPackages(test,800);

	std::cout << pa.first << pa.second ;
}