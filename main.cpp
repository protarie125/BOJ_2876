#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr auto kMaxGrad = ll{5};

ll n;
vvl dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  dp = vvl(kMaxGrad + 1, vl(n + 1, 0));

  for (auto i = 1; i <= n; ++i) {
    ll x, y;
    cin >> x >> y;
    dp[x][i] = 1;
    dp[y][i] = 1;
  }

  ll g = 0;
  ll ans = 0;
  for (auto x = 1; x <= 5; ++x) {
    ll now = 0;
    for (auto i = 1; i <= n; ++i) {
      now += dp[x][i];
      // cout << x << ',' << i << ',' << dp[x][i] << '\n';
      if (now > ans) {
        g = x;
        ans = now;
      }
      if (dp[x][i] == 0) {
        now = 0;
      }
    }
  }

  cout << ans << ' ' << g;

  return 0;
}