#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, i, a[100008];
void rec(lll x, lll y) {
    if (x == y) return;
    lll z = x + y >> 1;
    rec(x, z), rec(z + 1, y), printf("%lld ", a[z]);
}
int main() {
    for (scanf("%lld", &t); t--; rec(i = 0, n), puts(""))
        for (scanf("%lld", &n); i != n; scanf("%lld", a + i++));
    exit(0);
}