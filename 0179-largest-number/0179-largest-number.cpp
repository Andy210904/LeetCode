class Solution {
public:
    static bool comparator(string &a, string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(),temp.end(),comparator);
        if (temp[0] == "0") return "0";
        string res;
        for(int i=0;i<temp.size();i++){
            res += temp[i];
        }
        return res;
    }
};