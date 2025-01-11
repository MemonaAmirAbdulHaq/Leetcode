class Solution {
public:
    string multiply(string num1, string num2) {
      if (num1 == "0" || num2 == "0") return "0";

    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;  // Place unit's digit
            result[i + j] += sum / 10;    // Add carry to the next position
        }
    }

    string ans = "";
    for (int num : result) {
        if (!(ans.empty() && num == 0)) { // Skip leading zeros
            ans.push_back(num + '0');
        }
    }

    return ans;
   
    }
};