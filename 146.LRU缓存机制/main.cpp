#include <hash_map>
using namespace __gnu_cxx;

struct KeyValue{
    int first;
    int second;
};

class LRUCache {
private:
    hash_map<int, list<KeyValue>::iterator> hashMap;
    list<KeyValue> li;
    int cap;
public:
    LRUCache(int capacity) {
        hashMap.resize(capacity);
        cap = capacity;
    }
    
    int get(int key) {
        hash_map<int, list<KeyValue>::iterator>::iterator itt = hashMap.find(key);
        if(itt == hashMap.end())
            return -1;
        list<KeyValue>::iterator it = itt->second;
        int value = it->second;
        li.splice(li.begin(), li, it);
        return value;
    }
    
    void put(int key, int value) {
        hash_map<int, list<KeyValue>::iterator>::iterator itt = hashMap.find(key);
        if(itt != hashMap.end())
        {
            itt->second->second = value;
            li.splice(li.begin(), li, itt->second);
            return;
        }

        list<KeyValue>::iterator it = li.insert(li.begin(), {key, value});
        hashMap[key] = it;
        if(li.size() > cap){
            int key = li.back().first;
            li.pop_back();
            hashMap.erase(key);
        }
    }
};