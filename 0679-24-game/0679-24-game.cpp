class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;
        for (int val : cards) {
            temp.push_back(val);
        }
        return recurse(temp);
    }

    bool recurse(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0]-24)<1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                vector<double> temp;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        temp.push_back(nums[k]);
                    }
                }
                double one = nums[i], two = nums[j];

                temp.push_back(one * two);
                if (recurse(temp)) {
                    return true;
                }
                temp.pop_back();
                temp.push_back(one - two);
                if (recurse(temp)) {
                    return true;
                }
                temp.pop_back();
                temp.push_back(one + two);
                if (recurse(temp)) {
                    return true;
                }
                temp.pop_back();
                if (fabs(two)>1e-6) {
                    temp.push_back(one / two);
                    if (recurse(temp)) {
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }
};