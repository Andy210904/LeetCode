class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] lis = new int[n]; 
        int[] cnt = new int[n]; 
        for (int i = 0; i < n; i++) {
            lis[i] = 1;
            cnt[i] = 1;
        }
        int maxLength = 1, result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j]; 
                    } else if (lis[j] + 1 == lis[i]) {
                        cnt[i] += cnt[j]; 
                    }
                }
            }
            maxLength = Math.max(maxLength, lis[i]);
        }
        for (int i = 0; i < n; i++) {
            if (lis[i] == maxLength) {
                result += cnt[i];
            }
        }
        return result;
    }
}
