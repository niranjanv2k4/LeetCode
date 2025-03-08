class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        string s;
        int n = blocks.size();
        int result = n, min = 0;

        for (int i = 0; i + k <= n; i++) {
            for (int j = i; j < k + i && j < n; j++) {
                if (blocks[j] == 'W') {
                    min++;
                }
            }

            result = min < result ? min : result;
            min = 0;
        }
        return result;
    }
};