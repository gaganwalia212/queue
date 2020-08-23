#include <iostream>

using namespace std;

class Deque
{
    int * Q;
    int size;
    int f{-1},r{-1};
public:
    Deque(int);
    ~Deque();
    void insert_front(int);
    void insert_rear(int);
    int delete_front();
    int delete_rear();
    void display();
    bool is_empty();
    bool is_full();

};

Deque::Deque(int x=0)
{
    size=x;
    Q=new int[size];
}

Deque::~Deque()
{
    delete []Q;
}

void Deque::insert_front(int x)
{
    if(f==-1)
    {
        cout<<"Cannot insert at front\n";
        return;
    }
    Q[f]=x;
    f--;
}

void Deque::insert_rear(int x)
{
    if(r==size-1)
    {
        cout<<"Cannot insert at back\n";
        return;
    }
    r++;
    Q[r]=x;
}

int Deque::delete_front()
{
    if(f==r)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    f++;
    int x=Q[f];
    if(f==r)
        f=r=-1;
    return x;
}

int Deque::delete_rear()
{
     if(f==r)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    int x=Q[r];
    r--;
    if(f==r)
        f=r=-1;
    return x;
}

void Deque::display()
{
    if(f==r)
    {
        cout<<"[]\n";
        return;
    }

    int i=f+1;
    cout<<"[";
    while(i!=r+1)
        cout<<Q[i++]<<" ";
    cout<<"\b]\n";
}

bool Deque::is_empty()
{
    return (f==r)?true:false;
}

bool Deque::is_full()
{
    return (r==size-1)?true:false;
}


int main()
{
    Deque q(5);
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque is full-"<<boolalpha<<q.is_full()<<endl;
    q.insert_front(10);
    for(int i=0;i<6;i++)
        q.insert_rear(i+1);
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque is full-"<<boolalpha<<q.is_full()<<endl;
    q.display();
    cout<<"\n=================================================================\n";
    for(int i=0;i<6;i++)
    q.delete_front();
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque is full-"<<boolalpha<<q.is_full()<<endl;
    q.display();
    cout<<"\n=================================================================\n";
    for(int i=0;i<6;i++)
        q.insert_rear((i+1)*10);
    q.display();
    for(int i=0;i<3;i++)
        q.delete_rear();
    q.display();
    cout<<"\n=================================================================\n";
    q.delete_front();
    q.insert_rear(100);
    q.delete_front();
    cout<<"Deque is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Deque is full-"<<boolalpha<<q.is_full()<<endl;
    q.display();
    cout<<"\n=================================================================\n";
    q.insert_front(6);
    q.insert_front(18);
    q.insert_front(20);
    q.insert_front(78);

    q.insert_rear(60);
    q.insert_rear(180);
    q.insert_rear(200);
    q.insert_rear(780);

    q.display();

    return 0;
}
