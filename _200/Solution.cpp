#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, k, i, j, a[200008], b[200008];
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", min(a[i], b[j])), i = j = 0) {
        for (scanf("%lld%lld%lld", &n, &m, &k); i != n; scanf("%lld", a + i++));
        for (a[n] = b[m] = 2e9; j != m; scanf("%lld", b + j++));
        for (i = j = 0; --k;)
            if (a[i] < b[j]) ++i;
            else ++j;
    }
    exit(0);
}