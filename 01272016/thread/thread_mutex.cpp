#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


std::mutex print_mtx_;
void safe_print(int x)
{
  std::lock_guard<std::mutex> lock(print_mtx_);
  std::cout << x << std::endl;
}

class X {
  std::mutex mtx_;
  std::vector<int> data_;
public:
  void add_value(int value)
  {
    std::lock_guard<std::mutex> lock(mtx_); 
    data_.push_back(value);
  } 

  void print()
  {
    std::lock_guard<std::mutex> lock(mtx_);
    for (int x : data_) {
      safe_print(x);
    }
  }
};

int main()
{
  X x;

  std::thread t1([&x]{ x.add_value(1); });
  std::thread t2([&x]{ x.add_value(2); });

  t1.join();
  t2.join();

  x.print();
}