class Solution {
public:
    bool containsPattern(vector<int>& arr, int n, int kk) {
        if (n*kk>arr.size()) return 0;
        for (int i=0; i<arr.size()-n*kk+1; i++)
        {
            string t;
            int c=1;
            for (int j=0; j<n; j++)
            {
                t+=to_string(arr[i+j])+' ';
            }
            for (int k=1; k<kk; k++)
            {
                string s;
                for (int j=0; j<n; j++) s+=to_string(arr[i+j+n*k])+' ';
                if (s==t) c++;
                else
                {
                    c=0;
                    break;
                }
            }
            if (c==kk) return 1;
        }
        return 0;
    }
};