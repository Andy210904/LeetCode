class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;  
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int curr = nums[i];
            while(!st.empty() && gcd(curr,st.top()) > 1){
                int a = st.top();
                st.pop();
                curr = lcm(curr,a);
            }
            st.push(curr);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};