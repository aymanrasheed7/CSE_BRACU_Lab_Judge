#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, s, i, j, a[200008];
int main() {
    for (scanf("%lld", &t); t--; i = j = 0) {
        for (scanf("%lld%lld", &n, &s); i != n; scanf("%lld", a + i++));
        for (i = 0, j = n - 1; i < j;)
            if (a[i] + a[j] < s) ++i;
            else if (a[i] + a[j] > s) --j;
            else printf("%lld %lld\n", i + 1, j + 1), i = j = -1;
        if (~i) puts("-1");
    }
    exit(0);
}