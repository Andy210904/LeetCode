class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev_sorted = "";
        for (auto &w : words) {
            string sorted_w = w;
            sort(sorted_w.begin(), sorted_w.end()); 
            if (sorted_w != prev_sorted) { 
                result.push_back(w);
                prev_sorted = sorted_w;
            }
        }
        return result;
    }
};
