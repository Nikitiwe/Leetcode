class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& nums) {
        vector<vector<int>> arr;
        unordered_map<string, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i][0])==0)
            {
                vector<int> a(1440, 0);
                arr.push_back(a);
                m[nums[i][0]]=arr.size()-1;
            }
            int t=(nums[i][1][0]-'0')*600+(nums[i][1][1]-'0')*60+(nums[i][1][2]-'0')*10+(nums[i][1][3]-'0');
            arr[m[nums[i][0]]][t]++;
            if (t+60<1440) arr[m[nums[i][0]]][t+60]--;
        }
        vector<string> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            for (int j=1; j!=1440; j++)
            {
                arr[m[i->first]][j]+=arr[m[i->first]][j-1];
                if (arr[m[i->first]][j]>=3)
                {
                    ans.push_back(i->first);
                    break;
                }
            }
        }
        return ans;
    }
};