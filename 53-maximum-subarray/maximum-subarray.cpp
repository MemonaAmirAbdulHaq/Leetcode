class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int maxSum = nums[0]; // Initialize maxSum as the first element
    int currentSum = nums[0]; // Initialize currentSum as the first element

    for (size_t i = 1; i < nums.size(); ++i) {
        // Update currentSum to include nums[i] or restart from nums[i]
        currentSum = std::max(nums[i], currentSum + nums[i]);
        // Update maxSum to the maximum of itself and currentSum
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;   
    }
};