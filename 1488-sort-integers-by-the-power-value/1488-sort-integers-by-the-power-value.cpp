class Solution {
public:
    int getKth(int l, int h, int k) {
        unordered_map<int, int> m;
        vector<int> arr, arr2;
        for (int i=l; i<=h; i++)
        {
            int t=i, c=0;
            while (t>1)
            {
                if (t%2!=0)
                {
                    t*=3;
                    t++;
                }
                else t/=2;
                c++;
            }
            arr2.push_back(c);
            m[i]=c;
        }
        sort(arr2.begin(), arr2.end());
        int ans=arr2[k-1], count=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second<ans) count++;
            else if (i->second==ans) arr.push_back(i->first);
        }
        sort(arr.begin(), arr.end());
        return arr[k-1-count];
    }
};