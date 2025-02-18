class Solution {
public:
    string smallestNumber(string pattern) {
        string res ="";
        string temp = "123456789";
        pattern.insert(0,1,'I');
        int ind = 0;
        int id = 0;
        while(ind != pattern.size()){
            int cd = 0;
            if(pattern[ind] == 'I'){
                while(ind+1 < pattern.size() && pattern[ind+1] == 'D'){
                    cd++;
                    ind++;
                }
                if(cd==0){
                    res += temp[id];
                    id++;
                }
                else{
                    int t = cd;
                    while(cd !=0){
                        res += temp[id+cd];
                        cd--;
                    }
                    res += temp[id+cd];
                    id = id+t+1;
                }
                ind++;
            }
        }
        return res;
    }
};