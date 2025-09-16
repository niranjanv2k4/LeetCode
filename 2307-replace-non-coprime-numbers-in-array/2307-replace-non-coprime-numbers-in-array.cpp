class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.push(nums[i]);
            while (st.size() > 1) {
                int el1 = st.top();
                st.pop();
                int el2 = st.top();
                st.pop();

                int temp = gcd(el1, el2);

                if (temp == 1) {
                    st.push(el2);
                    st.push(el1);
                    break;
                }

                long long lcm = 1LL * el1 / temp * el2;
                st.push((int)lcm);
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};