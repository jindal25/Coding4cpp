#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	std::vector <std::thread> workers;
	for(int i=0;i<10;i++){
			workers.push_back(std::thread([i]()
			{
	           	std::cout << "this is the thread" << i <<std::endl;
			}));
	}

	std::cout << "this is the main" <<std::endl;

	std::for_each(workers.begin(),workers.end(),[](std::thread& th){
			th.join();
			std::cout << "thread joined" <<std::endl;
	});
	return 0;

}