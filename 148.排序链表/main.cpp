#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return quickSort(head);
    }

    ListNode* quickSort(ListNode* node){
        auto ptr = node;
        auto leftHead = new ListNode(0);
        auto rightHead = new ListNode(0);
        auto mediumHead = new ListNode(0);
        auto left = leftHead;
        auto right = rightHead;
        auto medium = mediumHead;
        while(ptr){
            if(ptr->val > node->val){
                right->next = ptr;
                right = right->next;
            }else if(ptr->val < node->val){
                left->next = ptr;
                left = left->next;
            }else{
                medium->next = ptr;
                medium = medium->next;
            }
            ptr = ptr->next;
        }
        leftHead = leftHead->next;
        rightHead = rightHead->next;
        mediumHead = mediumHead->next;
        if(leftHead != nullptr && leftHead->next != nullptr){
            leftHead = quickSort(leftHead);
        }
        if(rightHead != nullptr && rightHead->next != nullptr)    
            rightHead = quickSort(rightHead);

        medium->next = rightHead;
        
        if(leftHead){
        	left->next = mediumHead;
        	return leftHead;
        }else{
        	return mediumHead;	
        }
    }
};

int main(){
	Solution solution;
	ListNode* node1 = new ListNode(-1);
	ListNode* node2 = new ListNode(5);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(0);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	ListNode* ptr = solution.sortList(node1);
	while(ptr){
		cout << ptr->val << " ";
		ptr = ptr->next;
	}

	return 0;
}