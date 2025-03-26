/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; 
        
        int index = 1;
        ListNode* odd = new ListNode();   
        ListNode* even = new ListNode(); 
        ListNode* oddHead = odd, *evenHead = even; 
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (index % 2 == 1) {
                odd->next = curr;
                odd = odd->next;
            } else {
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            index++;
        }
        even->next = nullptr;   
        odd->next = evenHead->next; 
        return oddHead->next;  
    }
};
