#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	int item;
	node* next;
	node(int x, node* t){
		item = x;
		next = t;
	}
};

typedef node *list_link;

list_link reverse(list_link x){
	list_link t, y = x, r = 0;
	while (y != 0){
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}

void ptrlist(list_link x){
	list_link t;
	for (t = x; t != 0; t = t->next)
		cout << t->item <<endl;
}

int main(int argc, char * argv[]){

	int N = atoi(argv[1]);
	node heada(0, 0);
	list_link a = &heada, t = a;
	for (int i = 0; i < N; i++)
		t = (t->next = new node(rand() % 1000, 0));

	ptrlist(a);

	cout << endl;

	list_link b = reverse(a);

	ptrlist(b);

}
