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
stack<int> st;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    int n = s.length();

    if (s.length()%2!=0 || s=="+-" || s=="-+") cout<<"No"<<endl;
    else if (s.length()==2) cout<<"Yes";
    else {
        for (int i=0; i<n; i++) {
            int t;
            if (s[i]=='+') t = 1;
            else t = -1;
            if (st.size()>0 && st.top()==t) st.pop();
            else st.push(t);
        }
        if (st.size()==0) cout<<"Yes";
        else cout<<"No"<<endl;
    }

    return 0;

}
