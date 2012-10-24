#include <iostream>

#define N 1000

using namespace std;


int main(){
	int a[N];
	int i, j;
	int count = 0;

	for(i = 2; i < N; i++) {
		a[i] = 1;
	}
	for(i = 2; i < N; i++){
		if(a[i]){
			for(j = i; j * i < N; j++)
				a[j * i] = 0;
		}
	}
	for(i = 2; i < N; i++)
		if(a[i]) {
			cout << i << " ";
			count++;
		}

	cout << endl;
	cout << count << endl;
}
