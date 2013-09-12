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
#include <stack>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m;

int a[100010];
int b[100010];
int c[100010];

int k1[100010];
int k2[100010];

stack<int> st;
int q[100010];
int in,fn;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for (int i=0; i<n; i++) scanf("%d",b+i);
    for (int i=0; i<n; i++) scanf("%d",a+i);

    for (int i=0; i<n; i++) k1[m-1-b[i]]++;
    for (int i=0; i<n; i++) k2[a[i]]++;

    int cnt = 0;

    for (int i=m; i>=0; i--) {
        while (k1[i]--) {
            st.push(m-1-i);
        }

        while (k2[i]--) {
            if (!st.empty()) {
                c[cnt++] = i + st.top();
                st.pop();
            }
            else q[fn++] = i;
        }
    }

    while (in<fn) {
        c[cnt++] = q[in++] + st.top();
        st.pop();
    }

    for (int i=0; i<n;i++) c[i] = c[i]%m;

    sort(c,c+n);
    reverse(c,c+n);

    for (int i=0; i<n; i++) cout<<c[i]<<" ";

    return 0;

}
