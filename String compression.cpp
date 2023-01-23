#include <bits/stdc++.h>
#include <string>
using namespace std;
void compress(string s)
{
    int num = s.length(); // calculating length of the string
    int i = 0;
    while (i < num)
    {
        // Counting the repetitions of each character
        int repetition = 1;
        while (s[i] == s[i + 1] && i < num - 1)
        {
            repetition++;
            i++;
        }
        // Print character and its count
        cout << s[i] << repetition;
        i++;
  }
}
int main()
{
    string str = "aaaabbcddddd";
    compress(str);
}


