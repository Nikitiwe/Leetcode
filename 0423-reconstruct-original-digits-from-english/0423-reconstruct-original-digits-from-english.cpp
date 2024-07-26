class Solution {
public:
    string originalDigits(string s) {
        vector arr(26, 0), ans(10, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        ans[0]=arr['z'-'a']; arr['e'-'a']-=arr['z'-'a']; arr['r'-'a']-=arr['z'-'a']; arr['o'-'a']-=arr['z'-'a'];
        ans[6]=arr['x'-'a']; arr['i'-'a']-=arr['x'-'a']; arr['s'-'a']-=arr['x'-'a'];
        ans[7]=arr['s'-'a']; arr['v'-'a']-=arr['s'-'a']; arr['n'-'a']-=arr['s'-'a']; arr['e'-'a']-=2*arr['s'-'a'];
        ans[8]=arr['g'-'a']; arr['e'-'a']-=arr['g'-'a']; arr['i'-'a']-=arr['g'-'a']; arr['h'-'a']-=arr['g'-'a']; arr['t'-'a']-=arr['g'-'a'];
        ans[3]=arr['h'-'a']; arr['t'-'a']-=arr['h'-'a']; arr['r'-'a']-=arr['h'-'a']; arr['e'-'a']-=2*arr['h'-'a'];
        ans[4]=arr['u'-'a']; arr['f'-'a']-=arr['u'-'a']; arr['o'-'a']-=arr['u'-'a']; arr['r'-'a']-=arr['u'-'a'];
        ans[5]=arr['f'-'a']; arr['i'-'a']-=arr['f'-'a']; arr['v'-'a']-=arr['f'-'a']; arr['e'-'a']-=arr['f'-'a'];
        ans[2]=arr['w'-'a']; arr['t'-'a']-=arr['w'-'a']; arr['o'-'a']-=arr['w'-'a'];
        ans[1]=arr['o'-'a']; arr['n'-'a']-=arr['o'-'a']; arr['e'-'a']-=arr['o'-'a'];
        ans[9]=arr['i'-'a'];
        string a;
        for (int i=0; i!=10; i++)
        {
            for (int j=0; j!=ans[i]; j++)
            {
                a+=to_string(i);
            }
        }
        return a;
    }
};