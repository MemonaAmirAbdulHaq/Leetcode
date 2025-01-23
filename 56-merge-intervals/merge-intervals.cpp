class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
        
        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());
        
        // Vector to store the merged intervals
        vector<vector<int>> merged;
        
        // Add the first interval to the merged list
        merged.push_back(intervals[0]);
        
        // Iterate through the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the last merged interval
            if (intervals[i][0] <= merged.back()[1]) {
                // Merge the intervals by updating the end time of the last merged interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // Otherwise, add the current interval to the merged list
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;    
    }
};