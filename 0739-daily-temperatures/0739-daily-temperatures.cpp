class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        int count, wasit;
        for (int i=0; i!=temp.size()-1; i++)
        {
            if (temp[i]==100) ans.push_back(0);
            else if ( (ans.size()!=0) && (temp[i]>=temp[i-1]) && (ans.back()==0) ) {ans.push_back(0);}
            else if ( (ans.size()!=0) && (temp[i]==temp[i-1]) ) {ans.push_back(ans.back()-1);}
            else
            {
                count=1;
                wasit=0;
                for (int j=i+1; j!=temp.size(); j++)
                {
                    if (temp[j]>temp[i]) {ans.push_back(count); wasit=1; break;}
                    else count++;
                }
                if (wasit==0) ans.push_back(0);
            }
        }
        ans.push_back(0);
        return ans;
    }
};