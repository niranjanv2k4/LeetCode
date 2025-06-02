class Solution {
public:
    int candy(vector<int>& ratings) {
        
        const int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] += left[i - 1];
            if (ratings[n - 1 - i] > ratings[n - 1 - (i - 1)])
                right[n - 1 - i] += right[n - 1 - (i - 1)];
        }

        int res = 0;
        for (int i = 0; i < n; i++) 
            res += max(left[i], right[i]);
        
        return res;
    }
};