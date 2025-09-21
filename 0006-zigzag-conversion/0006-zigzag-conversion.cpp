class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> mat(numRows,vector<char>(1000,' '));
        int r = 0;
        int c = 0;
        int ind = 0;
        int n = s.size();
        while(n > 0){
            if(r == 0){
                for(int i=0;i<numRows && n > 0;i++){
                    mat[i][c] = s[ind];
                    ind++;
                    n--;
                }
                r = numRows-1;
                c++;
            }
            else{
                r--;
                if(r!=0){
                    mat[r][c] = s[ind];
                    ind++;
                    n--;
                }
                c++;
            }
        }
        string res = "";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<1000;j++){
                if(mat[i][j] != ' ' && mat[i][j] !='\0'){
                    res += mat[i][j];
                }
            }
        }
        return res;
    }
};