class Solution {
public: 
    string shortestCommonSupersequence(string str1, string str2) {
        string res = "";
        int a =str1.size();
        int b = str2.size();
        vector<vector<int>> result(a + 1, vector<int>(b + 1, 0));
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    result[i][j] = result[i - 1][j - 1] + 1;
                } else {
                    result[i][j] = max(result[i - 1][j], result[i][j - 1]);
                }
            }
        }
        int i = a;
        int j = b;
        while(i>0&&j>0){
            if(str1[i-1] == str2[j-1]){
                res+=str1[i-1];
                i--;
                j--;
            }
            else if(result[i-1][j] > result[i][j-1]){
                res += str1[i-1];
                i--;
            }
            else{
                res += str2[j-1];
                j--;
            }
        }
        while(i>0){
            res+=str1[i-1];
            i--;
        }
        while(j>0){
            res+=str2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};