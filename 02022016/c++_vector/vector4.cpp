#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	//  initialize empty vector of integers
	vector<int> vectorOne;
	
	//  use push_back() to add 10 random integers to the vector
	for (long index=0; index<10; ++index) vectorOne.push_back(rand());
	
	//  display contents of vector
	cout << "vectorOne contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) cout << vectorOne.at(index) << " ";
	cout << endl << endl;
	
	//  add two more elements to the vector using push_back()
	for (long index=0; index<2; ++index) vectorOne.push_back(rand());
	
	//  display contents of vector
	cout << "vectorOne now contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) cout << vectorOne.at(index) << " ";
	cout << endl << endl;
	
	//  remove the last 9 elements of the vector using pop_back()
	for (long index=0; index<9; ++index) vectorOne.pop_back();
	
	//  display contents of vector
	cout << "vectorOne now contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) cout << vectorOne.at(index) << " ";
	cout << endl << endl;
	
}
