class Spreadsheet {
    vector<vector<int>> res;

    pair<int, int> getCell(string& s, int& idx) {
        int col = s[idx++] - 'A';
        int row = 0;
        while (idx < s.size() && isdigit(s[idx])) {
            row = row * 10 + (s[idx] - '0');
            idx++;
        }
        return {row - 1, col};
    }

    int getVal(string& formula, int& idx) {
        if (idx >= formula.size())
            return 0;
        bool pos = true;
        if (formula[idx] == '-') {
            pos = false;
        }
        idx++;

        if (isdigit(formula[idx])) {
            int val = 0;
            while (idx < formula.size() && isdigit(formula[idx])) {
                val = val * 10 + formula[idx] - '0';
                idx++;
            }
            return pos ? val : -val;
        }
        auto [r, c] = getCell(formula, idx);
        return pos ? res[r][c] : -res[r][c];
    }

public:
    Spreadsheet(int rows) {
        while (rows--) {
            res.push_back(vector<int>(26, 0));
        }
    }

    void setCell(string cell, int value) {
        int idx = 0;
        auto [r, c] = getCell(cell, idx);
        res[r][c] = value;
    }

    void resetCell(string cell) {
        int idx = 0;
        auto [r, c] = getCell(cell, idx);
        res[r][c] = 0;
    }

    int getValue(string formula) {
        int i = 0;
        int res = 0;
        while (i < formula.size()) {
            res += getVal(formula, i);
        }
        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */