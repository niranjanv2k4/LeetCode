class Solution {
public:
    
    long long distributeCandies(int n, int limit) {

        if ((float)n / limit > 3)
            return 0;
        if (n / limit == 3)
            return 1;
        if (n <= limit)
            return (long long)(n+2)*(n+1)/2;

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
            res += temp * ((i==0 || i==3)?1:3);
        }
        
        return res;
    }
};