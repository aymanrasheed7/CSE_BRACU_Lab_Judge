#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, w, i, u[75008], v[75008], x[2][50008];
priority_queue<tuple<lll, lll, lll>> q;
vector<pair<lll, lll>> a[50008];
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", min(x[0][n], x[1][n])
        < 1e17 ? min(x[0][n], x[1][n]) : -1), i = 0) {
        for (scanf("%lld%lld", &n, &m);
            i++ != n; x[0][i] = x[1][i] = 1e18, a[i].clear());
        for (i = 0; i != m; scanf("%lld", u + i), ++i);
        for (i = 0; i != m; scanf("%lld", v + i), ++i);
        for (i = 0; i != m; scanf("%lld", &w),
            a[u[i]].push_back(make_pair(w, v[i])), ++i);
        for (x[0][1] = x[1][1] = 0, q.push(make_tuple(0, 0, 1)),
            q.push(make_tuple(0, 1, 1)); !q.empty();)
            if (tie(w, i, m) = q.top(), q.pop(), w = -w, w == x[i][m])
                for (auto& z : a[m]) if (((i ^ z.first) & 1)
                    && x[i][m] + z.first < x[i ^ 1][z.second])
                    q.push(make_tuple(-(x[i ^ 1][z.second] =
                        x[i][m] + z.first), i ^ 1, z.second));
    }
    exit(0);
}