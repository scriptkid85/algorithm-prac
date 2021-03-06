/*
 * 9.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: gavin
 */


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define MAXNUM 10000
#define GRID 8


//(1)



int countstair(int n, int stair[]){
	if(stair[n] != 0)return stair[n];
	if(n == 1){
		stair[1] = 1;
		return 1;
	}
	if(n == 2){
		stair[2] = 2;
		return 2;
	}
	if(n == 3){
		stair[3] = stair[1] + stair[2];
		return stair[3];
	}
	stair[n] = countstair(n - 1, stair) + countstair(n - 2, stair) + countstair(n - 3, stair);
	return stair[n];
}

int runstair(int n){
	int stair[MAXNUM];
	for(int i =  1; i <= n; i++)stair[i] = i;
	return countstair(n, stair);
}

//(3) the non-distinct case is interesting to think about
int magicindexdistinct(int a[], int l, int r){
	if(r < l || (r == l && a[l] != l))return -1;
	if(r == l && a[l] == l) return l;
	int index = (r + l) / 2;
	int val = a[(r + l) / 2];
	if(val == index)return index;
	else if(val < index)return magicindexdistinct(a, index + 1, r);
	else return magicindexdistinct(a, l, index - 1);
}

int magicindexnondistinct(int a[], int l, int r){
	if(r < l || (r == l && a[l] != l))return -1;
	if(r == l) {
		if(a[l] == l)return l;
		return -1;
	}

	int index = (r + l) / 2;
	int val = a[(r + l) / 2];

	if(val == index)return index;
	int leftindex = magicindexnondistinct(a, l, min(index - 1, val));
	if(leftindex != -1)return leftindex;

	int rightindex = magicindexnondistinct(a, max(index + 1, val), r);
	return rightindex;

}

//(4) uses bits to print all subset;
void printsubset(int a[], int n){
	int cnt;
	for(int i = 0; i < (1 << n); i++){
		cnt = 0;
		cout << " { ";
		while(cnt < n){
			if((i >> cnt) & 1)cout << a[cnt] <<" ";
			cnt ++;
		}
		cout << "}" << endl;
	}
}

//(5)
vector<string> distinctstring(string s){
	vector<string> permutations, temp1, temp2;

	if(s.size() == 1){
		permutations.push_back(s);
		return permutations;
	}

	temp1.push_back(s.substr(s.size() - 1, 1));
	for(int i = s.size() - 2; i >= 0; i--){
		for(vector<string>::iterator it = temp1.begin(); it != temp1.end(); ++it){
			int length = (*it).size();
			temp2.push_back(s.substr(i, 1) + (*it));
			for(int j = 1; j < length; j ++){
				temp2.push_back((*it).substr(0, j) + s.substr(i, 1) + (*it).substr(j, length - j));
			}
			temp2.push_back((*it) + s.substr(i, 1));
		}
		temp1.clear();
		temp1 = temp2;
		temp2.clear();
	}
	return temp1;
}

vector<string> distinctstring2(string s){
	vector<string> result;
	if(s.size() == 0)return result;
	if(s.size() == 1){
		result.push_back(s);
		return result;
	}

	string reminder = s.substr(1, s.size() - 1);
	string currentchar = s.substr(0, 1);
	vector<string> pre = distinctstring2(reminder);

	for(vector<string>::iterator it = pre.begin(); it != pre.end(); ++ it){
		for(int i = 0; i <= (*it).size(); i ++){
			result.push_back((*it).substr(0, i) + currentchar + (*it).substr(i, (*it).size() - i));
		}
	}
	return result;

}

//GREAT!!! recursion !! can be used for nondistinct string (sorted first, or say put
//same char together)
void printpermutation(string s, int index){
	char lastchar = 0;
	if(index == s.size()){
		cout << s << endl;
	}
	for(int i = index; i < s.size(); i++){
		if(lastchar == s[i])continue;
		else lastchar = s[i];

		char t = s[i];
		s[i] = s[index];
		s[index] = t;

		printpermutation(s, index + 1);

		t = s[i];
		s[i] = s[index];
		s[index] = t;

	}

}


//(6)
//very HARD! ok not very hard, but spend a lot time the first time
void printparentheses(string s, int n, int cnt, int leftinstack){
	if(cnt == n){
		for(int i = 0; i < leftinstack; i++)
			s = s + ")";
		cout << s << endl;
		return;
	}

	string temp;
	temp.clear();
	temp = s;

	if(leftinstack > 0){
		s = s + ")";
		printparentheses(s, n, cnt, leftinstack - 1);
		s.clear();
		s = temp;
		s = s + "(";
		printparentheses(s, n, cnt + 1, leftinstack + 1);
	}
	else{
		s.clear();
		s = temp;
		s = s + "(";
		printparentheses(s, n, cnt + 1, leftinstack + 1);
	}
}


void parentheses(int n){
	string s;
	s.clear();
	printparentheses(s, n, 0, 0);
}



//(8)
void printcents(int a[]){
	cout << a[0] << " pennies(1), " << a[1] << " nickels(5), " << a[2] << " dims(10), "
			<< a[3] << " quarters(25)" << endl;
}

void computecents(int a[], int n, int sum, int lastused){
	if(n - sum < 5){
		for(int i = 0; i < (n - sum); i++)
			a[0] ++;
		printcents(a);
		return;
	}
	int temp[4] = {a[0], a[1], a[2], a[3]};
	if(n - sum >= 25 && lastused >= 25){
		a[3]++;
		computecents(a, n, sum + 25, 25);
	}
	if(n - sum >= 10 && lastused >= 10){
		a[0] = temp[0];a[1] = temp[1];a[2] = temp[2];a[3] = temp[3];
		a[2]++;
		computecents(a, n, sum + 10, 10);
	}
	if(n - sum >= 5 && lastused >= 5){
		a[0] = temp[0];a[1] = temp[1];a[2] = temp[2];a[3] = temp[3];
		a[1]++;
		computecents(a, n, sum + 5, 5);
	}
	if(n - sum >= 1 && lastused >= 1){
		a[0] = temp[0];a[1] = temp[1];a[2] = temp[2];a[3] = temp[3];
		a[0]++;
		computecents(a, n, sum + 1, 1);
	}
}


//(9)

bool checkvaild(int row, int column, int columns[]){
	for(int i = 0; i < row; i++){
		if(columns[i] == column)return false;

		int dist1 = abs(columns[i] - column);
		int dist2 = row - i;
		if(dist1 == dist2)return false;
	}
	return true;
}

int* clonearray(int s[], int size){
	int *d = new int(size);
	for(int i = 0; i < size; i++)
		d[i] = s[i];
	return d;
}

void eightqueen(int row, int columns[], vector<int *> &result){
	if(row == GRID){
		int d[8] = {columns[0], columns[1], columns[2], columns[3], columns[4], columns[5], columns[6], columns[7]};
		result.push_back(d);
	}

	int d[8] = {columns[0], columns[1], columns[2], columns[3], columns[4], columns[5], columns[6], columns[7]};
	for(int i = 0; i < GRID; i++){
		for(int j = 0; j < GRID; j++)columns[j] = d[j];
		if(checkvaild(row, i, columns)){
			columns[row] = i;
			eightqueen(row + 1, columns, result);
		}
	}
}

void printqueen(vector<int *> queen){
	int cnt = 0;
	for(vector<int *>::iterator it = queen.begin(); it == queen.begin(); ++it){

		for(int i = 0; i < GRID; i++){
			for(int j = 0; j < (*it)[i]; j++)
				cout << " + ";
			cout << " o ";
			for(int k = (*it)[i] + 1; k < GRID; k++)
				cout << " + ";
			cout << '\n' ;  //note here!!!! why cannot use endl, endl will change the *it, dont know why
		}
		cnt ++;
	}
}

// (10)
bool checkTriValid(int **a, int level, int sort[], int length){
	return (a[level][0] >= a[sort[length - 1]][0] && a[level][1] >= a[sort[length - 1]][1] && a[level][2] >= a[sort[length - 1]][2]);
}

vector<int *> Trisort(int **a, vector<int *> result, int sort[], int length, int n, int level){
	if(level == n){
		result.push_back(sort);
	}
	int *temp = new int(n);
	for(int i = 0; i < level; i ++){
		temp[i] = sort[i];
	}
	if(checkTriValid(a, level, sort, length)){
		sort[length] = level;
		Trisort(a, result, sort, length + 1, n, level + 1);
	}
	for(int i = 0; i < level; i ++){
		sort[i] = temp[i];
	}
	for(int i = level; i < n; i ++){
		sort[i] = -1;
	}
	Trisort(a, result, sort, length, n, level + 1);
}


int tallest(int **a, int n){
	int *s = new int(n);
	for(int i = 0; i < n; i++)s[i] = -1;
	vector<int *> result;
	result = Trisort(a, result, s, 0, n, 0);
}

int main(int argc, char * argv[]){
	vector<int *> queen;
	int array[8] = {0,0,0,0,0,0,0,0};
	eightqueen(0, array, queen);

	printqueen(queen);
}

