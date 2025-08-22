#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, p1, q1, p2, q2, i, j, k, a[2008][2008];
lll dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
lll dy[] = { 1, -1, -2, 2, 2, -2, -1, 1 };
queue<lll> r;
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", a[p2][q2]), i = 0) {
        for (scanf("%lld%lld%lld%lld%lld", &n, &p1, &q1, &p2, &q2); i++ != n;)
            for (j = 0; j++ != n; a[i][j] = -1);
        for (a[p1][q1] = 0, r.push(p1), r.push(q1); !r.empty();)
            for (p1 = r.front(), r.pop(), q1 = r.front(), r.pop(), k = 8; k--;)
                if (i = p1 + dx[k], j = q1 + dy[k],
                    1 <= i && i <= n && 1 <= j && j <= n && a[i][j] == -1)
                    a[i][j] = 1 + a[p1][q1], r.push(i), r.push(j);
    }
    exit(0);
}