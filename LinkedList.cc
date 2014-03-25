#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct node
{ 
  int data;
  struct node* next;
};

class LinkedList
{
  public:
       LinkedList() { head = NULL;}
       virtual ~LinkedList()
       {
           clearList();
       }
       int insertData(int aInData);
       void clearList();
       int deleteNode(int aInData);
       void reverseList();
       void reverseListIterative();
       void printList();
       void printHead();

  private:
       struct node* head;
       struct node* reverseListHelper(struct node* aInList);
};

struct node* LinkedList::reverseListHelper(struct node* aInList)
{
  if(aInList == NULL || aInList->next == NULL)
  {
      return aInList;
  }

  struct node* newHead = reverseListHelper(aInList->next);
  aInList->next->next = aInList;
  aInList->next = NULL;

  return newHead;

}

void LinkedList::reverseList()
{
  if(head == NULL)
  {
    cout<<"Head is NULL"<<endl;
    return;
  }

  head = reverseListHelper(head);
  return;
}

void LinkedList::reverseListIterative()
{
  if(head == NULL)
  {
    cout<<"reverseListIterative(): Head is NULL"<<endl;
    return;
  }
  
  struct node* prev = NULL;
  struct node* next = head;

  while(next)
  { 
    struct node* temp = next->next;

    next->next = prev;
    prev = next;
    next = temp;
     
  }

  head = prev; 
  
}


int LinkedList::insertData(int aInData)
{
    if(head == NULL)
    {
        head = new node();
        if(head == NULL)
        {
           cout<<"Could not allocate memory to head"<<endl;
           return -1;
        }
        head->data = aInData;
        head->next = NULL;
        return 0;
    }  

    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new node();
    if(temp->next == NULL)
    {
       cout<<"Could not allocate memory to head"<<endl;
       return -1;
    }
    temp->next->data = aInData;
    temp->next->next = NULL;

    return 0;
}

int LinkedList::deleteNode(int aInData)
{
  if(head == NULL)
  {
      cout<<"Head is NULL"<<endl;
      return -1;
  }

  struct node* next = head;
  struct node* prev = NULL;

  while(next != NULL)
  {
    if(next->data == aInData)
    {
       if(next == head)
       {
         head = next->next;
       }
       else
       {
         prev->next = next->next;
       }

       delete(next);
       return 0;
    }

    prev = next;
    next = next->next;
  }
  
  return -1;
}

void LinkedList::clearList()
{
   if(head == NULL)
   {
       cout<<"Head is NULL"<<endl;
       
       return;
   }

   struct node* prev = head;
   struct node* next;
 
   while(prev)
   {
       next = prev->next;
       delete(prev);
       prev = next;
   }

   head = NULL;

   return;
}

void LinkedList::printHead()
{
   if(head == NULL)
    cout<<"Head is null..."<<endl;

   cout<<head->data;
}

void LinkedList::printList()
{
  struct node* temp = head;
  cout<<"Printing Linked List: "<<endl;
  while(temp)
  {
     if(temp != head)
       cout<<"->";

     cout<<temp->data;
     temp = temp->next;
  }

  cout<<endl;
}

int main()
{
  class LinkedList l;

  for(int i=0;i<10;i++)
    l.insertData(i);

  l.printList();
  l.deleteNode(5);
  l.deleteNode(0);
  l.printList();
  l.printHead();
  l.reverseListIterative();
  l.printList();
 
  return 0;
}

