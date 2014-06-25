/*#include <iostream>
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
*/

#include <unordered_map>
#include <list>
#include <cstddef>
#include <stdexcept>

template<typename key_t, typename value_t>
class lru_cache 
{
public:
	typedef typename std::pair<key_t, value_t> key_value_pair_t;
	typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;

	lru_cache(size_t max_size) :
		_max_size(max_size) 
	{
	}
	
	void put(const key_t& key, const value_t& value) 
	{
		auto it = _cache_items_map.find(key);
		
		if (it != _cache_items_map.end()) 
		{
			_cache_items_list.erase(it->second);
			_cache_items_map.erase(it);
		}
			
		_cache_items_list.push_front(key_value_pair_t(key, value));
		_cache_items_map[key] = _cache_items_list.begin();
		
		if (_cache_items_map.size() > _max_size) 
		{
			auto last = _cache_items_list.end();
			last--;
			_cache_items_map.erase(last->first);
			_cache_items_list.pop_back();
		}
	}
	
	const value_t& get(const key_t& key) 
	{
		auto it = _cache_items_map.find(key);
		if (it == _cache_items_map.end()) 
		{
			throw std::range_error("There is no such key in cache");
		} 
		else 
		{
			_cache_items_list.splice(_cache_items_list.begin(), _cache_items_list, it->second);
			return it->second->second;
		}
	}
	
	bool exists(const key_t& key) const 
	{
		return _cache_items_map.find(key) != _cache_items_map.end();
	}
	
	size_t size() const 
	{
		return _cache_items_map.size();
	}
	
private:
	std::list<key_value_pair_t> _cache_items_list;
	std::unordered_map<key_t, list_iterator_t> _cache_items_map;
	size_t _max_size;
};
