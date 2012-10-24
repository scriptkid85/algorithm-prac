/*Basic version for the connection problem*/


#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

#define N 100

int pointer[N + 1];

void printpointer(){
	for(int i = 1; i < N + 1; i++)
		cout << pointer[i]<<',';
	cout<<endl;
}

int main(){
	int p, q;

    ifstream fp("input.txt");
	//initialize the pointer array
	for(int i = 0; i < N + 1; i++)pointer[i] = i;

	//read input pairs.
	while(fp >> p >> q){
		cout << p << '-' << q << endl;
		int temp = pointer[p];
		for(int i = 1; i < N + 1; i++)
		{
			if(pointer[i] == temp)pointer[i] = pointer[q];
		}
		printpointer();
	}
}
