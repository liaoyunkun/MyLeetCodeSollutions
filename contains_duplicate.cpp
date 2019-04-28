class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> indicator;
        pair< set<int>::iterator,bool> ptr;
        for(auto it=nums.begin();it<nums.end();it++){
            ptr = indicator.insert(*it);
            if(!ptr.second){
                return true;
            }
        }
        return false;
    }
};