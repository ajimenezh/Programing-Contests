#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXV = 150;
typedef bitset<MAXV> bs;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n;
const int MAXN = 150;
int as[MAXN];

bs good[MAXV];
void precalc() {
  for (int a = 0; a < MAXV; a++)
  for (int b = 0; b < MAXV; b++)
    if (gcd(a, b) == 1)
      good[a].set(b);
}

int ans;

void go(int pos, int cans, const bs &cur, int prval) {
  if (pos >= n) {
    ans = min(ans, cans);
    return;
  }
  {
    int ptr = max(prval, as[pos]);
    int cans2 = cans;
    for (int i = pos; i < n; i++) {
      while (ptr < MAXV && !cur.test(ptr)) ptr++;
      if (ptr >= MAXV) return;
      cans2 += ptr - as[i];
      if (ptr != 1)
        ptr++;
    }
    if (cans2 >= ans) return;
  }

  for (int cv = max(prval, as[pos]); cv < MAXV; cv++) if (cur.test(cv)) {
    go(pos + 1, cans + cv - as[pos], cur & good[cv], cv);
  }
}

void solve() {
  int k, ans = 0;
  assert(scanf("%d%d", &n, &k) == 2);
  assert(2 <= n && n <= MAXN);
  assert(k >= 1);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
    int me = as[i];
    assert(0 <= as[i] && as[i] <= 50);
    as[i] = (as[i] + k - 1) / k;
    ans += as[i] * k - me;
  }
  sort(as, as + n);
//  reverse(as, as + n);
  bs cur;
  for (int i = 0; i < MAXV; i++)
    cur.set(i);
  ::ans = 1e9;
  go(0, 0, cur, 0);
  ans += ::ans * k;
  printf("%d\n", ans);
}

int main(int argc, char* argv[]) {
freopen("output2.txt","w",stdout);
  precalc();

  int TN;
  char buf[16];
  assert(fgets(buf, sizeof buf, stdin));
  assert(sscanf(buf, "%d", &TN) >= 1);
  for (int TID = 1; TID <= TN; TID++)
    try {
      eprintf("===== Solving test case #%d =====\n", TID);
      printf("Case #%d: ", TID);
      solve();
    } catch (...) {
      eprintf("Exception was caught while executing on test #%d\n", TID);
      return 1;
    }
  return 0;
}
