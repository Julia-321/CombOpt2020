#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e10;

long long dist[100][100];
int shops[10];
vector<int> sh1, sh2;

int getBit(int mask, int j) {return mask&(1<<j);}

long long getMinDist(int start, vector <int> path)
{
    if (path.size() == 0 )
        return 0;
    sort(path.begin(), path.end());
    long long ans = INF;
    do {
        long long sum = dist[start][path[0]] ;
        for (int i = 1; i < path.size(); ++i)
            sum += dist[path[i-1]][path[i]];
        ans = min(ans, sum);
    }
    while (next_permutation(path.begin(), path.end()));
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j= 0; j < n; ++j)
                dist[i][j] = min(dist[i][j],
                                 dist[i][k]+dist[k][j]);

    int s;
    cin >> s;
    for (int i = 0; i < s; ++i)
        cin >> shops[i];

    int home1, home2;
    cin >> home1 >> home2;


    long long ans = INF;
    for (int mask = 0; mask < (1<<s); ++mask)
    {
        sh1.clear();
        sh2.clear();
        for (int i = 0; i < s; ++i)
            if (getBit(mask, i))
                sh1.push_back(shops[i]);
            else
                sh2.push_back(shops[i]);
            long long d = getMinDist(home1, sh1) + getMinDist(home2, sh2);
            ans = min(ans, d);
    }
    cout << ans << "\n";
    return 0;
}
