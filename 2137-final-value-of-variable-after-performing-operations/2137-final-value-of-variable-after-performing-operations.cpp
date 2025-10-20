class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (string operation : operations) 
            res += (operation[1] == '+' ? 1 : -1);
        
        return res;
    }
};