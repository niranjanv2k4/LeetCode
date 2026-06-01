class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() == 1)
            return cost[0];

        sort(cost.begin(), cost.end());
        int res = 0;
        for (int i = 0; i < cost.size(); i++) {
            if((i + 1) % 3)
                res += cost[cost.size() - 1 - i];
        }
        
        return res;
    }
};