class Solution {
public:
    string robotWithString(string s) {

        const int n = s.size();
        string st = "", res = "";
        vector<char> arr(n);

        arr[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            arr[i] = min(s[i], arr[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            while (st.size() != 0 && st.back() <= arr[i]) {
                res += st.back();
                st.pop_back();
            }
            st.push_back(s[i]);
        }

        reverse(st.begin(), st.end());
        res += st;

        return res;
    }
};