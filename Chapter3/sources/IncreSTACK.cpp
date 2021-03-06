template <class Item>

#define THRESHOLD 3

class INCRESTACK{
private:
	struct node{
		Item *item;
		node *next;
		node(Item *x, node *t){
			item = x;
			next = t;
		}
	};

	typedef node *mylink;

	int top;
	mylink stackhead;

public:
	INCRESTACK(){
		Item *s = new Item(THRESHOLD);
		mylink link = new node(s, 0);
		stackhead  = link;
		top = 0;
	}

	int empty() const{
		return (top <= 0 && stackhead -> next == 0);
	}

	void push(Item x){
		if(top >= THRESHOLD){
			top = 0;
			Item *s = new Item(THRESHOLD);
			mylink link = new node(s, stackhead);
			stackhead = link;
		}
		(stackhead -> item)[top++] = x;
	}

	Item pop(){
		mylink temp;
		if(top <= 0 && stackhead -> next == 0)return 0;
		if(top <= 0){
			top = THRESHOLD;
			temp = stackhead;
			stackhead = stackhead -> next;
			delete(temp);
		}
		return (stackhead -> item)[--top];
	}
};
