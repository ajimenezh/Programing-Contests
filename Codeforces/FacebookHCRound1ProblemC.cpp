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
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 40010

int w,h,q,p;
int X, Y, a,b,c,d,n;
vector<int> v[MAXN];
set<int> s[MAXN];

struct ST{
    int val[3*MAXN];
    int si[3*MAXN];
    int left[3*MAXN];
    int right[3*MAXN];
    int used[3*MAXN];
    int N;
    int M;
    void init(int _N) {
        N = _N;
        for (M=0; (1<<M)<N; M++);
        if ((1<<(M-1))==N) M--;
        M = (1<<M);
        for (int i=0; i<N; i++) used[i] = 0;
        for (int i=0; i<N; i++) {
            right[M+i] = 1;
            left[M+i] = 1;
            si[M+i] = 1;
            used[i] = 0;
            if (q==1) val[M+i] = 1;
            else val[M+i] = 0;
        }

        for (int i=M+N; i<2*M; i++) {
            right[i] = 0;
            left[i] = 0;
            si[i] = 0;
            used[i-M] = 0;
            val[i] = 0;
        }

        for (int i=0; i<M; i++) {
            doit((M+i)/2);
        }
        //cout<<"done"<<endl;

    }

    void update(int i, int c) {
        used[i] = used[i] + c;
        used[i] = max(used[i],0);
        if (used[i]==0) {
            left[M+i] = 1;
            right[M+i] = 1;
            if (q==1) val[M+i] = 1;
            else val[M+i] = 0;
        }
        if (used[i]>=1) {
            left[M+i] = 0;
            right[M+i] = 0;
            val[M+i] = 0;
        }

        doit(((M)+i)/2);

        //cout<<query()<<endl;
    }

    void doit(int i) {
        si[i] = si[2*i] + si[2*i+1];

        val[i] = val[2*i] + val[2*i+1];

        if (left[2*i+1]+right[2*i]>=q) {
            if (left[2*i+1]<q && right[2*i]<q) {
                val[i] += (left[2*i+1]+right[2*i]) - q + 1;
            }
            else if (left[2*i+1]<q && right[2*i]>=q) {
                val[i] += min(q-1, left[2*i+1]);
            }
            else if (left[2*i+1]>=q && right[2*i]<q) {
                val[i] += min(right[2*i], q-1);
            }
            else if (left[2*i+1]>=q && right[2*i]>=q){
                val[i] += q-1;
            }
        }

        left[2*i]==si[2*i] ? left[i] = left[2*i] + left[2*i+1] : left[i] = left[2*i];
        right[2*i+1]==si[2*i+1] ? right[i] = right[2*i] + right[2*i+1] : right[i] = right[2*i+1];

        //cout<<left[2*i]<<" "<<si[2*i]<<" "<<left[i]<<endl;
        //cout<<i<<" "<<val[i]<<" "<<left[i]<<" "<<right[i]<<" "<<si[i]<<endl;

        if (i==1) return;
        doit(i/2);

    }

    int query() {
        return val[1];
    }
}st;


int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=0; t<tt; t++) {
        scanf("%d%d%d%d",&w,&h,&p,&q);
        scanf("%d%d%d%d%d%d%d",&n,&X,&Y,&a,&b,&c,&d);

        for (int i=0; i<w; i++) {
            v[i].clear();
            s[i].clear();
        }

        v[X].push_back(Y);

        for (int i=1; i<n; i++) {
            int x1 = (X*a + Y*b+1)%w;
            int y1 = (X*c + Y*d+1)%h;

            if (s[x1].find(y1) == s[x1].end()) {
                v[x1].push_back(y1);
                s[x1].insert(y1);
            }
            X = x1;
            Y = y1;

            //cout<<x1<<" "<<y1<<endl;

        }

        for (int i=0; i<w; i++) {
            sort(v[i].begin(),v[i].end());
        }

        st.init(h);

        //cout<<st.query()<<endl;

        int k = 0;
        long long res = 0;

        for (int i=0; i<p; i++) {
            for (int j=0; j<v[i].size(); j++) {
                st.update(v[i][j],1);
            }

        }

        res += st.query();

        for (int i=p; i<w; i++) {
            for (int j=0; j<v[i-p].size(); j++) {
                st.update(v[i-p][j],-1);
            }
            for (int j=0; j<v[i].size(); j++) {
                st.update(v[i][j],1);
            }

            //cout<<res<<" "<<st.query()<<endl;
            res += st.query();
        }

        printf("Case #%d: %I64d\n",t+1,res);

    }

    return 0;

}
