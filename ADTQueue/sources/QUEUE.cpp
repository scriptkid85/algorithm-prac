template <class Item>

class QUEUE{
private:
	struct node{
		Item item;
		node *next;
		node(Item x){
			item = x;
			next = 0;
		}
	};
	typedef node *link;
	link head, tail;

public:
	QUEUE(int){
		head = 0;
	}

	int empty() const{
		return head == 0;
	}

	void put(Item x){
		link t = tail;
		tail = new node(x);
		if(head == 0){
			head = tail;
		}
		else t->next = tail;
	}

	Item get(){
		Item v = head->item;
		link t = head->next;
		delete head;
		head = t;
		return v;
	}
};
