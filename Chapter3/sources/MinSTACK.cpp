#include <iostream>

using namespace std;

template <class Item>

class MinSTACK{
private:
	Item *s, *m;
	int top;

public:
	MinSTACK(int maxN){
		s = new Item(maxN);
		m = new Item(maxN);
		top = 0;
	}

	int empty() const{
		return top == 0;
	}

	void push(Item x){
		Item min;
		if(top <= 0)min = x;
		else min = x > m[top - 1] ? m[top - 1] : x;
		s[top++] = x;
		m[top - 1] = min;
	}

	Item pop(){
		if(top <= 0){
			cout << "empty! " << endl;
		}
		return s[--top];
	}

	Item min(){
		if(top <= 0){
			cout << "empty! " << endl;
		}
		return m[top - 1];
	}
};
