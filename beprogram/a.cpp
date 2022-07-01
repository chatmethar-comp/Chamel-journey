#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
using namespace std;
vector<pii> v;
ll cnt[4]; // 2 3 5 7 (prime arr that <= x)
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> m >> n;
    int x, s, t;
    for (int i = 1; i <= m; i++) {
        cin >> x >> s >> t;
        v.push_back({s, x});
        v.push_back({t+1, -x});
    }
    sort(v.begin(), v.end());
    ll num = 1, ans1 = 0, ans2 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].s > 0) {
            num *= v[i].s;
            switch (v[i].s) {
                case  2: cnt[0] += 1; break;
                case  3: cnt[1] += 1; break;
                case  4: cnt[0] += 2; break;
                case  5: cnt[2] += 1; break;
                case  6: cnt[0] += 1; cnt[1] += 1; break;
                case  7: cnt[3] += 1; break;
                case  8: cnt[0] += 3; break;
                case  9: cnt[1] += 2; break;
                case 10: cnt[0] += 1; cnt[2] += 1; break;
            }
            num = 1;
            for (int i = 0; i < 4; i++) num *= (1 + cnt[i]);
            if (num > ans1) {
                ans1 = num;
                ans2 = v[i+1].f - v[i].f;
            } else if (num == ans1) {
                ans2 += v[i+1].f - v[i].f;
            }
        } else {
            num /= (-v[i].s);
            switch (-v[i].s) {
                case  2: cnt[0] -= 1; break;
                case  3: cnt[1] -= 1; break;
                case  4: cnt[0] -= 2; break;
                case  5: cnt[2] -= 1; break;
                case  6: cnt[0] -= 1; cnt[1] -= 1; break;
                case  7: cnt[3] -= 1; break;
                case  8: cnt[0] -= 3; break;
                case  9: cnt[1] -= 2; break;
                case 10: cnt[0] -= 1; cnt[2] -= 1; break;
            }
        }
    }
    cout << ans1 << " " << ans2;

    return 0;
}
