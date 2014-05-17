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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
pair<int,int> p[100010];
int k;
int ind1[100010];
map<int,int> ind2;


int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    k = 0;

    cin>>n;
    for (int i=0; i<n+1; i++) p[i] = mp(-1,-1);
    for (int i=0; i<n; i++) ind1[i] = -1;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);

        if (ind2.find(a)==ind2.end()) {ind1[k] = a; ind2[a] = k++;}
        if (ind2.find(b)==ind2.end()) {ind1[k] = b; ind2[b] = k++;}

        //cout<<a<<" "<<ind2[a]<<" "<<k<<endl;

        if (p[ind2[a]].first==-1) p[ind2[a]].first = ind2[b];
        else p[ind2[a]].second = ind2[b];
        if (p[ind2[b]].first==-1) p[ind2[b]].first = ind2[a];
        else p[ind2[b]].second = ind2[a];
    }

    //cout<<k<<endl;

    int in = -1;
    for (int i=0; i<k; i++) {
        if (p[i].first==-1) {
            in = i;
            break;
        }
        if (p[i].second==-1) {
            in = i;
            break;
        }
    }

    //cout<<in<<endl;
    //cout<<p[in].first<<" "<<p[in].second<<endl;
    //int df; cin>>df;

    cout<<ind1[in]<<" ";
    int pre = -1;
    while (true) {
        if (p[in].first == pre) {
            pre = in;
            in = p[in].second;
        }
        else if (p[in].second == pre) {
            pre = in;
            in = p[in].first;
        }
        cout<<ind1[in]<<" ";
        //cout<<p[in].second<<" "<<p[in].first<<endl;
        //int df; cin>>df;
        //cout<<in<<" "<<pre<<endl;
        if (p[in].second==-1 || p[in].first==-1) break;
    }

	return 0;

}
