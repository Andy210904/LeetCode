class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int ind = 0;
        int count = 0;
        int n = s.size();
        while(ind< n){
            string temp = "";
            for(int i=ind;i<ind+k;i++){
                if(i < n){
                    temp += s[i];
                }
            }
            count++;
            res.push_back(temp);
            ind = ind+k;
        }
        if(res[count-1].size() !=k){
            string temp = res[count-1];
            int n1 = temp.size();
            res.pop_back();
            for(int i=0;i<k-n1;i++){
                temp += fill;
            }
            res.push_back(temp);
        }
        return res;
    }
};