class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        vector<int> arr(s.size()+1, 0);
        for (int i=0; i!=sh.size(); i++)
        {
            if (sh[i][2]==1)
            {
                arr[sh[i][0]]++;
                arr[sh[i][1]+1]--;
            }
            else
            {
                arr[sh[i][0]]--;
                arr[sh[i][1]+1]++;
            }
        }
        for (int i=0; i<arr.size()-1; i++)
        {
            arr[i+1]+=arr[i];
            arr[i]%=26;
            s[i]='a'+((s[i]-'a'+arr[i])%26+26)%26;
        }
        return s;
    }
};