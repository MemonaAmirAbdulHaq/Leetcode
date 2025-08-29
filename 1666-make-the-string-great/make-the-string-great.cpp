class Solution {
public:
    string makeGood(string s) {
         int j = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (j > 0 && abs(s[j - 1] - s[i]) == 32) {
            j--; 
        } else {
            s[j++] = s[i]; 
        }
    }
    return s.substr(0, j);
    }
};