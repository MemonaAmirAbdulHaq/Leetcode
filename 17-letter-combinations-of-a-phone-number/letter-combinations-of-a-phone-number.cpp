

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;
        backtrack(digits, phone, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &digits, const vector<string> &phone, int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, phone, index + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};

