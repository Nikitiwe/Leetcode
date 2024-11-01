class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<string> m;
        vector<vector<int>> ans;
        int a=2, n=nums.size();
        while (n>1) {a*=2; n--;}
        for (int k=1; k<a; k++)
        {
            vector<int> temp;
            int x=k, l=0;
            bool isit=1;
            while (x>0)
            {
                if (x%2==1)
                {
                    temp.push_back(nums[l]);
                }
                x/=2;
                l++;
                if (temp.size()>1&&temp[temp.size()-2]>temp[temp.size()-1])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1&&temp.size()>1)
            {
                string s;
                for (int i=0; i!=temp.size(); i++) s+=to_string(temp[i])+',';
                if (m.count(s)==0) ans.push_back(temp);
                m.insert(s);
            }
        }
        return ans;
    }
};