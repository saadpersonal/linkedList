#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class List {
private:
  Node *head, *tail;
public:
  List() {
    head=NULL;
    tail=NULL;
  }
  void createnode(int value);
  void display();
  void insert_start(int value);
  void insert_position(int pos, int value);
  void delete_first();
  void delete_last();
  void delete_position(int pos);
};


void List::createnode(int value) {
  Node *temp = new Node;
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else {
    tail->next=temp; //set the current tail's next to the new node
    tail=temp;  //set the new tail
  }
}

void List::display() {
  Node *temp = new Node;
  temp = head;
  while(temp!=NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << endl;
}

void List::insert_start(int value) {
  Node *temp = new Node; 
  temp->data = value;
  temp->next = head;
  head = temp;
}

void List::insert_position(int pos, int value) {
  Node *pre = new Node;
  Node *curr = new Node;
  Node *temp = new Node;
  curr = head;
  for (int i = 1; i < pos; i++) {
    pre = curr;
    curr = curr->next;
  }
  temp->data = value;
  pre->next = temp;
  temp->next = curr;
}

void List::delete_first() {
  Node *temp = new Node;
  temp=head;
  head=head->next;
  delete temp;
}

void List::delete_last() {
  Node *curr = new Node;
  Node *pre = new Node;
  curr = head;
  while(curr->next != NULL) {
    pre = curr;
    curr = curr->next;
  }
  tail = pre;
  pre->next = NULL;
  delete curr;
}

void List::delete_position(int pos) {
  Node *pre = new Node;
  Node *curr = new Node;
  curr = head;
  for(int i = 0; i < pos; i++) {
    pre = curr;
    curr = curr->next;
  }
  pre->next = curr->next;
  delete curr;
}

int main() {
  List *list = new List;
  list->createnode(5);
  list->createnode(3);
  list->display();
  list->insert_start(12);
  list->createnode(22);
  list->insert_position(2, 300);
  list->display();
  list->delete_position(3);
  list->display();
  return 0;
}
