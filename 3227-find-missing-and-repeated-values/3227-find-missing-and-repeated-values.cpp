class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long long int sum = 0;
        long long int square = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                square += grid[i][j] * grid[i][j];
            }
        }

        long long int total = n * n;

        long long eq2 = (total * (total + 1) / 2 - sum);
        long long eq1 = (square - (total * (total + 1) * (2 * total + 1) / 6)) /
                        (sum - total * (total + 1) / 2);

        return {static_cast<int>((eq1 - eq2) / 2),
                static_cast<int>((eq1 + eq2) / 2)};
    }
};