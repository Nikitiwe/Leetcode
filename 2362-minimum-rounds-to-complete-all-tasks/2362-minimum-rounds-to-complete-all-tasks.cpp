class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if (tasks.size()==1) return -1;
        sort(tasks.begin(), tasks.end());
        int ans=0, temp=1;
        for (int i=1; i!=tasks.size(); i++)
        {
            if (tasks[i]==tasks[i-1]) temp++;
            else
            {
                if (temp==1) return -1;
                else
                {
                    ans+=temp/3;
                    if (temp%3!=0) ans++;
                    temp=1;
                }
            }
        }
        if (temp==1) return -1;
        ans+=temp/3;
        if (temp%3!=0) ans++;
        return ans;
    }
};