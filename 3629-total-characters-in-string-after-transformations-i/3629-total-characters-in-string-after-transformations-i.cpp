class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> map(26, 0);
        for (char c : s)
            map[c - 'a']++;
        for (t; t > 0; t--) {
            int temp = map[25];
            for (int i = 25; i > 0; i--) {
                map[i] = map[i - 1];
            }
            map[0] = temp;
            map[1] = (map[1] + temp) % 1000000007;
        }
        int result = 0;
        for (int freq : map) {
            result = (result + freq) % 1000000007;
        }
        return result;
    }
};