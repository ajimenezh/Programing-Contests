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
set<pair<int,int> >  s2;
set<pair<int,int> > s3;
set<pair<int,int> > notused;

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
        if (y==0) notused.insert(*it);
        else {
            y--;
            suma += (*it).first;
        }
	}
	if (y==0) res = min(res, suma);

	long long sumb = 0;

	for (int i=0; i<n; i++) {
        if (s3.size()==0) break;
        int p = (*s3.begin()).second;
        s3.erase(s3.begin());
        y -= 1;
        sumb += b[p];
        suma -= a[p];
        if (y<=0) res = min(res, suma+sumb);
        if (y<0 && s3.size()>0) {
            int q = (*s3.begin()).second;
            s3.erase(s3.begin());
            y += 1;
            if (b[q]<b[p]) {
                sumb += b[q] - b[p];
            }
            suma -= a[q];
        }
        cout<<i<<" "<<n<<" "<<y<<" "<<suma<<" "<<sumb<<endl;
	}

    cout<<res<<endl;

	return 0;
}
