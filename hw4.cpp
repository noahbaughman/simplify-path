
/**
 * CISC 2200: Data Structures
 * HW4: Questions 1-5
 *
 * This program has functions for question 1-5 of hw4 and implements each one in the main function. 
 *
 * @author Noah Baughman
 * @date 11/26/18
 * @file hw4.cpp
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include<stack>

using namespace std;

/**
 *	This struct defines a TreeNode that is used in a binary tree
*/
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->data = data;
		left = right = NULL;
	}
};


/**
 *	This function recursively calculates all the ways you can climb the 
 *	amount of stairs n, if you can climb one or two stairs per step.
 *
 *	@param int n, the number of stairs to climb
 *	@return the number of ways to climb stairs
*/
vector<int> sumOfLevels(TreeNode* root){
    vector<int> sum;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int temp=0;
        int s=q.size();
        for(int i=0;i<s;i++) {
            TreeNode* t=q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            temp += t->data;
        }
        sum.push_back(temp);
    }
    return sum;
}


/**
 *	This function prints out thee in ordeer traversal of a bunary tree using stack
 *
 *	@param TreeNode root, the root node of given binary tree
*/
void inOrder(TreeNode *root) { 
    stack<TreeNode*> s; 
    TreeNode *curr = root; 
  
    while (curr != NULL || s.empty() == false) { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        curr = curr->right; 
  
    }
} 


/**
 *	This function recursively calculates the sum of each the binary tree paths where each 
 * path represent a number. 
 *
 *	@param TreeNode root, current node to make the tree path integer
 *  @param int val, the value of the sum
 *	@return the final sum
*/
int treePathsSumUtil(TreeNode *root, int val) { 
    if (root == NULL)  
    	return 0; 
    val = (val*10 + root->data); 
    if (root->left==NULL && root->right==NULL) 
       return val; 
    return treePathsSumUtil(root->left, val) + 
           treePathsSumUtil(root->right, val); 
} 
  
/**
 *	This function is the initial caller to caluclate the tree path sums. 
 *
 *	@param TreeNode root, the root node of a binary tree
 *	@return the treePathUntil function that actually calculates the sum.
*/
int treePathsSum(TreeNode *root) 
{ 
    return treePathsSumUtil(root, 0); 
} 

/**
 *	This function converts a sorted array into a balanced binary search tree.
 *
 *	@param int arr[], a sorted array of integers
 *  @param int first, the first index of 
 *  @param int last, the last index of array
 *	@return the TreeNode binary search tree
*/
TreeNode* sortedArrayToBT(int arr[], int first, int last) 
{ 
	TreeNode* root = NULL;
    if (first <= last) {
    	int mid = first + (last - first) / 2;
    	root = new TreeNode(arr[mid]); 
    	root->left = sortedArrayToBT(arr, first, mid-1); 
    	root->right = sortedArrayToBT(arr, mid+1, last); 
	}
    return root; 
} 

/**
 *	This function finds and returns the kth smallest element in a binary search tree
 *
 *	@param TreeNode root, the root of the binary search tree
 *  @param int k, the kth smallest integer to be found
 *	@return the value of kth smallest element
*/
int kthSmallest(TreeNode* root, int k) {       
    TreeNode* curr = root;
    stack<TreeNode*> s;
    while(!s.empty() || curr != NULL)
    {
        if(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            k--;
            if(k == 0)
                return curr->data;
            curr = curr->right;    
        }     
    }
    return 0;
}

int main() {
	//implementation of sumOfLevels function
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	
	vector<int> v = sumOfLevels(root);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	//implementation of inOrder function
	inOrder(root);
	cout << endl;

	//impleementation of treePathSum function
	TreeNode* root1 = new TreeNode(2);
	root1->left = new TreeNode(3);
	root1->right = new TreeNode(4);

	int sum = treePathsSum(root1);
	cout << sum << endl;

	//implementation of sortedArraytoBT function
	int arr[] = {2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	TreeNode* root2 = sortedArrayToBT(arr, 0, size-1);
	inOrder(root2);
	cout << endl;

	//implementation of kthSmallest function.
	TreeNode* root3 = new TreeNode(4);
	root3->left = new TreeNode(3);
	root3->right = new TreeNode(6);
	root3->left->left = new TreeNode(2);


	int i = kthSmallest(root3, 2);
	cout << i << endl;

}