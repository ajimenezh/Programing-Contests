#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define clause pair<int,int>
#define makecl make_pair<int,int>

int n, m;
char Pattern[502][502];

const int NN = 1000000;

/*** Strongly connected components ***/

int teller, vlowlink[NN], vlink[NN];
stack<int> S;
int situatie[NN]; // 0 = not seen yet, 1 = in stack, 2 = processed
vector<int> adj[NN];
int sccnr[NN], cur;

void sccrec (int v) {
    vlink[v] = vlowlink[v] = teller++;
    S.push(v);
    situatie[v] = 1;
    int j, buur;
    for (j = adj[v].size()-1; j >= 0; j--)
        if (situatie[buur = adj[v][j]] < 2) {
            if (situatie[buur] == 0)
                sccrec(buur);
        vlowlink[v] = min(vlowlink[v], vlowlink[buur]);
    }
    if (vlowlink[v] == vlink[v]) {
        int w;
        do {
            sccnr[w = S.top()] = cur;
            situatie[w] = 2;
            S.pop();
        }
        while (w != v);
        cur++;
    }
}

void strongly_connected_components (int n) {
    memset(situatie, 0, sizeof(situatie));
    teller = cur = 0;
    for (int i = 0; i < n; i++)
        if (situatie[i] < 2)
            sccrec(i);
}

/*** 2SAT ***/

// Returns whether there is a solution to an equation of the form:
// true = (A1 || A2) && (B1 || B2) && ...
// where Xi and Yj can be equal statements or each others negation
// K = number of statements (1 t/m K), C = number of clauses

clause Cl[NN]; // The clauses: Cl[i].first || Cl[i].second (-a = !a)

bool twosat (int K, int C) {
    for (int i = 0; i <= 2*K; i++)
        adj[i].clear();
    for (int i = 0; i < C; i++) {
        adj[K - Cl[i].first].push_back(K + Cl[i].second);
        adj[K - Cl[i].second].push_back(K + Cl[i].first);
    }
    strongly_connected_components(2 * K + 1);
    for (int i = 1; i <= K; i++)
        if (sccnr[K + i] == sccnr[K - i])
        return false;
    return true;
}

int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};

bool possible()
{ int i, j, b, w, C, x, y, k1, k2, id[4];
  bool b1, b2, W[4];
  b = w = 0;
  C = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    { id[0] = (i-1)*m+j - 1;
      id[1] = (i-1)*m+j - m + n*m;
      id[2] = (i-1)*m+j ;
      id[3] = (i-1)*m+j + n*m;
      if (Pattern[i][j] == 'B')
      { b++;
        for (x = 0; x < 2; x++) // For both directions
        { b1 = Pattern[i+di[x]][j+dj[x]] == 'W';
          b2 = Pattern[i+di[x+2]][j+dj[x+2]] == 'W';
          k1 = id[x];
          k2 = id[x+2];
          if (b1 || b2)
          { Cl[C++] = makecl(b1 ? k1 : k2, b2 ? k2 : k1);
            if (b1 && b2)
              Cl[C++] = makecl(-k1, -k2);
          }
          else
            return false;
        }
      }
      else if (Pattern[i][j] == 'W')
      { w++;
        for (x = 0; x < 4; x++)
          W[x] = Pattern[i+di[x]][j+dj[x]] == 'B';
        for (x = 0; x < 3; x++)
          for (y = x+1; y < 4; y++)
            if (W[x] && W[y])
              Cl[C++] = makecl(-id[x], -id[y]);
      }
    }
  return w == 2*b && twosat(2*n*m, C);
}

int main() {
    int runs, run, i;
    scanf("%d", &runs);
    for (run = 0; run < runs; run++) {
        scanf("%d %d\n", &n, &m);
        // Read in pattern and put dots around the perimeter
        for (i = 1; i <= n; i++) {
            scanf("%s", Pattern[i]+1);
            Pattern[i][0] = Pattern[i][m+1] = '.';
        }
        memset(Pattern[0], '.', m+2);
        memset(Pattern[n+1], '.', m+2);
        printf("%s\n", possible() ? "YES" : "NO");
    }
    return 0;
}

