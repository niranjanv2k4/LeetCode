class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res, prev;

        for (int i = 0; i <= rowIndex; i++) {
            res.clear();
            for (int j = 0; j <= i; j++) 
                res.push_back((j == 0 || j == i) ? 1 : prev[j] + prev[j - 1]);
            prev = res;
        }
        
        return res;
        
    }
};