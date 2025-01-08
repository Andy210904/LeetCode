class Solution {
public:
    bool isPre_suff(string str1,string str2){
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1 > n2){
            return false;
        }
        int i=0;int j = 0;
        while(i != n1 && j != n2){
            if(str1[i] == str2[j]){
                i++;
                j++;
                continue;
            }
            else{
                return false;
            }
        }
        i = n1-1;j = n2-1;
        while(i >= 0 && j >= 0){
            if(str1[i] == str2[j]){
                i--;
                j--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPre_suff(words[i],words[j])){
                    cout<<words[i]<<words[j]<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};