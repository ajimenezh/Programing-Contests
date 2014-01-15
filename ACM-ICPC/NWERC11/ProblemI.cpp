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

#define INF 1000000

const double eps = 1.0e-8;

int s,r,w,p;
int sx[250100], sy[250100];
int bx[25],by[25],ex[25],ey[25];
int px[10010],py[10010];
pair<int,pair<int,int> > v[300010];
set<pair<pair<int,int>,int> > points;
set<pair<pair<int,int>,int> > walls;
vector<pair<int,int> > sol[10010];

double dist(pair<int,int> p, int k) {
    int x = p.first - sx[k];
    int y = p.second - sy[k];
    return sqrt((long long)x*x + (long long)y*y);
}

double xi,yi; // Result of the line intersection
double ua, ub;
int parallel;
bool lineIntersect(pair<double,double> p1, pair<double,double> p2, pair<double,double> p3, pair<double,double> p4) {
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    double x4 = p4.first;
    double y4 = p4.second;
    parallel = 0;
    if (fabs( (x2-x1)*(y4-y3) - (y2-y1)*(x4-x3) ) <= eps) {
        parallel = 1;
        return 0;
    }
    ua = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    ub = ((x2-x1)*(y1-y3) - (y1-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    xi = x1 + ua*(x2-x1);
    yi = y1 + ua*(y2-y1);

    return ( (xi + eps >= fmin(x1,x2)) && (xi - eps <= fmax(x1,x2)) &&
             (yi + eps >= fmin(y1,y2)) && (yi - eps <= fmax(y1,y2)) &&
             (xi + eps >= fmin(x3,x4)) && (xi - eps <= fmax(x3,x4)) &&
             (yi + eps >= fmin(y3,y4)) && (yi - eps <= fmax(y3,y4))
            );
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>s>>r>>w>>p;
        for (int i=0; i<s; i++) scanf("%d%d",sx+i,sy+i);
        for (int i=0; i<w; i++) scanf("%D%D%d%d",bx+i,by+i,ex+i,ey+i);
        for (int i=0; i<p; i++) scanf("%d%d",px+i,py+i);

        for (int i=0; i<s; i++) v[i] = make_pair(sy[i]+r, make_pair(10,i));
        for (int i=0; i<w; i++) v[i+s] = make_pair(min(by[i],ey[i]), make_pair(3,i));
        for (int i=0; i<w; i++) v[i+s+w] = make_pair(max(by[i],ey[i]), make_pair(4,i));
        for (int i=0; i<p; i++) v[i+s+w+w] = make_pair(py[i],make_pair(2,i));
        sort(v,v+s+w+w+p);

        int i=-1, j=0;

        while (++i<s+w+w+p) {
            if (v[i].second.first==10) {
                int k = v[i].second.second;

                while (j<i) {
                    if (v[j].second.first==2) {
                        if (v[i].first-v[j].first>2*r) {
                            int kk = v[i].second.second;
                            points.erase(make_pair(make_pair(px[kk],px[kk]),kk));
                            j++;
                            continue;
                        }
                    }
                    if (v[j].second.first==4) {
                        if (v[i].first-v[j].first>2*r) {
                            int kk = v[i].second.second;
                            pair<int,int> p1 = make_pair(bx[k],by[k]);
                            pair<int,int> p2 = make_pair(ex[k],ey[k]);
                            if (p1.first>p2.first) swap(p1,p2);
                            walls.erase(make_pair(p1,k));
                            j++;
                            continue;
                        }
                    }
                    break;
                }

                set<pair<pair<int,int>,int> >::iterator itp, itw, tmp;
                itp = lower_bound(points.begin(),points.end(),make_pair(make_pair(sx[k]-r,-INF),-1));
                itw = walls.begin();

                while(itp!=points.end() && (*itp).first.first<=sx[k]+r) {

                    tmp = itw;

                    int t = (*itp).second;

                    bool good = 1;

                    //cout<<"posible  "<<sx[k]<<" "<<sy[k]<<" "<<px[t]<<" "<<py[t]<<endl;

                    if (dist(make_pair(px[t],py[t]), k)<r+eps) {

                        pair<double,double> cc = make_pair(sx[k],sy[k]);
                        pair<double,double> pp = make_pair(px[t],py[t]);

                        int cnt = 0;

                        //cout<<"Sensor   point  "<<sx[k]<<" "<<sy[k]<<" "<<px[t]<<" "<<py[t]<<endl;

                        while (tmp!=walls.end()) {
                            int ww = (*tmp).second;

                            pair<double,double> a = make_pair(bx[ww],by[ww]);
                            pair<double,double> b = make_pair(ex[ww],ey[ww]);

                            //cout<<"Wall   "<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<" "<<endl;

                            if (lineIntersect(cc,pp,a,b)) {
                                if (!parallel) {
                                    cnt++;
                                    //cout<<"Intersection  "<<xi<<" "<<yi<<" de  "<<sx[k]<<" "<<sy[k]<<" "<<px[t]<<" "<<py[t]<<endl;
                                }
                            }
                            else {
                                if (parallel) {
                                    a.first += 0.01;
                                    b.first -= 0.01;
                                    if (lineIntersect(cc,pp,a,b)) good = 0;
                                }
                            }

                            tmp++;
                        }

                        if (dist((*itp).first, k)>r-cnt+eps) good = 0;
                    }
                    else good = 0;

                    if (good) {
                        sol[t].push_back(make_pair(sx[k],sy[k]));
                    }
                    itp++;
                }

            }
            if (v[i].second.first==2) {
                int k = v[i].second.second;
                //cout<<"Insertar  "<<px[k]<<" "<<py[k]<<endl;
                points.insert(make_pair(make_pair(px[k],py[k]),k));
            }
            if (v[i].second.first==3) {
                int k = v[i].second.second;
                pair<int,int> p1 = make_pair(bx[k],by[k]);
                pair<int,int> p2 = make_pair(ex[k],ey[k]);
                if (p1.first>p2.first) swap(p1,p2);
                walls.insert(make_pair(p1,k));
            }
        }

        for (int i=0; i<p; i++) {
            printf("%d ",sol[i].size());
            sort(sol[i].begin(),sol[i].end());
            for (int j=0; j<sol[i].size(); j++) {
                cout<<"("<<sol[i][j].first<<","<<sol[i][j].second<<") ";
            }
            cout<<"\n";
        }
    }

    return 0;

}
