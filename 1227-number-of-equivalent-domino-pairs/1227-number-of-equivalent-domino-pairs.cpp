class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
        }
        map<pair<int, int>, int> temp;
        for(int i = 0; i < dominoes.size(); i++) {
            temp[{dominoes[i][0], dominoes[i][1]}]++;
        }
        int count = 0;
        for (auto& [key, value] : temp) {
            if(value >= 2){
                count += value * (value - 1) / 2;
            }
        }
        return count;
    }
};
