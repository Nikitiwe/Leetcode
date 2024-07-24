class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans=1;
        int temp;
        unordered_map<int, long long> m;
        m.insert({tasks[0], 1});
        for (int i=1; i<tasks.size(); i++)
        {
            if (m.count(tasks[i])>0)
            {
                ans=max(m[tasks[i]]+space+1, ans+1);
                m[tasks[i]]=ans;
            }
            else
            {
                ans++;
                m.insert({tasks[i], ans});
            }
        }
        return ans;
    }
};