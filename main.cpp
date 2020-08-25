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
    cout<<"Queue deleted\n";
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
/***********************************************************************************************************************************/
template<typename T>
class Priority_Queue
{
    int priorities;
    int size;
    Queue<T>**Q;
public:
    Priority_Queue(int x,int p)
    {
        size=x;
        priorities=p;
        Q=new Queue<T>*[priorities];
        for(int i=0;i<priorities;i++)
            Q[i]=new Queue<T>(size);

        cout<<"Priority Queue constructed\n";
    }

    ~Priority_Queue()
    {
        for(int i=0;i<priorities;i++)
            Q[i]->~Queue();
        delete []Q;
        cout<<"Priority Queue destructed\n";
    }

    void enqueue(T ele,int p)
    {
        if(p>priorities||p<1)
        {
            cout<<"Invalid priority\n";
            return;
        }

        Q[p-1]->enqueue(ele);
        cout<<"Inserted\n";
    }

    T dequeue()
    {
        T x='\0';
        int i;
        for( i=0;i<priorities;i++)
        {
            if(!Q[i]->is_empty())
            {
               x=Q[i]->dequeue();
               break;
            }
        }
        if(i==priorities&&x=='\0')
            cout<<"Priority Queue is empty\n";
            else return x;
    }

    bool is_empty()
    {
        for(int i=0;i<priorities;i++)
        {
            if(!Q[i]->is_empty())
                return false;
        }
        return true;
    }

    void display()
    {
        for(int i=0;i<priorities;i++)
            Q[i]->display();
    }

};
int main()
{
    cout<<"Enter size and no of priorities:";
    int size,p;
    cin>>size>>p;
    Priority_Queue<char>q(size,p);
    char ch;
    do
    {
        cout<<"1-enqueue\n";
        cout<<"2-dequeue\n";
        cout<<"3-display\n";
        cout<<"4-is_empty??\n";
        cout<<"Q-quit\n";
        cout<<"\nInput-";
        cin>>ch;

        switch(ch)
        {
        case('1'):
            char ele;
            int p;
            cout<<"Enter element and its priority-";
            cin>>ele>>p;
            q.enqueue(ele,p);
            break;
        case('2'):
            q.dequeue();
            break;
        case('3'):
            q.display();
            break;
        case('4'):
            cout<<"Queue is empty-"<<boolalpha<<q.is_empty()<<endl;
            break;
        case('Q'):
        case('q'):
            break;
        default:
            cout<<"Invalid Input\n";

        }
        cout<<"\n**************************************************************************************\n";
    }while(ch!='q'&&ch!='Q');

    return 0;
}
