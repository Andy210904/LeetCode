class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> temp;
        for (int i = 0; i < arr.size(); i++) {
            int remainder = (arr[i] % k + k) % k;  
            temp[remainder]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            int remainder = (arr[i] % k + k) % k;
            if (remainder == 0) {
                if (temp[remainder] % 2 != 0) {  
                    return false;
                }
            } 
            else if (temp[remainder] != temp[k - remainder]) {
                return false;
            }
        }
        return true;
    }
};
