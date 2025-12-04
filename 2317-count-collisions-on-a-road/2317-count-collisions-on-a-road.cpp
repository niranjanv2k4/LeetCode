class Solution {
public:
    int countCollisions(string dir) {
        stack<char> st;
        int res = 0;
        bool flag = false;
        for (char ch : dir) {
            if (ch == 'R') {
                st.push(ch);
                flag = false;
            } else if (ch == 'L') {
                if (flag) {
                    res++;
                } else {
                    if (!st.empty()) {
                        st.pop();
                        res += 2;
                        while (!st.empty()) {
                            st.pop();
                            res++;
                        }
                        flag = true;
                    }
                }
            } else {
                while (!st.empty()) {
                    st.pop();
                    res++;
                }
                flag = true;
            }
        }
        return res;
    }
};