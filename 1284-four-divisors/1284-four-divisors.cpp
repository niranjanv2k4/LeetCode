class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int el : nums) {
            res += countDivisor(el);
        }
        return res;
    }

    int countDivisor(int n) {
        int res = 2;
        int sum = 1 + n;
        for (int i = 2; i < sqrt(n); i++) {
            if (n % i == 0) {
                res += 2;
                sum += (i + n / i);
            }
        }
        if(pow(floor(sqrt(n)), 2) == n){
            res++;
            sum += sqrt(n);
        }
        
        return res == 4 ? sum : 0;
    }
};