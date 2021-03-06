#include <iostream>
#include <stdlib.h>
#include "time.h"

#define MAXVALUE 100
#define MAXN 100
#define MINFILE 3
#define CLOCKS_PER_SEC ((clock_t)1000)

using namespace std;



template <class Item>
	void exch(Item &A, Item &B){
		Item t = A; A = B; B = t;
	}

template <class Item>
	void compexch(Item &A, Item &B){
		if(B < A) exch(A, B);
	}

template <class Item>
	void printarray(Item a[], int N){
		int i;
		for(i = 0; i < N; i++)
				cout << a[i] << " ";
		cout << endl;
	}

//non-adaptive sorting, good for large Items and small keys (also can use pointer sorting)
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

// adaptive sorting, if the initial array is almost sorted, adaptive sorting is better.
template <class Item>
	void insertionsort(Item a[], int l, int r){
		for(int i = r; i > l; i--){
			compexch(a[i - 1], a[i]);
		}
		for(int i = l + 2; i < r; i ++){
			int j = i;
			Item v = a[i];
			while(a[j - 1] > v){
				a[j] = a[j-1];
				j--;
			}
			a[j] = v;
		}
}

template <class Item>
	void bubblesort(Item a[], int l, int r){
		for(int i = l; i < r; i++){
			for(int j = r; j > i; j--)
				compexch(a[j - 1], a[j]);
		}
	}


template <class Item>
	void shellsort(Item a[], int l,  int r){
		int h;
		for(h = 1; h <= (r - l) / 9; h = h * 3  + 1);
		for(; h > 0; h /= 3){
			for(int i = l + h; i <= r; i++){
				Item v = a[i];
				int j = i;
				while( j >= l + h && a[j - h] > v){
					a[j] = a[j - h];
					j -= h;
				}
				a[j] = v;
			}
		}
	}

template <class Item>
	int partition(Item a[], int l, int r){
		int i = l - 1, j = r;
		Item v = a[r];
		for(;;){
			while(a[++i] < v);
			while(a[--j] > v) if(j == l) break;
			if(i >= j)break;
			exch(a[i], a[j]);
		}
		exch(a[i], a[r]);
		return i;
	}

template <class Item>
	void quicksort(Item a[], int l, int r){
		if(r - l <= MINFILE){
			insertionsort(a, l, r);
			return;
		}
		int m = (r + l)/2;
		exch(a[m], a[r - 1]);
		compexch(a[l], a[r - 1]);
		compexch(a[l], a[r]);
		compexch(a[r - 1], a[r]);
		int i = partition(a, l, r - 1);
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}


void indexsort(int a[], int l, int r){
		int b[MAXN];
		int i, j, cnt[MAXVALUE + 1];
		for(j = 0; j < MAXVALUE; j++) cnt[j] = 0;
		for(i = l; i <= r; i++) {
			cnt[a[i] + 1] += 1;
		}

		for(j = 1; j < MAXVALUE; j++) cnt[j] += cnt[j - 1];
		for(i = l; i <=r; i++) b[cnt[a[i]]++] = a[i];
		for(i = l; i <=r; i++) a[i] = b[i - l];
}

template <class Item>
	void mergeAB(Item c[], Item a[], int N, Item b[], int M){
		for(int i = 0, j = 0, k = 0; k < N + M; k++){
			if(i == N){ c[k] = b[j++]; continue;}
			if(j == M){ c[k] = a[i++]; continue;}
			c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
		}
	}

template <class Item>
	void


int main(int argc, char *argv[]){
	clock_t start, finish;
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = new int(N);
	if(sw){
		for(i = 0; i < N; i++)
			a[i] = MAXVALUE * (1.0 * rand() / RAND_MAX);
	}
	else{
		int MaxN = N;
		N = 0;
		while(cin >> a[N] && N < MaxN) N++;
	}

    printarray(a, N);

//	selectsort(a, 0, N-1);

//	insertionsort(a, 0, N-1);

//	bubblesort(a, 0, N - 1);

//	shellsort(a, 0, N - 1);

//  indexsort(a, 0, N - 1);
    start = clock();
    quicksort(a, 0, N - 1);
    finish = clock();
    double duration = (double)(finish - start);
    cout << "duration: " << duration << endl;


    printarray(a, N);

}
