class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();
        int result = n, curr = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                curr++;
        }

        result = curr;

        for (int i = 0; i + k < n; i++) {
            if (blocks[i] == 'W' && blocks[i + k] == 'B') curr--;
            if (blocks[i] == 'B' && blocks[i + k] == 'W') curr++;
            
            result = min(result, curr);
        }

        return result;
    }
};