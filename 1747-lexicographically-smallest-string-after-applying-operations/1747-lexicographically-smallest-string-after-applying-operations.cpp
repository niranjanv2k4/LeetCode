class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        queue<string> q;
        unordered_set<string> st;
        string res = s;
        int n = s.size();

        q.push(s);
        st.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            res = min(res, curr);

            string temp = curr;
            for (int i = 1; i < n; i+=2) {
                temp[i] = (temp[i] - '0' + a) % 10 + '0';
            }

            if (st.find(temp) == st.end()) {
                st.insert(temp);
                q.push(temp);
            }

            temp = curr.substr(n-b) + curr.substr(0, n-b);
            if(st.find(temp) == st.end()){
                st.insert(temp);
                q.push(temp);
            }
        }
        return res;
    }
};