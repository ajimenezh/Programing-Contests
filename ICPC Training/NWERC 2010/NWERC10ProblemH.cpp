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
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,t;
priority_queue<pair<int,int> > buy;
priority_queue<pair<int,int> > sell;
int ask,bid,stock;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        ask = -1;
        bid = -1;
        stock = -1;

        while (!buy.empty()) buy.pop();
        while (!sell.empty()) sell.pop();

        cin>>n;

        for (int i=0; i<n; i++) {
            string s,d;
            int c,p;
            cin>>s>>c>>d>>d>>p;
            if (s=="sell") {
                sell.push(make_pair(-p,c));
            }
            else {
                buy.push(make_pair(p,c));
            }

            while (!buy.empty() && !sell.empty() && buy.top().first >= -sell.top().first) {
                pair<int,int> b = buy.top();
                pair<int,int> s = sell.top();
                buy.pop();
                sell.pop();

                if (s.second>b.second) {
                    s.second -= b.second;
                    sell.push(s);
                }
                else if (s.second<b.second) {
                    b.second -= s.second;
                    buy.push(b);
                }
                stock = -s.first;
            }

            if (!sell.empty()) ask = -sell.top().first;
            else ask = -1;
            if (!buy.empty()) bid = buy.top().first;
            else bid = -1;

            ask==-1?cout<<"- ":cout<<ask<<" ";
            bid==-1?cout<<"- ":cout<<bid<<" ";
            stock==-1?cout<<"- ":cout<<stock<<" ";
            cout<<endl;
        }

    }

    return 0;

}
