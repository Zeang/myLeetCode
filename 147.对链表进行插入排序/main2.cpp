#include <iostream>
#include <climits>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};

int main(){
    Solution solution;
    ListNode* node1 = new ListNode(2147483647);
    ListNode* node2 = new ListNode(2147483646);
    // ListNode* node3 = new ListNode(1);
    // ListNode* node4 = new ListNode(3);
    node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    
    ListNode* ptr = solution.insertionSortList(node1);
    while(ptr){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    return 0;
}