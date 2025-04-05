class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        unordered_map<int, int> m;
        for (int i=0; i!=l.size(); i++)
        {
            if (l[i] != -1)
            {
                if (m.count(l[i]) != 0) return 0;
                m[l[i]] = i;
            }
            if (r[i] != -1)
            {
                if (m.count(r[i]) != 0) return 0;
                m[r[i]] = i;
            }
        }
        int zerocount = 0;
        /*for (auto i = m.begin(); i != m.end(); i++)
        {
            if (m.count(i) != 0 && i->second == 0) arr[]
        }*/
        /*for (int i=0; i!=n; i++)
        {
            if (m.count(i) == 0) zerocount++;
        }
        if (zerocount == 1) return 1;
        else return 0;*/
        vector<int> arr(n, -1);
        for (int i=0; i!=n; i++)
        {
            int t = i;
            int c = 0;
            while (m.count(t) != 0)
            {
                t = m[t];
                c++;
                if (c > 10000) return 0;
            }
            arr[i] = t;
        }
        sort(arr.begin(), arr.end());
        //if (arr[0] != -1) return 0;
        //if (n>1 && arr[1] == -1) return 0;
        for (int i=1; i<n; i++) if (arr[i-1] != -1 && arr[i] != arr[i-1]) return 0;
        return 1;
    }
};