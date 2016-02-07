#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	std::map< char, int > charmap;
	
	charmap.insert(std::pair<char, int>('h',1));
	charmap.insert(std::pair<char, int>('e',1));
	charmap.insert(std::pair<char, int>('l',1));
	charmap.insert(std::pair<char, int>('l',2));

    map <char,int>::iterator it;

	for( it = charmap.begin();it!=charmap.end();it++)
	 std::cout << (*it).first << (*it).second << std::endl;
}


