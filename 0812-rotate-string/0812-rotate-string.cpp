class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string result=s+s;
        if(result.find(goal) == string :: npos){
            return false;
        }
        return true;
    }
};