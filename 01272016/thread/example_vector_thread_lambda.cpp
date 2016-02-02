#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>


int main(){
	std::vector<std::thread> vec;
	std::mutex mut;
	std::condition_variable cond;
	std::unique_lock<std::mutex> locker(mut,std::defer_lock);

	for( int i = 0 ; i<10;i++){
			vec.push_back(std::thread([i](){
	 			std::cout << "this is the thread no " << i << std::endl;
				}));
	}
	std::cout << "this is from the main" << std::endl;
	//std::vector iterator it;
	//for( it = vec.begin(); it != vec.end();it++)
		//it.join();
	std:for_each (vec.begin(), vec.end(), [](std::thread &th){
		th.join();
	});
	return 0;
}