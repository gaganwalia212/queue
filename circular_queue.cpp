#include <iostream>

using namespace std;

//General class for circular queue:
template<typename T>
class Queue
{
    int size;
    T*Q;
    int f{0},r{0};//index pointers..f-front....r-rear/back....rememeber they must be initialized to 0 not -1..else there will be a problem in display function
public:
    Queue(int x=0);
    ~Queue();
    void enqueue(T);
    T dequeue();
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
    if(f==(r+1)%size)
    {
        cout<<"Queue Overflow\n";
        return;
    }

    r=(r+1)%size;
    Q[r]=x;
}

template<typename T>
T Queue<T>:: dequeue()
{
    if(f==r)
        {
            cout<<"Queue Underflow\n";
            return 0;
        }
    f=(f+1)%size;
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
    if(f==(r+1)%size)
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
    while(i!=(r+1)%size){
        cout<<Q[i]<<" ";
        i=(i+1)%size;}
    cout<<"\b]\n";
}

int main()
{
    //try tracing the following
    Queue<int>q(5);
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
