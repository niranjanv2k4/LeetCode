class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, empty = 0;
        while (numBottles > 0) {
            res += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty -= numBottles * numExchange;
            if (empty >= numExchange) {
                int temp = empty / numExchange;
                numBottles += temp;
                empty -= temp * numExchange;
            }
        }
        return res;
    }
};