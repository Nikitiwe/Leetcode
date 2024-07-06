class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.rbegin(), processorTime.rend());
        int m=0;
        for (int i=0; i!=tasks.size(); i++)
        {
            m=max(m, tasks[i]+processorTime[i/4]);
        }
        return m;
    }
};