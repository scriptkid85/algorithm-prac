#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

//(2)
string binaryofdouble(double a){
	if(a >= 1 || a <= 0)return NULL;

	string r;
	double num = a;
	while(num > 0){
		num *= 2;
		if(num >= 1){
			r.append("1");
			num -= 1;
		}
		else r.append("0");
	}
	return r;
}

//(3)
void printnextlargeasamll(int a){

}

//(7) Important and hard!

/*  test part
 	int a1[4] = {0, 0, 0, 0};
	int a2[4] = {1, 0, 0, 0};
	int a3[4] = {0, 1, 0, 0};
	int a4[4] = {1, 1, 0, 0};
	int a5[4] = {0, 0, 1, 0};

	vector<int *> a;
	a.push_back(a1);
	a.push_back(a2);
	a.push_back(a3);
	a.push_back(a4);
	a.push_back(a5);

	cout << findloss(a) << endl;
 */

int findloss(vector<int*> array){
	if(array.size() == 0)return 0;

	vector<int*> zeros, ones;
	int r = 0, onecnt = 0, zerocnt = 0, position = 0;
	while(array.size() > 0){
		for(vector<int *>::iterator it = array.begin(); it != array.end() ; ++it){
			if((*it)[position] == 1){
				ones.push_back(*it);
				onecnt ++;
			}
			else {
				zeros.push_back(*it);
				zerocnt ++;
			}
		}
		if(onecnt < zerocnt) {
			r = r | (1 << position);
			array = ones;
		}
		else array = zeros;
		zeros.clear();
		ones.clear();
		onecnt = 0;
		zerocnt = 0;
		position ++;
	}

	return r;
}

int main(int argc, char *argv[]){

}
