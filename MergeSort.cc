#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MergeSort
{
    vector<int> input;

public:
    void setInput(vector<int> in)
    {
        input =in;
    }
    void Merge(int low, int middle, int high);
    void Sort(int low, int high);
    void Print()
    {
        for(int i=0;i<input.size();i++)
            cout<<input[i]<<endl;
    }
};

void MergeSort::Sort(int low, int high)
{
    int middle = (low+high)/2;

    if(low < high)
    {
        Sort(low, middle);
        Sort(middle+1,high);
        Merge(low,middle,high);
    }
}

void MergeSort::Merge(int low, int middle, int high)
{
    queue<int> q1, q2;
   
    // Initialize the queues with the values
    for(int i=low;i<=middle;i++)
        q1.push(input[i]);

    for(int i=middle+1;i<=high;i++)
        q2.push(input[i]);

    int i = low;
    while(!q1.empty() && !q2.empty()) // while both queues aren't empty
    {
        if(q1.front() < q2.front())
        {
            input[i++] = q1.front();
            q1.pop();
        }
        else
        {
            input[i++] = q2.front();
            q2.pop();
        }
    }
   
    while(!q1.empty())
    {
        input[i++] = q1.front();
        q1.pop();
    }
       
    while(!q2.empty())
    {
        input[i++] = q2.front();
        q2.pop();
    }
}

int main()
{
    int i=0;
    vector<int> in;
    MergeSort m;

    cout<<"Enter the number of elements in the input: ";
    cin>>i;

    for(int j=0;j<i;j++)
    {
        int temp;
        cout<<"Enter element: ";
        cin>>temp;
        in.push_back(temp);

    }

    m.setInput(in);
    m.Sort(0, in.size()-1);
    m.Print();

    getchar();
    getchar();

}
