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
#include <stack>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string s;
char buf[200010];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    stack<char> st;

    for (int i=0; i<s.length(); i++) {
        if (st.empty()) st.push(s[i]);
        else {
            if (s[i]==st.top()) {
                st.pop();
            }
            else st.push(s[i]);
        }
    }

    while (!st.empty()) {
        buf[n++] = st.top();
        st.pop();
    }
    reverse(buf,buf+n);
    buf[n] = '\n';
    cout<<buf;

    return 0;

}
