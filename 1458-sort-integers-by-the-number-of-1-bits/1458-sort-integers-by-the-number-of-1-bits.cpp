class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int c1 = 0, c2 = 0;
            int temp = a;
            while(temp > 0){
                if(temp & 1)
                    c1++;
                temp >>= 1;
            }

            temp = b;
            while(temp > 0){
                if(temp & 1)
                    c2++;
                temp >>= 1;
            }

            if(c1 == c2)
                return a < b;
                
            return c1 < c2;
        });
        return arr;
    }
};