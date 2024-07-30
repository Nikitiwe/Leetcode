class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> arr(s.size()+1, 0);
        int temp=0, ans=s.size();
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='b') temp++;
            arr[i+1]=temp;
        }
        temp=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='a') temp++;
            arr[i]+=temp;
        }
        for (int i=0; i!=s.size()+1; i++)
        {
            ans=min(ans, arr[i]);
        }
        return ans;
    }
};