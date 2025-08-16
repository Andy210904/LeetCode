class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        priority_queue<pair<int,char>> pq;
        int cnt = 1;
        char c = s[0];
        int num = s.size();
        int ind = 1;
        while(num > 0){
            if(s[ind] == c){
                cnt++;
            }
            else{
                pq.push({cnt,c});
                c = s[ind];
                cnt = 1;
            }
            ind++;
            num--;
        }
        string res = "";
        while(!pq.empty()){
            auto [cnt1,c1] = pq.top();
            pq.pop();
            for(int i=0;i<cnt1;i++){
                res += c1;
            }
        }
        return res;
    }
};