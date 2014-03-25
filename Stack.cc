#include<cstdio>
#include<cstdlib>
#include<exception>
#include<vector>
#include<iostream>

using namespace std;

class StackException: public exception
{
public:
    virtual const char* what() const throw ()
    {
        return "Stack is empty";
    }

}stackException;


template <typename T>
class Stack
{
    public:
            Stack() {}
            virtual ~Stack(){}
            void push(T& aIn);
            T pop();
            T& top();
    private:
            vector<T> array;

};

template <typename T>
void Stack<T>::push(T& aIn)
{
    array.push_back(aIn);
}


template <typename T>
T Stack<T>::pop()
{
    if(array.size())
    {
        T ret = array[0];
        array.erase(array.begin());
        return ret;
    }
    else
        throw stackException;  
}

template <typename T>
T& Stack<T>::top()
{
    if(array.size())
        return array[0];
    else
        throw stackException;
}


int main()
{
    Stack<int> s;
    
    for(int i=1;i<10;i++)
        s.push(i);

    try
    {
        for(int i=0;i<121;i++)
          cout<<s.pop();
    }
    catch(StackException& e)
    {
        cout<<endl<<e.what();
    }
    return 0;
}
