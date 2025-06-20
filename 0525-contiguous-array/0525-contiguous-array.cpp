class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLength=0;
        unordered_map <int,int> sumsIndex;
        sumsIndex[0]=-1;
        for (int i=0;i<nums.size();i++){
            sum+=(nums[i]==1?1:-1);
            if (sumsIndex.find(sum)!=sumsIndex.end()){
                if (maxLength<i-sumsIndex[sum]){
                    maxLength=i-sumsIndex[sum];
                }
            }
            else {
                sumsIndex[sum]=i;
            }

        }
        return maxLength;
    }
};