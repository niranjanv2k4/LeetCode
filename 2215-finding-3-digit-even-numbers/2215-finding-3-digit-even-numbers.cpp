class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> set;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if ((j == k) || (i == k) || digits[k] % 2 == 1)
                        continue;
                    set.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        vector<int> result;
        for (int el : set)
            result.push_back(el);
        sort(result.begin(), result.end());
        return result;
    }
};