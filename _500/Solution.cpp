#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, k, x, y, z, i, j, h, a[2008][2008];
lll dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
lll dy[] = { 1, -1, -2, 2, 2, -2, -1, 1 };
queue<lll> q;
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", z), i = 0) {
        for (scanf("%lld%lld%lld%lld", &n, &k, &x, &y); i++ != n;)
            for (j = 0; j++ != n; a[i][j] = 0);
        for (z = a[x][y] = 1, q.push(x), q.push(y), q.push(k); !q.empty();)
            for (x = q.front(), q.pop(), y = q.front(), q.pop(),
                k = q.front(), q.pop(), h = 8; h-- && k;)
                if (i = x + dx[h], j = y + dy[h],
                    1 <= i && i <= n && 1 <= j && j <= n && !a[i][j])
                    z += a[i][j] = 1, q.push(i), q.push(j), q.push(k - 1);
    }
    exit(0);
}