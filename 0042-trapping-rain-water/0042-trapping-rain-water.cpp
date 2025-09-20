class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightmax(n,0);
        rightmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i] > rightmax[i+1]){
                rightmax[i] = height[i];
            }
            else{
                rightmax[i] = rightmax[i+1];
            }
        }
        int lmax = height[0];
        int res = 0;
        for(int i=0;i<n;i++){
            if(height[i] < lmax && height[i] < rightmax[i]){
                res += (min(lmax,rightmax[i])-height[i]);
            }
            lmax = max(lmax,height[i]);
        }
        return res;
    }
};