#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

class tree {
	private:	
		Node* root;
	
	public:
		void insert(int data);
		void insertFirst();
		void insertHelper(Node* &subTree, Node* newNode);
		void remove();
		bool isEmpty();
		int getHeight();
		int find(); 
		tree();
};

void tree::insertHelper(Node* &subTree, Node* newNode){
	if (subTree == NULL)
        	subTree = newNode;

        else if (subTree->left < subTree->right)
        {
                insertHelper(subTree->left, newNode);
        } 
        else 
        {
                insertHelper(subTree->right, newNode);
		}	
}

void tree::insert(int data){
	    Node* newNode = new Node;
	    newNode->data = data;
	    newNode->right = NULL;
	    newNode->left = NULL;

	    insertHelper(root, newNode);
}


void tree::remove(int data, Node* startingPoint = root){
	if(startingPoint != Null)
	{
		if (startingPoint->data)
	}

}

tree::tree()
{
	root = NULL;
}

int main(){
	cout << "Turn down for what!?" << endl;
	return 0;
	
}
