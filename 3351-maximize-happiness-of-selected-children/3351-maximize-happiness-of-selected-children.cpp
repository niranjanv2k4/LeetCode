class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),
             [](int& a, int& b) { return a > b; });
        
        long long res = 0, idx = 0, temp = 0;
        while (k-- && idx < happiness.size()) {
            if (happiness[idx] + temp > 0)
                res += happiness[idx] + temp;
            temp--;
            idx++;
        }
        return res;
    }
};