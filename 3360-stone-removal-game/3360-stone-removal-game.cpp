class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }
        else if(n >= 10 && n < 19){
            return true;
        }
        else if(n >= 19 && n < 27){
            return false;
        }
        else if(n >= 27 && n < 34){
            return true;
        }
        else if(n >= 34 && n < 40){
            return false;
        }
        else if(n >= 40 && n < 45){
            return true;
        }
        else if(n >= 45 && n < 49){
            return false;
        }
        else if(n >= 49 && n < 52){
            return true;
        }
        else if(n >= 52 && n < 54){
            return false;
        }
        else if(n >= 54 && n < 55){
            return true;
        }
        else{
            return false;
        }
    }
};