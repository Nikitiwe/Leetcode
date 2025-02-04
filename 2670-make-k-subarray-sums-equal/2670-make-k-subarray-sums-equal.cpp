class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int g=gcd(arr.size(), k), d=arr.size()/g;
        vector<int> temp;
        long long ans=0;
        for (int a=0; a<g; a++)
        {
            int c=0;
            for (int i=0; ; i+=g)
            {
                temp.push_back(arr[(i+a)%arr.size()]);
                c++;
                if (c==d) break;
            }
            sort(temp.begin(), temp.end());
            for (int i=0; i<temp.size()/2; i++) ans+=(temp[temp.size()-1-i]-temp[i]);
            temp.clear();
        }
        return ans;
    }
};