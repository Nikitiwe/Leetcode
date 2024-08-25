class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<string, int> m;
        string t, temp;
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            t=to_string(nums[i]);
            for (int a=0; a!=t.size(); a++)
            {
                for (int b=a+1; b<t.size(); b++)
                {
                    temp=t;
                    if (temp[a]!=temp[b])
                    {
                        swap(temp[a], temp[b]);
                        while (temp[0]=='0')
                        {
                            reverse(temp.begin(), temp.end());
                            temp.pop_back();
                            reverse(temp.begin(), temp.end());
                        }
                        if (m.count(temp)>0) ans+=m[temp];
                    }
                }
            }
            if (m.count(t)>0) ans+=m[t];
            //ans+=m.count(t);
            m[t]++;
        }
        //for (auto i=m.begin(); i!=m.end(); i++) if (i->second>1) ans+=(i->second-1)*i->second/2;
        return ans;
    }
};