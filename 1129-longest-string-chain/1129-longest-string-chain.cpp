bool ssort(string a, string b)
{
    return a.size()<b.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& w) {
        sort(w.begin(), w.end(), ssort);
        vector<int> arr(w.size(), 1);
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=i+1; j<w.size(); j++)
            {
                if (w[j].size()==w[i].size()+1)
                {
                    int l=0, r=w[j].size()-1;
                    while (l<w[i].size()&&w[i][l]==w[j][l]) l++;
                    while (r>=1&&w[i][r-1]==w[j][r]) r--;
                    if (l>=r) arr[j]=max(arr[j], arr[i]+1);
                }
                else if (w[j].size()>w[i].size()+1) break;
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};