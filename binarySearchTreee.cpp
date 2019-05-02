#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

int height(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int treeSize(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + treeSize(root->left) + treeSize(root->right);
}

TreeNode* add(TreeNode* root, int data) {
	if (root == NULL) {
		TreeNode* res = new TreeNode(data);
		return res;
	}
	if (root->val > data) {
		root->left = add(root->left, data);
	}
	else {
		root->right = add(root->right, data);
	}
	return root;
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

TreeNode* search(TreeNode* root, int data) {
	if (root == NULL || root->val == data)
		return root;
	if (root->val > data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

TreeNode* minValueNode(TreeNode* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int data) {
	if (root == NULL) {
		return root;
	}
	if (root->val < data) {
		root->right = deleteNode(root->right, data);
	}
	else if (root->val > data) {
		root->left = deleteNode(root->left, data);
	}
	else { // root->val == data
		// case1: remove a leaf node (no children)
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
		// case2: remove a node with only left child
		else if (root->left != NULL && root->right == NULL) {
			TreeNode* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		// case 2: remove a node with only right child
		else if (root->right != NULL && root->left == NULL) {
			TreeNode* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		// case3: remove a node with 2 children
		else {
			// find inorder successor
			TreeNode* successor = minValueNode(root->right);
			root->val = successor->val;
			root->right = deleteNode(root->right, successor->val);
		}
	}
	return root;
}

TreeNode* inorderSuccessor(TreeNode* root, int data) {
	TreeNode* node = search(root, data);
	if (node == NULL) {
		return node;
	}
	// node has a right subtree
	if (node->right != NULL) {
		return minValueNode(node->right);
	}
	TreeNode* successor = NULL;
	while (root->val != data) {
		if (root->val < data) {
			root = root->right;
		}
		else if (root->val > data) {
			successor = root;
			root = root->left;
		}
		else {
			break;
		}
	}
	return successor;
}

int main() {
	TreeNode* root = new TreeNode(12);
	root = add(root, 5);
	root = add(root, 15);
	root = add(root, 3);
	root = add(root, 7);
	root = add(root, 1);
	root = add(root, 9);
	root = add(root, 13);
	root = add(root, 17);
	root = add(root, 14);
	root = add(root, 16);
	root = add(root, 20);

	cout << "Inorder traversal " << endl;
	inorder(root);
	cout << endl;

	int target = 21;
	if (search(root, target) != NULL)
		cout << "find the target " << target << endl;
	else 
		cout << "Cannot find " << target << endl;

	int k = 15;
	deleteNode(root, k);
	inorder(root);
	cout << endl;

	int data = 9;
	TreeNode* successor = inorderSuccessor(root, data);
	if (successor != NULL)
		cout << "Inorder successor of " << data << " is " 
			<< successor->val << endl;
	else 
		cout << "No inorder successor " << endl;
}
