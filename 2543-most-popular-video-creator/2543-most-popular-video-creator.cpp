class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long> m, count;
        unordered_map<string, string> vid;
        for (int i=0; i!=creators.size(); i++)
        {
            m[creators[i]]+=views[i];
            if (vid.count(creators[i])==0) {vid[creators[i]]=ids[i]; count[creators[i]]=views[i];}
            else
            {
                if (views[i]>count[creators[i]])
                {
                    count[creators[i]]=views[i];
                    vid[creators[i]]=ids[i];
                }
                else if (views[i]==count[creators[i]]) vid[creators[i]]=min(vid[creators[i]], ids[i]);
            }
        }
        long pop=0;
        for (auto i=m.begin(); i!=m.end(); i++) pop=max(pop, i->second);
        vector<vector<string>> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==pop) ans.push_back({i->first, vid[i->first]});
        }
        return ans;
    }
};