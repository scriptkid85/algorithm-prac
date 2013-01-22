template <class Item>

class STACK{
private:
	Item *s;
	int N;

public:
	STACK(int maxN){
		s = new Item[maxN];
		N = 0;
	}

	int empty() const{
		return N == 0;
	}

	void push(Item item){
		s[N++] = item;
	}

	Item pop(){
		return s[--N];
	}

};
