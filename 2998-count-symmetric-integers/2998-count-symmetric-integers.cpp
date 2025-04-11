class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low;i<=high;i++){
            string num = to_string(i);
            if(num.size()%2==1){
                continue;
            }
            else{
                int s1 = 0;
                int s2 = 0;
                for(int i =0;i<num.size()/2;i++){
                    s1 += num[i] -'0';
                }
                for(int i =num.size()/2;i<num.size();i++){
                    s2 += num[i] -'0';
                }
                if(s1==s2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};