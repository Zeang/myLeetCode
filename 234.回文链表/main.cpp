#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        int num = 0;
        ListNode* node = head;
        while(node){
            ++num, node = node->next;
        }
        node = head;
        ListNode* prev;
        ListNode* next;
        for(int i = 1; i < num; ++i){
            if(i > num/2){
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }else{
                prev = node;
                node = node->next;
            }
        }
        node->next = prev;
        prev = head;
        for(int i = 0; i < num/2; ++i){
            if(node->val != prev->val)
                return false;
            node = node->next;
            prev = prev->next;
        }
        return false;
    }
};

int main(){
    vector<int> v = {1, 2};
    ListNode* head = new ListNode(0);
    ListNode* node = head;
    for(int i = 0; i < v.size(); ++i){
        ListNode* temp = new ListNode(v[i]);
        node->next = temp;
        node = temp;
    }
    node = head->next;
    delete head;
    Solution solution;
    bool result = solution.isPalindrome(node);
    cout << result << endl;
}