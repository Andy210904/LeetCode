class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        while(k!=0){
            int x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
            k--;
        }
        long long res = 0;
        for(int i=0;i<gifts.size();i++){
            res += pq.top();
            pq.pop();
        }
        return res;
        
    }
};