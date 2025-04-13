class Solution {
public:
    int countGoodNumbers(long long n) {
        long long size = n / 2;
        long long result = n % 2 == 0 ? 1 : 5;
        long long multiplier = 20;

        while (size > 0) {
            if (size % 2 == 1) 
                result = (result * multiplier) % 1000000007;
            
            size /= 2;
            multiplier = (multiplier * multiplier) % 1000000007;
        }

        return result;
    }
};