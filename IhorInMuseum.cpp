#include <iostream>

using namespace std;


bool mp[1001][1001];
int comp[1001][1001];

int cnt(int x, int y)
{
    return !mp[x-1][y]+!mp[x+1][y]+!mp[x][y-1]+!mp[x][y+1];

}

int dfs(int x, int y, int c)
{
    comp[x][y] = c;
    int ans = cnt(x, y);
    if (mp[x-1][y] && comp[x-1][y] == 0)
        ans += dfs(x-1, y, c);
    if (mp[x+1][y] && comp[x+1][y] == 0)
        ans += dfs(x+1, y, c);
    if (mp[x][y-1] && comp[x][y-1] == 0)
        ans += dfs(x, y-1, c);
    if (mp[x][y+1] && comp[x][y+1] == 0)
        ans += dfs(x, y+1, c);
    return ans;

}

int ans[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, comps = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char c;
            cin >> c;
            mp[i][j] = c=='.';
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] && comp[i][j]==0)
            {
                ans[comps] = dfs(i, j, ++comps);
            }
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        cout << ans[comp[x][y]] << "\n";
    }
    return 0;
}
