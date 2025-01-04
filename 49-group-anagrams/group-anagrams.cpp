class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string, vector<string>> anagramGroups;

    // Iterate through each string
    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end()); // Sort the string to use as a key
        anagramGroups[sortedStr].push_back(str); // Group anagrams together
    }

    vector<vector<string>> result;
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;    
    }
};