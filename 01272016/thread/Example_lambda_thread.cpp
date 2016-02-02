#include <iostream>
#include <thread>
#include <algorithm>

int main(){
	std::thread th([](){
	 std::cout << "this is the thread" << std::endl;
	});
	std::cout << "this is from the main" << std::endl;
	th.join();
	return 0;
}