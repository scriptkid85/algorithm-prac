/*
 * 11.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: gavin
 */




#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
//(1)
void ABsort(int *A, int m, int *B, int n){
	int sortpoint = m + n - 1;
	int a = m - 1;
	int b = n - 1;
	while(a >= 0 && b >= 0){
		A[sortpoint --] = (A[a] > B[b])? A[a --] : B[b --];
	}
	if(a < 0){
		while(b >= 0)A[sortpoint --] = B[b --];
		return;
	}
	while(a >= 0)A[sortpoint --] = A[a --];
	return;
}


//(2) Sometimes, changing the comparator is a good way to solve some special sorting problem.
//note !!!!: for sort function, the compare(i ,j) function is a bool and return true
//if i < j, otherwise return false.
bool stringcomparator(string a, string b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return (a.compare(b) < 0)? true : false;
}

void sortanagrams(vector<string> &a){
	sort(a.begin(), a.end(), stringcomparator);
}


//(3)
int findafterrotate(int *a, int target, int l, int r){
	if(r <= l){
		if(a[l] == target)return l;
		else return -1;
	}
	int middle = (r + l) / 2;
	if(a[middle] == target)return middle;
	if(a[middle] >= a[l] && a[middle] <= a[r]){
		if(a[middle] > target)return findafterrotate(a, target, l, middle - 1);
		return findafterrotate(a, target, middle + 1, r);
	}
	if(a[middle] < a[l]){
		if(a[middle] < target && a[r] >= target)return findafterrotate(a, target, middle + 1, r);
		return findafterrotate(a, target, l, middle - 1);
	}
	if(a[middle] > target && a[l] <= target)return findafterrotate(a, target, l, middle - 1);
	return findafterrotate(a, target, middle + 1, r);
}

//(5)
int findinblank(string s[], string target, int l, int r){
	if(r <= l){
		if(s[l] == target)return l;
		return -1;
	}

	int middle = (r + l) / 2;
	if(s[middle] == target)return middle;
	int temp = middle;
	while(s[--temp] == "");
	if(s[temp].compare(target) == 0)return temp;
	if(s[temp].compare(target) > 0)return findinblank(s, target, l, temp - 1);
	temp = middle;
	while(s[++temp] == "");
	if(s[temp].compare(target) == 0)return temp;
	if(s[temp].compare(target) < 0)return findinblank(s, target, temp + 1, r);
	return -1;
}


//(6)
int* findinmatrix(int **a, int rl, int rr, int cl, int cr, int target){
	int result[2] = {-1, -1};
	if(rr <= rl && cr <= cl){
		if(a[rl][cl] == target){
			result[0] = rl;
			result[1] = cl;
		}
		return result;
	}
	int rmiddle, cmiddle;

	rmiddle = (rl + rr) / 2;
	cmiddle = (cl + cr) / 2;
	if(a[rmiddle][cmiddle] >= target && a[rl][cl] <= target){
		int *temp1 = findinmatrix(a, rl, rmiddle, cl, cmiddle, target);
		if(temp1[0] != -1)return temp1;
	}
	if(a[rmiddle + 1][cmiddle + 1] <= target && a[rr][cr] >= target){
		int *temp2 = findinmatrix(a, rmiddle + 1, rr, cmiddle + 1, cr, target);
		if(temp2[0] != -1)return temp2;
	}
	if(a[rmiddle + 1][cl] <= target && a[rr][cmiddle] >= target){
		int *temp3 = findinmatrix(a, rmiddle + 1, rr, cl, cmiddle, target);
				if(temp3[0] != -1)return temp3;
	}
	if(a[rl][cmiddle + 1] <= target && a[rmiddle][cr] >= target){
			int *temp4 = findinmatrix(a, rl, rmiddle, cmiddle + 1, cr, target);
					if(temp4[0] != -1)return temp4;
	}
	return result;
}

//(7) O(n^2) algorithm
bool comparewtht(int *a, int *b){
	if(a[0] == b[0])
		return (a[1] < b[1]);
	return (a[0] < b[0]);
}

vector<int *> maxtower(vector<int *> a, vector<int *> b){
	if(a.size() == 0) return b;
	if(b.size() == 0) return a;
	return a.size() >= b.size() ? a : b;
}

void createtower(int endpeople, vector<int *> peoples, vector<int *> towerendwith[]){
	if(endpeople >= peoples.size())return;

	vector<int *> bestsolution;
	for(int i = 0; i < endpeople; i++){
		if((peoples[i])[1] <= (peoples[endpeople])[1]){
			bestsolution = maxtower(towerendwith[i], bestsolution);
		}
	}
	bestsolution.push_back(peoples[endpeople]);
	vector<int *> newsolution(bestsolution);
	towerendwith[endpeople] = newsolution;

	createtower(endpeople + 1, peoples, towerendwith);
}

vector<int *> createtower(vector<int *> peoples){
	sort(peoples.begin(), peoples.end(), comparewtht);
	vector<int *> solutions[peoples.size()];
	createtower(0, peoples, solutions);
	int max = 0, index = 0;
	for(size_t i = 0; i < peoples.size(); i++){
		if(max < solutions[i].size())
			index = i;
	}
	return solutions[index];
}


//O(nlogn) algorithm (hard!!)
void LIS(vector<int *> peoples, vector<int *> &result){
	if(peoples.size() <= 0)return;
	vector<int> p(peoples.size());
	vector<int> b;
	int u, v;

	sort(peoples.begin(), peoples.end(), comparewtht);

	b.push_back(0);
	for(size_t i = 0; i < peoples.size(); i++){
		if(peoples[b.back()][1] < peoples[i][1]){
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
		//binary search
		for(u = 0, v = b.size(); u < v;){
			int middle = (u + v) / 2;
			if(peoples[b[middle]][1] < peoples[i][1])
				u = middle + 1;
			else v = middle;
		}
		if(peoples[b[u]][1] > peoples[i][1]){
			b[u] = i;
			p[i] = b[u - 1];
		}
	}
	for(size_t i = 0; i < b.size(); i++)result.push_back(peoples[b[i]]);
}

int main(int argc, char * argv[]){
	vector<int *> peoples;
	int a1[2] = {15, 10};
	int a2[2] = {20, 150};
	int a3[2] = {56, 10};
	int a4[2] = {75, 100};
	int a5[2] = {60, 95};
	int a6[2] = {68, 99};

	peoples.push_back(a1);
	peoples.push_back(a2);
	peoples.push_back(a3);
	peoples.push_back(a4);
	peoples.push_back(a5);
	peoples.push_back(a6);

	for(size_t i = 0; i < peoples.size(); i++){
		cout << "( " << peoples[i][0] << ", " << peoples[i][1] <<" )" << endl;
	}


	vector<int *> tower;
	LIS(peoples, tower);
	cout << endl;
	for(size_t i = 0; i < tower.size(); i++){
		cout << "( " << tower[i][0] << ", " << tower[i][1] <<" )" << endl;
	}

	vector<int *> tower1(createtower(peoples));
	cout << endl;

	for(size_t i = 0; i < tower1.size(); i++){
		cout << "( " << tower1[i][0] << ", " << tower1[i][1] <<" )" << endl;
	}
}
