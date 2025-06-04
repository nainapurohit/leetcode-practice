class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //product except self implies produt of all elements to left and all elements to the right. so we can use suffix product array to store products on the right and then a variable to store prefix product while filling result array.
        vector <int> postProduct(nums.size()); // to store product of all the numbers to the right of number at index i of nums
        postProduct[nums.size()-1]=1; //set last value as 1 as no numbers after that
        for(int i=nums.size()-2;i>=0;i--){
            postProduct[i]=nums[i+1]*postProduct[i+1];
        }
        vector<int> result(nums.size());   //stores result
        result[0]=postProduct[0];
        int prod=nums[0];    //prod stores product of number at the left of the number
        for (int i=1;i<nums.size();i++){
            result[i]=postProduct[i]*prod;
            prod=prod*nums[i];
        }
        return result;
    }
};