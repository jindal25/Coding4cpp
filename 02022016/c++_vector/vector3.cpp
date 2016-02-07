#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	//  initialize vector of integers with 20 elements
	vector<int> vectorOne(10);
		
	
	//  display size and capacity of vector
	cout << "Size of vectorOne is: " << vectorOne.size() << " elements." << endl;
	cout << "Capacity of vectorOne is: " << vectorOne.capacity() << " elements." << endl;
	
	//  put some random data into the vector using at()
	for (long index=0; index<(long)vectorOne.size(); ++index) vectorOne.at(index)=rand();
	
	//  display vector contents
	cout << "vectorOne contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) {
		cout << vectorOne.at(index) << " ";
	}
	cout << endl << endl;
	
	
	//  reserve more space for the vector and repeat
	cout << "Using reserve to reallocate vectorOne with enough storage for 40 elements."  << endl;
	
	vectorOne.reserve(40);
	
	//  display size and capacity of vector
	cout << "Size of vectorOne is: " << vectorOne.size() << " elements." << endl;
	cout << "Capacity of vectorOne is: " << vectorOne.capacity() << " elements." << endl;
	
	//  put some random data into the vector using at()
	for (long index=0; index<(long)vectorOne.size(); ++index) 
				vectorOne.at(index)=rand();
	
	//  display vector contents
	cout << "vectorOne contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) {
		cout << vectorOne.at(index) << " ";
	}
	cout << endl << endl;
	
	
	//  add elements to vector using resize
	cout << "Using resize to increase size of vector to 15 elements, with new elements set to 0." << endl;
	vectorOne.resize(15,(int)0);

	//  display size and capacity of vector
	cout << "Size of vectorOne is: " << vectorOne.size() << " elements." << endl;
	cout << "Capacity of vectorOne is: " << vectorOne.capacity() << " elements." << endl;
	
	//  put some random data into the vector using at()
	for (long index=0; index<(long)vectorOne.size(); ++index) 
				vectorOne.at(index)=rand();
	
	//  display vector contents
	cout << "vectorOne contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) {
		cout << vectorOne.at(index) << " ";
	}
	cout << endl << endl;
	
	
	//  remove elements from vector using resize
	cout << "Using resize to decrease size of vector to 5 elements." << endl;
	vectorOne.resize(5);
	
	//  display size and capacity of vector
	cout << "Size of vectorOne is: " << vectorOne.size() << " elements." << endl;
	cout << "Capacity of vectorOne is: " << vectorOne.capacity() << " elements." << endl;
	
	//  put some random data into the vector using at()
	for (long index=0; index<(long)vectorOne.size(); ++index) vectorOne.at(index)=rand();
	
	//  display vector contents
	cout << "vectorOne contains the following elements:" << endl;
	for (long index=0; index<(long)vectorOne.size(); ++index) {
		cout << vectorOne.at(index) << " ";
	}
	cout << endl << endl;

	
	return EXIT_SUCCESS;
}
