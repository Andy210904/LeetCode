class Solution {
public:
    void backtrack(int n,vector<string> &result,string res){
        if(res.size() == n*2){
            result.push_back(res);
            return;
        }
        backtrack(n,result,res+'(');
        backtrack(n,result,res+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string>FR;
        string res;
        backtrack(n,result,res);
        for(int i=0;i<result.size();i++){
            stack<char> temp;
            bool cor = true;
            for(int j=0;j<result[i].size();j++){
                if(result[i][j] == '('){
                    temp.push('(');
                }
                else if (result[i][j] == ')' && temp.empty()){
                    cor = false;
                    break;
                }
                else{
                    temp.pop();
                }
            }
            if(temp.empty() && cor){
                FR.push_back(result[i]);
            }
        }
        return FR;
    }
};