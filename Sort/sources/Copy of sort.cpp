#include <stdlib.h>
#include <iostream>

using namespace std;

template <class Item>
	void exch(Item &A, Item &B){
		Item t = A; A = B; B = t;
	}

template <class Item>
	void compexch(Item &A, Item &B){
		if (B < A) exch(A, B);
	}

template <class Item>
	void selectsort(Item a[], int l, int r){
		for(int i = l; i <= r; i++){
			int min = i;
			for(int j = i + 1; j <= r; j++){
				if(a[min] > a[j]) min = j;
			}
			exch(a[i], a[min]);
		}
	}
/*

int main(int argc, char *argv[]){
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = new int[N];
	if(sw){
		for(int i = 0; i < N; i++){
			a[i] = 100 * (1.0 * rand()/RAND_MAX);
		}
	}
	else {
		N = 0;
		while(cin >> a[N]) N++;
	}


	for(i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;

	selectsort(a, 0, N - 1);


	for(i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
}
*/
