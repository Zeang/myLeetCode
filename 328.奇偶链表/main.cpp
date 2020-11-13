class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode* ptr = head->next;
        int count = 1;
        while(ptr){
            if((count & 0x1) == 1 && ptr->next != nullptr){
                ListNode* temp = ptr->next;
                ptr->next = temp->next;
                oddTail->next = temp;
                oddTail = temp;
                temp->next = evenHead;
            }else{
                ptr = ptr->next;
            }
            ++count;
        }
        return head;
    }
};