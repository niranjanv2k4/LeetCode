class Solution {
public:

    vector<vector<int>> pre;
    int m, n;
    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();
        vector<int> selected(n, -1);
        pre = vector<vector<int>> (n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = 0;
                for (int k = 0; k < m; k++) {
                    if (students[i][k] == mentors[j][k])
                        temp++;
                }
                pre[i][j]=temp;
            }
        }
        int res = 0;
        //return recurse(students, mentors, 0, selected, 0, res);
        recurse(students, mentors, 0, selected, 0, res);
        return res;
    }

    int recurse(vector<vector<int>>& students, vector<vector<int>>& mentors,
                 int idx, vector<int>& selected, int curr, int& sum) {
        if(idx==n){
            sum = max(sum, curr);
            return 0;
        }

        int maxVal = 0;
        for (int i = idx; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (selected[j] != -1)
                    continue;
                selected[j] = idx;
                maxVal = max(maxVal, recurse(students, mentors, i + 1, selected, curr + pre[i][j], sum))+pre[i][j];
                selected[j] = -1;
            }
        }
        return maxVal;
    }
};