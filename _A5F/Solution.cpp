#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, u, v, i, f, w[200008];
vector<lll> a[200008];
void dfs(lll p) {
    w[p] = 1;
    for (auto& q : a[p]) if (!w[q]) dfs(q);
    else if (w[q] == 1) f = 1;
    w[p] = 2;
}
int main() {
    for (scanf("%lld", &t); t--; puts(f ? "YES" : "NO"), i = f = 0) {
        for (scanf("%lld%lld", &n, &m); i != m;
            scanf("%lld%lld", &u, &v), a[u].push_back(v), ++i);
        for (i = 0; i++ != n;) if (!w[i]) dfs(i);
        for (i = 0; i++ != n; w[i] = 0, a[i].clear());
    }
    exit(0);
}