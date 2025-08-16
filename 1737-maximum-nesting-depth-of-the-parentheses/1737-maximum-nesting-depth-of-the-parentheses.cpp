class Solution {
public:
    int maxDepth(string s) {
        int dep= 0;
        int cnt = 0;
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
                cnt++;
            }
            else if(s[i] == ')'){
                st.pop();
                cnt--;
            }
            dep = max(dep,cnt); 
        }
        return dep;
    }
};