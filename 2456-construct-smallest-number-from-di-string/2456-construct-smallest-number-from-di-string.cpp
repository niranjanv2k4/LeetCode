class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;

        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1);
            if (pattern[i] == 'I' || i == pattern.size()) {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};