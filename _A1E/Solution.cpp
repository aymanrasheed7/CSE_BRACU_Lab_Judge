#include<bits/extc++.h>
using namespace std;
int t, n, i, f, a[1008];
vector<int> v;
int main() {
    for (scanf("%d", &t); t--; v.clear(), i = 0) {
        for (scanf("%d", &n); i != n; scanf("%d", a + i++));
        for (f = n; --f;) for (i = 0; i + 2 < n; ++i)
            if (a[i] > a[i + 2]) swap(a[i], a[i + 2]), v.push_back(i + 1);
        for (i = f = 0; i + 1 < n && !f; f |= a[i] > a[i + 1], ++i);
        if (puts(f ? "NO" : "YES"), !f) for (printf("%d\n", (int)v.size()),
            i = 0; i < v.size(); printf("%d %d\n", v[i], v[i] + 2), ++i);
    }
    exit(0);
}