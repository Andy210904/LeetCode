class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return -1;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        unordered_map<int, int> temp1; 
        unordered_map<int, int> temp2; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp1[mat[i][j]] = i;
                temp2[mat[i][j]] = j;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            row[temp1[arr[i]]]++;
            col[temp2[arr[i]]]++;
            if (row[temp1[arr[i]]] == n) {
                return i; 
            }
            if (col[temp2[arr[i]]] == m) {
                return i; 
            }
        }
        return -1; 
    }
};
