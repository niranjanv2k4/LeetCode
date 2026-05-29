class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        
        for(int el : nums)
            res = min(res, find_sum(el));
        
        return res;
    }

    int find_sum(int n){
        int res = 0;
        while(n > 0){
            res += (n % 10);
            n /= 10;
        }
        return res;
    }
};