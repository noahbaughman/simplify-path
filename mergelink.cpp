#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node{
	int item;
	Node *next;
};

void mergeSort(Node *&head);
// sorts the link list pointed to by head 
// precondition: head points to a linked list of items
// postcondition: head points to a sorted linked list, containing the items
// that were in the original linked list, but in sorted order

Node* merge(Node *&head1,Node *&head2);
// returns a pointer to a sorted linked list that results from merging the sorted 
// linked lists pointed to by head1 and head2
// preconditions: head1 and head2 point to sorted linked lists
// postconditions: returns a pointer to a sorted linked list containing the nodes
// that used to be in the sorted linked lists pointed to by head1 and head2; 
// head1 and head2 are NULL

int getLength(Node *head);
//return a length of a linked list pointed to by head
//precondition: head point to a linked list
//postcondition: none
void printLinkedList(Node *head);
//cout each element in linked list pointed to by head
//precondition: head point to a linked list
//postcondition: none
void receiveLinkedList(Node *&head);
//receive the input from user using stringstream, and store each element into a node
//each node is linked together become a linked list with head point to the first node, and the last node's next point to NULL
//precondition: need a Node pointer to pass in the function
//postcondition: a Node pointer point to the first Node of the linked list
int main(){
	Node* headNode = NULL;

	receiveLinkedList(headNode);
	mergeSort(headNode);
	cout<<"Sorted Number:";
	printLinkedList(headNode);
	cout<<endl;
	
	return 0;
}
void mergeSort(Node *&head){
	if(head->next!=NULL)				//check the condition if this is the last node, do nothing
	{
		Node* head1;
		Node* head2 = head;				//assign head to head 2. Head 2 will point to second half of the linked list
		int len = getLength(head);
		for(int i=0; i<len/2;i++)		//use for loop to increment the pointer 2 to the mid poin in linked list
		{      
			head1 = head2;				// assign head1 to any node head2 point to, 
			head2 = head2->next;		//in order to put NULL terminate for the first half of the linked list
		}
		head1->next = NULL;				//terminate first half of the linked list
		head1 = head;					//reposition head1 to the beginning of linked list, also the first node of the first half
		mergeSort(head1);
		mergeSort(head2);
		head = merge(head1,head2);
	}
}

Node* merge(Node *&head1,Node *&head2){
	Node* newHead;
	//Base case: return the other half if  one of them is NULL
	if(head1==NULL) return head2;
	else if(head2 ==NULL) return head1;
	
	//compare the value
	if(head1->item < head2->item){
		newHead = head1;							//assign the newHead to the Node has smaller value
		newHead->next = merge(head1->next,head2);	//recall the functionto find the next Node
	}
	else{
		newHead = head2;
		newHead->next = merge(head1,head2->next);
	}
	
	return newHead;
}

void printLinkedList(Node *head){
	Node* cur = head;
	for(;cur!=NULL;cur=cur->next){
		cout<<cur->item<<" ";
	}
}
int getLength(Node *head){
	Node* cur = head;
	int i=0;
	for(;cur!=NULL;cur=cur->next){
		i++;
	}
	return i;
}

void receiveLinkedList(Node *&head){
	stringstream ss;
	string input;
	Node* myNode = new Node;
	Node* lastNode;
	head = myNode;

	cout<<"Enter number to be sorted: ";
	getline(cin,input);
	ss<<input;

	while(ss>>myNode->item){
		lastNode = myNode;					//keep track of the last Node
		myNode->next = new Node;			//Create new Node and link it to the previous Node
		myNode = myNode->next;				//increment to the next Node
	}
	lastNode->next = NULL;					//assign NULL to the lastNode's next
	delete myNode;							//delete pointer but I'm not sure if we need this. I remember function will delete all local variable
}