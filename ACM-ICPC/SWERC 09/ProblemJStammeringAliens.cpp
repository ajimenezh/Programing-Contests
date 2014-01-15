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
#define MAXN 40005
#define MAXM 20

int A[MAXN];
int S[MAXN];
pair<int,int> B[MAXN];
int P[MAXN], P2[MAXN], R[MAXN], H[MAXN], N, i, stp, cnt;
int ST[MAXN][MAXM];
int H2[MAXN];

struct entry {
        int nr[2],p;
} L[MAXN];

struct SuffixArray2{

    struct compare{
        bool operator() (struct entry a,struct entry b) {
            return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
        }
    } cmp;

    void init() {

        //Make array A with position of letters of s in sorted array
        for (i=0; i<N; i++) B[i] = make_pair(S[i],i);
        sort(B, B + N);

        cnt = 0;
        for (i=0; i<N; i++) {
            long long c = B[i].first;
            while (i<N && B[i].first==c) {
                A[B[i].second] = cnt;
                i++;
            }
            cnt++;
            i--;
        }

        for (i=0; i<N; i++)
            P[i] = A[i];

        for (stp = 1, cnt = 1; cnt>>1 < N; stp++, cnt <<= 1) {
            for(i = 0; i<N; i++) P2[i] = P[i];
            for (i = 0; i<N; i++) {
                L[i].nr[0] = P2[i];
                L[i].nr[1] = i + cnt < N ? P2[i + cnt] : -1;
                L[i].p = i;
            }
            sort(L, L + N,cmp);
            for (i = 0; i<N; i++)
                P[L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[L[i-1].p] : i;
        }

        for (i=0; i<N; i++) R[P[i]] = i;

        return;
    }

    void lcp(void) {
        int k, ret = 0,j;
        for (i = 0; i<N; i++) if (P[i]>0) {
            j = R[P[i] - 1];
            while(S[i+ret] == S[j + ret]) ret++;
            H[P[i] - 1] = ret;
            if (ret > 0) ret--;
        }
        H[N-1] = 0;
    }

};

int sum[40010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    string s;
    while (cin>>n && n!=0) {
        cin>>s;
        SuffixArray2 sa;
        for (int i=0; i<s.length(); i++) S[i] = s[i];
        N = s.length();
        sa.init();
        sa.lcp();

        for (int i=1; i<N; i++) {
            if (H[i]>H[i-1]) sum[i] = 1 + sum[i-1];
        }
        int best = 0;
        for (int i=0; i<N; i++) {
            if (sum[i]>=n-1) {
                best = max(best, H[i-(n-2)]);
                sum[i-(n-2)-1] = -2;
            }
        }
        int p = 0;
        for (int i=0; i<N; i++) if (H[i-(n-2)]>=best && sum[i]>=n-1) {
            p = max(R[i],p);
            p = max(R[i-1],p);
        }
        printf("%d %d\n",best,p);
    }

    return 0;

}
