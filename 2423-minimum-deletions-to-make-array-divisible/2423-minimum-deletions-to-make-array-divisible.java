class Solution {
    public int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    public int minOperations(int[] nums, int[] numsDivide) {
        int gcd1 = numsDivide[0];
        for(int i=1;i<numsDivide.length;i++){
            gcd1 = gcd(gcd1,numsDivide[i]); 
        }
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            if(gcd1 % nums[i] == 0){
                return i;
            }
        }
        return -1;
    }
}