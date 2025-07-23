class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string max_s = "ba", min_s = "ab";
        int max_val = y, min_val = x;
        if (x > y) {
            max_s = "ab";
            max_val = x;
            min_s = "ba";
            min_val = y;
        }
        int res = 0;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            while (st.size() >= 2) {
                char second = st.top();
                st.pop();
                char first = st.top();
                if (first == max_s[0] && second == max_s[1]) {
                    st.pop();
                    res += max_val;
                } else {
                    st.push(second);
                    break;
                }
            }
        }
        s.clear();
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        cout << s << " "<<res<<endl;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            while (st.size() >= 2) {
                char second = st.top();
                st.pop();
                char first = st.top();
                if (first == min_s[0] && second == min_s[1]) {
                    st.pop();
                    res += min_val;
                } else {
                    st.push(second);
                    break;
                }
            }
        }
        return res;
    }
};