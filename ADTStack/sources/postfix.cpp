#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "STACK2.cpp"

using namespace std;

int main(int argc, char *argv[]){
	char *a = argv[1]; int N = strlen(a);
	STACK2<int> save(N);

	for(int i = 0; i < N; i++){
		if (a[i] == '+')
			save.push(save.pop() + save.pop());
		if (a[i] == '*')
			save.push(save.pop() * save.pop());
		if (a[i] <= '9' && a[i] >= '0')
			save.push((a[i]) - '0');
//		while((a[i] >= '0') && (a[i] <= '9'))
//			save.push(save.pop() * 10 + (a[i++] - '0'));
	}
	cout << save.pop() << endl;
}
