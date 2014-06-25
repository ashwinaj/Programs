#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define MAX 10

typedef int cache_node;         

class LRU
{
    private:
    
            map<int, list<cache_node>::iterator > _mapping;
            list<cache_node> _list;
            unsigned int _maxListSize;
            
    public:
            LRU()
            {
                _maxListSize = MAX;
                _list.clear();
                
            }
            bool removeNode(string key);
            int lookup(int value);
            bool addNode(int value);
            
};

bool LRU::removeNode(string key)
{
    return false;
}

cache_node LRU::lookup(int value)
{
    // Find the key in the map first
    map<int, list<cache_node>::iterator >::iterator it = _mapping.find(value);
    
    if(it == _mapping.end())
    {    
    	addNode(value);
        return value;        
    }
    else 
        return (*it).first;
    
}

bool LRU::addNode(int value)
{
    // Find the key in the map first
    map<int, list<cache_node>::iterator >::iterator it = _mapping.find(value);
    
    if(it != _mapping.end())
    {
        cout<<"Value present"<<endl;
        return false;
    }
        //return false;
        
    if(_maxListSize == _list.size())
    {
        // Get the node to be removed
        list<cache_node>::iterator listIt; 
        listIt = _list.end();
        --listIt;
        
        // Remove from the map
        it = _mapping.find(*listIt);
        _mapping.erase(it);
        
        _list.pop_back();
        _list.push_front(value);
        _mapping[value] = _list.begin();
    }
    else
    {
    	//map.insert(make_pair<cache_node, list<cache_node::iterator>>)
    	_list.push_front(value);    	
    	list<cache_node>::iterator listIt = _list.begin();
    	
    	_mapping[value] = listIt;
    }
    
    return true;
}

int main(int argc, char* argv[])
{
   LRU l;
   
   for(int i=0;i<14;i++)
    l.addNode(i);
    
    cout<<l.lookup(12);
   
   return 0;
}
