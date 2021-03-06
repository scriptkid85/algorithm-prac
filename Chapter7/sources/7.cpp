/*
 * 7.cpp
 *
 *  Created on: Jan 17, 2013
 *      Author: gavin
 */


#include <iostream>
#include <stdlib.h>
#include <queue>
#include <math.h>

#define MAXINT 10000000;

using namespace std;

//(4)
int neg(int a){
	if(a == 0)return 0;
	int result = 0, i = 0;
	if(a > 0){
		while(i < a){
			result += -1;
			i ++;
		}
	}
	else {
		while(i > a){
			result += 1;
			i--;
		}
	}
	return result;
}

int multiply(int a, int b){
	if(a == 0 || b == 0)return 0;

	int result = 0;
	int i = 0;
	if(b >= 0){
		while (i < b){
			result += a;
			i++;
		}
	}
	else {
		int nega = neg(a);
		while (i > b){
			result += nega;
			i--;
		}
	}
	return result;
}


//(7) Important !!! hard detail!!
int kthnumber(int k){
	queue<int> save3, save5, save7;

	if(k == 0)return 0;
	if(k == 1)return 1;
	save3.push(3);
	save5.push(5);
	save7.push(7);
	int v3, v5, v7, val;

	for(int i = 1; i < k; i++){
		v3 = save3.size() > 0 ? save3.front() : MAXINT;
		v5 = save5.size() > 0 ? save5.front() : MAXINT;
		v7 = save7.size() > 0 ? save7.front() : MAXINT;

		val = min(v3, min(v5, v7));
		if(val == v3){
			save3.pop();
			save3.push(val * 3);
			save5.push(val * 5);
			save7.push(val * 7);
		}
		else if(val == v5){
			save5.pop();
			save5.push(val * 5); // note if 5x exists, then 3x must already added, 5x * 3 = 3x * 5!!!!
			save7.push(val * 7);
		}
		else {
			save7.pop();
			save7.push(val * 7);
		}

	}
	return val;
}




int main(int argc, char *argv[]){

	cout << kthnumber(9) << endl;

}

