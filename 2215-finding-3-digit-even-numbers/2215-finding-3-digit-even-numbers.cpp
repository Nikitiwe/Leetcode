class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        unordered_set<int> m;
        for (int i=0; i!=d.size(); i++)
        {
            for (int j=i+1; j<d.size(); j++)
            {
                for (int k=j+1; k<d.size(); k++)
                {
                    if (d[i]%2==0)
                    {
                        if (d[j]>0) m.insert(d[j]*100+d[k]*10+d[i]);
                        if (d[k]>0) m.insert(d[j]*10+d[k]*100+d[i]);
                    }
                    if (d[j]%2==0)
                    {
                        if (d[i]>0) m.insert(d[i]*100+d[k]*10+d[j]);
                        if (d[k]>0) m.insert(d[i]*10+d[k]*100+d[j]);
                    }
                    if (d[k]%2==0)
                    {
                        if (d[j]>0) m.insert(d[j]*100+d[i]*10+d[k]);
                        if (d[i]>0) m.insert(d[j]*10+d[i]*100+d[k]);
                    }
                }
            }
        }
        vector<int> ans;
        for (auto i=m.begin(); i!=m.end(); i++) ans.push_back(*i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};