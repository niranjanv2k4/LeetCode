class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0)
            return "0";
        if(denominator == 1)
            return to_string(numerator);

        string res = "";
        bool flag = true;
        unordered_map<long long, int> mp;

        if ((numerator < 0) ^ (denominator < 0))
            res += '-';

        numerator = llabs(numerator);
        denominator = llabs(denominator);

        while (numerator) {
            long long rem = numerator % denominator;
            long long quo = numerator / denominator;
            res += to_string(quo);
            if (rem != 0 && flag) {
                res += '.';
                flag = false;
            }
            if (rem == 0) {
                break;
            }
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ')';
                break;
            }
            mp[rem] = res.size();
            numerator = 1LL * rem * 10;
        }
        return res;
    }
};