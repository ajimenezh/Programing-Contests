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
#include <string.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int t;
string l,r;
string s;
long long dp1[19][7][8][9][2][128];
long long dp2[19][7][8][9][2][128];

long long solve(int pos, int r7, int r8, int r9,bool r5, int mask, bool flag) {
    if (pos == s.length()) {
        for (int i=2; i<=5; i++) {
            if ((1<<(i-2))&mask) {
                if (i==2 && r8%2!=0) return 0;
                if (i==4 && r8%4!=0) return 0;
                if (i==5 && !r5) return 0;
                if (i==3 && r9%3!=0) return 0;
            }
        }
        for (int i=7; i<10; i++) {
            if ((1<<(i-3))&mask) {
                if (i==7 && r7!=0) return 0;
                if (i==8 && r8!=0) return 0;
                if (i==9 && r9!=0) return 0;
            }
        }
        return 1;
    }
    if (flag && dp1[pos][r7][r8][r9][r5][mask]>=0) return dp1[pos][r7][r8][r9][r5][mask];
    if (!flag && dp2[pos][r7][r8][r9][r5][mask]>=0) return dp2[pos][r7][r8][r9][r5][mask];

    long long tmp = 0;
    if (flag) {
        for (int i=2; i<min((s[pos]-'0'),6); i++) tmp += solve(pos+1,(10*r7+i)%7,(10*r8+i)%8,(10*r9+i)%9,i==5,(mask|(1<<(i-2))),0);
        if (6<(s[pos]-'0')) tmp += solve(pos+1,(10*r7+6)%7,(10*r8+6)%8,(10*r9+6)%9,0,(mask|3),0);
        for (int i=7; i<(s[pos]-'0'); i++) tmp += solve(pos+1,(10*r7+i)%7,(10*r8+i)%8,(10*r9+i)%9,0,(mask|(1<<(i-3))),0);
        if (s[pos]>'1') tmp += solve(pos+1,(10*r7+1)%7,(10*r8+1)%8,(10*r9+1)%9,0,mask,0);
        if (s[pos]>'0') tmp += solve(pos+1,(10*r7+0)%7,(10*r8+0)%8,(10*r9+0)%9,1,mask,0);
        int i = s[pos]-'0';
        int m = mask;
        if (i>1 && i!=6) {
            if (i<6) m = m | (1<<(i-2));
            else m = m | (1<<(i-3));
        }
        else if (i==6)  m = m | 3;
        tmp += solve(pos+1,(10*r7+i)%7,(10*r8+i)%8,(10*r9+i)%9,i%5==0,m,1);
    }
    else {
        for (int i=2; i<6; i++) tmp += solve(pos+1,(10*r7+i)%7,(10*r8+i)%8,(10*r9+i)%9,i==5,(mask|(1<<(i-2))),0);
        for (int i=7; i<10; i++) tmp += solve(pos+1,(10*r7+i)%7,(10*r8+i)%8,(10*r9+i)%9,0,(mask|(1<<(i-3))),0);
        tmp += solve(pos+1,(10*r7+1)%7,(10*r8+1)%8,(10*r9+1)%9,0,mask,0);
        tmp += solve(pos+1,(10*r7+0)%7,(10*r8+0)%8,(10*r9+0)%9,1,mask,0);
        tmp += solve(pos+1,(10*r7+6)%7,(10*r8+6)%8,(10*r9+6)%9,0,mask|3,0);
    }

    if (flag) dp1[pos][r7][r8][r9][r5][mask] = tmp;
    if (!flag) dp2[pos][r7][r8][r9][r5][mask] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    //memset (dp2,-1,sizeof(dp2));
    for (int tt=0; tt<t; tt++) {
        cin>>l>>r;
        for (int i=l.length()-1; i>=0; i--) {
            if (l[i]!='0') {
                l[i] = char(l[i]-1);
                break;
            }
            else l[i] = '9';
        }
        long long res = 0;
        s = r;
        memset (dp1,-1,sizeof(dp1));
        memset (dp2,-1,sizeof(dp2));
        res += solve(0,0,0,0,0,0,1);
        s = l;
        memset (dp1,-1,sizeof(dp1));
        memset (dp2,-1,sizeof(dp2));
        res -= solve(0,0,0,0,0,0,1);
        cout<<res<<endl;
    }

    return 0;

}
