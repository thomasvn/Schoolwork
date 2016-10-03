/*
 *  Thomas Nguyen + Paras Zaveri
 *  Tuesday 2:15
 *  Coen 70
*/



#include <cstdlib>
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cassert>
//#include <stdlib.h>

using namespace std;

class ExpTree {
private:
	struct Node {
		int value;
		char op;
		Node *left, *right;
	};
	
	stack <Node*> nodes;
	
	void remove(Node* node);
public:
	ExpTree();
	~ExpTree();
	void build(string expr);
	int evaluate(Node* source);
	void print_preorder(Node* node);
	void print_inorder(Node* node);
	void print_postorder(Node* node);

	Node* root;
};


ExpTree::ExpTree() {
	root = NULL;
}

ExpTree::~ExpTree() {
	remove(root);
	cout << "Everything has been removed" << endl;
}

void ExpTree::build (string expr) {
	istringstream stream(expr);
	string token;
	
	while (stream>>token) {
		if (token == "+" || token == "-" || token == "/" || token == "*") {
			Node* a;
			Node* b;
			Node* c = new Node;

			a = nodes.top();
			nodes.pop();
			b = nodes.top();
			nodes.pop();
			
			c-> op = token[0];
			c-> left = b;
			c-> right = a;
			
			nodes.push(c);
		
		}
		else {
			Node* d = new Node;
			d-> value = atoi(token.c_str());
			d-> left = NULL;
			d-> right = NULL;

			nodes.push(d);
		}
	}
	root = nodes.top();	
}

int ExpTree::evaluate (Node* source) {
	if ((source->left == NULL) && (source->right == NULL)) {
		return source->value;
	}

	int x = evaluate (source->left);
	int y = evaluate (source->right);

	if (source->op == '+') {
		return (x+y);	
	}
	else if (source->op == '-') {
		return (x-y);
	}
	else if (source->op == '/') {
		return (x/y);
	}
	else if (source->op == '*') {
		return (x*y);
	}

	return -1;
}


void ExpTree::print_preorder(Node* node) {
	if (node == NULL) {
		return;
	}

	if ((node->left == NULL) && (node->left == NULL)) {
		cout << node -> value << " ";
	}
	else {
		cout << node -> op << " ";
	}


	print_preorder(node->left);
		
	print_preorder(node->right);

}

void ExpTree::print_inorder(Node* node) {
	if (node == NULL) {
		return;
	}

	print_inorder(node->left);

	if ((node->left == NULL) && (node->left == NULL)) {
		cout << node -> value << " ";
	}
	else {
		cout << node -> op << " ";
	}

	print_inorder(node->right);
}

void ExpTree::print_postorder(Node* node) {
	if (node == NULL) {
		return;
	}

	print_postorder(node->left);

	print_postorder(node->right);

	if ((node->left == NULL) && (node->left == NULL)) {
		cout << node -> value << " ";
	}
	else {
		cout << node -> op << " ";
	}

}


void ExpTree::remove(Node* node) {
	if (node == NULL) {
		return;
	}

	remove(node->left);

	remove(node->right);

	nodes.pop();

}


int main() {
	ExpTree tree;
	string s = "5 3 + 2 5 * 9 3 / - +";
	int result;
		
	tree.build(s);
	tree.print_inorder(tree.root);
	cout << endl;
	tree.print_preorder(tree.root);
	cout << endl;
	tree.print_postorder(tree.root);
	
	cout << endl;
	cout << "The result is: ";
	result = tree.evaluate(tree.root);

	cout << result << endl;

	return 0;
}









