class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> s;
        vector<int> prev_less(n), next_less(n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            prev_less[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            next_less[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        int mod = 1e9 + 7, res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_less[i];
            long long right = next_less[i] - i;
            res = (res + arr[i] * left % mod * right % mod) % mod;
        }
        return res;
    }
};