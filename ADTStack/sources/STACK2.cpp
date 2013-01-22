template <class Item>


class STACK2{
	private:
		struct node{
			Item item;
			node *next;
			node(Item x, node *t){
				item = x;
				next = t;
			}
		};
		typedef node *link;
		link head;

	public:
		STACK2(int){
			head = 0;
		}

		int empty() const{
			return head == 0;
		}

		void push(Item item){
			head = new node(item, head);
		}

		Item pop(){
			Item r = head -> item;
			link t = head -> next;
			delete head; // delete is used to free the object to which the pointer points;
			head = t;
			return r;
		}

};
