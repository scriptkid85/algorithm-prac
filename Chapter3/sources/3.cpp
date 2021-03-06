#include <iostream>
#include <stdlib.h>
#include "IncreSTACK.cpp"

using namespace std;

//(1) TRISTACK
//(2) MinSTACK
//(3) IncreSTACK

//(4)

void hanoi(int N, int tower, int direction){
	if(N <= 1){
		cout << tower << "->" << (tower + direction + 3) % 3 << endl;
		return;
	}
	hanoi(N - 1, tower, -1 * direction);
	cout << tower << "->" << (tower + direction + 3) % 3 << endl;
	hanoi(N - 1, (tower -1 * direction + 3) % 3, -1 * direction);
}

int main(int argc, char * argv[]){
	INCRESTACK<int> stack;
	hanoi(4, 0, -1);

}
