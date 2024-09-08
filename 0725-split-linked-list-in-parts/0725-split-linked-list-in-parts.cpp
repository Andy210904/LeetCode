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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Calculate the length of the linked list
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        // Determine the size of each part and the remainder
        int partSize = count / k;
        int remainder = count % k;
        
        // Initialize the result vector with nullptrs
        vector<ListNode*> result(k, nullptr);
        curr = head;
        
        for (int i = 0; i < k && curr != nullptr; ++i) {
            // Start of the current part
            result[i] = curr;
            // Determine the size for the current part
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
            remainder--;

            // Move `curr` to the end of the current part
            for (int j = 1; j < currentPartSize; ++j) {
                if (curr != nullptr) {
                    curr = curr->next;
                }
            }

            // Break the link for the current part if necessary
            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;  // Break the link
                curr = nextPart;       // Move to the next part
            }
        }

        return result;
    }
};
