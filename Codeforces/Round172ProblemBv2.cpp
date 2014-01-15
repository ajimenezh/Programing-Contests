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

int n;
int a[100010];
vector<int> st;

int solve() {
    st.clear();
    int m = 0;
    for (int i=0; i<n; i++) {
        while (st.size()>0 && st.back()<a[i]) st.pop_back();
        st.push_back(a[i]);
        if (st.size()>1) m = max(m, st[st.size()-1]^st[st.size()-2]);
    }
    return m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    int res = solve();
    reverse(a,a+n);
    cout<<max(res, solve());

    return 0;

}
