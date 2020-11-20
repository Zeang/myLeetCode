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
        ListNode* ptrHead = head;
        ListNode* ptrPrev = nullptr;
        while(ptrHead){
            ListNode* curr;
            ListNode* currPrev = nullptr;
            ListNode* ptr = ptrHead;
            ListNode* prev = nullptr;
            int val = INT_MAX;
            while(ptr){
                if(ptr->val <= val){
                    val = ptr->val;
                    curr = ptr;
                    currPrev = prev;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            if(curr != ptrHead){
                currPrev->next = curr->next;
                curr->next = ptrHead;
                if(ptrPrev){
                    ptrPrev->next = curr;
                }else{
                	head = curr;
                }
                ptrPrev = curr;
            }else{
                ptrPrev = ptrHead;
                ptrHead = ptrHead->next;
            }
        }
        return head;
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