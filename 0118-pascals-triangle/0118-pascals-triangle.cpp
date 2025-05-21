class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> curr;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) 
                curr.push_back((j == 0 || j == i) ? 1 : result[i-1][j] + result[i-1][j - 1]);
            
            result.push_back(curr);
            curr.clear();
        }
        return result;
    }
};