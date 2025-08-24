class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int count = 1;
        int n = citations.size();
        for(int i=0;i<n;i++){
            if(citations[i] >= count){
                count++;
            }
        }
        return count-1;
    }
};