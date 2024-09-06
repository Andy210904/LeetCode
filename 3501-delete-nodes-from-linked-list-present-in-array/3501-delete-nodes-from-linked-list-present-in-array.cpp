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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> temp(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);  
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr->next != nullptr) {
            if (temp.find(curr->next->val) != temp.end()) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;  
            } else {
                curr = curr->next;
            }
        }
        ListNode* modifiedHead = dummy->next;
        delete dummy;  
        return modifiedHead;
    }
};
