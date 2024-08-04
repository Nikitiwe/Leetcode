class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> arr;
        for (int i=0; i!=words.size(); i++)
        {
            arr[words[i]]++;
        }
        char a='a', b='a';
        string temp1, temp2;
        int ans=0, ans1=0, ans2=0;
        for (int i=0; i!=26; i++)
        {
            for (int j=i+1; j<26; j++)
            {
                a='a';
                b='a';
                temp1="";
                temp2="";
                if (i!=j)
                {
                    a+=i;
                    b+=j;
                    temp1+=a; temp1+=b;
                    temp2+=b; temp2+=a;
                    ans+=min(arr[temp1], arr[temp2]);
                }
            }
        }
        for (int i=0; i!=26; i++)
        {
            a='a';
            a+=i;
            temp1="";
            temp1+=a; temp1+=a;
            ans1+=arr[temp1]/2;
        }
        for (int i=0; i!=26; i++)
        {
            a='a';
            a+=i;
            temp1="";
            temp1+=a; temp1+=a;
            if (arr[temp1]%2==1) {ans2++; break;}
        }
        return 4*ans+4*ans1+2*ans2;
    }
};