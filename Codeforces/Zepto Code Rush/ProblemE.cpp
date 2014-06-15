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

int n, w;
int a[300010], b[300010];
set<pair<int,int> > s2;
set<pair<int,int> > s3;
set<pair<int,int> > s4;
set<pair<int,int> > s1;

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>w;
	for (int i=0; i<n; i++) {
        scanf("%d%d", &a[i], &b[i]);
	}


	long long suma = 0;
	for (int i=0; i<n; i++) {
        s2.insert(make_pair(a[i], i));
        s3.insert(make_pair(b[i]-a[i], i));
	}
	long long res = 1000000000LL*300000LL + 1000;

	int y = w;
	rep(it, s2) {
        if (y==0) {
            int p = (*it).second;
            s1.insert(make_pair(b[p],p));
        }
        else {
            y--;
            suma += (*it).first;
            int p = (*it).second;
            s4.insert(make_pair(a[p],p));
        }
	}
	if (y==0) res = min(res, suma);

	long long sumb = 0;

	for (int i=0; i<n; i++) {
        if (s4.size()==0) break;
        int p = (*s4.begin()).second;
        s4.erase(s4.begin());
        y -= 1;
        s1.insert(make_pair(b[p],p));
        suma -= a[p];
        if (y<0 && s4.size()>0) {
            int q = (*s4.begin()).second;
            s4.erase(s4.begin());
            s1.insert(make_pair(b[q],q));
            suma -= a[q];
            y += 1;
        }
        int x = i+1;
        long long tmp = 0;
        rep(it, s1) {
            if (x==0) break;
            x--;
            tmp += (*it).first;
        }
        cout<<suma<<endl;
        res = min(res, tmp + suma);
	}

    cout<<res<<endl;

	return 0;
}
