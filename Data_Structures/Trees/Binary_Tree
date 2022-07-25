#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int data)
	{
		val = data;
		left = right = NULL;
	}
};

Node *createNode(int value) {
	Node *newnode = new Node(value);
	return newnode;
}

void preorder_traversal(Node *root) {
	if (root == NULL) return;

	cout << root->val << " ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(Node *root) {
	if (root == NULL) return;

	inorder_traversal(root->left);
	cout << root->val << " ";
	inorder_traversal(root->right);
}

void postorder_traversal(Node *root) {
	if (root == NULL) return;

	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout << root->val << " ";
}

vector<vector<int>> BFS(Node *root) {
	vector<vector<int>> arr;
	if (root == NULL) return arr;
	queue<Node *> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		vector<int> level;
		for (int i = 0; i < size; i++) {
			int data = q.front()->val;
			level.push_back(data);
			if (q.front()->left != NULL) q.push(q.front()->left);
			if (q.front()->right != NULL) q.push(q.front()->right);
			q.pop();
		}
		arr.push_back(level);
	}
	return arr;
}

void iterative_preorder(Node *root) {
	if (root == NULL) return;
	stack<Node*> st;
	st.push(root);
	while (!st.empty()) {
		Node *current_node = st.top();
		st.pop();
		cout << current_node->val << " ";
		if (current_node->right != NULL) st.push(current_node->right);
		if (current_node->left != NULL) st.push(current_node->left);
	}
}

void iterative_inorder(Node *root) {
	if (root == NULL) return;
	stack<Node*> st;
	Node *current = root;
	while (true) {
		if (current != NULL) {
			st.push(current);
			current = current->left;
		} else {
			if (st.empty()) break;
			cout << st.top()->val << " ";
			current = st.top()->right;
			st.pop();
		}
	}
}

void iterative_postorder_1(Node *root) {
	if (root == NULL) return;
	stack<Node*> st1, st2;
	st1.push(root);
	while (!st1.empty()) {
		Node *current_node = st1.top();
		st1.pop();
		st2.push(current_node);
		if (current_node->left != NULL) st1.push(current_node->left);
		if (current_node->right != NULL) st1.push(current_node->right);
	}
	while (!st2.empty()) {
		cout << st2.top()->val << " ";
		st2.pop();
	}
}

void iterative_postorder_2(Node *root) {
	if (root == NULL) return;
	stack<Node*> st;
	Node *current = root;
	while (current != NULL or !st.empty()) {
		if (current != NULL) {
			st.push(current);
			current = current->left;
		} else {
			Node *temp = st.top()->right;
			if (temp) {
				current = temp;
			} else {
				temp = st.top();
				st.pop();
				cout << temp->val << " ";
				while (!st.empty() and temp == st.top()->right) {
					temp = st.top();
					st.pop();
					cout << temp->val << " ";
				}
			}
		}
	}
}

vector<vector<int>> preorder_inorder_postorder_in_one_traversal(Node *root) {
	/*
	    if(num in stack is == 1)
	        its preorder
	        increment num
	        push if left exist
        else if(num in stack is == 2)
            its inorder
            increment num
            push if right exist
        else if(num in stack is == 2)
            its postorder
            pop out from stack
	*/
	vector<vector<int>> a(3);
	if (root == NULL) return a;
	stack<pair<Node*, int>> st;
	st.push({root, 1});
	while (!st.empty()) {
		pair<Node*, int> p = st.top();
		st.pop();
		if (p.second == 1) {
			a[0].push_back(p.first->val);
			p.second++;
			st.push(p);
			if (p.first->left != NULL) st.push({p.first->left, 1});
		} else if (p.second == 2) {
			a[1].push_back(p.first->val);
			p.second++;
			st.push(p);
			if (p.first->right != NULL) st.push({p.first->right, 1});
		} else {
			a[2].push_back(p.first->val);
		}
	}
	return a;
}

int main()
{
	// Level 1
	Node *root = createNode(1);
	// Level 2
	root->left = createNode(2);
	root->right = createNode(3);
	// Level 3
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	// Level 4
	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);

	preorder_traversal(root);
	cout << '\n';
	inorder_traversal(root);
	cout << '\n';
	postorder_traversal(root);
	cout << '\n';

	vector<vector<int>> ans = BFS(root);
	for (auto it1 : ans) {
		for (auto it2 : it1) {
			cout << it2 << " ";
		}
		cout << '\n';
	}

	iterative_preorder(root);
	cout << '\n';
	iterative_inorder(root);
	cout << '\n';
	iterative_postorder_1(root);
	cout << '\n';
	iterative_postorder_2(root);
    cout << '\n';
    
	vector<vector<int>> a = preorder_inorder_postorder_in_one_traversal(root);
	for(auto it1 : a){
		for(auto it2 : it1){
            cout << it2 << " ";
		}
		cout << '\n';
	}
}
