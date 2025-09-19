class RandomizedSet {
public:
    unordered_map<int,int> result;
    vector<int> keysWithOne;
    RandomizedSet() {  
    }
    bool insert(int val) {
        if(result[val]==0){
            result[val]++;
            keysWithOne.push_back(val);
            return true;
        }
        else{
            return false;
        }   
    }
    bool remove(int val) {
        if(result[val]==1){
            result[val]=0;
            auto it = std::remove(keysWithOne.begin(), keysWithOne.end(), val);
            keysWithOne.erase(it, keysWithOne.end());
            return true;
        }
        else{
            return false;
        }   
    }
    int getRandom() {
        if (keysWithOne.empty()) {
            return -1;
        }
        return keysWithOne[rand() % keysWithOne.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */