class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> arr(26, 0), barr = arr;
        for (int i=0; i!=a.size(); i++) arr[a[i] - 'a']++;
        for (int i=0; i!=b.size(); i++) barr[b[i] - 'a']++;
        int ans = 1e9;
        int suma = 0, sumb = 0;
        for (int i=0; i!=26; i++) suma += arr[i];
        for (int i=0; i!=25; i++)
        {
            suma -= arr[i];
            sumb += barr[i];
            ans = min(ans, suma + sumb);
        }
        suma = 0; sumb = 0;
        for (int i=0; i!=26; i++) sumb += barr[i];
        for (int i=0; i!=25; i++)
        {
            suma += arr[i];
            sumb -= barr[i];
            ans = min(ans, suma + sumb);
        }
        int mia = 1e9, mib = 1e9;
        for (int i=0; i!=26; i++)
        {
            mia = min(mia, (int)a.size() - arr[i]);
            mib = min(mib, (int)b.size() - barr[i]);
        }
        ans = min(ans, mia + mib);
        return ans;
    }
};