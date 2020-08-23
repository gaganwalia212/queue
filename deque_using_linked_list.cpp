#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node*next=0;
    Node*prev=0;
};

class Deque
{
   Node*f{0},*r{0};
public:
    ~Deque();
    void insert_front(int);
    void insert_rear(int);
    int delete_front();
    int delete_rear();
    void display();
    bool is_empty();
    bool is_full();

};


Deque::~Deque()
{
   Node*p;
   while(f)
   {
       p=f;
       f=f->next;
       delete p;
   }
}

void Deque::insert_rear(int x)
{
    Node* t=0;
    t=new Node;
    if(t==0)
    {
        cout<<"Deque overflow\n";
        return;
    }

    t->data=x;
    if(f==0)
        f=r=t;
    else{
        r->next=t;
        t->prev=r;
        r=t;

    }
}

void Deque::insert_front(int x)
{
      Node* t=0;
    t=new Node;
    if(t==0)
    {
        cout<<"Deque overflow\n";
        return;
    }

    t->data=x;
    if(f==0)
        f=r=t;
    else
        {
            t->next=f;
            f->prev=t;
            f=t;
        }
}

int Deque::delete_front()
{
   if(!f)
   {
       cout<<"Deque is empty\n";
       return -1;
   }

   Node*p=f;
   f=f->next;
   int x=p->data;
   f->prev=0;
   delete p;
   return x;
}

int Deque::delete_rear()
{
     if(!f)
   {
       cout<<"Deque is empty\n";
       return -1;
   }

   Node*p=r;
   r=r->prev;
   r->next=0;
   int x=p->data;
   delete p;
   return x;


}

void Deque::display()
{
    if(f==0)
    {
        cout<<"[]\n";
        return;
    }

    Node*p=f;
    cout<<"[";
 while(p)
 {
     cout<<p->data<<" ";
     p=p->next;
 }
    cout<<"\b]\n";
}

bool Deque::is_empty()
{
    return (f==0)?true:false;
}

bool Deque::is_full()
{
    Node*t=0;
    t=new Node;
    if(!t) return true;
    delete t;
    return false;
}


int main()
{
    Deque q;
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque if full-"<<boolalpha<<q.is_full()<<endl;
    q.insert_rear(1);
    q.display();
    q.insert_front(9);
    q.display();
    q.insert_front(10);
    q.display();
    q.insert_front(20);
    q.display();
    q.insert_rear(7);
    q.display();
    q.insert_front(6);
    q.display();
    q.insert_rear(19);
    q.display();
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque if full-"<<boolalpha<<q.is_full()<<endl;
    for(int i=0;i<6;i++)
    q.delete_rear();
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque if full-"<<boolalpha<<q.is_full()<<endl;
    q.display();


    return 0;
}
