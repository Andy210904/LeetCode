class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> temp;
        for(char c : s){
            temp[c]++;
        }
        int odd_max = 0;
        int even_min = INT_MAX;
        int res = INT_MIN;
        for(auto pair : temp){
            if(pair.second % 2==0){
                even_min = min(even_min,pair.second);
            }
            else{
                odd_max = max(odd_max,pair.second);
            }
        }
        return odd_max-even_min;
    }
};