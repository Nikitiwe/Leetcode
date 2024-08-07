class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        if (b.size()==1) return b;
        unordered_map<int, int> m;
        int a=0, id;
        for (int i=0; i!=b.size(); i++)
        {
            m[b[i]]++;
            if (m[b[i]]>a)
            {
                id=b[i];
                a=m[b[i]];
            }
        }
        int i;
        for (i=0; i<b.size(); i=i+2)
        {
            b[i]=id;
            m[b[i]]--;
            if (m[b[i]]==0)
            {
                m.erase(b[i]);
                break;
            }
        }
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            while (it->second>0)
            {
                i=i+2;
                if (i>=b.size()) i=1;
                b[i]=it->first;
                it->second--;
            }
        }
        return b;
    }
};