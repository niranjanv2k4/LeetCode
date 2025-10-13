class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> st;
        for (string s : words) {
            if (!st.empty()) {
                vector<int> fre(26, 0);
                for (char c : s) {
                    fre[c - 'a']++;
                }
                string temp = st.top();
                for (char c : temp) {
                    fre[c - 'a']--;
                }
                if (isSame(fre)) {
                    continue;
                }
            }
            st.push(s);
        }
        vector<string> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isSame(vector<int>& fre) {
        return all_of(fre.begin(), fre.end(), [](int x) { return x == 0; });
    }
};