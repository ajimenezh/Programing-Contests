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

int n,k;
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>s;

    int best = 100000000;
    string ans;
    for (int i=0; i<10; i++) {
        int t = k;
        int res = 0;
        string str = s;
        for (int j=0; j<n; j++) if (str[j]-'0'==i) t--;
        for (int j=1; j<10; j++) {
            if (i+j>9 && i-j<0) break;
            if (t<=0) break;
            for (int p=0; p<n && t>0 && i+j<=9; p++) {
                if (str[p]-'0'==i+j) {
                    t--;
                    res += j;
                    str[p] = char('0'+i);
                }
            }
            for (int p=n-1; p>=0 && t>0 && i-j>=0; p--) {
                if (str[p]-'0'==i-j) {
                    t--;
                    res += j;
                    str[p] = char('0'+i);
                }
            }
        }
        //cout<<i<<" "<<res<<" "<<str<<endl;
        if (res<best) {
            best = res;
            ans = str;
        }
        else if (res==best && str<ans) ans = str;
    }

    cout<<best<<" "<<ans;

    return 0;

}
