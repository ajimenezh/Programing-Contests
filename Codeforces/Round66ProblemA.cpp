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

int x, y, z, k;

long long solve(int lox, int hix, int loy, int hiy, int loz, int hiz, int kk, int cur, long long tot) {
    if (kk<0) return 0;
    if (cur==3) return tot;
    if (cur==0) {
        while (lox<hix-2) {
            int l = (2*lox + hix)/3;
            int r = (lox + 2*hix)/3;

            long long fl = solve(lox, hix, loy, hiy, loz, hiz,kk-l, 1, tot*(l+1));
            long long fr = solve(lox, hix, loy, hiy, loz, hiz,kk-r, 1, tot*(r+1));

            if (fl>=fr) {
                hix = r;
            }
            else {
                lox = l;
            }
        }
        long long res = 0;
        for (int i=lox; i<=min(lox+3,x-1); i++) res = max(res, solve(lox, hix, loy, hiy, loz, hiz,kk-i, 1, tot*(i+1)) );
        return res;
    }
    if (cur==1) {
        while (loy<hiy-2) {
            int l = (2*loy + hiy)/3;
            int r = (loy + 2*hiy)/3;

            long long fl = solve(lox, hix, loy, hiy, loz, hiz,kk-l, 2, tot*(l+1));
            long long fr = solve(lox, hix, loy, hiy, loz, hiz,kk-r, 2, tot*(r+1));

            if (fl>=fr) {
                hiy = r;
            }
            else {
                loy = l;
            }
        }
        long long res = 0;
        for (int i=loy; i<=min(loy+3, y-1); i++) res = max(res, solve(lox, hix, loy, hiy, loz, hiz,kk-i, 2, tot*(i+1)) );
        return res;
    }
    if (cur==2) {
        while (loz<hiz-2) {
            int l = (2*loz + hiz)/3;
            int r = (loz + 2*hiz)/3;

            long long fl = solve(lox, hix, loy, hiy, loz, hiz,kk-l, 3, tot*(l+1));
            long long fr = solve(lox, hix, loy, hiy, loz, hiz,kk-r, 3, tot*(r+1));

            if (fl>=fr) {
                hiz = r;
            }
            else {
                loz = l;
            }
        }
        long long res = 0;
        for (int i=loz; i<=min(loz+3,z-1); i++) res = max(res, solve(lox, hix, loy, hiy, loz, hiz,kk-i, 3, tot*(i+1)) );
        return res;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x>>y>>z>>k;

    int lox, loy, loz, hix, hiy, hiz;
    lox = 0; hix = x-1;
    loy = 0; hiy = y-1;
    loz = 0; hiz = z-1;

    long long res = solve(lox, hix, loy, hiy, loz, hiz, k, 0, 1);

    cout<<res<<endl;

    return 0;

}
