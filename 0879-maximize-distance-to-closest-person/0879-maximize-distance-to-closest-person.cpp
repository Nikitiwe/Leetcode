class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int temp=0, ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==0) temp++;
            else
            {
                ans=temp;
                break;
            }
        }
        temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==0) temp++;
            else
            {
                ans=max(ans, (temp+1)/2);
                temp=0;
            }
        }
        ans=max(ans, temp);
        return ans;
    }
};