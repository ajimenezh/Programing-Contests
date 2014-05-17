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

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define forit(s,it) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)

#define MAXN 200005
#define MAXM 20

int A[MAXN];
string S;
pair<char,int> B[MAXN];
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





int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int m;

    while (true) {
        cin>>m;
        if (m==0) break;

        cin>>S;
        N = S.size();

        SuffixArray2 sa;

        sa.init();
        sa.lcp();

        build();

        int cnt = 0;
        int longest = -1;
        vector<int> v;
        int index;
        int tmp = 0;
        for (int i=0; i<N-1; i++) {
            int t = rmq(R[i],R[i+1]);
            //cout<<R[i]<<" "<<t<<endl;
            if ((v.size()==0 && t>0) || (v.size()>0 && t>v[v.size()-1])) {
                v.push_back(t);
                cnt++;
            }
            else {
                //cout<<cnt<<" "<<m<<" hola"<<endl;
                sort(v.begin(),v.end());
                //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
                if (cnt-m+1 >= 0 && longest < v[cnt-m+1]) {
                    longest = v[cnt - m + 1];
                    index = R[i];
                }
                v.clear();
                cnt = 0;
            }
        }
        sort(v.begin(),v.end());
        //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
        if (cnt-m+1 >= 0 && longest < v[cnt-m+1]) {
            longest = v[cnt - m + 1];
            index = R[i];
        }
        v.clear();
        cnt = 0;

        if (longest==-1) {
            cout<<"none"<<endl;
        }
        else {
            cout<<longest<<" ";
            int t = 0;
            //cout<<index<<endl;
            for (int i=0; i<N; i++) {
                //cout<<rmq(R[i],index)<<" "<<t<<" "<<R[i]<<endl;
                if (rmq(R[i],index)>=longest) {
                    t = max(t,R[i]);
                }
            }
            cout<<t<<endl;
        }
    }

    return 0;

}
