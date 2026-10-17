class Solution {
public:
    int minSwaps(vector<int>& nums) {
        map<int, vector<int>> temp;
        for (int num : nums) {
            int n = num;
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            temp[sum].push_back(num);
        }
        for (auto& p : temp) {
            sort(p.second.begin(), p.second.end());
        }
        vector<int> arr;
        for (auto& p : temp) {
            for (int num : p.second) {
                arr.push_back(num);
            }
        }
        map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }
        vector<int> permutation;
        for (int num : arr) {
            permutation.push_back(pos[num]);
        }
        int n = permutation.size();
        vector<bool> visited(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = permutation[j];
            }

            cycles++;
        }
        return n - cycles;
    }
};