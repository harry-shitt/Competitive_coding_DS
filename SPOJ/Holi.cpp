#include <bits/stdc++.h>
#define fopi freopen("in.txt", "r", stdin)
#define fopo freopen("out.txt", "w", stdout)
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
typedef pair<int, int> Pair;

vector<Pair> V[maxn];
LL sum[maxn], ans;

void dfs1(int x, int from) {
    sum[x] = 1;
    for (auto p : V[x]) {
        int y = p.first;
        if (y == from) continue;
        dfs1(y, x);
        sum[x] += sum[y];
    }
}

void dfs2(int x, int from) {
    for (auto p : V[x]) {
        int y = p.first, l = p.second;
        if (y == from) continue;
        ans += min(sum[y], sum[1] - sum[y]) * l * 2;
        dfs2(y, x);
    }
}

int T, n;
int main() {
    //fopi;

    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) V[i].clear();

        for (int i = 1; i <= n-1; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            V[x].push_back({y, z});
            V[y].push_back({x, z});
        }

        ans = 0;
        dfs1(1, 0);
        dfs2(1, 0);

        printf("Case #%d: %lld\n", ca, ans);
    }
}