class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 1);
        freq[n] = 1;

        int pref = n;

        long long res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                cnt += freq[pref];
                pref++;
            } else {
                pref--;
                cnt -= freq[pref];
            }
            freq[pref]++;
            res += cnt;
        }

        return res;

        return 0;
    }
};