#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
//(1)
void swapinplace(int &a, int &b){
	a = a - b;
	b = a + b;
	a = b - a;
}

//This method is much more cool!
void swapinplace2(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = b ^ a;
}

//(3)
int trailingzeros2(int n){
	int result = 0;
	for(int i = 5; n / i >= 1; i *= 5){
		result += (n / i);
	}
	return result;
}

//(4)
double findmax(double a, double b){
	return a / 2 + b / 2 + abs((int)(a - b)) / 2;
}

//another method can use the sign bit of any data type instead fo the abs function;
int sign(int a){
	return 1 - 2 * ((a >> 31) & 1);
}

int findmax2(int a, int b){
	int diff = sign(a - b) * (a - b);
	return a / 2.0 + b / 2.0 + diff / 2.0;
}
//(5)
void hits(string solution, string guess){
	int Rcount = 0, Ycount = 0, Bcount = 0, Gcount = 0, hitcount = 0;
	int gRcount = 0, gYcount = 0, gBcount = 0, gGcount = 0, psedohitcount = 0;
	for(int i = 0; i < 4; i++){
		if(solution[i] == guess[i])hitcount ++;
		switch (solution[i]){
		case 'R':
			Rcount ++;
			break;
		case 'Y':
			Ycount ++;
			break;
		case 'G':
			Gcount ++;
			break;
		case 'B':
			Bcount ++;
			break;
		default:
			break;
		}

		switch (guess[i]){
		case 'R':
			gRcount ++;
			break;
		case 'Y':
			gYcount ++;
			break;
		case 'G':
			gGcount ++;
			break;
		case 'B':
			gBcount ++;
			break;
		default:
			break;
		}
	}
	psedohitcount = min(Rcount, gRcount) + min(Ycount, gYcount)+ min(Gcount, gGcount) +min(Bcount, gBcount) - hitcount;
	cout << "hit: " << hitcount << endl;
	cout << "psedohit: " << psedohitcount << endl;
}


//(6)
void findmn(int *a, int n){
	vector<int> v (a, a + n);
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	while(v[i] == a[i] && i < n){
		++i;
	}
	if(i == n){
	cout << "null" << endl;
	return;
	}
	while(v[j] == a[j]){
		--j;
	}

	cout << "m: " << i << ", n: " << j << endl;
}

//thinking about the final property of the three part
// the last element of left part is smaller than the min of middle part, the first element of the right part is larger than the
// max of middle part.

void findmn2(int *a, int n){

	if(n < 2){
		cout << "null" << endl;
		return;
	}
	int i = 0, j = n - 1;
	int max = a[0], min = a[0];
	while(a[i] <= a[i + 1] && i < n){
		++i;
	}
	if(i == n){
		cout << "null" << endl;
		return;
	}
	while(a[j] >= a[j - 1]){
		--j;
	}
	min = max = a[i + 1];
	for(int m = i + 1; m < j; m++){
		if(max < a[m]){
			max = a[m];
		}
		if(min > a[m]){
			min = a[m];
		}
	}

	while(a[i] > min && i >= 0){
		if(max < a[i])max = a[i];
		--i;
	}
	++i;
	while(a[j] < max && j <= n){
		++j;
	}
	--j;
	cout << "m: " << i << ", n: " << j << endl;
}

string InttoStr(int i){
	switch(i){
	case 0:
		return "";
	case 1:
		return "One";
	case 2:
		return "Two";
	case 3:
		return "Three";
	case 4:
		return "Four";
	case 5:
		return "Five";
	case 6:
		return "Six";
	case 7:
		return "Seven";
	case 8:
		return "Eight";
	case 9:
		return "Nine";
	case 10:
		return "Ten";
	case 11:
		return "Eleven";
	case 12:
		return "Twelve";
	case 13:
		return "Thirteen";
	case 14:
		return "Fourteen";
	case 15:
		return "Fifteen";
	case 16:
		return "Sixteen";
	case 17:
		return "Seventeen";
	case 18:
		return "Eighteen";
	case 19:
		return "Nineteen";
	default:
		return "";
	}
}

string BasetoStr(int i){
	string result;
	int hundred = i / 100;
	int ten = (i % 100) / 10;
	result += (hundred > 0)? (InttoStr(hundred) + " Hundred ") : "";
	if(ten >= 2){
		switch(ten){
		case 2:
			result += "Twenty ";
			break;
		case 3:
			result += "Thirty ";
			break;
		case 4:
			result += "Forty ";
			break;
		case 5:
			result += "Fifty ";
			break;
		case 6:
			result += "Sixty ";
			break;
		case 7:
			result += "Seventy ";
			break;
		case 8:
			result += "Eighty ";
			break;
		case 9:
			result += "Ninety ";
			break;
		}
		result += InttoStr(i % 10);
	}
	else{
		result += (InttoStr(i % 100));
	}
	return result;
}

void printinteger(int i){
	if(i == 0){
		cout << "Zero" << endl;
		return;
	}
	int billion = i / 1000000000;
	int million = (i % 1000000000) / 1000000;
	int thousand = (i - (billion * 1000000000) - (million * 1000000)) / 1000;
	int base = i - (billion * 1000000000) - (million * 1000000) - (thousand * 1000);

	if(billion > 0){
		cout << BasetoStr(billion) << " Billion ";
	}
	if(million > 0){
		cout << BasetoStr(million) << " Million ";
	}
	if(thousand > 0){
		cout << BasetoStr(thousand) << " Thousand ";
	}
	cout << BasetoStr(base) << endl;

}

void largestsum(int a[], int n){
	int startpoint[n];
	int value[n];
	int maxindex = 0;
	for(int i = 0; i < n; ++i){
		startpoint[i] = i;
		value[i] = a[i];
	}
	for(int i = 1; i < n; ++i){
		if(value[i] + value[i - 1] > value[i]){
			startpoint[i] = startpoint[i - 1];
			value[i] += value[i - 1];
		}
		if(value[i] > value[maxindex])maxindex = i;
	}
	for(int i = startpoint[maxindex]; i <= maxindex; ++i)
		cout << a[i] <<" ";
	cout << endl;
}

int main(){
	int a[] = {2, -8, 3, -2, 4, 5, -100, -10};
	largestsum(a, 8);
}
