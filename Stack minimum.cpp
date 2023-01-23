#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // int minEle;
    stack<int> s;
    vector<int> prefix;


public:
    // returns min element from stack/
    int getMin()
    {
        if (s.empty())
            return -1;
        return prefix[s.size() - 1];
    }
    // returns poped element from stack/
    int pop()
    {
        if (s.empty())
            return -1;
        prefix.erase(prefix.end() - 1);
        int temp = s.top();
        s.pop();
        return temp;
    }
    // push element x into the stack/
    void push(int x)
    {
        if (prefix.empty())
            prefix.push_back(x);
        else
            prefix.push_back(x < prefix.back() ? x : prefix.back());
        s.push(x);
    }
};
//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while (q--)
        {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                // pop
                cout << ob.pop() << " ";
            }
            else if (qt == 3)
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
//Answer of Bonus Question
/*
We use stack or queue instead of arrays/lists when we want the elements in a specific order  in the order we put them (queue) or in the reverse order (stack). Queues and stacks are dynamic while arrays are static. So when we require dynamic memory we use queue or stack over arrays.
Real world usecase -

 consider plates in a cupboard. When we keep plates in the cupboard one upon another (bottom to top). But when we take the plate from the cupboard. we take it out from (top to form). So, it is also an example of the stack as it works on LIFO(last in first out).

*/
