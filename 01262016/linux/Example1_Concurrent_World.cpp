#include <iostream>
#include <thread>

void hello()
{
 std::cout<<"Hello Concurrent World\n";
}

int main()
{
 std::thread t(hello);
 t.join();

 std::thread t2(hello);
 t2.join();

std::thread t3(hello);
 t3.join();

std::thread t4(hello);
 t4.join();

 std::thread t5(hello);
 t5.join();


}