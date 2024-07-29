class Solution {
public:
    int numTilings(int n) {
        vector<long long> oo(n+2, 0), oc(n+1, 0), co(n+1, 0);
        oo[0]=1;
        for (int i=0; i!=n; i++)
        {
            oo[i+1]+=oo[i]; 
            oo[i+2]+=oo[i]; 
            oc[i+1]+=oo[i];
            co[i+1]+=oo[i];
            oc[i+1]+=co[i];
            co[i+1]+=oc[i];
            oo[i+2]+=co[i];
            oo[i+2]+=oc[i];

            oo[i+1]%=1000000007;
            oo[i+2]%=1000000007;
            co[i+1]%=1000000007;
            oc[i+1]%=1000000007;
        }
        return oo[n];
    }
};