class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int maxLen = 0, maxLenIdx = -1;
        const int n = words.size();
        vector<int> dp(n, 1);
        vector<int> track(n, -1);
        vector<string> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j])
                    continue;
                if (isSubsequence(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    track[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxLenIdx = i;
            }
        }

        while (maxLenIdx != -1) {
            result.push_back(words[maxLenIdx]);
            maxLenIdx = track[maxLenIdx];
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool isSubsequence(const string& a, const string& b) {
        if (a.size() != b.size())
            return false;
        int hammingDist = 0; 
        for (int k = 0; k < a.size() && hammingDist <= 1; k++) {
            if (a[k] != b[k])
                hammingDist++;
        }
        return hammingDist == 1;
    }
};