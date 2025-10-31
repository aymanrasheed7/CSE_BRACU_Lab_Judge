#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, s, i, j, k;
pair<lll, lll> a[5008];
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld%lld", &n, &s); i != n;
            scanf("%lld", &a[i].first), a[i].second = i, ++i);
        sort(a, a + n);
        for (k = n - 1; 0 < k; --k)
            for (i = 0, j = k - 1; i < j;)
                if (a[i].first + a[j].first + a[k].first < s) ++i;
                else if (a[i].first + a[j].first + a[k].first > s) --j;
                else printf("%lld %lld %lld\n", a[i].second + 1,
                    a[j].second + 1, a[k].second + 1), i = j = k = -1;
        if (~i) puts("-1");
    }
    exit(0);
}