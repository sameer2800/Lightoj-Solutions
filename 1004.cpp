#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int k = 0;
    while (t--)
    {

        unsigned long long int dp[200][200];
        unsigned long long int a[200][200];
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= i + 1; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = n; i < 2 * n; i++)
        {
            for (int j = 1; j < 2 * n - i; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= i + 1; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
            }
        }
        for (int i = n; i < 2 * n; i++)
        {
            for (int j = 1; j < 2 * n - i; j++)
            {
                dp[i][j] = max(dp[i - 1][j + 1] + a[i][j], dp[i - 1][j] + a[i][j]);
            }
        }
        k++;
        cout << "Case " << k << ": " << dp[2 * n - 2][1]<<endl;
    }
    return 0;
}
