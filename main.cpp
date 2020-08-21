#include <iostream>

using namespace std;

//General class for queue:
template<typename T>
class Queue
{
    int size;
    T*Q;
    int f{-1},r{-1};//index pointers..f-front....r-rear/back
public:
    Queue(int x=0);
    ~Queue();
    void enqueue(T);
    T deque();
    bool is_empty();
    bool is_full();
    void display();


};

template<typename T>
Queue<T>::Queue(int x)
{
    size=x;
    Q=new T[size];
}

template<typename T>
Queue<T>::~Queue<T>()
{
    delete []Q;
}

template<typename T>
void Queue<T>::enqueue(T x)
{
    if(r==size-1)
    {
        cout<<"Queue Overflow\n";
        return;
    }

    r++;
    Q[r]=x;
}

template<typename T>
T Queue<T>:: deque()
{
    if(f==r)
        {
            cout<<"Queue Underflow\n";
            return 0;
        }
    f++;
    return Q[f];
}

template<typename T>
bool Queue<T>::is_empty()
{
    if(f==r)
        return true;
    return false;
}

template<typename T>
bool Queue<T>::is_full()
{
    if(r==size-1)
        return true;
    return false;
}

template<typename T>
void Queue<T>:: display()
{
    if(f==r)
        {cout<<"[ ]\n";
        return;}
    cout<<"[";
    int i=f+1;
    while(i!=r+1)
        cout<<Q[i++]<<" ";
    cout<<"\b]\n";
}

int main()
{
    Queue <int>q(3);
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    q.display();
    q.enqueue(14);
    q.display();
    q.enqueue(189);
    q.display();
    q.enqueue(355);
    q.display();
    q.enqueue(78);
    q.display();
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    cout<< q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
    cout<<"Queue is full-"<<boolalpha<<q.is_full()<<endl;
    return 0;
}
