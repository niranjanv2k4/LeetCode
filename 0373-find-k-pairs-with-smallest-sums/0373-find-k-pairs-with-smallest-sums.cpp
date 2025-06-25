class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {

        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        vector<vector<int>> res;
        set<pair<int, int>> visited;
        
        q.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        for (k; k > 0; k--) {
            auto el = q.top();
            q.pop();
            i = el[1], j = el[2];
            res.push_back({nums1[i], nums2[j]});
            if (i + 1 < n1 && visited.find({i+1, j})==visited.end()) {
                visited.insert({i + 1, j});
                q.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
            if (j + 1 < n2 && visited.find({i, j+1})==visited.end()) {
                visited.insert({i, j+1});
                q.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return res;
    }
};