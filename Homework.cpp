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

void enqueue(){

	cout << "please insert number to enqueue: ";
	int x ; cin >> x;

	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = x;
	temp->next = head;
	head = temp;

	print();
}

bool Is_empty()
{
	Node* temp = head;
	return ( temp->next != NULL ? false : true);
}

int Get_top()
{
	Node* top = head;
	return top->data;
}

int Get_front()
{
	Node* front = head;
	while(front->next != NULL) front = front->next;
	return front->data;
}
void dequeue(){
    Node* temp = head;
    while(temp->next->next != NULL){//error when having only one element in list
        
		temp = temp->next;
	
    }
	temp->next = NULL;
	print();
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
	
	cout << "this code was reached"; // surprisingly won't print even though the problem lies on line where the traverse node is initaialized
 	
	Node* traverse = head; //used for finding the last node to insert a new one
    /*    while(traverse->next != NULL){
	    traverse = traverse->next;            
	    }
	traverse->next = temp; */ 
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
			<< "1.Push //segmentation issue" << endl
			<< "2.Pop // " << endl
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
					Is_empty();
					break;
				case 4:
					cout << "top is " << Get_top() << endl;
					break;
				case 5: 
					break;		
				}
		}	
			

		
        }
	else{

		int choice;
		while(choice != 5){
			cout << "What would you like to do with the queue? " << endl
		    << "1.Enqueue" << endl
			<< "2.Dequeue" << endl
			<< "3.Is_empty" << endl
			<< "4.Get_front" << endl
			<< "5.Exit " << endl;
			cin >> choice;
		
		switch (choice)
				{
				case 1:
					enqueue();	
					break;
				case 2:
					dequeue();
					break;
				case 3:
					cout << Is_empty() << endl;
					break;
				case 4:
					cout << "front is " << Get_front() << endl;
					break;
				case 5: 
					break;		
				}
		
		}
			
			
		
	}

	
	return 0;
}


