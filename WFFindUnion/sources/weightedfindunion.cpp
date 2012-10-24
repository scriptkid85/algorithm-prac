#include <iostream>
#include <fstream>

using namespace std;

#define N 15

int Array[N];
int Asize[N];

void printarray(){
	for(int i = 1; i < N + 1; i++)
		cout << Array[i] << ',';
	cout << endl;
}

void initarray(){
	for(int i = 0; i < N + 1; i++){
		Array[i] = i;
		Asize[i] = 1;
	}

}


int main(){
	ifstream fp("input.txt");
	int p, q;
	int rootp, rootq;

	initarray();
	printarray();
	while(fp >> p >> q){
		cout << p << '-' << q << endl;
		for(rootp = p; rootp != Array[rootp]; rootp = Array[rootp])
			Array[rootp] = Array[Array[rootp]];
		for(rootq = q; rootq != Array[rootq]; rootq = Array[rootq])
			Array[rootq] = Array[Array[rootq]];
		if(rootp == rootq)continue;
		if(Asize[rootp] >= Asize[rootq]){
			Array[rootq] = Array[rootp];
			Asize[rootp] += Array[rootq];
		}
		else{
			Array[rootp] = Array[rootq];
			Asize[rootq] += Array[rootp];
		}
		printarray();
	}
}
