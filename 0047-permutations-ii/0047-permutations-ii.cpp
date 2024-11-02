class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<string> m;
        string s;
        for (int i=0; i!=nums.size(); i++)
        {
            nums[i]+=10;
            s+=to_string(nums[i])+' ';
        }
        m.insert(s);
        int n=nums.size(), nn=n;
        vector<vector<int>> ans;
        while (nn>1)
        {
            nn--;
            n*=nn;
        }
        while (n>0)
        {
            s="";
            next_permutation(nums.begin(), nums.end());
            for (int i=0; i!=nums.size(); i++)
            {
                s+=to_string(nums[i])+' ';
            }
            m.insert(s);
            n--;
        }
        vector<int> a;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans.push_back(a);
            int t=0;
            s=*i;
            for (int j=0; j!=s.size(); j++)
            {
                if (s[j]==' ')
                {
                    ans[ans.size()-1].push_back(t-10);
                    t=0;
                }
                else
                {
                    t*=10;
                    t+=s[j]-'0';
                }
            }
        }
        return ans;
    }
};