class Solution {
public:
    string robotWithString(string s) {

        const int n = s.size();
        stack<int> st;
        vector<char> arr(n);
        string res = "";

        arr[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            arr[i] = min(s[i], arr[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= arr[i]) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};