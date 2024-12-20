class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> temp;
        for (int num : nums) {
            temp[num]++;
        }
        priority_queue<pair<int, int>> res1;   
        for (auto& pair : temp) {
            res1.push({pair.second, pair.first}); 
        }
        while (k > 0) {
            pair<int, int> curr = res1.top();
            res.push_back(curr.second); 
            res1.pop();
            k--;
        }
        return res;
    }
};
