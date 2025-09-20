class Router {

    map<vector<int>, deque<vector<int>>::iterator> mp;
    deque<vector<int>> q;
    map<int, vector<int>> count;

    int memLimit = 0;

public:
    Router(int memoryLimit) { memLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> temp = {source, destination, timestamp};
        if (mp.count(temp)) {
            return false;
        }

        if (q.size() >= memLimit) {
            forwardPacket();
        }

        q.push_back(temp);
        mp[temp] = prev(q.end());
        count[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        auto temp = q.front();
        q.pop_front();

        mp.erase(temp);
        auto& ts = count[temp[1]];
        ts.erase(ts.begin());

        return temp;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (count.find(destination) == count.end()) {
            return 0;
        }

        int res = 0;

        int l = (lower_bound(count[destination].begin(),
                             count[destination].end(), startTime) -
                 count[destination].begin());
        int r = (upper_bound(count[destination].begin(),
                             count[destination].end(), endTime) -
                 count[destination].begin());

        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */