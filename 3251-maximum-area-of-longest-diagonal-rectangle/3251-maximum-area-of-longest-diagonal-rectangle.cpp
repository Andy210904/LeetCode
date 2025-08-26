class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea = 0;
        int maxdiag = 0;
        int n = dimensions.size();
        for(int i=0;i<n;i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diag = l*l+ w*w;
            if(diag > maxdiag){
                maxdiag = diag;
                maxarea = (l*w);
            }
            else if (diag == maxdiag){
                maxarea = max(maxarea,l*w);
            }
        }
        return maxarea;
    }
};