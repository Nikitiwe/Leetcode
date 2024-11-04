class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i!=nums.size(); i++) nums[i]+=10;
        int n=nums.size(), a=2;
        while(n>1)
        {
            a*=2;
            n--;
        }
        vector<vector<int>> ans;
        vector<string> s;
        unordered_set<string> m;
        for (int i=0; i<a; i++)
        {
            int k=i, l=0;
            string t;
            while (k>0)
            {
                if (k%2==1) t+=to_string(nums[l])+' ';
                k/=2;
                l++;
            }
            if (m.count(t)==0)
            {
                s.push_back(t);
                m.insert(t);
            }
        }
        for (int i=0; i!=s.size(); i++)
        {
            vector<int> arr;
            int t=0;
            for (int j=0; j!=s[i].size(); j++)
            {
                if (s[i][j]!=' ')
                {
                    t*=10;
                    t+=s[i][j]-'0';
                }
                else
                {
                    arr.push_back(t-10);
                    t=0;
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};