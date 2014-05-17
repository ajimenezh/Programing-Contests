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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 100010
#define MAXM 18

string s;
vector<int> a;
int lpos[100010];
int ca[MAXN];

void fastLongestPalindrome(string s)
{
    int i = 0;
    int n = s.length();
    int palLen = 0;

    while (i < n)
    {
        if (i > palLen && s[i-palLen-1] == s[i])
        {
            palLen += 2;
            i += 1;
            continue;
        }
        a.pb(palLen);

        int c = a.size() - 2;
        int e = c - palLen;
        bool exit = false;

        for (int j=c; j>e; j--)
        {
            int d = j - e - 1;

            if (a[j] == d)
            {
                palLen = d;
                exit = true;
                break;
            }
            a.pb(min(d,a[j]));
        }

        if (!exit)
        {
            palLen = 1;
            i += 1;
        }
    }

    a.pb(palLen);

    int l = a.size();
    int c = l - 2;
    int e = c - (2*n + 1 - l);
    for (i=c; i>e; i--)
    {
        int d = i - e - 1;
        a.pb(min(d,a[i]));
    }
}

int A[MAXN];
long long S[MAXN];
pair<long long,int> B[MAXN];
int P[MAXN], P2[MAXN], R[MAXN], H[MAXN], N, i, stp, cnt;
//R son los indices de los sufijos ordenados
//El prefijo mas largo entre sufijos contiguos
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

        lcp();
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

}sa;

void build(void) {
    for (i=0; i<N; i++) ST[i][0] = H[i];
    for (int j=1; (1<<j)<=N; j++)
        for (i=0; i+(1<<j)-1<N; i++) ST[i][j] = min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
}

int rmq(int x, int y) {
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

    cin>>s;
    fastLongestPalindrome(s);
    for (int j=0; j<a.size(); j++) cout<<a[j]<<" "; cout<<endl;

    s += '#';
    N = s.length();
    for (int j=0; j<N; j++) S[j]=s[j];

    sa.init();

    for (int j=0; j<N; j++) cout<<P[j]<<" ";
    cout<<endl;
    for (int j=0; j<N; j++) cout<<R[j]<<" ";
    cout<<endl;
    for (int j=0; j<N; j++) cout<<H[j]<<" ";
    cout<<endl;

    for (int j=0; j<s.length()-1; j++) lpos[j] = -1;
    char c = s[s.length()-2];
    for (int j=0; j<N; j++) if (s[j]==c)
    {
        lpos[0] = j;
        break;
    }

    for (int j = 1; j<N; j++)
    {
        int l = R[P[lpos[j-1]]];
        if (l==-1) continue;
        if (s[l+j]==s[s.length()-2-j]) lpos[j] = l;
        else
        {
            if (s[l+j]>s[s.length()-2-j])
            {
                for (int k=l-1; k>=0; k--)
                {
                    if (H[k]<j-1) break;
                    if (s[P[k]+j]==s[s.length()-2-j])
                    {
                        lpos[j] = k;
                        break;
                    }
                }
            }
            else
            {
                for (int k=l+1; k<s.length()-1; k++)
                {
                    if (H[k]<j-1) break;
                    if (s[P[k]+j]==s[s.length()-2-j])
                    {
                        lpos[j] = k;
                    }
                }
            }
        }
    }

    for (int j=0; j<s.length()-1; j++) cout<<lpos[j]<<" ";
    for (int i=0; i<s.length()-1; i++) ca[i] = 0;
    for (int j=1; j<s.length()-1; j++)
    {
        if (lpos[j]==lpos[j-1] && lpos[j]!=-1) ca[j] = ca[j-1]+1;
        else if (lpos[j]!=-1) ca[j] = 1;
    }
    for (int j=1; j<s.length()-1; j++) ca[j] = max(ca[j-1],ca[j]);

    int best=0;

    for (int j=0; j<s.length()-1; j++)
    {
        int k = 2*j+1;
        int len = (a[k]-1)/2;

        cout<<s[j]<<" "<<len<<" "<<s[j+len/2+1]<<endl;
        cout<<ca[s.length()-1-(j+len/2+1)]<<endl;
        if (best<len+1 + ca[j+len/2+1])
        {
            best = len+1 + ca[j+len/2+1];
        }

    }

    cout<<best;

	return 0;

}
