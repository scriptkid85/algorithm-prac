#include <iostream>

using namespace std;

template <class Item>

class TriSTACK{
private:
	Item *s;
	int top[3];
	int stacksize;

public:
	TriSTACK(int maxN){
		s = new Item(3 * maxN);
		top[0] = 0;
		top[1] = maxN;
		top[2] = 2 * maxN;
		stacksize = maxN;
	}
	void push(int stacknum, Item x){
		if(top[stacknum] >= (stacknum + 1) * stacksize){
			cout << "out of space! " << endl;
			return;
		}
		s[top[stacknum]++] = x;
	}

	Item pop(int stacknum){
		if(top[stacknum] <= (stacknum) * stacksize){
			cout << "empty! " << endl;
			return 0;
		}
		return s[--top[stacknum]];
	}

	int empty(int stacknum) const{
		return top[stacknum] == stacknum * stacksize;
	}

};
