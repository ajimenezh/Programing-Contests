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

int n, t;
string s;
int end;
int top;

bool check(int x) {
    cout<<x<<endl;
    int last = -1;
    int cnt = 0;
    int tmp = t;
    int visit = 0;
    for (int i=0; i<n; i++) {
        if (s[i]=='H') {
            if (x) {
                x--;
                visit++;
            }
            else {
                if (last==-1) {
                    last = i;
                    cnt = 1;
                }
                else cnt++;
            }
        }
        else if (s[i]=='S') {
            if (cnt<=1) {
                if (last==-1) x++;
                else {
                    tmp -= 2*(i-last);
                    if (i==n-1) tmp += (i-last);
                    last = -1;
                    cnt = 0;
                    visit++;
                }
            }
            else {
                cnt--;
                visit++;
            }
        }
        if (visit==top) break;
        tmp--;
        if (i==end && last==-1) break;
    }
    cout<<cnt<<" "<<tmp<<endl;
    if (cnt>0) return false;
    return tmp>=0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>t>>s;
    int lo = 0;
    int hi = 0;
    for (int i=0; i<n; i++) if (s[i]=='H') hi++;
    end = n-1;
    while (end>=0 && s[end]!='H') end--;

    top = hi;
    hi++;

    while (lo<hi) {
        int mi = (lo+hi)>>1;
        if (!check(mi)) lo = mi+1;
        else hi = mi;
    }
    if (lo>top) cout<<-1;
    else cout<<lo<<endl;

    return 0;

}
