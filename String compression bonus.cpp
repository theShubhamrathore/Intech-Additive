#include <bits/stdc++.h>
using namespace std;
string compress(string s)
{
    string ans = "";
    int num = s.length(); // calculating length of the string
    int i = 0;
    int rold = 1;
    while (i < num)
    {
        int rnew = 1;
        // Counting the repetitions of each character
        while (s[i] == s[i + 1] && i < num - 1)
        {
            rnew++;
            i++;
        }
        if (rold == rnew)
 {
            string ro = ans;
            int x = ans.length();
            ro = ro.substr(0, x - 1);
            // cout<<ro<<endl;
            ans = ro;
            ans += s[i];
            ans += to_string(rnew);
        }
        else
        {
            ans += s[i];
            ans += to_string(rnew);
        }
        rold = rnew;
        i++;
    }
    return ans;
    int main()
    {
        string a = "aabbcddd";
        cout << compress(a);
        return 0;
    }
