class Solution {
public:
       void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find the next larger element to swap with nums[i]
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        std::swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the sequence after the swapped index
    std::reverse(nums.begin() + i + 1, nums.end());
} 
    
};