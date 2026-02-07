class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> temp;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(!temp.empty() && s[i]=='a' && temp.top()=='b'){
                temp.pop();
                count++;
            }
            else{
                temp.push(s[i]);
            }
        }
        return count;
    }
};