class Solution {
public:
 int divide(int dividend, int divisor) {
        // Handle edge cases for overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow case
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to handle edge cases and work with absolute values
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long result = 0;

        // Perform subtraction in a loop, using bitwise shifting for optimization
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            absDividend -= tempDivisor;
            result += multiple;
        }

        // Apply the sign and ensure result fits in the integer range
        result = isNegative ? -result : result;

        return result > INT_MAX ? INT_MAX : (result < INT_MIN ? INT_MIN : result);
    }
};
        
    
