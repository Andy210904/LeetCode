class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> fr(friends.begin(),friends.end());
        vector<int> res;
        for(int i=0;i<order.size();i++){
            if(fr.find(order[i]) != fr.end()){
                res.push_back(order[i]);
            }
        }
        return res;
    }
};