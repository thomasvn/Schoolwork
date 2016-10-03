/*
 *	Thomas Nguyen
 *	Coen 70 Lab
 *	Tuesday 2:15
*/


#include "Map.h"

int main() {
	// <Key, Value>
	Map<int, std::string> myMap;
	
	myMap.insert(5,"Joe");
	myMap.insert(6,"Bobby");
	myMap.insert(19,"Christopher");

	myMap.remove_key(5);

	myMap.value_of(6);
	
	cout << myMap;
	return 0;
}
