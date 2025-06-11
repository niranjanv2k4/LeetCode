class Solution {
public:
    int maxDifference(string s, int k) {
        const int n = s.size();
        int res = INT_MIN;
        for (char a = '0'; a < '5'; a++) {
            for (char b = '0'; b < '5'; b++) {
                if (a == b)
                    continue;

                auto [prefix_a, prefix_b] = computePrefix(s, a, b);
                vector<int> minIdx(4, -1);
                vector<int> minVal(4, INT_MAX);

                minVal[0] = minIdx[0] = 0;

                for (int end = k; end <= n; end++) {

                    int right_parity = getParity(prefix_a[end], prefix_b[end]);
                    int left_parity = right_parity ^ 0b10;

                    if (minVal[left_parity] != INT_MAX) {
                        if (prefix_b[minIdx[left_parity]] != prefix_b[end]) {
                            res = max(res, prefix_a[end] - prefix_b[end] -
                                               minVal[left_parity]);
                        }
                    }

                    int start = end - k + 1;
                    int parity = getParity(prefix_a[start], prefix_b[start]);
                    int start_diff = prefix_a[start] - prefix_b[start];

                    if(start_diff<minVal[parity]){
                        minVal[parity] = start_diff;
                        minIdx[parity] = start;
                    }
                }
            }
        }
        return res;
    }

    int getParity(int count_1, int count_2) {
        return (count_1 & 1) << 1 | count_2 & 1;
    }

    pair<vector<int>, vector<int>> computePrefix(const string& s, char a,
                                                 char b) {
        vector<int> prefix_a(s.size() + 1, 0);
        vector<int> prefix_b(s.size() + 1, 0);

        for (int i = 0; i < s.size(); i++) {
            prefix_a[i + 1] = prefix_a[i] + (s[i] == a);
            prefix_b[i + 1] = prefix_b[i] + (s[i] == b);
        }

        return {prefix_a, prefix_b};
    }
};