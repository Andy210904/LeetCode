class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k-1;
        double sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        double max = sum/k;
        while(right < nums.size()){
            double avg = sum / k;
            max = std::max(avg,max);
            right++;
            sum -= nums[left];
            left++;
            if(right < nums.size()){
                sum += nums[right];
            }
        }
        return max;
    }
};