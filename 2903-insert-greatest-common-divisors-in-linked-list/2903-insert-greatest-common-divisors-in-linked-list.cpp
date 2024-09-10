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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while(current->next!=nullptr){
            int gcd = std::gcd(current->val,current->next->val);
            ListNode* newnode = new ListNode();
            newnode->next = current->next;
            newnode->val = gcd;
            current->next = newnode;
            current = current->next->next; 
        }
        return head;
    }
};