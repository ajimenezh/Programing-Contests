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

#define MAXN 200005
#define MAXM 20

int A[MAXN];
long long S[MAXN];
pair<long long,int> B[MAXN];
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

};


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s;
	int k;
	cin>>s>>k;
	
	N = s.length();
	for (int i=0; i<N; i++) S[i] = s[i];
	
	SuffixArray2 sa;
	sa.init();
	
	int cur = 0;
	int l = 0;
	int last = N;
	while (k>0 && cur<N) {
		while (cur<N && R[cur]+l>=N) cur++;
		int t = cur;
		while (cur+1<last && R[cur+1]+l<N && s[R[cur+1]+l]==s[R[cur]+l]) cur++;
		long long c = 0;
		for (int i=t; i<=cur; i++) c += N - R[i] - l;
		if (c>=k) {
			if (cur-t+1>=k) {
				cout<<s.substr(R[t],l+1)<<endl;
				return 0;
			}
			l++;
			k -= (cur-t+1);
			last = cur+1;
			cur = t;
		}
		else {
			k -= c;
			cur++;
		}
		//cout<<k<<endl;
	}
	
	cout<<"No such line."<<endl;
	

    return 0;

}
