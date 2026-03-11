class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        int curr = 1, res = 0;

        while (n > 0) {
            if (!(1 & n))
                res += curr;
            curr *= 2;
            n >>= 1;
        }
        
        return res;
    }
};