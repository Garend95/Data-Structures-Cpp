#include <iostream> 
#include <cstdlib>

using namespace std;


struct Node{
	int data;
	Node* next;
};

Node* head;

void print(){
    Node* temp = head; 

    cout << "Current list is: " ;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
       
    }
    cout << endl;
}

void enqueue(int x){
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void dequeue(Node* head){
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        if(temp->next == NULL) temp = NULL;
    }
}

void pop(){
	Node* traverse = head; // for traversing to last node in order to remove it
	while(traverse->next->next != NULL){
		traverse = traverse->next;
	      }
        traverse->next = NULL;
}

void push(){

        cout << "please insert number to push: ";
	int x ; cin >> x;
	
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = x;
	temp->next = NULL;
	cout << "im ok";
	
	Node* traverse = head; //used for finding the last node to insert a new one
        while(traverse->next != NULL){
	    traverse = traverse->next;            
	    }
	traverse->next = temp;  
	print();  
}



int main(){
	head = NULL;
	cout << "Stack or queue?" << endl
	     << "1.Stack" << endl
	     << "2.Queue" << endl;

	int answer; cin >> answer;

	if(answer == 1){
		
		int choice;
		while(choice != 5){
			cout << "What would you like to do with the stack? " << endl
			<< "1.Push" << endl
			<< "2.Pop" << endl
			<< "3.Is_empty" << endl
			<< "4.Get_top" << endl
			<< "5.Exit " << endl;
			cin >> choice;
			
			switch (choice)
				{
				case 1:
					push();	
					break;
				case 2:
					pop();
					break;
				case 3:
					break;
				case 4:
					break;
				case 5: 
					break;		
				}
		}	
			

		
        }
	else{
	
		cout << "How many numbers?" << endl;
		int n , x ; cin >> n;
		
		int choice;
		while(choice != 5){
			cout << "What would you like to do with the stack? " << endl
		        << "1.Enqueue" << endl
			<< "2.Dequeue" << endl
			<< "3.Is_empty" << endl
			<< "4.Get_front" << endl
			<< "5.Exit " << endl;
		}
		
		for(int i = 0; i < n ; i++){
		    cout << "please insert term no." << i << ":" ;
		    cin >> x;
		    enqueue(x);
		    print();
		}	
	}

	
	return 0;
}


