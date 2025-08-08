#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, a, b, c;
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", c))
        for (scanf("%lld%lld", &a, &b), c = 1; b; a = a * a % 107, b >>= 1)
            if (b & 1) c = c * a % 107;
    exit(0);
}