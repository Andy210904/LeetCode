class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string word : words){
            int sum = 0;
            for(char ch : word){
                sum += weights[ch-'a'];
            }
            sum = sum % 26;
            sum = 25 - sum;
            res += sum + 'a';
        }
        return res;
    }
};