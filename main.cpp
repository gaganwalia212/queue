#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*next=0;
};

class Stack {
Node*top=0;
public:
    ~Stack();
    bool is_empty();
    bool is_full();
    void push(int);
    int pop();
    void display();
    int peak(int);
    int stack_top();
};



Stack::~Stack()
{
    Node*p=0;
    while(top)
    {
        p=top;
        top=top->next;
        delete p;
    }
    cout<<"Stack deleted\n";
}

bool Stack:: is_empty()
{
 return top?false:true;
}

bool Stack::is_full()
{
    Node*t=new Node;
    return t?false:true;
}

void Stack::push(int x)
{
   Node*t=new Node;
   if(!t)
   {
       cout<<"Stack Overflow\n";
       return;
   }
   t->data=x;
   t->next=top;
   top=t;

}

int Stack::pop()
{
    if(!top)
    {
        cout<<"Stack Underflow\n";
        return -1;

    }
    Node*p{top};
    top=top->next;
    int x=p->data;
    delete p;
    return x;
}

void Stack::display()
{
    if(top==0)
    {
        cout<<"[ ]";
        return;
    }
    Node*p=top;
    cout<<"[ ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"]";
}

int Stack::peak(int pos)
{
    Node*p=top;
    for(int i=0;i<pos-1&&p;i++)
        p=p->next;
    if(!p||pos<1)
    {
        cout<<"Invalid position\n";
        return -1;
    }
    return p->data;
}

int Stack::stack_top()
{
    if(!top)
    {
        cout<<"Stack underflow\n";
        return -1;
    }

    return top->data;
}


class Queue
{
    Stack s1;
    Stack s2;
public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        if(s2.is_empty())
        {
            if(s1.is_empty())
            {
                cout<<"Queue underflow\n";
                return -1;
            }
            while(!s1.is_empty())
                s2.push(s1.pop());
        }
        return s2.pop();
    }

    bool is_empty()
    {
        if(s1.is_empty()&&s2.is_empty())
            return true;
        return false;
    }
    bool is_full()
    {
        if(s1.is_full()&&s2.is_full())
        return true;
        return false;
    }

    void display()
    {

        if(Queue::is_empty())
        {
            cout<<"[]\n";
            return;
        }
        if(!s1.is_empty())
            s1.display();
        cout<<endl;
        if(!s2.is_empty())
            s2.display();
        cout<<endl;

    }
};

int main()
{
     //try tracing the following
    Queue q;
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
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.display();
    q.enqueue(10);
    q.enqueue(28);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
}
