#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct treenode{
	int item;
	treenode *left;
	treenode *right;
	treenode(int x, treenode *l, treenode *r){
		item = x;
		left = l;
		right = r;
	}
};

typedef treenode *treelink;

void printnode(int x, int h){
	for(int i = 0; i < h; i++)cout<< "     ";
	cout << x << endl;
}

void printtree(treelink root, int h){
	if(root == 0){
		printnode(0, h);
		return;
	}
	printtree(root -> left, h + 1);
	printnode(root -> item, h);
	printtree(root -> right, h + 1);
}


//(1)
int checkbinary(treelink root){
	int h1 = 0, h2 = 0, height;
	if(root -> left != 0)
		h1 = checkbinary(root -> left);
	if(root -> right != 0)
		h2 = checkbinary(root -> right);

	if(h1 == -1 || h2 == -1 || abs(h1 - h2) > 1)return -1;
	else height = (h1 >= h2 ? h1 : h2) + 1;
	return height;

}


//(3)
void createBT(int a[], int l, int r, treelink root){
	if(r <= l){
	    root -> item = a[l];
		treelink t = new treenode(0, 0, 0);
		root -> left = t;
		t = new treenode(0, 0, 0);
		root -> right = t;
		return;
	}
	if(r - l == 1){
	    root -> item = a[l];
		treelink t = new treenode(a[r], 0, 0);
		root -> right = t;
		return;
	}
	int m = (r + l)/2;
	root -> item = a[m];
	treelink t = new treenode(0, 0, 0);
	root -> left = t;
	t = new treenode(0, 0, 0);
	root -> right = t;

	if(m - 1 - l >= 0)
		createBT(a, l, m - 1, root -> left);
	if(r - m - 1 >= 0)
		createBT(a, m + 1, r, root -> right);
}

//(5)
struct tresult{
	int min, max, trueflag;
	tresult(int a, int b, int t){
		min = a;
		max = b;
		trueflag = t;
	}
};

typedef tresult *trt;

trt isBST(treelink root){
	trt r = new tresult(0, 0, 1);
	trt lr, rr;
	r -> min = root -> item;
	r -> max = root -> item;
	if(root -> left != 0){
		lr = isBST(root -> left);
		if(lr -> trueflag == 0 || lr -> max > r -> min){
			r -> trueflag = 0;
			return r;
		}
		r -> min = lr -> min;
	}
	if(root -> right != 0){
		rr = isBST(root -> right);
		if(rr -> trueflag == 0 || rr -> min < r -> max){
			r -> trueflag = 0;
			return r;
		}
		r -> max = rr -> max;
	}
	return r;
}

//another method, use the in-order traverse to find the first element, and compare the second with the first one,
//should be larger or equal, then repeat

int testa[100], i;

void readBST(treelink root){
	if(root -> left != 0)readBST(root -> left);
	testa[i++] = root -> item;
	if(root -> right != 0)readBST(root -> right);
}

int isBST2(treelink root){
	i = 0;
	readBST(root);
	if(i <= 1) return 1;
	for(int j = 1; j < i; j++){
		if(testa[j] < testa[j - 1]){
			return 0;
		}
	}
	return 1;
}

//(6)
/*
treelink inordernext(treelink target){
	if(target -> right != 0)return the leafmost children of target -> right;
	while(target != target -> parent -> left && target -> parent != 0){
		target = target -> parent;
	}
	if(target -> parent == 0)return 0;
	else return target -> parent;
}
*/

//(7)

int cover(treelink root, treelink a){
	int l = 0, r = 0;
	if(root == a)return 1;
	if(root -> left != 0)l = cover(root -> left, a);
	if(root -> right != 0)r = cover(root -> right, a);
	if(l == 1 || r == 1)return 1;
	return 0;
}

treelink commonancestor(treelink root, treelink a, treelink b){
	int r1 = cover(root, a) + cover(root, b);
	int r2 = cover(root, a) * cover(root, b);
	treelink r;
	if(r1 == 1 && r2 == 0)return root;
	if(root -> left != 0){
		r = commonancestor(root -> left, a, b);
		if(r != 0)return r;
	}
	if(root -> right != 0){
		r = commonancestor(root -> right, a, b);
		if(r != 0)return r;
	}
	return 0;
}

void findpath(treelink root, int value){

}

int main(int argc, char *argv[]){

	treelink root = new treenode(10, 0, 0);
	treelink t1 = new treenode(5, 0, 0);
	treelink t2 = new treenode(16, 0, 0);
	treelink t3 = new treenode(2, 0, 0);
	treelink t4 = new treenode(30, 0, 0);
	treelink t5 = new treenode(6, 0, 0);
	treelink t6 = new treenode(7, 0, 0);
	treelink t7 = new treenode(8, 0, 0);
	treelink t8 = new treenode(9, 0, 0);
	treelink t9 = new treenode(10, 0, 0);
	treelink t10 = new treenode(11, 0, 0);
	treelink t11 = new treenode(12, 0, 0);
	treelink t12 = new treenode(13, 0, 0);
	treelink t13 = new treenode(14, 0, 0);
	treelink t14 = new treenode(15, 0, 0);

	root -> left = t1;
	root -> right = t2;
	t1 -> left = t3;
	t1 -> right = t4;
//	t2 -> left = t5;
//	t2 -> right = t6;
//	t3 -> left = t7;
//	t3 -> right = t8;
//	t4 -> left = t9;
//	t4 -> right = t10;
//	t5 -> left = t11;
//	t5 -> right = t12;
//	t6 -> left = t13;
//	t6 -> right = t14;


	printtree(root, 0);
	cout << endl;
	cout << isBST(root)->trueflag << endl;
	cout << endl;
	cout << isBST2(root) << endl;

	int a[10];
	for(int i = 0; i < 10; i ++){
		a[i] = i;
	}

	treelink root2 = new treenode(0, 0, 0);
	createBT(a, 0, 9, root2);
	printtree(root2, 0);
	cout << endl;
	cout << isBST(root2)->trueflag << endl;



	cout << endl;
	cout << isBST2(root2) << endl;

	for(int j = 0; j < i; j++)
		cout << testa[j] << " ";
	cout << endl;

//	cout << checkbinary(root) << endl;
}
