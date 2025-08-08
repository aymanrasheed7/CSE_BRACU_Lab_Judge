#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, i, j, u, v, w, a[108][108];
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld%lld", &n, &m); i != m;
            scanf("%lld%lld%lld", &u, &v, &w), a[u][v] = w, ++i);
        for (i = 0; i++ != n; puts(""))
            for (j = 0; j++ != n; printf("%lld ", a[i][j]), a[i][j] = 0);
    }
    exit(0);
}