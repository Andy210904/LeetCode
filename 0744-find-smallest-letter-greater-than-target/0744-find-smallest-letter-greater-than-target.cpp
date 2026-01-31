class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target == 'z'){
            return letters[0];
        }
        int left = 0;
        int right = letters.size()-1;
        int ans = 0;
        while(left <= right){
            int mid = (left + right)/2;
            if(letters[mid] > target){
                right = mid-1;
                ans = mid;
            }
            else{
                left = mid+1;
            }
        }
        return letters[ans];
    }
};