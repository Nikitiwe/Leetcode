class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> prev={1,2,3,4,5,6,7,8,9}, ans;
        for (int i=1; i!=n; i++)
        {
            for (int j=0; j!=prev.size(); j++)
            {
                if (prev[j]%10+k<=9) ans.push_back(prev[j]*10+prev[j]%10+k);
                if (k!=0&&prev[j]%10-k>=0) ans.push_back(prev[j]*10+prev[j]%10-k);
            }
            prev=ans;
            ans.clear();
        }
        return prev;
    }
};