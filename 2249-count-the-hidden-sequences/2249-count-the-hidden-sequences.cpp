class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {

        int n = difference.size();
        long long maxel = 1, minel = 1, prev = 1, curr;

        for(int c:difference){
            curr=c+prev;
            prev = curr;
            maxel = max(maxel, curr);
            minel = min(minel, curr);
        }

        maxel += (lower - minel);
        return maxel>upper?0:upper - maxel + 1;


    }
};