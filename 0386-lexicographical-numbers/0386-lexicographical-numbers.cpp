class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            createEl(n, res, i);
        }
        return res;
    }
    void createEl(int n, vector<int>& res, int num) {
        if (num > n) {
            return;
        }
        res.push_back(num);
        for (int i = 0; i <= 9; i++) {
            createEl(n, res, num * 10 + i);
        }
    }
};