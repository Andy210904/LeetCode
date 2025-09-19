class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.assign(26,vector<int>(rows+1,0));
    }
    void setCell(string cell, int value) {
        char colum = cell[0];
        string num = cell.substr(1,cell.size());
        sheet[colum-'A'][stoi(num)] = value;
    }
    void resetCell(string cell) {
        char colum = cell[0];
        string num = cell.substr(1,cell.size());
        sheet[colum-'A'][stoi(num)] = 0;
    }
    int getValue(string formula) {
        string left = "";
        string right = "";
        int ind = 0;
        for(int i=1;i<formula.size();i++){
            if(formula[i] == '+'){
                ind = i;
                break;
            }
            left += formula[i];
        }
        for(int i=ind+1;i<formula.size();i++){
            right += formula[i];
        }
        
        int num1 = 0;
        if(isalpha(left[0])){
            char colum = left[0];
            string num = left.substr(1,left.size());
            num1 = sheet[colum-'A'][stoi(num)];
        }
        else{
            num1 = stoi(left);
        }
        int num2 = 0;
        if(isalpha(right[0])){
            char colum = right[0];
            string num = right.substr(1,right.size());
            num2 = sheet[colum-'A'][stoi(num)];
        }
        else{
            num2 = stoi(right);
        }
        return num1+num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */