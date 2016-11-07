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
		void remove(int data, Node* startingPoint = NULL);
		bool isEmpty();
		int getHeight();
		int find(); 
		Node* getRoot()
		{
		    return root;
		}
		tree()
        {
        	root = NULL;
        }
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


/*void tree::remove(int data, Node* startingPoint = NULL){
    if(startingPoint == NULL) startingPoint = root;	
    
    if(startingPoint->data == data) startingPoint = NULL;
	/*if(startingPoint != Null)
	{
		if (startingPoint->data == data) ~startingPoint;
	}*/

//}



int main(){
    
    tree tr;
    
    int choice;
    
    do{
        cout << "What do you want to do?" << endl
             << "1-insert" << endl << "2-remove" << endl << "3-find" << endl
             << "4-inorder" << endl << "5-preorder" << endl << "6-postorder" << endl
             << "7-get height" << endl << "0-exit";
        
        cin >> choice;
        
        int member;
        
        switch (choice) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 0:
                
                break;    
        }
    
        
    }while(choice != 0)  
         
    //tr.insert(5);
	//cout << "Turn down for what!?" << endl;
	return 0;
	
}
