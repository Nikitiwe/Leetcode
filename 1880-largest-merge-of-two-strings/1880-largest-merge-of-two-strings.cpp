class Solution {
public:
    string largestMerge(string s1, string s2) {
        string ans;
        int l1=0, l2=0, temp1, temp2, f;
        while (l1<s1.size()&&l2<s2.size())
        {
            if (s1[l1]<s2[l2]) {ans+=s2[l2]; l2++;}
            else if (s1[l1]>s2[l2]) {ans+=s1[l1]; l1++;}
            else
            {
                temp1=l1;
                temp2=l2;
                f=1;
                while (s1[l1]==s2[l2])
                {
                    l1++; l2++;
                    if (l1==s1.size()) {l1=temp1; l2=temp2; ans+=s2[l2]; l2++; f=0; break;}
                    if (l2==s2.size()) {l2=temp2; l1=temp1; ans+=s1[l1]; l1++; f=0; break;}
                }
                if (f==1) {
                if (s1[l1]>s2[l2])
                {
                    l2=temp2;
                    l1=temp1;
                    ans+=s1[l1]; l1++;
                }
                else
                {
                    l2=temp2;
                    l1=temp1;
                    ans+=s2[l2]; l2++;
                }
                }
            }
        }
        while (l1<s1.size()) {ans+=s1[l1]; l1++;}
        while (l2<s2.size()) {ans+=s2[l2]; l2++;}
        return ans;
    }
};