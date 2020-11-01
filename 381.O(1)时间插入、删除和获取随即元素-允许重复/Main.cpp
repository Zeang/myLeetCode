#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

using namespace std;

class RandomizedCollection {
    unordered_map<int, unordered_set<int>> uMap;
    vector<int> nums;
    random_device e;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.emplace_back(val);
        uMap[val].insert(nums.size()-1);
        return uMap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = uMap.find(val);
        if(it == uMap.end())
            return false;
        int temp = *(uMap[val].begin());

        nums[temp] = nums.back();
        uMap[val].erase(temp);
        uMap[nums[temp]].erase(nums.size()-1);
        if(temp < nums.size()-1){
        	uMap[nums[temp]].insert(temp);
        }

        if(uMap[val].size() == 0)
        	uMap.erase(it);
        nums.pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[e() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
	RandomizedCollection* obj = new RandomizedCollection();
	bool param_1 = obj->insert(0);
	bool param_2 = obj->insert(1);
	// cout << param_1 << " " << param_2 << endl;
	// cout << obj->getRandom() << endl;
	obj->remove(0);
	obj->insert(2);
	obj->remove(1);
	cout << obj->getRandom() << endl;

	return 0;
}