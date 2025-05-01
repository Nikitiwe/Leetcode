class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int ans = 0;
        priority_queue<int> q, next;
        next.push(-p[0][1]);
        for (int i=1; i<p.size(); i++)
        {
            if (p[i][0] > p[i-1][0])
            {
                while (next.size() > 0)
                {
                    q.push(next.top());
                    next.pop();
                }
            }
            while (q.size() > 0 && - q.top() < p[i][1])
            {
                q.pop();
                ans++;
            }
            next.push(-p[i][1]);
        }
        /*while (q.size() > 0 && - q.top() < p[p.size()-1][1])
            {
                q.pop();
                ans++;
            }*/
        return ans;
    }
};