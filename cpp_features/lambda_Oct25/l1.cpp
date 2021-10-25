// Cpp program to demonstrate
// how to sort integers, floats, strings
// floating data types using a 
// generalized lambda and sort function
  
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
  
using namespace std;
  
// Utility Function to print the elements of a collection
void printElements(auto& C)
{
  
    for (auto e : C)
        cout << e << " ";
  
    cout << endl;
}
  
int main()
{
  
    // Declare a generalized lambda and store it in greater
    auto greater = [](auto a, auto b) -> bool {
        return a > b;
    };
  
    // Initialize a vector of integers
    vector<int> vi = { 1, 4, 2, 1, 6, 62, 636 };
  
    // Initialize a vector of doubles
    vector<double> vd = { 4.62, 161.3, 62.26, 13.4, 235.5 };
  
    // Initialize a vector of strings
    vector<string> vs = { "Tom", "Harry", "Ram", "Shyam" };
  
    // Sort integers
    sort(vi.begin(), vi.end(), greater);
  
    // Sort doubles
    sort(vd.begin(), vd.end(), greater);
  
    // Sort strings
    sort(vs.begin(), vs.end(), greater);
  
    printElements(vi);
    printElements(vd);
    printElements(vs);
  
    return 0;
}

