#include<bits/extc++.h>
using namespace std;
int t, n;
int main() {
    for (scanf("%d", &t); t--; scanf("%d", &n), printf("%lld\n", n * (n + 1LL) >> 1));
    exit(0);
}