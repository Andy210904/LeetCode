class Solution {
public:
    int subs_less_than_k(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int,int> map;
        int cnt = 0;
        while(right < nums.size()) {
            map[nums[right]]++;
            while(map.size() > k) {
                map[nums[left]]--;
                if(map[nums[left]] == 0)
                    map.erase(nums[left]);

                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subs_less_than_k(nums,k) - subs_less_than_k(nums,k-1);
    }
};