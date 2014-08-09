#include <iostream>
#include <list>
#include <map>

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node(int k=0, int v=0) : key(k), value(v) {}
    };
    
private:
    int _size;
    int _capacity;
    std::map<int, std::list<Node>::iterator> _map;
    std::list<Node> _list;
    
public:
    LRUCache(int capacity)
    {
        _size = 0;
        _capacity = capacity;
        _map = std::map<int, std::list<Node>::iterator>();
        _list.clear();
    }
    
    int get(int key)
    {
        std::map<int, std::list<Node>::iterator>::iterator iter = _map.find(key);
        if (iter == _map.end())
        {
            return -1;
        }
        _list.splice(_list.begin(), _list, iter->second);
        return iter->second->value;
    }
    
    void set(int key, int value)
    {
        int _value = get(key);
        if (_value != -1)
        {
            _list.begin()->value = value;
        }
        else
        {
            if (_size == _capacity)
            {
                _map.erase(_list.back().key);
                _list.pop_back();
                --_size;
            }
            
            ++_size;
            _list.push_front(Node(key, value));
            _map.insert(std::make_pair(key, _list.begin()));
        }
    }
};

int main(int argc, char **argv)
{
    LRUCache cache(2);
    std::cout << cache.get(2) << std::endl;
    cache.set(2, 6);
    std::cout << cache.get(1) << std::endl;
    cache.set(1, 5);
    cache.set(1, 2);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(2) << std::endl;
    
    return 0;
}
