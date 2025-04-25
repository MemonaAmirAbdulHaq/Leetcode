class Solution {
public:
 
   
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    // Return the palindrome substring
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(const string& s) {
    if (s.empty()) return "";

    string longest;
    for (int i = 0; i < s.size(); ++i) {
        // Check for longest odd-length palindrome
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.size() > longest.size()) {
            longest = oddPalindrome;
        }

        // Check for longest even-length palindrome
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.size() > longest.size()) {
            longest = evenPalindrome;
        }
    }

    return longest;
   
    }
};