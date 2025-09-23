class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> versions1;
        vector<string> versions2;
        int n = version1.size();
        int m = version2.size();
        string temp = "";
        for(int i=0;i<n;i++){
            if(version1[i] == '.'){
                versions1.push_back(temp);
                temp = "";
            }
            else{
                temp += version1[i];
            }
        }
        versions1.push_back(temp);
        temp = "";
        for(int i=0;i<m;i++){
            if(version2[i] == '.'){
                versions2.push_back(temp);
                temp = "";
            }
            else{
                temp += version2[i];
            }
        }
        versions2.push_back(temp);
        if(versions1.size() != versions2.size()){
            int n1 = versions1.size();
            int m1 = versions2.size();
            if(versions1.size() > versions2.size()){
                for(int i=0;i<n1-m1;i++){
                    versions2.push_back("0");
                }
            }
            else{
                for(int i=0;i<m1-n1;i++){
                    versions1.push_back("0");
                }
            }
        }
        int res = 0;
        for(int i=0;i<versions1.size();i++){
            int v1 = stoi(versions1[i]);
            int v2 = stoi(versions2[i]);
            if(v1 > v2){
                return 1;
            }
            if(v2 > v1){
                return -1;
            }
        }
        return res;
    }
};