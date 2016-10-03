/*
 *	Thomas Nguyen
 *	Wednseday 2:15-5:00
 *	
 *	This header file deque.h creates a class called
 *	Deque which contains the public struct NODE and
 *	the variables inside the old struct Deque - count
 *	and NODE *head. The header file also includes the
 *	declarations for the member functions.
*/

class Deque{
	struct NODE {
		int data;
		struct NODE *next;
		struct NODE *prev;
	};
	int count;
	NODE *head;
	public:
	Deque();
	~Deque();
	int size();
	void addFirst (int x);
	void addLast (int x);
	int removeFirst();
	int removeLast();
	int getFirst();
	int getLast();
};
