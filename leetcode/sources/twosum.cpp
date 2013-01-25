#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val = x;
		next = NULL;
	}
};

vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> r;
    	map<int, int> save;
        for(int i = 0; i < numbers.size(); i++){
        	if(save.find(numbers[i]) != save.end()){
        		r.push_back(save.find(numbers[i]) -> second);
        		r.push_back(i + 1);
        	}
        	else {
        		save[target - numbers[i]] = i + 1;
        	}
        }
        return r;
}




int findposition(int a, int b[], int l, int r){
	if(r <= l) {
		if(b[l] > a)return l;
		if(b[l] <= a) return l + 1;
	}
	if(b[(r + l) / 2] <= a && b[(r + l) / 2 + 1] >= a)return (r + l) / 2 + 1;
	if(b[(r + l) / 2] > a) return findposition(a, b, l, (r + l) / 2 - 1);
	return findposition(a, b, (r + l) / 2 + 1, r);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

	if(m == 0 || n == 0){
		if(m == 0){
			if(n % 2 == 0)return (B[(n - 1) / 2] + B[(n - 1) / 2 + 1]) / 2.0;
			return B[(n - 1) / 2];
		}
		if(m % 2 == 0)return (A[(m - 1) / 2] + A[(m - 1) / 2 + 1]) / 2.0;
		return A[(m - 1) / 2];
	}

	int a1 = 0, b1 = 0, a2 = m - 1, b2 = n - 1, Am, Bm, min;
	while((a2 - a1) > 1 && (b2 - b1) > 1){
		Am = (a2 + a1) / 2;
		Bm = (b2 + b1) / 2;
		min = (a2 - a1) <= (b2 - b1) ? (a2 - a1) / 2 : (b2 - b1) / 2;
		if(A[Am] > B[Bm]){
			a2 -= min;
			b1 += min;
		}
		else if(A[Am] < B[Bm]){
			b2 -= min;
			a1 += min;
		}
		else if((a2 - a1) % 2 == 0 || (b2 - b1) % 2 == 0)
			return A[Am];
		else{
			a2 -= min;
			b1 += min;
		}
	}
    if((a2 - a1) == 0 && (b2 - b1) == 0){
    	return (A[a1] + B[b1]) / 2.0;
    }
    if((a2 - a1) > 1){
    	int *t, t1, t2;
    	t = A; A = B; B = t;
    	t1 = a1; a1 = b1; b1 = t1;
    	t2 = a2; a2 = b2; b2 = t2;
    }
	int final1, final2;
    if((a2 - a1) == 0){
    	int po = findposition(A[a1], B, b1, b2);
    	if((b2 - b1) % 2 == 0){
    		final1 = (b2 + b1) / 2;
    		final2 = (b2 + b1) / 2 + 1;
    		if(po < final1)return (B[final1 - 1] + B[final2 - 1]) / 2.0;
    		if(po == final1) return (A[a1] + B[final2 - 1]) / 2.0;
    		if(po < final2)return (B[final1] + B[final2 - 1]) / 2.0;
    		if(po == final2)return (B[final1] + A[a1]) / 2.0;
    		return (B[final1] + B[final2]) / 2.0;
    	}
    	final1 = (b2 + b1) / 2 + 1;
    	if(po < final1)return B[final1 - 1];
    	if(po == final1)return A[a1];
    	return B[final1];
    }

	int po1 = findposition(A[a1], B, b1, b2);
	int po2 = findposition(A[a2], B, b1, b2) + 1;

	if((b2 - b1) % 2 == 0){
		final1 = (b2 + b1 + 2) / 2;
		if(po2 < final1)return B[final1 - 2];
		if(po2 == final1)return A[a2];
		if(po1 < final1)return B[final1 - 1];
		if(po1 == final1)return A[a1];
		return B[final1];
	}
	final1 = (b2 + b1 + 2) / 2;
	final2 = (b2 + b1 + 2) / 2  + 1;
	if(po2 < final1)return (B[final1 - 2] + B[final2 - 2]) / 2.0;
	if(po2 == final1)return (A[a2] + B[final2 - 2]) / 2.0;
	if(po2 == final2 && po1 < po2 - 1)return (A[a2] + B[final1 - 1]) / 2.0;
	if(po2 == final2 && po1 == po2 - 1)return (A[a1] + A[a2]) / 2.0;
	if(po2 > final2 && po1 == final1)return (A[a1] + B[final2 - 1]) / 2.0;
	if(po1 == final2)return (A[a1] + B[final1]) / 2.0;
	if(po1 < final1 && po2 > final2)return (B[final1 - 1] + B[final2 - 1]) / 2.0;
	return (B[final1] + B[final2]) / 2.0;

}


int lengthOfLongestSubstring(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(s.length() < 2)return s.length();

    map<char, int> save;
    int maxlength = 1, start = 0;
    save[s[0]] = 0;

    for(int i = 1; i < s.length(); i ++){
        if(save.find(s[i]) == save.end()){
			if(i - start + 1 > maxlength)
            maxlength =  i - start + 1;
    	}
    	else {
    		if(start < (save.find(s[i]) -> second) + 1)
    			start = (save.find(s[i]) -> second) + 1;
    		if(i - max(save.find(s[i]) -> second + 1, start) + 1 > maxlength)
    			maxlength = i - max(save.find(s[i]) -> second + 1, start) + 1;
    	}
    	save[s[i]] = i;
    }
    return maxlength;
}



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int val, carryon = 0;
    ListNode *result = 0, *head = 0;
    while(l1 != NULL || l2 != NULL || carryon > 0){
        val = carryon;
        if(l1 != 0){
            val += l1 -> val;
            l1 = l1 -> next;
        }
        if(l2 != 0){
            val += l2 -> val;
            l2 = l2 -> next;
        }
        carryon = val / 10;
        if(head == 0) {
            head = new ListNode(val % 10);
            result = head;
        }
        else {
            ListNode *a = new ListNode(val % 10);
            result -> next = a;
            result = a;
        }
    }
    return head;
}


int main(int argc, char *argv[]){
	ListNode *a = new ListNode(5);
	ListNode *b = new ListNode(5);

	cout << addTwoNumbers(a, b)->val << endl;
}