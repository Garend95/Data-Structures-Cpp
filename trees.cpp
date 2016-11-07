

#include <iostream>
using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
};

//problems with templates which is why they aren't included
class tree {
	private:	
		Node* root;
	
	public:
		void insert(int data);
		void insertHelper(Node* &subTree, Node* newNode);
		void remove(int data, Node* startingPoint = NULL); // we start with node pointer NULL because we'll have different situations for removing nodes from root or subtrees
		void inorder(Node* startingPoint);
		void preorder(Node* startingPoint);
		void postorder(Node* startingPoint);
		int getHeight();
		bool find(int data, Node* startingPoint); 
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
        {	
            subTree = newNode; 
            cout << "subtree was null" << endl;
        }	
        else if (subTree->left < subTree->right)
        {
            cout << "gone left";
            insertHelper(subTree->left, newNode);
        } 
        else  
        {
            insertHelper(subTree->right, newNode); //Are these conditions enough? what if the subtree's left and right are null
            
		}	
}

void tree::insert(int data){
	    cout << " this got reached" << endl;
	    Node* newNode = new Node;
	    newNode->data = data;
	    newNode->right = NULL;
	    newNode->left = NULL;
       
	    insertHelper(root, newNode);
}


/*void tree::remove(int data, Node* startingPoint){
    if(startingPoint == NULL) startingPoint = root;	
    
    if(startingPoint->data == data) startingPoint = NULL;
	/*if(startingPoint != Null)
	{
		if (startingPoint->data == data) ~startingPoint;
	}*/

//}

void tree::inorder(Node* startingPoint)
{
    if(startingPoint != NULL) {
        inorder(startingPoint->left);
        cout << startingPoint->data << " " << endl;
        inorder(startingPoint->right);
        
    }
}

void tree::preorder(Node* startingPoint)
{
    if(startingPoint != NULL) {
        cout << startingPoint->data << " " << endl;
        preorder(startingPoint->left);
        preorder(startingPoint->right);
        
    }
}

void tree::postorder(Node* startingPoint)
{
    if(startingPoint != NULL) {
        postorder(startingPoint->left);
        postorder(startingPoint->right);
        cout << startingPoint->data << " " << endl;
    }
}

/*bool tree::find(int data,Node* startingPoint)
{
    if(startingPoint != NULL && startingPoint->data == data) {
        
        return true;
    }
    else
    {
        find(int data, Node* startingPoint->left);
        find(int data, Node* startingPoint->right);
    }
}*/

int main(){
    
    tree tr;
    
    int choice;
    
    do{
        cout << "What do you want to do?" << endl
             << "1-insert 2-remove 3-find 4-inorder 5-preorder 6-postorder 7-get height" << endl << "0-exit: ";
        
        cin >> choice;
        
        int member;
        
        switch (choice) {
            case 1:
                cout << "input an integer please:";
                cin >> member;
                tr.insert(member); 
                break;
            case 2:
                cout << "insert integer to remove from tree:";
                cin >> member;
                //tr.remove(member)
                break;
            case 3:
                cout << "insert integer to find in tree:";
                cin >> member;
                bool result = tr.find(member);
                cout << "Search result is: " << result << endl;
                break;
            case 4:
                tr.inorder(tr.getRoot()); //not tested
                break;
            case 5:
                tr.preorder(tr.getRoot()tr.getRoot()); //not tested
                break;
            case 6:
                tr.postorder(tr.getRoot()); //not tested 
                break;
            case 7:
                //int result = tr.getHeight(); not available
                //cout << "the height of the tree is " << result << endl;
                break;
            case 0:
                
                break;
            default:
            
                cout << "invalid input please try again" << endl << endl; //input until quitting
        }
    
        
    }while(choice != 0);  
         
	return 0;
	
}


