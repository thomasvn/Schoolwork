/*
 *	Thomas Nguyen
 *	Coen 70 Lab
 *	Tuesday 2:15pm
*/

#include <cstdlib>
#include <utility>
#include <list>
#include <iostream>

using namespace std;

template <class K, class V>
class Map {
public:
	void insert(K Key, V Value);
	bool contains_key(K Key);
	V value_of(K Key);
	void remove_key(K Key);

	friend ostream& operator<< (ostream& out, const Map<K,V> &m) {
		// Declare iterator
		typename std::list< pair<K,V> >::const_iterator it;

		// Move through entire list
		for (it = m.list.begin(); it != m.list.end(); it++) {
			cout << "Key: " << it->first << endl;
			cout << "Value: " << it->second << "\n" << endl; 
		}

		return out;
	}

private:
	std::list< std::pair<K,V> > list;
};

template <class K, class V>
void Map<K,V>::insert(K Key, V Value) {
	// Cannot insert a duplicate
	if (Map<K,V>::contains_key(Key)) {
		cout << "Attempted to insert a duplicate" << endl;
		return;
	}

	// Pushes key and value to the end
	list.push_back(pair<K,V> (Key, Value));	
}

template <class K, class V>
bool Map<K,V>::contains_key(K Key) {
	// Declare iterator
	typename std::list< pair<K,V> >::iterator it;

	// Not inside if list is empty
	if (list.empty()) {
		return false;
	}
	// Iterate through list to check
	for (it = list.begin(); it != list.end(); it++) {
		if (Key == it->first) {
			return true;
		}
	}

	return false;
}

template <class K, class V>
V Map<K,V>::value_of(K Key) {
	// Declare iterator
	typename std::list< pair<K,V> >::iterator it;

	// Iterator through list to find value
	for (it = list.begin(); it != list.end(); it++) {
		if (Key == it->first) {
			return (it->second);
		}
	}

	return 0;
}

template <class K, class V>
void Map<K,V>::remove_key(K Key) {
	// Declare iterator
	typename std::list< pair<K,V> >::iterator it;
	
	// Move through list finding key
	for (it = list.begin(); it != list.end(); it++) {
		if (Key == it->first) {
			list.erase(it);
		}
	}
	

}






