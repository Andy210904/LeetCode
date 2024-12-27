class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int first = values[0];
        int max = 0;
        for(int i=1;i<values.size();i++){
            int second = values[i]-i;
            max = std::max(max,first+second);
            first = std::max(first,values[i]+i);
        }
        return max;
    }
};