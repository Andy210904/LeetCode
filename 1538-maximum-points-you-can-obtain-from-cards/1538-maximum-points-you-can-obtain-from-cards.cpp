class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //intution is if we want k from front or back or the combinations we can move a window
        // of size n-k and we will get the required answer
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        int windowSize = n - k;
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        int minWindowSum = windowSum;
        int left = 0, right = windowSize;
        while (right < n) {
            windowSum -= cardPoints[left];
            windowSum += cardPoints[right];
            minWindowSum = min(minWindowSum, windowSum);
            left++;
            right++;
        }
        return total - minWindowSum; 
    }
};
