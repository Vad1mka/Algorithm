#include <iostream>
using namespace std;
 
struct Node {
    string number; 
    Node *next; 
    Node *prev; 
};
 
class doubleList {
    Node *head;
    Node *tail;
public:
    doubleList();
    void addFirst(string number);
    void addLast(string number);
    void delTail();
    void delHead();
    void showList() const;
    void clearFromTheTail();
};
 
doubleList :: doubleList() {
    head = tail = NULL;
}
void doubleList::clearFromTheTail()
{
if (head) {
        Node *buf = tail;
        while (buf) {
      tail = tail -> prev;
        tail -> next = NULL;
        delete buf;
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
}	

 
void doubleList :: addFirst(string number) {
    Node *buf  = new Node;
    buf -> number = number;
    if (!head) {
        buf -> next = tail;
        tail = buf;
    }
    else {
        buf -> next = head;
        head -> prev = buf;
    }
    head = buf;
    head -> prev = NULL;
 
}
 
void doubleList :: addLast(string number) {
    Node *buf = new Node;
    buf -> number = number;
    if (!head) {
        buf -> next = tail;
        head = buf;
        buf -> prev = NULL;
    }
    else {
        buf -> next = tail -> next;
        buf -> prev = tail;
        tail -> next = buf;
    }
    tail = buf;
}

void doubleList :: showList() const 
{
    if (head) {
        Node *buf = head;
        while (buf) {
            cout << buf ->number << " ";
            buf = buf -> next;
            
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
}
void doubleList :: delHead()
 {
    if (head) {
        Node *buf = head;
        head = head -> next;
        head -> prev = NULL;
        delete buf;
    }
    else cout << "List is empty " << endl;
}
 
void doubleList :: delTail() 
{
    if (tail) {
        Node *buf = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete buf;
    }
    else cout << "List is empty " << endl;
}
 

 
 main()
{
    doubleList ob;
    int N;
    string a_i;
    cout << "Enter number of elements" << endl;
    cin>>N;
for(int i =0; i<N;i++)
{
cin >> a_i;
ob.addFirst(a_i);
int *a_i=NULL;
}
    ob.showList();
	ob.clearFromTheTail();
    system("pause");
}
//Vad1mka
