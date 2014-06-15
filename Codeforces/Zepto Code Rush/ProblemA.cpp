#line 2 "BigO.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n,x;
vector<pair<int,int> > v1, v2;
bool used[2010][2];

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>x;
	for (int i=0; i<n; i++) {
        int t,h,m;
        scanf("%d%d%d", &t, &h, &m);
        if (t==0) v1.push_back(make_pair(h,m));
        else v2.push_back(make_pair(h,m));
	}

	//sort(v1.begin(), v1.end());
	//sort(v2.begin(), v2.end());

	int tot = 0;
	int y = x;
	while (true) {
        int j, p = -1;
        for (int i=0; i<v1.size(); i++) if (!used[i][0]) {
            if (v1[i].second>p && v1[i].first<=y) {
                p = v1[i].second;
                j = i;
            }
        }
        if (p!=-1) {
            y += p;
            used[j][0] = 1;
            tot ++;
        }
        else break;


        p = -1;
        for (int i=0; i<v2.size(); i++) if (!used[i][1]) {
            if (v2[i].second>p && v2[i].first<=y) {
                p = v2[i].second;
                j = i;
            }
        }
        if (p!=-1) {
            y += p;
            used[j][1] = 1;
            tot++;
        }
        else break;
	}

	for (int i=0; i<2000; i++) {
        used[i][0] = 0;
        used[i][1] = 0;
	}

	int res = tot;
	tot = 0;
	y = x;
	while (true) {
        int j, p = -1;
        for (int i=0; i<v2.size(); i++) if (!used[i][1]) {
            if (v2[i].second>p && v2[i].first<=y) {
                p = v2[i].second;
                j = i;
            }
        }
        if (p!=-1) {
            y += p;
            used[j][1] = 1;
            tot++;
        }
        else break;


        p = -1;
                for (int i=0; i<v1.size(); i++) if (!used[i][0]) {
            if (v1[i].second>p && v1[i].first<=y) {
                p = v1[i].second;
                j = i;
            }
        }
        if (p!=-1) {
            y += p;
            used[j][0] = 1;
            tot ++;
        }
        else break;
	}

    if (tot>res) res = tot;
    cout<<res<<endl;

	return 0;
}
