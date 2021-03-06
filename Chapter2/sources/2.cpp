#include <iostream>
#include <stdlib.h>
#include <map>
#include <stack>

using namespace std;

struct mynode{
	int item;
	mynode *next;
	mynode(int x, mynode *t){
		item = x;
		next = t;
	}
};

typedef mynode *mylink;
map<int,int> record;

void printlist(mylink head){
	mylink t;
	for(t = head; t != 0; t = t -> next){
		cout << t -> item << " ";
	}
	cout << endl;
}

void printlistn(mylink head, int n){
	mylink t;
	int i;
	for(t = head, i = 0; t != 0, i < n; t = t -> next, i++){
		cout << t -> item << " ";
	}
	cout << endl;
}

void removeduplicate(mylink head){
	mylink t, k, pre;
	for(t = head; t != 0; t = t -> next){
		for(k = t -> next, pre = t; k != 0; k = k -> next){
			if(t -> item == k -> item){
				pre -> next = k -> next;
			}
			else pre = k;
		}
	}
}


void removeduplicate2(mylink head){
	mylink t, pre;
    record[head -> item] = 1;
	for(pre = head, t = head -> next; t != 0; t = t -> next){
		if(record.find(t -> item) == record.end()){
			record[t -> item] = 1;
			pre = pre -> next;
		}
		else{
			pre -> next = t -> next;
		}
	}
}

mylink addlistnum(mylink a, mylink b){
	mylink t, k, r, oldr, result = 0;;
	int avalue, bvalue, yu, carryon = 0;
	for(t = a, k = b; t != 0 || k != 0 || carryon != 0;){   //carryon != 0 case you should continue add node in the list
		avalue = 0; bvalue = 0;
		if(t != 0){
			avalue = t -> item;
			t = t -> next;
		}
		if(k != 0){
			bvalue = k -> item;
			k = k -> next;
		}
		yu = (avalue + bvalue + carryon) % 10 ;
		carryon = (avalue + bvalue + carryon) / 10;
		r = new mynode(yu, 0);
		if(result == 0){
			result = r;
			oldr = r;
			continue;
		}
		oldr -> next = r;
		oldr = r;
	}
	return result;
}

void aroundx(mylink &head, int x){
	mylink k, start, end, tmp;
	mylink t = new mynode(0, 0);
	start = end = t;
	for(k = head; k != 0; k = tmp){
		tmp = k -> next;
		if(k -> item > x){
			end -> next = k;
			end = k;
			end -> next = 0;
		}
		else {
			if(start == t){
				k -> next = start;
				start = k;
				head = start;
			}
			else{
				k -> next = t;
				start -> next = k;
				start = k;
			}
		}
	}
	start -> next = t -> next;
}

int findkth(mylink head, int k){
	mylink t;
	int i, count = 0;
	for(t = head; t != 0; t = t -> next){
		count++;
	}
	if(count < k) return 0;
	for(t = head, i = 1; i <= (count - k); t = t -> next , i++);
	return t -> item;
}


//(6)
//very important method:
//use fast runner and slow runner to test the loop. At the same time,
//the fast runner and slow runner can also be used to find the loop.
//Assume the no-loop part of the list has length k, the slow runner
//has step speed 1 and fast runner has step speed 2, then after k steps,     --> k < N steps
//the slow runner just enter the loop and fast runner is K steps ahead
//of slow runner, (K = mod(2k - k, loop_size)), or say loop_size - K steps
//behind the slow runner. So After loop_size - K steps, the fast runner will   --> loop_size - K < N steps
//catch slow runner. Remember this collision position which is K steps
//far from the loop_start.

//Then set another pointer in the head of the list, which moves together with
//a point at the collision position, after k step, they will meet.


int loopstart(mylink head){
	mylink slowrunner, fastrunner, start;
	start = slowrunner = fastrunner = head;
	int count;
	while(fastrunner != 0){
		if(fastrunner = fastrunner -> next){
			fastrunner = fastrunner -> next;
		}
		slowrunner = slowrunner -> next;
		if(fastrunner == slowrunner){
			count = 1;
			while(start != slowrunner){
				slowrunner = slowrunner -> next;
				start = start -> next;
				count ++;
			}
			return count;
		}
	}
	return 0;
}

//(7)

int isPalindrome(mylink head){
	stack<int> save;
	mylink slowrunner, fastrunner;
	slowrunner = fastrunner = head;
	if(head -> next == 0)return 1;
	while(fastrunner != 0){
		if(fastrunner = fastrunner -> next){
			save.push(slowrunner -> item);
			if(fastrunner = fastrunner -> next){
				slowrunner = slowrunner -> next;
			}
		}
	}
	while((slowrunner = slowrunner -> next) != 0){
		if(slowrunner -> item != save.top()){
			return 0;
		}
		save.pop();
	}
	return 1;
}


int main(int argc, char * argv[]){
	mylink t, r, k;
	k = t = new mynode(10, 0);
	t = new mynode(9, t);
	t = new mynode(9, t);
	t = new mynode(10, t);
/*
	for(int i = 9; i > 0 ; i--){
		t = new mynode(i, t);
	}
	for(int i = 11; i > 0 ; i--){
		t = new mynode(11 - i, t);
	}
	*/
	printlist(t);

	cout << isPalindrome(t) << endl;

}
