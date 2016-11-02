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
		void remove();
		bool isEmpty();
		int getHeight();
		int find(); 
};

void tree::insert(int data){
	
}

int main(){
	cout << "Turn down for what!?" << endl;
	return 0;
	
}
