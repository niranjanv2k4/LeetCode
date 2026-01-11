class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
            arr[0][i] = matrix[0][i] == '0' ? 0 : 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = matrix[i][j] == '0' ? 0 : arr[i - 1][j] + 1;
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> left(m), right(m);
            stack<int> st;
            for (int j = 0; j < m; j++) {
                while (!st.empty() && arr[i][st.top()] >= arr[i][j]) {
                    st.pop();
                }
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            while (!st.empty())
                st.pop();
            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && arr[i][st.top()] >= arr[i][j]) {
                    st.pop();
                }

                right[j] = st.empty() ? m : st.top();
                st.push(j);
            }

            for (int j = 0; j < m; j++) {
                int width = right[j] - left[j] - 1;
                res = max(res, width * arr[i][j]);
            }
        }
        return res;
    }
};