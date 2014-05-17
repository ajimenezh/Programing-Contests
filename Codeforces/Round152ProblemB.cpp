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

int n,t;
char buf[500010];
string s;

int solve(int m)
{
    int i;
    int last = 0;
    int tmp = 0;
    for (i=0; i<n; i++)
    {
        if (s[i]=='S') m++;
        if (s[i]=='H')
        {
            last = i;
            if (m==0) break;
            else m--;
        }
        tmp++;
    }
    if (i==n && last<=t) return 1;
    if (last>t) return -1;

    int t2 = last;
    int pos = -1;
    while (i<n)
    {
        if (s[i]=='H' && m>0) {m--;}
        else if (s[i]=='H' && m<=0)
        {
            if (m==0) last = i;
            m--;
            if (pos==-1) pos = i;
        }
        else if (s[i]=='S' && m>=0) m++;
        else if (s[i]=='S' && m<-1) m++;
        else if (s[i]=='S' && m==-1)
        {
            m = 0;
            t2 += 2*(i-pos);
            pos = -1;
        }
        i++;
        t2++;
    }
    //cout<<t2<<" ";
    t2 -= (n-1-last);
    //cout<<last<<" "<<t2<<endl;
    if (m<0) return -1;
    return t2<=t ? 1 : -1;
}

int main() {

    cin>>n>>t;
    scanf("%s",buf);
    s = buf;

    int lo = 0, hi = 100100;

    int h = 0;
    int ss = 0;
    int l = 0;
    int last = 0;
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='H') {h++; last = i;}
        if (s[i]=='S')
        {
            ss++;
            l = i;
        }
    }
    if (last+1>t) {cout<<-1; return 0;}
    if (ss>=h && t>=2*l)
    {
        //cout<<0;
        //return 0;
    }
    while (lo<hi-1)
    {
        int mi = lo + (hi-lo)/2;
        //cout<<mi<<" "<<lo<<" "<<hi<<endl;
        int tmp = solve(mi);
        //cout<<tmp<<endl;
        if (tmp == -1) lo = mi;
        else hi = mi;
    }

    //cout<<solve(0)<<endl;
    if (solve(hi)==-1) cout<<-1;
    for (int i=max(lo-1,0); i<=hi; i++) if (solve(i)!=-1) {cout<<i<<endl; break;}

	return 0;

}
