#include <iostream>

using namespace std;
 
struct Node {
    float number; 
    Node *next; 
    Node *prev; 
};
 
class doubleList 
{
    Node *head;
    Node *tail;
public:
    doubleList();
    void addFirst(float number);
    void addLast(float number);
    void delTail();
    void delHead();
    void sortingList();
    float showListAverage();
    void swap(float &a, float &b);
    void showList() const;
};
 
doubleList :: doubleList() 
{
    head = tail = NULL;
}
 
void doubleList :: addFirst(float number) 
{
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
 
void doubleList :: addLast(float number)
 {
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
    if (head) 
	{
        Node *buf = head;
        while (buf) 
		{
            cout << buf ->number << " ";
            buf = buf -> next;
            
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
}
float doubleList :: showListAverage()  
{
  if (head) 
  {
Node *buf = head;
        float sum = 0;
        int count = 0;         
        while(buf)    
        {
            sum += head->number ;   
            buf = buf -> next;                       
            count ++;                              
        }
        return  sum/count;
    }
} 
void doubleList :: delHead() 
{
    if (head) 
	{
        Node *buf = head;
        head = head -> next;
        head -> prev = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}
 
void doubleList :: delTail() 
{
    if (tail) 
	{
        Node *buf = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}
 
void doubleList :: swap(float &a, float &b) {
    int buf = a;
    a = b;
    b = buf;
}
 
void doubleList :: sortingList() 
{
    Node *buf = head;
    for (Node *i = buf; i; i = i -> next) 
	{
        for (Node *j = i -> next; j; j = j -> next) 
		{
            if (i -> number < j -> number) 
			{
                swap(i -> number, j -> number);
            }
        }
    }
 
}
 
 
 main()
{
    doubleList ob;
    int N;
    float a_i;
    cout << "Enter number of elements" << endl;
    cin>>N;
for(int i =0; i<N;i++)
{
cin >> a_i;
ob.addFirst(a_i);
int *a_i=NULL;
}
   ob.sortingList();
   ob.showList();
   cout<<"AVG="<< ob.showListAverage();
   system("pause");
}

//Vad1mka
