#include <iostream>

using namespace std;

template<class T>
class Stack {
public:
    Stack(const std::initializer_list<T>& i):elem(i) {}
    int size() const { return elem.size(); }
    bool empty() const { return elem.empty();}
    void push(const T&);
    T pop();
    T peek();
private:
    std::vector<T> elem;
};


template<class T>
void Stack<T>::push(const T& t) {
    elem.push_back(t);
}

template<class T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    auto x = elem.back();  
    elem.pop_back();
    return x;
}

template<class T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    return elem.back();
}


int findMaxLen(string str)
{
    int n = str.length();
 
    // Create a stack and push -1 as initial index to it.
    Stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i=0; i<n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
          stk.push(i);
 
        else // If closing bracket, i.e.,str[i] = ')'
        {
            // Pop the previous opening bracket's index
            stk.pop();
 
            // Check if this length formed with base of
            // current valid substring is more than max 
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
 
            // If stack is empty. push current index as 
            // base for next valid substring (if any)
            else stk.push(i);
        }
    }
 
    return result;
}
 
// Driver program
int main()
{
    string str = "((()()";
    cout << findMaxLen(str) << endl;
 
    str = "()(()))))";
    cout << findMaxLen(str) << endl ;
 
    return 0;
}
Run on IDE
