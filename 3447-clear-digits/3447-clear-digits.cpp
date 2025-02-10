class Solution {
public:
    string clearDigits(string s) {
        while(true){
            int pos_num = 0;
            int pos_al=0;
            int is_pre = 0;
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                    pos_num = i;
                    is_pre = 1;
                }
            }
            if(is_pre == 0){
                break;
            }
            if(pos_num-1>=0){
                for(int i = pos_num;i>0;i--){
                    if(isalpha(s[i])){
                        pos_al = i;
                        break;
                    }
                }
                s.erase(pos_num,1);
                s.erase(pos_al,1);
            }
            else{
                break;
            }
            
        }
        return s;
    }
};