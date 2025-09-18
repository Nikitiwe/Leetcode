class TaskManager {
public:
    unordered_map<int, int> p; // приоритет от задание
    priority_queue<tuple<int, int, int>> q; // очередь приоритет + taskId + userId
    unordered_map<int, int> uft; // юзер от задания

    TaskManager(vector<vector<int>>& tasks) {
        for (int i=0; i!=tasks.size(); i++)
        {
            int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
            uft[taskId] = userId;
            q.push({priority, taskId, userId});
            p[taskId] = priority;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        uft[taskId] = userId;
        q.push({priority, taskId, userId});
        p[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        q.push({newPriority, taskId, uft[taskId]});
        p[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        p.erase(taskId);
        uft.erase(taskId);
    }
    
    int execTop() {
        while(q.size() > 0)
        {
            auto [pri, tid, uid] = q.top();
            q.pop();
            if (p.count(tid) != 0)
            {
                int temppri = p[tid];
                if (temppri == pri)
                {
                    rmv(tid);
                    return uid;
                }
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