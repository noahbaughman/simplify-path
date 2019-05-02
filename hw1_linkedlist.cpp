/*
 * CISC 2200: Data Structures
 * HW1: Questions 3, 4, 5
 *
 *This program merges two linked lists, reverses a linked list, and removes elements of value val from a list.
 *
 * @author Noah Baughman
 * @date 10/2/18
 * @file hw1_linkedlist.cpp
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
};

Node* add(Node* head, const int& newEntry) {
    Node* cur = new Node();
    cur->data = newEntry;
    cur->next = head;
    head = cur;
    cur = NULL;
    return head;
}

void display(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << ", ";
        cur = cur->next; 
    }
    cout << endl;
}

/*
  This functions merges two lists.

  @param l1, on linked list, and l2 a second linked list.
  @return head, the merged list
*/
Node* mergeTwoLists(Node* l1, Node* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        Node *node = NULL;

        if(l1->data <= l2->data){
            node = l1;
            l1 = l1->next;
        }
        else{
            node = l2;
            l2 = l2->next;
        }

        Node *head = node;

        while(l1 != NULL && l2 != NULL){
            if(l1->data <= l2->data){
                node->next = l1;
                node = node->next;

                l1 = l1->next;
            }
            else{
                node->next = l2;
                node = node->next;

                l2 = l2->next;
            }
        }

        if(l1 != NULL){
            node->next = l1;
        }
        else if(l2 != NULL){
            node->next = l2;
        }
        return head;
    }

/*
  This functions reverses a linked list.

  @param list, the linked list to be reversed
  @return previous, the reversed list
*/
Node* reverse(Node* list){
    Node *temp;
    Node *previous = NULL;
    while(list != NULL) {
        temp = list->next;
        list->next = previous;
        previous = list;
        list = temp;
    }
    return previous;
}

/*
  This function removes elements of value val from linked list.

  @param head, the list, and int val the value to be removed
  @return Thee new list with no value val
*/
Node* removeElements(Node* head, int val) {
    if (head==NULL){
        return head;
    }
    Node* p = head;
    while(p->next != NULL){
        if (p->next->data == val){
            p->next = p->next->next;
        }
        else{
            p=p->next;
        }
    }
        if (head->data == val)
            head=head->next;
    return head;
}


int main() {
    Node* n1 = NULL;
    n1 = add(n1, 4);
    n1 = add(n1, 2);
    n1 = add(n1, 1);
    
    Node* n2 = NULL;
    n2 = add(n2, 4);
    n2 = add(n2, 3);
    n2 = add(n2, 1);

    Node* mergedlist = mergeTwoLists(n1, n2);

    cout << "The merge of the following linked lists: 1, 2, 4 and 1, 3, 4 is" << endl;
    display(mergedlist);

    Node* rev = NULL;
    rev = add(rev, 5);
    rev = add(rev, 4);
    rev = add(rev, 3);
    rev = add(rev, 2);
    rev = add(rev, 1);

    Node* reversedList = reverse(rev);

    cout << "The reversed list of 1, 2, 3, 4, 5 is" << endl;
    display(reversedList);

    Node* del = NULL;
    del = add(del, 6);
    del = add(del, 5);
    del = add(del, 4);
    del = add(del, 3);
    del = add(del, 6);
    del = add(del, 2);
    del = add(del, 1);

    Node* deletedList = removeElements(del, 6);

    cout << "After deleting the value 6 from the list 1,2,6,3,4,5,6, the list is" << endl;
    display(deletedList);
}
