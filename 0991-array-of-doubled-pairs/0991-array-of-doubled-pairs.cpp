class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        vector<int> t;
        unordered_map<int, int> m;
        int temp, zero=0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i]>0)
            {
                t.push_back(arr[i]);
                m[arr[i]]++;
            }
            else if (arr[i]==0) zero++;
        }
        if (zero%2!=0) return 0;
        if (t.size()>0)
        {
            sort(t.begin(), t.end());
            int i=0;
            while (i<t.size()&&m.size()>0)
            {
                temp=2*t[i];
                if (m.count(t[i])>0&&m[t[i]]>0&&m.count(temp)>0&&m[temp]>0)
                {
                    m[temp]--;
                    m[t[i]]--;
                    if (m[temp]==0) m.erase(temp);
                    if (m[t[i]]==0) m.erase(t[i]);
                }
                else if (m.count(t[i])>0&&m[t[i]]>0) return 0;
                i++;
            }
        }
        m.clear();
        t.clear();
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i]<0)
            {
                t.push_back(arr[i]);
                m[arr[i]]++;
            }
        }
        if (t.size()>0)
        {
            sort(t.begin(), t.end());
            int i=0;
            while (i<t.size()&&m.size()>0)
            {
                temp=t[i];
                if (t[i]%2==0&&m.count(temp/2)>0&&m[temp/2]>0&&m.count(temp)>0&&m[temp]>0)
                {
                    m[temp]--;
                    m[temp/2]--;
                    if (m[temp]==0) m.erase(temp);
                    if (m[temp/2]==0) m.erase(temp/2);
                }
                else if (m.count(temp)>0&&m[temp]>0) return 0;
                i++;
            }
        }
        return 1;
    }
};