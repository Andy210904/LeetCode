class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        int ind = 0;
        while(ind < words.size()){
            string res = "";
            int count = 0;
            vector<string> temp;
            for(int i=ind;i<words.size();i++){
                if(count + words[i].size() <= maxWidth){
                    temp.push_back(words[i]);
                    count += words[i].size();
                    count = count+1;
                    ind++;
                }
                else{
                    break;
                }
            }
            if(ind == words.size() || temp.size() == 1){
                for(int i=0;i<temp.size();i++){
                    res += temp[i];
                    if(i != temp.size()-1) res += ' ';
                }
                while(res.size() < maxWidth) res += ' ';
                out.push_back(res);
                continue; 
            }
            int space = maxWidth - count + temp.size();
            int num_space = temp.size()-1;
            int equal_space = space;
            int extra_space = 0;
            if(num_space != 0){
                equal_space = space / num_space;
                extra_space = space % num_space;
            }
            for(int i=0;i<temp.size();i++){
                res += temp[i];
                if(i != temp.size()-1){
                    for(int j=0;j<equal_space;j++){
                        res += ' ';
                    }
                    if(extra_space > 0){
                        res += ' ';
                        extra_space--;
                    }
                }
            }
            out.push_back(res);
        }
        return out;
    }
};
