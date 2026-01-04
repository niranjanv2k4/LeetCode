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
        for (int i = 2; i <= sqrt(n); i++) {
            if(i == sqrt(n)){
                res++;
                sum += i;
            }
            else if (n % i == 0) {
                res += 2;
                sum += (i + n / i);
            }
        }
        cout<<sum<<" "<<res<<endl;
        return res == 4 ? sum : 0;
    }
};