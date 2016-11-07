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
		void inorder();
		void preorder();
		void postorder();
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
                cout << "input an integer please:" << endl;
                cin >> member;
                tr.insert(member);
                break;
            case 2:
                cout << "insert integer to remove from tree:" << endl;
                cin >> member;
                //tr.remove(member)
                break;
            case 3:
                cout << "insert integer to find in tree:" << endl;
                cin >> member;
                //bool result = tr.find(member);
                //cout << "Search result is: " << result << endl;
                break;
            case 4:
                //tr.inorder();
                break;
            case 5:
                //tr.preorder();
                break;
            case 6:
                //tr.postorder();
                break;
            case 7:
                //int result = tr.getHeight();
                //cout << "the height of the tree is " << result << endl;
                break;
            case 0:
                
                break;
            default:
            
                cout << "invalid input please try again" << endl << endl;
        }
    
        
    }while(choice != 0);  
         
    //tr.insert(5);
	//cout << "Turn down for what!?" << endl;
	return 0;
	
}
