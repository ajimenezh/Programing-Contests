#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define INF 1000000

int m,n;

struct state{
    int v[15], wait[15], swaps[2];
};

int solve(state st, int ply, int alpha, int beta) {

    int last;
    int ofs1 = (ply*(m+1)), ofs2 = (ofs1 + (m+1))%n;
    state tmp;

    int sum1 = 0, sum2 = 0;
    for (int i=0; i<m; i++) sum1 += st.v[ofs1 + i], sum2 += st.v[ofs2 + i];

    if (sum1==0) {
        if (sum2==0) return st.v[ofs1+m] - st.v[ofs2+m];

        tmp = st;
        for (int j=0; j<m; j++) tmp.wait[j]--;
        int sol = -solve(tmp, ply^1,-beta,-alpha);
        if (alpha<sol) alpha = sol;
        return alpha;
    }

    for (int i=0; i<m; i++) {
        if (st.v[ofs1+i]==0) continue;

        tmp = st;
        int last = ofs1+i;
        int j;
        for (j=tmp.v[ofs1+i], tmp.v[last] = 0; j>0; j--) ++(tmp.v[(++last)%n]);

        if (last==ofs1+m) {
            int sol = solve(tmp, ply, alpha, beta);
            if (alpha<sol) alpha = sol;
            if (alpha>=beta) return alpha;
        }
        else {
            if (ofs1<=last && last<ofs1+m && st.v[last]==0 && tmp.v[2*m-last]>0) {
                tmp.v[ofs1+m] += tmp.v[last] + tmp.v[2*m-last];
                tmp.v[last] = tmp.v[2*m-last] = 0;
            }

            for (int j = 0; j < m; j++) --tmp.wait[j];
            int sol = -solve(tmp, ply^1, -beta, -alpha);
            if (alpha < sol) alpha = sol;
            if (alpha >= beta) return alpha;

            if (ofs2 <= last && last < ofs2 + m && tmp.swaps[ply] > 0 && tmp.v[ofs1 + last - ofs2] > 0 && tmp.wait[last - ofs2] < 0) {
                int k = tmp.v[last];
                tmp.v[last] = tmp.v[ofs1 + last - ofs2];
                tmp.v[ofs1 + last - ofs2] = k;
                tmp.wait[last - ofs2] = 4;
                --tmp.swaps[ply];

               int sol = -solve(tmp, ply^1, -beta, -alpha);
                if (alpha < sol) alpha = sol;
                if (alpha >= beta) return alpha;
            }
        }

    }

    return alpha;

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>m;
        n = 2*(m+1);
        state st;
        for (int i=0; i<n; i++) cin>>st.v[i];
        for (int i=0; i<n; i++) st.wait[i] = 0;
        for (int i=0; i<2; i++) st.swaps[i] = 3;

        cout<<-solve(st, 1, -INF, INF)<<endl;
    }

    return 0;

}
