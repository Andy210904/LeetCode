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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        vector<int> ans(2, -1);
        if (!head || !head->next || !head->next->next) {
            return ans;
        }
        ListNode* prev = head;
        head = head->next;
        int dis = 1;
        while (head->next != nullptr) {
            if ((prev->val > head->val && head->next->val > head->val) ||
                (prev->val < head->val && head->next->val < head->val)) {
                criticalPoints.push_back(dis);
            }
            prev = prev->next;
            head = head->next;
            dis++;
        }
        if (criticalPoints.size() < 2) {
            return ans;
        }

        ans[1] = criticalPoints.back() - criticalPoints.front();
        int minDist = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }
        ans[0] = minDist;

        return ans;
    }
};