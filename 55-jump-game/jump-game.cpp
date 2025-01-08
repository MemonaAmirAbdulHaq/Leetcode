class Solution {
public:
    bool canJump(vector<int>& nums) {
         int reachable = 0; // Tracks the furthest reachable index
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reachable) return false; // If the current index is not reachable, return false
            reachable = max(reachable, i + nums[i]); // Update the furthest reachable index
        }
        return true; 
    }
};