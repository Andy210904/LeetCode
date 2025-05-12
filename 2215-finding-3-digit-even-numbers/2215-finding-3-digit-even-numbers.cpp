class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        unordered_map<int,int> temp;
        for(int i=0;i<digits.size();i++){
            temp[digits[i]]++;
        }
        for(int i=100;i<1000;i++){
            int a = i;
            bool s = true;
            unordered_map<int,int> temp1 = temp;
            while(a!=0){
                int x = a % 10;
                a = a/10;
                if(temp1.find(x)==temp1.end()){
                    s= false;
                }
                else{
                    if(temp1[x]!=0){
                        temp1[x]--;
                    }
                    else{
                        s = false;
                    }
                }
            }
            if(s && i % 2==0){
                res.push_back(i);
            }
        }
        return res;
    }
};