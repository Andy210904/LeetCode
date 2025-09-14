class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int> temp;
        for (int i=0; i<wordlist.size(); i++) {
            temp[wordlist[i]]++; 
        }
        vector<string> lowerWordlist(wordlist.size());
        for (int i=0; i<wordlist.size(); i++) {
            lowerWordlist[i] = wordlist[i];
            transform(lowerWordlist[i].begin(), lowerWordlist[i].end(), lowerWordlist[i].begin(), ::tolower);
        }
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<string> res;
        for (int i=0; i<queries.size(); i++) {
            if (temp.find(queries[i]) != temp.end()) { 
                res.push_back(queries[i]);
            } else {
                string quer = queries[i];
                transform(quer.begin(), quer.end(), quer.begin(), ::tolower);
                bool enter = true;
                for (int j=0; j<wordlist.size(); j++) { 
                    if (quer == lowerWordlist[j]) {
                        res.push_back(wordlist[j]); 
                        enter = false;
                        break;
                    }
                }
                if (enter) { 
                    bool enter1 = true;
                    for (int j=0; j<wordlist.size(); j++) {
                        if (lowerWordlist[j].size() != quer.size()) continue;
                        bool ok = true;
                        for (int k=0; k<quer.size(); k++) {
                            if (lowerWordlist[j][k] != quer[k]) {
                                if (!(vowels.count(lowerWordlist[j][k]) && vowels.count(quer[k]))) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (ok) {
                            res.push_back(wordlist[j]);
                            enter1 = false;
                            break;
                        }
                    }
                    if (enter1) res.push_back("");
                }
            }
        }
        return res;
    }
};
