#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class HeapSort
{
  private:
          vector<int> heap;
 
  public:        
         void Sort();
         void Insert(int element);
         int ExtractMin();
         void Bubble_up(int index);
         void Bubble_down(int index);
         int getParent(int index);
         int getLeftChild(int index);          
         int getRightChild(int index);
         void Print();
};

void HeapSort::Print()
{
  int i=0;
 
  while(i != heap.size())
  {         
    cout<<heap[i]<<endl;
    i++;       
  }    
}

int HeapSort::ExtractMin()
{
    int min = heap.at(0);

    if(heap.size() <=0)
        return -1;
    // Copy the last element in the heap to the first and bubble down
    heap[0] = heap.back();
    heap.pop_back();
   
    Bubble_down(0);
   
    return min;
   
}

void HeapSort::Sort()
{
     int len = heap.size();
     cout<<endl<<"Length= "<<len<<endl;
     cout<<"Sorted array: "<<endl;
     for(int i=0;i<len;i++)
     {
       cout<<ExtractMin()<<"    ";             
     }    
}

void HeapSort::Insert(int element)
{
     heap.push_back(element);
    
     // Check to see if element appended needs to bubbled up
     Bubble_up(heap.size()-1);
}

int HeapSort::getParent(int index)
{
   if(index == 0)
      return -1;
   else
      return (index-1)/2;    
}

int HeapSort::getLeftChild(int index)
{
   if((index*2+1) >= heap.size())
      return -1;
   else
      return (index*2+1);    
}

int HeapSort::getRightChild(int index)
{
   if((index*2+2) >= heap.size())
      return -1;
   else
      return (index*2+2);    
}

void HeapSort::Bubble_up(int index)
{
     int parent = getParent(index);
     // Check if 1st element
    
     if(parent == -1)
        return;
       
     if(heap.at(parent) > heap.at(index))
     {        
         int temp = heap.at(index);
         heap[index] = heap.at(parent);
         heap[parent] = temp;
         Bubble_up(parent);
     }
}

void HeapSort::Bubble_down(int index)
{
     int leftChild = getLeftChild(index);
    
     if(leftChild == -1)
        return;
    
     int leastChild = leftChild;
     int rightChild = getRightChild(index);

     if(rightChild == -1)
        leastChild = leftChild;
     else
     if(heap.at(leftChild) > heap.at(rightChild))
         leastChild = rightChild;
  
     if(heap.at(index) > heap.at(leastChild))
     {        
         int temp = heap.at(index);
         heap[index] = heap.at(leastChild);
         heap[leastChild] = temp;
         Bubble_down(leastChild);
     }
}

int main()
{
     HeapSort h;
     int i=0,element=0;
     cout<<"Enter the number of elements in the heap: ";
     cin>>i;
    
     for(int j=0;j<i;j++)
     {            
         cout<<"Enter elements:";
         cin>>element;
         h.Insert(element);       
     }
     h.Print();
     h.Sort();
     getchar();
     getchar(); 
}
