class TaskManager {
    priority_queue<pair<int, int>> task;
    unordered_map<int, int> user, priority;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto temp : tasks) {
            add(temp[0], temp[1], temp[2]);
        }
    }

    void add(int userId, int taskId, int prio) {
        task.push({prio, taskId});
        user[taskId] = userId;
        priority[taskId] = prio;
    }

    void edit(int taskId, int newPriority) {
        task.push({newPriority, taskId});
        priority[taskId] = newPriority;
    }

    void rmv(int taskId) { priority[taskId] = -1; }

    int execTop() {
        while (!task.empty()) {
            auto curr = task.top();
            task.pop();
            if (curr.first == priority[curr.second]) {
                priority[curr.second] = -1;
                return user[curr.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */