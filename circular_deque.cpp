#include <iostream>

using namespace std;

class Deque
{
    int * Q;
    int size;
    int f{0},r{0};
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
    if(f==(r+1)%size)
    {
        cout<<"Cannot insert at front\n";
        return;
    }
    Q[f]=x;
    f=(f+size-1)%size;
}

void Deque::insert_rear(int x)
{
    if(f==(r+1)%size)
    {
        cout<<"Cannot insert at back\n";
        return;
    }
    r=(r+1)%size;
    Q[r]=x;
}

int Deque::delete_front()
{
    if(f==r)
    {
        cout<<"Deque is empty\n";
        return -1;
    }
    f=(f+1)%size;
    int x=Q[f];
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
    r=(r+size-1)%size;

    return x;
}

void Deque::display()
{
    if(f==r)
    {
        cout<<"[]\n";
        return;
    }

    int i=(f+1)%size;
    cout<<"[";
    while(i!=(r+1)%size)
        {cout<<Q[i]<<" ";
        i=(i+1)%size;}
    cout<<"\b]\n";
}

bool Deque::is_empty()
{
    return (f==r)?true:false;
}

bool Deque::is_full()
{
    return (f==(r+1)%size)?true:false;
}


int main()
{
    Deque q(6);
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
