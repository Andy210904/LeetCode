class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        vector<int> onesIndices;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                onesIndices.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            int totalSteps = 0;
            for (int index : onesIndices) {
                totalSteps += abs(index - i);
            }
            result[i] = totalSteps;
        }
        return result;
    }
};