class Solution {
public:
    vector<vector<int>> generate(vector<int> nums){
        vector<vector<int>> result;
        for (int l = 0; l < nums.size(); l++) {
            for (int r = l + 1; r <= nums.size(); r++) { 
                auto start = nums.begin() + l;
                auto end = nums.begin() + r;
                vector<int> part(start, end); 
                vector<int> remaining(nums.begin(), nums.end());
                remaining.erase(remaining.begin() + l, remaining.begin() + r);
                for (int pos = 0; pos <= remaining.size(); pos++) {
                    vector<int> temp = remaining;
                    temp.insert(temp.begin() + pos, part.begin(), part.end());
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();
       queue<pair<vector<int>,int>> q;
       map<vector<int>,int> vis;
       q.push({nums1,0});
       vis[nums1] = 1;
       while(!q.empty()){
        vector<int> vec = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(vec == nums2){
            return steps;
        }
        vector<vector<int>> all_comb = generate(vec);
        for(auto vect : all_comb){
            if(vect != vec && vis[vect] != 1){
                q.push({vect,steps+1});
                vis[vect] = 1;
            }
        }    
       }
       return 0;
    }
};