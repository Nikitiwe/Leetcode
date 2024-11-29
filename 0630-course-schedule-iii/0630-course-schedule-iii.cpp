bool ssort (vector<int> &a, vector<int> &b)
{
    if (a[1]!=b[1]) return a[1]<b[1];
    else return a[0]<b[0];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), ssort);
        priority_queue<int> q;
        int t=0, ans=0;
        for (int i=0; i!=c.size(); i++)
        {
            if (t+c[i][0]<=c[i][1])
            {
                ans++;
                t+=c[i][0];
                q.push(c[i][0]);
            }
            else if (q.size()>0&&c[i][0]<q.top()&&t-q.top()+c[i][0]<=c[i][1])
            {
                t+=c[i][0]-q.top();
                q.pop();
                q.push(c[i][0]);
            }
        }
        return ans;
    }
};