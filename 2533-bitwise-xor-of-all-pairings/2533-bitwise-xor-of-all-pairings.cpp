class Solution {
public:
    string to_bi(int number) {
        return bitset<32>(number).to_string();
    }
    int biToInt(const string& binaryString) {
        return bitset<32>(binaryString).to_ulong(); 
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<long> req(32,0);
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            string temp = to_bi(nums1[i]);
            for(int i=0;i<32;i++){
                if(temp[i] == '1'){
                    req[i] = req[i]+m;
                }
            }
        }
        for(int i=0;i<m;i++){
            string temp = to_bi(nums2[i]);
            for(int i=0;i<32;i++){
                if(temp[i] == '1'){
                    req[i] = req[i]+n;
                }
            }
        }
        string binaryString(32, '0');
        for(int i=0;i<32;i++){
            if(req[i]!=0 && req[i]%2 == 1){
                binaryString[i] = '1';
            }
        }
        int result = biToInt(binaryString);
        return result;
    }
};