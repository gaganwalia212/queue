#include <iostream>

using namespace std;

//Node for storing each element
template<typename T>
struct Node
{
    T data;
    Node* next=0;
};


//class of queue will only contain two pointers to node...no need to define the size
//dynamic queue
template<typename T>
class Queue
{
    Node<T>*first=0;
    Node<T>*rear=0;
public:
    bool is_empty();
    bool is_full();
    void enqueue(T );
    T dequeue();
    void display();
    ~Queue();
};

template<typename T>
bool Queue<T>:: is_empty()
{
    return (first==0)?true:false;
}

template<typename T>
bool Queue<T>::is_full()
{
    Node<T>*t=0;
    t=new Node<T>;
    if(t==0)
        return true;
    delete t;
    return false;
}

template<typename T>
void Queue<T>::enqueue(T x)
{
    Node<T>* t=0;
    t=new Node<T>;
    if(t==0)
    {
        cout<<"Queue overflow\n";
        return;
    }
    t->data=x;
    if(first==0)
        rear=first=t;
    else{
    rear->next=t;
    rear=t;}
}

template<typename T>
T Queue<T>::dequeue()
{
    if(first==0)
    {
        cout<<"Queue underflow\n";
        return '\0';
    }
    Node<T>*p=first;
    T x=p->data;
    first=first->next;
    delete p;
    return x;
}

template<typename T>
void Queue<T>::display()
{
    if(first==0)
    {
        cout<<"[ ]\n";
        return ;
    }
    Node<T>*p=first;
    cout<<"[";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\b]\n";
}

template<typename T>
Queue<T>::~Queue()
{
    Node<T>*p=first;
    while(first)
    {
        p=first;
        delete p;
        first=first->next;
    }
}
int main()
{
    Queue<int>q;
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(10);
    q.enqueue(28);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    return 0;
}
