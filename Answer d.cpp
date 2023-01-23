#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        int maxl[n];
        int maxr[n];
        maxl[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            maxl[i] = max(maxl[i - 1], arr[i]);
        }
        maxr[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxr[i] = max(maxr[i + 1], arr[i]);
        }
        int water[n];
        for (int i = 0; i < n; i++)
        {
            water[i] = min(maxl[i], maxr[i]) - arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + water[i];
        }
        return sum;
    }
};
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    // calling trappingWater() function
    cout << obj.trappingWater(a, n) << endl;
    return 0;
}
