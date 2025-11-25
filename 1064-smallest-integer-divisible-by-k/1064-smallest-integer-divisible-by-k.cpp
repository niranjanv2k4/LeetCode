class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> st;
        int num = 1;
        int size = 1;
        while (st.find(num) == st.end()) {
            if (num % k == 0)
                return size;
            st.insert(num % k);
            size++;
            num = (num * 10 + 1)%k;
        }
        return -1;
    }
};