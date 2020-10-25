#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

using namespace std;

struct keyValue{
    int key;
    int value;
};

class LRUCache {
private:
    unordered_map<int, list<keyValue>::iterator> hashMap;
    list<keyValue> li;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto itKey = hashMap.find(key);
        if(itKey == hashMap.end())
            return -1;
        auto it = itKey->second;
        li.splice(li.begin(), li, it);

        return it->value;
    }
    
    void put(int key, int value) {
        auto itKey = hashMap.find(key);
        if(itKey != hashMap.end())
        {
            itKey->second->value = value;
            li.splice(li.begin(), li, itKey->second);
            return;
        }

        auto it = li.insert(li.begin(), {key, value});
        hashMap[key] = it;
        if(li.size() > cap){
            hashMap.erase(li.back().key);
            li.pop_back();
        }
    }
};

int main(){
    LRUCache* cache = new LRUCache(1); /* 缓存容量 */ 

    cache->put(2, 1);
    cout << cache->get(2) << endl;
    // cout << cache->get(1) << endl;       // 返回  1
    cache->put(3, 2);    // 该操作会使得关键字 2 作废
    cout << cache->get(2) << endl;       // 返回 -1 (未找到)
    // cache->put(4, 4);    // 该操作会使得关键字 1 作废
    // cout << cache->get(1) << endl;       // 返回 -1 (未找到)
    cout << cache->get(3) << endl;       // 返回  3
    // cout << cache->get(4) << endl;       // 返回  4

}