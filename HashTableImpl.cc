#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class hashTableEntry
{
      unsigned int key;
      std::string definition;
      //List <class hashTableEntry> list;
     
      public:
             hashTableEntry()
             {
             }
                         
             void setKey(int key)
             {
                  this->key = key;    
             }
             int getKey()
             {
                 return key;
             }
             std::string getDefinition()
             {
                         return definition;
             }
             void setDefinition(std::string def)
             {
                  definition = def;    
             }
             // Define the <, > and = operators
             hashTableEntry& operator=(const hashTableEntry& rhs)
             {
                  this->key = rhs.key;
                  this->definition = rhs.definition;
                  return *this;  
             }
            
             int operator<(const hashTableEntry& rhs)
             {
                 if(this->key < rhs.key)
                    return 1;
                 if(this->key >= rhs.key)
                      return 0;
                             
             }
             int operator>(const hashTableEntry& rhs)
             {
                 if(this->key > rhs.key)
                    return 1;
                 if(this->key <= rhs.key)
                    return 0;   
             }
             int operator==(const hashTableEntry& rhs)
             {
                 if(this->key == rhs.key)
                    return 1;
                 else
                    return 0;   
             }
            
     
};

class hashTable
{
      vector< list<hashTableEntry> > table;
     
      public:
             hashTable()
             {
                // Initialize all lists
                for(int i = 0;i<30 ;i++)
                {
                   list<hashTableEntry> l;
                   hashTableEntry hte;
                   hte.setKey(0);
                   hte.setDefinition("");
                   l.push_back(hte);
                   table.push_back(l);                  
                }
             }
            
             void insertEntry(hashTableEntry& hte);
             void removeEntry(hashTableEntry& hte);
             int hashCode(int key);
             void print();
            
            
};

void hashTable::print()
{
   cout<<"Table:"<<endl;
   list<hashTableEntry>::iterator it;
  
   for(int i = 0;i<table.size();i++)
   {     
      cout<<"Index:"<<i<<endl<<"---------------------"<<endl;
      cout<<"List Size:"<<table[i].size()<<endl;
      for(it=table[i].begin();it != table[i].end();it++)
      {
          cout<<"Key:"<<it->getKey()<<endl;
          cout<<"Definition:"<<it->getDefinition()<<endl;
      }
      getchar();
     
   }
   cout<<endl<<"End"<<endl;   
}

int hashTable::hashCode(int key)
{
   
    return ((127 * key)+ 600)% 3331333;
}

void hashTable::insertEntry(hashTableEntry& hte)
{
     // Calculate the hash code or index into the vector
     // hashcode = (a* key + b) % p; a, b are positive integers and p is a large prime
     int index = hashCode(hte.getKey()) % 30;
     if(table[index].size() == 1) // first entry
     {    
         table[index].front().setKey(hte.getKey());
         table[index].front().setDefinition(hte.getDefinition());
     }
     else        
         table[index].push_back(hte);        
}

void hashTable::removeEntry(hashTableEntry& hte)
{
     // Find the hte and remove it
     // Get the hashcode into the index
     int index = hashCode(hte.getKey()) % 30;    
    
     // We know the bucket, search the list to find the entry
     list<hashTableEntry>::iterator it;
     it = find(table[index].begin(), table[index].end(), hte);
     if(it != table[index].end())
     {
           // Remove it
           table[index].erase(it);     
     }
}


int main()
{
    hashTable h;
    hashTableEntry hte;
   
    for(int i = 0;i<10;i++)
    {
        hte.setKey(i);
        //char ai;
        //itoa(i,&ai, 10);
        std::string str("hello");
        str+= (i+48);
        hte.setDefinition(str);
        h.insertEntry(hte);       
    }
   
    h.print();
   
    getchar();
    getchar();
   
   
    return 0;
}
