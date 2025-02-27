class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0;
        unordered_set<int> temp(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                int a = arr[i], b = arr[j];
                int count = 2;
                while(temp.find(a + b) != temp.end()){
                    count++;
                    int next = a + b;
                    a = b;
                    b = next;
                }
                if(count > 2) { 
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};
