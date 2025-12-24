class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int tot = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), [](int& a, int& b){
            return a>b;
        });

        int idx = 0;
        while(tot>0)
            tot -= capacity[idx++];

        return idx;
    }
};