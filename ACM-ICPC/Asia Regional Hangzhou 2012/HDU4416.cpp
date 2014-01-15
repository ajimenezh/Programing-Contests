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

#define MAXN 310000
#define MAXM 20

int A[MAXN];
int S[MAXN];
pair<int,int> B[MAXN];
int P[MAXN], P2[MAXN], R[MAXN], H[MAXN], N, i, stp, cnt;
int ST[MAXN][MAXM];
int H2[MAXN];
int num;

struct entry {
        int nr[2],p;
} L[MAXN];

struct SuffixArray2{

    int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN], sa[MAXN];
    int cmp(int *r,int a,int b,int l)
    {return r[a]==r[b]&&r[a+l]==r[b+l];}

    void init() {
        int m = num;
        int n = N;

        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0;i<m;i++) Ws[i]=0;
        for(i=0;i<n;i++) Ws[x[i]=S[i]]++;
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
        for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;
        for(j=1,p=1;p<n;j*=2,m=p){
            for(p=0,i=n-j;i<n;i++) y[p++]=i;
            for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0;i<n;i++) wv[i]=x[y[i]];
            for(i=0;i<m;i++) Ws[i]=0;
            for(i=0;i<n;i++) Ws[wv[i]]++;
            for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
            for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }

        for (int i=0; i<N; i++) R[i] = sa[i];
        for (int i=0; i<N; i++) P[R[i]] = i;

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

void build(void) {
    for (i=0; i<N; i++) ST[i][0] = H[i];
    for (int j=1; (1<<j)<=N; j++)
        for (i=0; i+(1<<j)-1<N; i++) ST[i][j] = min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
}

int rmq(int x, int y) {
	if (x==y) return N - x;
    if (P[x]>P[y]) return rmq(y,x);
    x = P[x];
    y = P[y]-1;

    int t;
    for (t=0; (1<<(t+1))<=(y-x+1); t++);
    return min(ST[x][t], ST[y-(1<<t)+1][t]);
}

int lcp(int x, int y) {
    if (P[x]>P[y]) return lcp(y,x);

    int t = P[x];
    int res = MAXN*10;
    for (int j=P[x]; j<P[y]; j++) res = min(res,H[j]);
    return res ==MAXN*10 ? 0 : res;
}

SuffixArray2 sa;
char str[100010];
int pos[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    int cas = 1;
    while (tt--) {
        int len;
        int m = 0;
        int n;
        num = 30;
        scanf("%d",&n);
        scanf("%s",str);
        len = strlen(str);
        for (int i=0; i<len; i++) S[m++] = str[i] - 'a' + 1;
        for (int i=0; i<n; i++) {
            S[m++] = num++;
            scanf("%s",str);
            int l = strlen(str);
            for (int j=0; j<l; j++) {
                S[m++] = str[j]-'a'+1;
            }
        }
        S[m] = 0;
        N = m+1;
        sa.init();
        sa.lcp();

        long long ans = (long long)len*(len+1)/2;

        int tmp = 100000000;

        for (int i=0; i<len; i++) pos[i] = 0;

        for (int i=m; i>=0; i--) H[i] = H[i-1];

        for (int i=1; i<=m; i++) {
            if (R[i]<len) {
                if (H[i]<tmp) tmp = H[i];
                if (pos[R[i]]<tmp) pos[R[i]] = tmp;
            }
            else tmp = 100000000;
        }

        tmp = 100000000;

        for (int i=m; i>=1; i--) {
            if (R[i-1]<len) {
                if (H[i]<tmp) tmp = H[i];
                if (pos[R[i-1]]<tmp) pos[R[i-1]] = tmp;
            }
            tmp = 100000000;
        }

        for (int i=1; i<=m; i++) {
            if (R[i]<len && R[i-1]<len) {
                if (pos[R[i-1]]<H[i]) {
                    pos[R[i-1]] = H[i];
                }
            }
        }

        for (int i=0; i<len; i++) {
            ans -= pos[i];
        }

        printf("Case %d: ", cas++);
        cout<<ans<<"\n";

    }

    return 0;

}
