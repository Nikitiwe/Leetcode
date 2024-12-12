class Solution {
public:
    int maximumLength(string s) {
        vector<priority_queue<int>> arr(26, priority_queue<int> () );
        int ans=-1, t=1;
        arr[s[0]-'a'].push(1);
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]==s[i-1])
            {
                t++;
                arr[s[i]-'a'].push(t);
            }
            else
            {
                t=1;
                arr[s[i]-'a'].push(t);
            }
        }
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i].size()>=3)
            {
                arr[i].pop();
                arr[i].pop();
                int c=arr[i].top();
                ans=max(ans, c);
            }
        }
        return ans;
    }
};