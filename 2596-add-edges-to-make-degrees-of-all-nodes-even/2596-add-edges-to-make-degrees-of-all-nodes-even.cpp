class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& s) {
        unordered_set<long long> m;
        vector<int> arr(n+1, 0);
        long long x=100001;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i][0]>s[i][1]) swap (s[i][0], s[i][1]);
            arr[s[i][0]]++;
            arr[s[i][1]]++;
            long long t=s[i][0]*x+s[i][1];
            m.insert(t);
        }
        vector<int> id;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]%2==1) id.push_back(i);
        }
        if (id.size()==0) return 1;
        if (id.size()>4) return 0;
        if (id.size()==4)
        {
            long long a=id[0]*x+id[1], b=id[2]*x+id[3];
            if (m.count(a)==0&&m.count(b)==0) return 1;
            else
            {
                long long c=id[0]*x+id[2], d=id[1]*x+id[3];
                if (m.count(c)==0&&m.count(d)==0) return 1;
                else
                {
                    long long e=id[0]*x+id[3], f=id[1]*x+id[2];
                    if (m.count(e)==0&&m.count(f)==0) return 1;
                    else return 0;
                }
            }
        }
        if (id.size()==2)
        {
            long long y=id[0]*x+id[1];
            if (m.count(y)==0) return 1;
            else
            {
                for (int i=1; i<id[0]; i++)
                {
                    long long a=i*x+id[0], b=i*x+id[1];
                    if (m.count(a)==0&&m.count(b)==0) return 1;
                }
                for (int i=id[0]+1; i<id[1]; i++)
                {
                    long long a=id[0]*x+i, b=i*x+id[1];
                    if (m.count(a)==0&&m.count(b)==0) return 1;
                }
                for (int i=id[1]+1; i<=n; i++)
                {
                    long long a=id[0]*x+i, b=id[1]*x+i;
                    if (m.count(a)==0&&m.count(b)==0) return 1;
                }
            }
        }
        return 0;
    }
};