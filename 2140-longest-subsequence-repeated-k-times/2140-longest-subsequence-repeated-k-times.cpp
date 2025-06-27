class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, -1);
        for (char c : s) {
            if (freq[c - 'a'] == -1) {
                freq[c - 'a'] = count(s.begin(), s.end(), c);
            }
        }
        string usable = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k)
                usable += (i + 'a');
        }
        string res;
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (char c : usable) {
                string next = curr + c, temp;
                for (int i = 0; i < k; i++) {
                    temp += next;
                }
                if (isSubsequence(s, temp)) {
                    if (res.size() < next.size() ||
                        (res.size() == next.size() && res < next)) {
                        res = next;
                    }
                    q.push(next);
                }
            }
        }
        
        return res;
    }

    bool isSubsequence(const string& s, const string& sub) {
        int j = 0;
        for (char c : s) {
            if (c == sub[j])
                j++;
        }
        return j == sub.size();
    }
};