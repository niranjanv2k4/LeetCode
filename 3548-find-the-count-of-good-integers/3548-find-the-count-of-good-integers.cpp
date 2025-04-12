class Solution {

    unordered_map<string, int> visited;
    unordered_map<int, long long> factorials;
    long long count = 0;

public:
    long long countGoodIntegers(int n, int k) {
        string first = string(n, '0');
        precomputeFactorials(n);
        kPalindrome(n, k);
        return count;
    }

    void kPalindrome(int n, int k) {

        int halfLen = (n + 1) / 2;
        int start = pow(10, halfLen - 1);
        int end = pow(10, halfLen);

        for (int i = start; i < end; ++i) {
            string half = to_string(i);
            string full = half;

            int skip = n % 2;
            for (int j = halfLen - 1 - skip; j >= 0; --j) {
                full += half[j];
            }

            if (stoll(full) % k == 0) {
                count += validPermutations(full, n);
            }
        }
    }

    int validPermutations(string& pal, int n) {
        unordered_map<int, int> map(10);
        for (char c : pal) {
            map[c - '0']++;
        }
        string key = "0000000000";
        for (int i = 0; i < 10; i++) {
            key[i] = map.count(i) ? map.at(i) + '0' : '0';
        }
        if (visited.find(key) != visited.end()) {
            return 0;
        }
        visited[key]++;
        int permutations = (n - map[0]) * factorials[n - 1];

        for (int i = 0; i < 10; i++) {
            permutations /= factorials[map[i]];
        }
        return permutations;
    }

    void precomputeFactorials(int n) {
        factorials[0] = factorials[1] = 1;
        for (int i = 2; i <= n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }
    }
};