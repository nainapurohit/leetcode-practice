class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum=0, currSum=0;
        for (int i=0; i<k; i++){  //sum of first k elements
            maxSum+=nums[i];
        }
        currSum=maxSum;
        for (int i=k; i<nums.size(); i++){  //sliding window for sum
            currSum-=nums[i-k];
            currSum+=nums[i];
            maxSum=max(maxSum,currSum);
        }
        double average=maxSum*1.0/k;  //to get decimal places multiply 1.0
        return (average);
    }
};