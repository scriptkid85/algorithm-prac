#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val = x;
		next = NULL;
	}
};



//Two Sum
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




//Median of Two Sorted Arrays
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





//Longest Substring Without Repeating Characters
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




//Add Two Numbers
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
int computearea(int righttopi, int rightopj, int leftbottomi, int leftbottomj){
	return (righttopi + 1 - leftbottomi) * (leftbottomj + 1 - leftbottomi);
}





//Valid Palindrome
bool isPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<char> save;
    stack<char> test;
    int cnt = 0;
    int i = 0;
    while(i < s.length()){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            save.push(s[i]);
        }
        else if( s[i] >= 'A' && s[i] <= 'Z'){
            save.push(s[i] + 32);
        }
        i++;
    }
    cnt = save.size();

    int half = cnt/2;
    int odd = cnt%2;

    i = 1;
    while(i++ <= half){
        test.push(save.top());
        save.pop();
    }
    if(odd == 1){
        save.pop();
    }
    while(save.size() != 0){
        if(save.top() != test.top())
            return false;
        save.pop();
        test.pop();
    }
    return true;
 }





//(Binary Tree Maximum Path Sum)
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
int findmax(TreeNode *root, int &max){
    int a = root -> val;
    int b = root ->val;
    int temp;
    int tempmax = root->val;
    if(root -> left != NULL){
        temp = findmax(root -> left, max);
        tempmax += (temp > 0? temp:0);
        a += (temp > 0? temp:0);
    }
    if(root -> right != NULL){
        temp = findmax(root -> right, max);
        tempmax += (temp > 0? temp:0);
        b += (temp > 0? temp:0);
    }

    if(tempmax > max)max = tempmax;
    return a>=b?a:b;
}
int maxPathSum(TreeNode *root) {
    int max = INT_MIN;
    findmax(root, max);
    return max;
}





//Best Time to Buy and Sell Stock3 (Very GOOD DP PROBLEM)
int maxProfit3(vector<int> &prices) {
// Start typing your C/C++ solution below
// DO NOT write int main() function
    int size = prices.size();

    if(size < 2) return 0;
    int dp1[size], dp2[size];
	int minv = prices[0];
	dp1[0] = 0;
	for(int i = 1; i < size; i++){
		minv = min(minv, prices[i]);
		dp1[i] = max(prices[i] - minv, dp1[i - 1]);
	}

	dp2[size - 1] = 0;
	int maxv = prices[size - 1];
	for(int i = size - 2; i >=0; i--){
		maxv = max(prices[i], maxv);
		dp2[i] = max(dp2[i + 1], maxv - prices[i]);
	}

	maxv = 0;
	for(int i = 1; i < size; i++){
		maxv = max(maxv, dp1[i] + dp2[i]);
	}
	return maxv;
}






//Best Time to Buy and Sell Stock2
int maxProfit2(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(prices.size() ==0)return 0;
    int profit = 0;
    int current = prices[0];
    for(int i = 1; i< prices.size(); i++){
        if(prices[i] > current){
            profit += (prices[i] - current);
        }
        current  = prices[i];
    }
    return profit;
}






//Best Time to Buy and Sell Stock1
int maxProfit1(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int size = prices.size();

    if(size == 0)return 0;

    int dp[size];

    int minvalue = prices[0];
    int finalmax = 0;

    for(int i = 1; i < size; i++){
        minvalue = min(minvalue, prices[i]);
        finalmax = max(finalmax, prices[i] - minvalue);
    }
    return finalmax;

}






//Triangle
int minimumTotal(vector<vector<int> > &triangle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int size = triangle.size();
    if(size == 0)return 0;

    int *record = new int[size];
    int currentrow;
    record[0] = triangle[0][0];
    for(currentrow = 1; currentrow < size; currentrow++){
        int *temp = new int[size];
        temp[0] = record[0] + triangle[currentrow][0];
        for(int j = 1; j < currentrow; j++){
            temp[j] = min(record[j - 1], record[j]) + triangle[currentrow][j];
        }
        temp[currentrow] = record[currentrow - 1] + triangle[currentrow][currentrow];
        int *del = record;
        record = temp;
        delete del;
    }

    int min = record[0];
    for(int i = 1; i< size; i++){
        if(min > record[i]) min = record[i];
    }
    return min;
}






//Pascal's Triangle II
vector<int> getRow(int rowIndex) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int *row = new int[rowIndex + 1];
    row[0] = 1;
    for(int i = 1; i < rowIndex + 1; i++){
        int *temp = new int[rowIndex + 1];
        temp[0] = 1;
        for(int j = 1; j < i; j++){
            temp[j] = row[j - 1] + row[j];
        }
        temp[i] = 1;
        int *del = row;
        row = temp;
        delete del;
    }

    vector<int> a(row, row + rowIndex + 1);
    return a;
}






//Pascal's Triangle
vector<vector<int> > generate(int numRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    if(numRows == 0)return result;
    int *row = new int[1];
    row[0] = 1;
    vector<int> a(row, row + 1);
    result.push_back(a);
    for(int i = 1; i < numRows; i++){
        row = new int[i + 1];
        row[0] = 1;
        for(int j = 1; j < i; j++){
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        row[i] = 1;
        vector<int> a(row, row + i + 1);
        result.push_back(a);
    }
    return result;
}







//Populating Next Right Pointers in Each Node
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return;
    root -> next = NULL;
    while(root){
        TreeLinkNode *prev = NULL;
        TreeLinkNode *nextlayer = NULL;
        for(; root; root = root->next){
            if(!nextlayer)nextlayer = root->left? root->left : root->right;
            if(root->left){
                if(prev)prev->next = root->left;
                prev = root->left;
            }
            if(root->right){
                if(prev)prev->next = root->right;
                prev = root->right;
            }
        }
        root = nextlayer;
    }
}







//Flatten Binary Tree to Linked List
void flatten(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return;
    if(root -> left){
        flatten(root -> left);
    }
    if(root -> right){
        flatten(root -> right);
    }
    if(root -> left){
        TreeNode *start = root -> left;
        TreeNode *end;
        for(end = start; end -> right; end = end -> right);
        end -> right = root -> right;
        root -> right = start;
        root -> left = NULL;
    }
}
// a little faster version:
//return the tail of the right children chain!, so dont need the for(;;) part!
TreeNode *dflatten(TreeNode *root){
	if(!root)return NULL;
	TreeNode *leftchild = root -> left;
	TreeNode *rightchild = root -> right;

	TreeNode *lefttail, *righttail;
	lefttail = dflatten(leftchild);
	righttail = dflatten(rightchild);

	if(!lefttail)lefttail = root;
	if(!righttail)righttail = lefttail;
	root -> right = leftchild;
	lefttail -> right = rightchild;
	return righttail;
}
void flatten2(TreeNode *root){
	dflatten(root);
}






//Path Sum
bool testPathSum(TreeNode *root, int currentsum, int sum){
    if(!(root -> right) && !(root -> left)){
        if(sum == (root -> val + currentsum))return true;
        return false;
    }
    bool r1 = false, r2 = false;
    if(root -> left)
        r1 = testPathSum(root->left, root->val + currentsum, sum);
    if(root -> right)
        r2 = testPathSum(root->right, root->val + currentsum, sum);
    return r1 || r2;
}
bool hasPathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return false;
    int currentsum = 0;
    return testPathSum(root, currentsum, sum);
}





//Path SumII
void findpathSum(vector<vector<int> > &result, vector<int> path, TreeNode *root, int currentsum, int sum){
    if(!(root->left) && !(root->right)){
        if(currentsum + root->val == sum){
            path.push_back(root ->val);
            result.push_back(path);
        }
    }
    path.push_back(root->val);
    if(root -> left){
        findpathSum(result, path, root->left, currentsum + root->val, sum);
    }
    if(root -> right){
        findpathSum(result, path, root->right, currentsum + root->val, sum);
    }
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    vector<vector<int> > result;
    if(!root)return result;
    vector<int> path;
    int currentsum = 0;
    findpathSum(result, path, root, currentsum, sum);
    return result;
}




//Minimum Depth of Binary Tree
int minDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return 0;
    if(!(root->left) && !(root->right))return 1;
    int leftdepth = 100000;
    int rightdepth = 100000;
    if(root -> left){
        leftdepth = minDepth(root -> left) + 1;
    }
    if(root -> right){
        rightdepth = minDepth(root -> right) + 1;
    }
    return leftdepth < rightdepth? leftdepth : rightdepth;
}




//Balanced Binary Tree
int findDepthwithbalancetest(TreeNode *root){
    if(!root)return 0;

    int ld, rd;
    ld = findDepthwithbalancetest(root -> left);
    rd = findDepthwithbalancetest(root -> right);

    if(ld==-1 || rd == -1)return -1;
    if(abs(ld - rd) > 1)return -1;
    return (ld>rd?ld:rd) + 1;
}
bool isBalanced(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return true;
    int depth = findDepthwithbalancetest(root);
    if(depth ==-1)return false;
    return true;
}




//Convert Sorted List to Binary Search Tree
int findinList(ListNode *head, int i){
    while((--i) > 0){
        head = head->next;
    }
    return head->val;
}

void constructBST(ListNode *head, TreeNode* &root, int l, int r){
    if(l>=r){
        root->val = findinList(head, l);
        return;
    }
    int middle = (l + r + 1) / 2;
    root->val = findinList(head, middle);
    if(middle > l){
        TreeNode *newroot = new TreeNode(0);
        root -> left = newroot;
        constructBST(head, newroot, l, middle - 1);
    }
    if(middle < r){
        TreeNode *newroot = new TreeNode(0);
        root -> right = newroot;
        constructBST(head, newroot, middle + 1, r);
    }
}
TreeNode *sortedListToBST(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!head)return NULL;
    ListNode *current = head;
    int size = 0;
    while(current){
        size++;
        current = current -> next;
    }

    TreeNode *root = new TreeNode(0);
    constructBST(head, root, 1, size);
    return root;
}
// A much better (faster!) idea!!! The sorted order is actually the post-order trans.
//instead of creating the tree top-down, we can create the tree DOWN_TOP!!!
TreeNode *downupcreateBST(ListNode* &head, int l, int r){
    if(l>r)return NULL;

    int middle = (l + r) / 2;

    TreeNode *leftchild = downupcreateBST(head, l, middle - 1);
    TreeNode *parent = new TreeNode(head->val);
    parent->left = leftchild;

    head = head->next;
    parent->right = downupcreateBST(head, middle + 1, r);
    return parent;
}

TreeNode *sortedListToBST2(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *tmp = head;
    int size = 0;
    while(tmp){
        size++;
        tmp = tmp->next;
    }
    return downupcreateBST(head, 0, size - 1);
}



//Convert Sorted Array to Binary Search Tree
TreeNode *constructBSTfromArray(vector<int> &num, int l, int r){
    if(l > r)return NULL;
    int middle = (l + r) / 2;
    TreeNode *parent = new TreeNode(num[middle]);
    parent -> left = constructBSTfromArray(num, l, middle - 1);
    parent -> right = constructBSTfromArray(num, middle + 1, r);
    return parent;

}
TreeNode *sortedArrayToBST(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return constructBSTfromArray(num, 0, num.size() - 1);
}




//Binary Tree Level Order Traversal II
int findDepth(TreeNode *root){
    if(!root)return 0;
    int ldepth = 1 + findDepth(root -> left);
    int rdepth = 1 + findDepth(root -> right);
    return ldepth > rdepth? ldepth:rdepth;
}
void pushNode(TreeNode *root, vector<vector<int> > &result, int depth, int current){
    if(!root)return;
    pushNode(root->left, result, depth, current + 1);
    result[depth - current - 1].push_back(root -> val);
    pushNode(root->right, result, depth, current + 1);

}
vector<vector<int> > levelOrderBottom(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    int depth = findDepth(root);
    for(int i = 0; i < depth; i++){
        vector<int> depthvector;
        result.push_back(depthvector);
    }
    pushNode(root, result, depth, 0);
    return result;
}



//Construct Binary Tree from Inorder and Postorder Traversal
TreeNode *createBSTfromIP(map<int, int> &inposition, vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr){
    if(il > ir)return NULL;
    if(il == ir){
        TreeNode *root = new TreeNode(inorder[il]);
        return root;
    }

    int rootposition = inposition.find(postorder[pr]) -> second;
    TreeNode *root = new TreeNode(inorder[rootposition]);

    root -> left = createBSTfromIP(inposition, inorder, postorder, il, rootposition - 1, pl, pl + (rootposition - il) - 1);
    root -> right = createBSTfromIP(inposition, inorder, postorder, rootposition + 1, ir, pl + (rootposition - il), pr - 1);
    return root;

}

TreeNode *buildTreefromIP(vector<int> &inorder, vector<int> &postorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    map<int, int> inposition;
    int size = inorder.size();
    for(int i = 0; i < inorder.size(); i++){
        inposition[inorder[i]] = i;
    }
    return createBSTfromIP(inposition, inorder, postorder, 0, size - 1, 0, size -1);
}





//Construct Binary Tree from Preorder and Inorder Traversal
TreeNode *createBSTfromPI(map<int, int> &inposition, vector<int> &preorder, vector<int> &inorder, int prel, int prer, int il, int ir){
    if(il > ir)return NULL;
    if(il == ir){
        TreeNode *root = new TreeNode(inorder[il]);
        return root;
    }

    int rootposition = inposition.find(preorder[prel]) -> second;
    TreeNode *root = new TreeNode(inorder[rootposition]);

    root -> left = createBSTfromPI(inposition, preorder, inorder, prel + 1, prel + (rootposition - il), il, rootposition - 1);
    root -> right = createBSTfromPI(inposition, preorder, inorder, prel + (rootposition - il) + 1, prer, rootposition + 1, ir);
    return root;

}

TreeNode *buildTreefromPI(vector<int> &preorder, vector<int> &inorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    map<int, int> inposition;
    int size = inorder.size();
    for(int i = 0; i < inorder.size(); i++){
        inposition[inorder[i]] = i;
    }
    return createBSTfromPI(inposition, preorder, inorder, 0, size - 1, 0, size -1);
}




//Maximum Depth of Binary Tree
int maxDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!root)return 0;

    int ld = 1 + maxDepth(root -> left);
    int rd = 1 + maxDepth(root -> right);

    return ld>rd?ld:rd;
}





//Binary Tree Zigzag Level Order Traversal
void addLevel(TreeNode *root, vector<vector<int> > &result, int count){
    if(!root)return;
    if(result.size() <= count){
        vector<int> tempvec;
        tempvec.push_back(root -> val);
        result.push_back(tempvec);
    }
    else{
        result[count].push_back(root -> val);
    }
    addLevel(root -> left, result, count + 1);
    addLevel(root -> right, result, count + 1);
}
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
     vector<vector<int> > result;
     addLevel(root, result, 0);
     for(int i = 0; i < result.size(); i ++){
         if(i % 2 == 0)continue;
         for(int g = 0, h = result[i].size() - 1; g < h; g++, h--){
             int temp = result[i][g];
             result[i][g] = result[i][h];
             result[i][h] = temp;
         }
     }
     return result;
}





//Binary Tree Level Order Traversal
    void addLayer(TreeNode *root, vector<vector<int> > &result, int count){
        if(!root)return;
        if(result.size() <= count){
            vector<int> newlayer;
            newlayer.push_back(root -> val);
            result.push_back(newlayer);
        }
        else{
            result[count].push_back(root -> val);
        }
        addLayer(root->left, result, count + 1);
        addLayer(root -> right, result, count + 1);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        addLayer(root, result, 0);
        return result;
    }






//Symmetric Tree
    bool myCheckSymmetric(TreeNode *leftroot, TreeNode *rightroot){
        if((!leftroot) || (!rightroot)){
            if((!leftroot) && (!rightroot))return true;
            return false;
        }
        return (leftroot->val == rightroot->val) && myCheckSymmetric(leftroot->left, rightroot->right) &&  myCheckSymmetric(leftroot->right, rightroot->left);
    }


    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return myCheckSymmetric(root, root);
    }







//Same Tree
    bool myCheckSameTree(TreeNode *p, TreeNode *q){
        if((!p) || (!q)){
            if((!p) && (!q))return true;
            return false;
        }

        return (p->val == q->val) && myCheckSameTree(p->left, q->left) && myCheckSameTree(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return myCheckSameTree(p, q);
    }





//Recover Binary Search Tree
//O(n) space, not good, but easy to
void inOrderTraverse(TreeNode* &root, vector<TreeNode *> &inorder, vector<int> &inorderval){
    if(!root)return;
    inOrderTraverse(root -> left, inorder, inorderval);
    inorder.push_back(root);
    inorderval.push_back(root->val);
    inOrderTraverse(root -> right, inorder, inorderval);
}

void recoverTree(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<TreeNode *> inorder;
    vector<int> inorderval;
    inOrderTraverse(root, inorder, inorderval);
    sort(inorderval.begin(), inorderval.end());

    for(int i = 0; i < inorderval.size(); i++){
        inorder[i]->val = inorderval[i];
    }
}

//O(1) space!






//Validate Binary Search Tree
bool compareInorder(TreeNode* root, int &pre){
    if(!root){
        return true;
    }
    bool leftcheck = compareInorder(root->left, pre);
    if(pre == -100000){
        pre = root -> val;
        //NOTE HERE： easy to forget about this check!!!
        return compareInorder(root->right, pre);
    }
    bool middlecheck = (root -> val > pre);
    pre = root -> val;
    bool rightcheck = compareInorder(root->right, pre);
    return leftcheck && middlecheck && rightcheck;
}
bool isValidBST(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int pre = -100000;
    return compareInorder(root, pre);
}





//Interleaving String
bool isInterleave(string s1, string s2, string s3) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int size1 = s1.length();
	int size2 = s2.length();
	int size3 = s3.length();
	if(size1 + size2 != size3) return false;
	vector<vector<bool> > dp2d(size1 + 1, vector<bool>(size2 + 1));
	dp2d[0][0] = true;

	for(int i = 1; i < size1 + 1; i++){
		if(dp2d[i - 1][0] && (s1[i - 1] == s3[i - 1])){
			dp2d[i][0] = true;
		}
		else dp2d[i][0] = false;
	}

	for(int i = 1; i < size2 + 1; i++){
		if(dp2d[0][i - 1] && (s2[i - 1] == s3[i - 1])){
			dp2d[0][i] = true;
		}
		else dp2d[0][i] = false;
	}

	for(int i = 1; i < size1 + 1; i++){
		for(int j = 1; j < size2 + 1; j++){
			if((dp2d[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || ((dp2d[i][j - 1] && (s2[j - 1] == s3[i + j - 1]))))
				dp2d[i][j] = true;
			else dp2d[i][j] = false;
		}
	}
	return dp2d[size1][size2];
}




//Unique Binary Search Trees
// all recursive method can be considered for DP(if extra space is allowed), much faster!!
    int record[1000] = {0};
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)return 1;
        if(n == 1)return 1;
        if(record[n])return record[n];
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += numTrees(i - 1)*numTrees(n - i);
        }
        record[n] = sum;
        return sum;
    }





//Unique Binary Search Trees II
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> ret;
        DFSgenTrees(ret, 1, n);
        return ret;
    }
    void DFSgenTrees(vector<TreeNode *> &ret, int l, int r){
        if(l > r)
            ret.push_back(NULL); // very important, cannot forget!!, since the left and right child can be NULL
        for(int i = l; i <= r; i++){
            vector<TreeNode *> leftsubtrees;
            vector<TreeNode *> rightsubtrees;
            DFSgenTrees(leftsubtrees, l, i - 1);
            DFSgenTrees(rightsubtrees, i + 1, r);

            for(int x = 0; x < leftsubtrees.size(); x++){
                for(int y = 0; y < rightsubtrees.size(); y++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftsubtrees[x];
                    root->right = rightsubtrees[y];
                    ret.push_back(root);
                }
            }
        }
    }




//Binary Tree Inorder Traversal
    void saveinorderTraversal(vector<int> &ret, TreeNode *root){
        if(!root)return;
        saveinorderTraversal(ret, root->left);
        ret.push_back(root->val);
        saveinorderTraversal(ret, root->right);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        saveinorderTraversal(ret, root);
        return ret;
    }





//Restore IP Addresses
    bool checkvalidip(string ip){ //consider carefully about valid ip!
        int i = 0;
        if(ip.length() == 1)return true;
        while(ip[i] == '0'&& ip[i] != '\0')i++;
        if(i > 0)return false;
        if(atoi(ip.c_str()) > 255)return false;
        return true;
    }
    void restoreIp(vector<string> &ret, string s, string ip, int count){
        if(count == 5){
            if(s.length() == 0){
                ip = ip.substr(0, ip.length() - 1);
                ret.push_back(ip);
            }
            return;
        }
        if(s.length() == 0)return;
        for(int i = 1; i <= min(3, (int)s.length()); i++){
            string tempip = ip;
            string temp = s;
            string substring = temp.substr(0, i);
            if(!checkvalidip(substring))continue;
            tempip = tempip + substring + ".";
            temp = temp.substr(i, temp.length() - i);
            restoreIp(ret, temp, tempip, count + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        string ip = "";
        restoreIp(ret, s, ip, 1);
        return ret;
    }





//Reverse Linked List II    (how to make it more clean and easy to understand!!)
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(m == n)return head;
        ListNode *fakenode = new ListNode(0);
        fakenode->next = head;

        ListNode *pre = fakenode, *cur = head, *nex = head -> next, *temp;
        int count = 1;
        while(1){
            if(count >= m && count < n){
                temp = nex -> next;
                nex->next = cur;
                cur = nex;
                nex = temp;
            }
            else if(count < m){
                pre = cur;
                cur = cur -> next;
                nex = cur -> next;
            }
            else if(count >= n){
                break;
            }
            count++;
        }
        pre->next->next = nex;
        pre->next = cur;
        return fakenode->next;
    }






//Sqrt(x)
//Newton Method! f(x) = x^2 - c, c is the input number. Find x such that f(x) = 0
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double y, z(1.0);
        while(int(y) - int(z)){
            y = z;
            z = x / 2.0 / y + y / 2;
        }
        return int(y);
    }



    //Longest Palindromic Substring
        string preProcess(string s){
            if(s.length() == 0)return "^&";
            string ret = "^";
            for(int i = 0; i < s.length(); i++){
                ret += ("#" + s.substr(i, 1));
            }
            ret += "#&";
            return ret;
        }

        string longestPalindrome(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string T = preProcess(s);
            int length = T.length();
            int *p = new int[length];
            int center = 0, edge = 0;
            int maxlength = 0;
            int maxcenter = 0;

            for(int i = 1; i < length - 1; i ++){
                int mirror = 2 * center - i;
                if(edge > i)p[i] = min(edge - i, p[mirror]);
                else p[i] = 0;
                while(T[i - 1 - p[i]] == T[i + 1 + p[i]])p[i] ++;

                if(i + p[i] > edge){
                    center = i;
                    edge = i + p[i];
                }

                if(p[i] > maxlength){
                    maxlength = p[i];
                    maxcenter = i;
                }

            }

            delete[] p;
            return s.substr((maxcenter - 1 - maxlength) / 2, maxlength);
        }



    //ZigZag Conversion
        string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(nRows == 1)return s;
            int i = 0;
            string ret = "";
            while(i < s.length()){
                ret += s.substr(i, 1);
                i += 2 * nRows - 2;
            }

            for(int j = 1; j < nRows - 1; j ++){
                i = j;
                while(i < s.length()){
                    ret += s.substr(i, 1);
                    i += 2 * nRows - 2 * (j + 1);
                    if(i >= s.length())break;
                    ret += s.substr(i, 1);
                    i += 2 * j;
                }
            }

            if(nRows < 2)return ret;
            i = nRows - 1;
            while(i < s.length()){
                ret += s.substr(i, 1);
                i += 2 * nRows - 2;
            }
            return ret;
        }



    //Reverse Integer (consider some other problems: overflow; 10000 -> 1)
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int digit = 0;
            int ret = 0;

            int zx = abs(x);
            while(zx >= 10){
                digit = zx % 10;
                zx /= 10;
                ret = ret*10 + digit;
            }
            ret = ret*10 + zx;
            return (x >= 0) ? ret : -1 * ret;
        }


    //String to Integer (atoi)   (take care of the overflow!!)
        int atoi(const char *str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(str == NULL || strlen(str) == 0)return 0;
            int i = 0;
            while(str[i] == ' '){
                i ++;
            }
            int sign = 1;
            if(str[i] == '-'){
                sign = 0;
                i ++;
            }
            else if(str[i] == '+'){
                sign = 1;
                i ++;
            }

            if(str[i] < '0' || str[i] > '9')return 0;

            int ret = 0;
            while(str[i] >= '0' && str[i] <= '9' && i < strlen(str)){
                if(sign == 1){
                    if(ret > 214748364 || (ret == 214748364 && (str[i] - '0') > 7)){
                        return 2147483647;
                    }
                }
                else if(sign == 0){
                    if(ret > 214748364 || (ret == 214748364 && (str[i] - '0') > 8)){
                        return -2147483648;
                    }
                }
                ret = ret * 10 + (str[i] - '0');
                i ++;
            }

            return sign > 0 ? ret: -1 * ret;
        }


    //Palindrome Number
        bool isPalindrome(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(x < 0)return false;
            int div = 1;
            while(x / div >= 10){
                div *= 10;
            }

            int l = 0, r = 0;
            while(x != 0){
                l = x / div;
                r = x % 10;
                if(l != r)return false;

                x = x % div;
                x = x / 10;
                div /= 100;
            }
            return true;
        }



    //Regular Expression Matching (clean code!!!)
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(*p == 0)return *s == 0;

            if(*(p + 1) != '*'){
                return((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
            }

            else{
                while((*p == *s) || (*p == '.' && *s != 0)){
                    if(isMatch(s, p + 2))return true;
                    s ++;
                }
            }
            return isMatch(s, p + 2);
        }


    //Integer to Roman (very good! greedy)
        int maxArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int start = 0, end = height.size() - 1;

            int area, ret = 0;
            while(start < end){
                area = min(height[start], height[end]) * (end - start);
                ret = area > ret? area: ret;
                if(height[start] < height[end]){
                    start ++;
                }
                else end --;
            }
            return ret;
        }



    //Longest Common Prefix
        string longestCommonPrefix(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int size = strs.size();

            if(size == 0)return "";
            if(size == 1)return strs[0];

            int j = 0;
            while(j < strs[0].size()){
                bool flag = false;
                for(int i = 1; i < size; i ++){
                    if(j >= strs[i].size() || strs[0][j] != strs[i][j]){
                        flag = true;
                        break;
                    }
                }
                if(flag)break;
                j++;
            }
            return strs[0].substr(0, j);
        }



int main(int argc, char *argv[]){

}
