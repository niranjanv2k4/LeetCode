class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        int size = n / 3;
        long long left = 0, right = 0;

        vector<long long> pref(nums.size(), 0), suff(nums.size(), 0);
        priority_queue<int> pq_pref;
        priority_queue<int, vector<int>, greater<int>> pq_suff;


        for (int i = 0; i < nums.size(); i++) {
            pq_pref.push(nums[i]);
            left += nums[i];
            if (pq_pref.size() > size) {
                left -= pq_pref.top();
                pq_pref.pop();
            }
            if (i >= size - 1)
                pref[i] = left;

            pq_suff.push(nums[n - 1 - i]);
            right += nums[n - 1 - i];
            if (pq_suff.size() > size) {
                right -= pq_suff.top();
                pq_suff.pop();
            }
            if (n - 1 - i <= n - size)
                suff[n - 1 - i] = right;
        }

        long long res = pref[size - 1] - suff[size];
        for (int i = size; i < n - size; i++) 
            res = min(res, pref[i] - suff[i + 1]);
        
        return res;
    }
};