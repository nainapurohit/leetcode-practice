class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        for (int i=0; i<nums.size(); i++){
            count[nums[i]]++;  //storing frequency using hashing
        }
        vector<vector<int>> bucket(nums.size()+1);   //array that has frequency as index and elements of that frequency at that index
        for (auto &it: count){
            bucket[it.second].push_back(it.first);   //insert elements in array
        }
        vector<int> result;
        for (int i=nums.size();i>0;i--){  //traverse from higher frequency end and store rightmost k elements in result array
            if (bucket[i].size()==0) continue;
            
            while(bucket[i].size()>0 && k>0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};