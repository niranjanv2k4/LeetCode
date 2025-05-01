class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());

        int low = 0;
        int high = min(tasks.size(), workers.size());
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(workers, mid, tasks, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return result;
    }

    bool canAssign(vector<int>& workers, int size, vector<int>& tasks,
                   int pills, int strength) {
        multiset<int> set(workers.end() - size, workers.end());

        int n = tasks.size(), count = 0;
        for (int i = size - 1; i >= 0 && !set.empty(); i--) {
            auto it = prev(set.end());
            if (*it >= tasks[i]) {
                count++;
                set.erase(it);
            } else if (pills > 0) {
                it = set.lower_bound(tasks[i] - strength);
                if (it != set.end() && *it + strength >= tasks[i]) {
                    pills--;
                    count++;
                    set.erase(it);
                }
            }
        }
        return count == size;
    }
};