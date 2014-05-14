#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

#define MAX 3

class queue
{
  int q[MAX];
  int front;
  int count;  
  
  public:
        queue()
        {
          front = 0;
          count = 0;   
        }
        int dequeue();
        int enqueue(int number);
};

int queue::dequeue()
{
    cout<<endl<<"Calling dequeue"<<endl;
    if( count == 0)
    {
      cout<<endl<<"Queue empty"<<endl;
      return -1;
    }
    
    int number = q[front];
    count--;
    front = (++front)%MAX;
    
    cout<<"New Front: "<<front<<" New count: "<<count<<endl;
  
    cout<<"Number: "<<number<<endl;
        
    return number;
    
}

int queue::enqueue(int number)
{
    cout<<endl<<"Adding number: "<<number<<endl;
    if( count == MAX)
    {
      cout<<"Queue full"<<endl;
      return -1;
    }

    //front = front+count;               
    q[(front+count)%MAX] = number;
    count++;    
    
    cout<<"Front: "<<front<<"  count: "<<count<<endl;
       
    return 0;
}

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(1);
    
    cout<<endl<<endl;
    
    q.dequeue();
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    getchar();
}
