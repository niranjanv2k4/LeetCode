class Solution {
public:
    
    long long distributeCandies(int n, int limit) {

        if ((float)n / limit > 3)
            return 0;
        if (n / limit == 3)
            return 1;
        if (n <= limit)
            return (long long)(n+2)*(n+1)/2;

        vector<long long> fac(4, 1);
        fac[0]=fac[3]=1;
        fac[1]=fac[2]=3;

        bool flag = false;
        long long res = 0, val, temp;

        limit+=1;
        for (int i = 0; i <= 3; i++) {
            val = n - i*limit;
            if (val < 0)
                break;
            temp = (val+2)*(val+1)/2;
            if (flag)
                temp = -temp;
            flag = !flag;
            res += temp * fac[i];
        }
        
        return res;
    }
};