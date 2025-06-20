class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> seen;
        for (int i=0;i<nums.size();i++){
            if(seen[nums[i]]==1){
                seen.erase(nums[i]);
            }
            else seen[nums[i]]=1;
        }
        return seen.begin()->first;
    }
};