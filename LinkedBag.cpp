#include "LinkedBag.h"

LinkedBag::LinkedBag() {
	head = NULL;
	itemCount = 0;
}

LinkedBag::~LinkedBag() {
	clear();
}

// int getCurrentSize() const;
int LinkedBag::getCurrentSize() const {
	return itemCount;
}

// bool isEmpty() const;
bool LinkedBag::isEmpty() const {
	return itemCount == 0;
}

// bool add(const int& newEntry);
bool LinkedBag::add(const int& newEntry) {
	Node* cur = new Node();
	cur->data = newEntry;
	cur->next = head;
	head = cur;
	itemCount++;
	return true;
}
// Node* getPointerTo(const int& anEntry) const;
// bool remove(const int& anEntry);
bool LinkedBag :: remove(const int& anEntry){
	Node* toDelete = getPointerTo(anEntry);
	bool canRemove = !isEmpty() && toDelete != NULL;
	if (canRemove){
		toDelete->data = head->data;
		toDelete=head;
		head = head->next;
		toDelete -> next= NULL;
		delete toDelete;
		toDelete = NULL;
		itemCount--;
	}
	return canRemove;
}

// void clear();
void LinkedBag::clear(){
	Node* cur = head;
	Node* toDelete = cur;
	while(cur != NULL) {
		cur = cur->next;
	}
}
// int getFrequencyOf(const int& anEntry) const;
// bool contains(const int& anEntry) const;
// vector<int> toVector() const;
vector<int> LinkedBag::toVector() const{
	vector<int> bagContents;
	Node* cur = head;
	while(cur != NULL) {
		bagContents.push_back
	}

}