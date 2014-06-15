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
#include <fstream>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

#include <bitset>  
#define NUM_THREADS 8
#define NUM_THREADS_QUERY1 6
using namespace std;

pthread_t threads[12];

pthread_mutex_t running_mutex = PTHREAD_MUTEX_INITIALIZER;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

struct timeval start, _end;

void StartCounter()
{
    gettimeofday(&start, NULL);
}
double GetCounter()
{
	double mtime, seconds, useconds;
    gettimeofday(&_end, NULL);

    seconds  = _end.tv_sec  - start.tv_sec;
    useconds = _end.tv_usec - start.tv_usec;

    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    
    return mtime;
}

string __DIR__ = "/media/OS/output/outputDir/";
string __DIR__ = "";
const int NUMBER_EDGES_PER_PERSON = 30;

struct EDGE{
    int v;
    int l;
    int op;
    EDGE(int a, int b, int c) {
        v = a;
        l = b;
        op = c;
    }
    EDGE() {}
    bool operator < ( const EDGE &ed) const {
		return v < ed.v;
	}
};
EDGE *edges;

struct PERSON{
    int numberEdges;
    vector<EDGE> inEdges;
    map<int,int> comments;
    int numberTags;
    vector<int> tagsArray;
    unsigned int date;
    set<int> tags;
    void allocateEdgesArray(void) {
        //inEdges = new EDGE[numberEdges];
        numberEdges = 0;
    }
    void deallocateEdgesArray(void) {
        //delete [] inEdges;
    }
    void allocateTagsArray(void) {
        //tagsArray = new int[numberTags];
        numberTags = 0;
    }
    void deallocateTagsArray(void) {
        //delete [] tagsArray;
    }
    PERSON() {
        numberEdges = 0;
        numberTags = 0;
        date = 0;
    }
};
PERSON *people;


struct FORUM{
    //int numberTags;
    vector<int> tagsArray;
    //int numberMembers;
    FORUM(){
        //numberMembers = 0;
        //numberTags = 0;
    }
};
FORUM *forums;

int *id;

set<int> queryTags;

int numberPeople;
int numberAllEdges;

int *commentCreator;

int locOrganisation[16000];
vector<int> *personLocWork;
vector<int> *personLocStudy;
int *personLoc;
set<pair<int,int> > have;
int parentPlace[16000];
pair<int,int> locConnections[16000];
int locConnectionsNumber;
map<string,vector<int> > placeId;

bool vis[16500];
int allTags[16500];
int numberPeopleTags[16500];
vector<int> peopleTags[16500];
int *tagsRelationsA;
int *tagsRelationsB;
int numberTags;
int numberTagId;
int numberForums;
char tagName[16500][500];
pair<string, int> tagId[16500];
int *pp;
int numberYears;

int *parent[4];
int *rk[4];
int *siz[4];

double data100[9][3] =  {{3, 53.19787045, 0.01064774},
				{6, -192.57003257, 0.07817590},
				{9, -14.53731343, 0.03171642},
				{12, -443.52380952, 0.17800454},
				{15, -190.95238095, 0.12018141},
				{18, -190.95238095, 0.12018141},
				{21, 113.05058366, 0.05058366},
				{30, 113.05058366, 0.05058366},
				{50, 258.77973568, 0.00110132}};

double data1000[9][3] = {{3, 56.51880114, 0.00614693},
				{6, 12.56942203, 0.01141976},
				{9, 12.56942203, 0.01141976},
				{12, -5.29961211, 0.01734647},
				{15, -5.29961211, 0.01734647},
				{18, 4.35413304, 0.01712964},
				{21, 58.47427627, 0.01591406},
				{30, 182.25659534, 0.01922708},
				{50, 989.77994251, 0.01101884}};
				
double data10000[9][3] = {{3, -111.89984883, 0.01222612},
				{6, 1119.70377626, 0.00917377},
				{9, 1119.70377626, 0.00917377},
				{12, 1119.70377626, 0.00917377},
				{15, 1119.70377626, 0.00917377},
				{18, 208.29913836, 0.02233326},
				{21, 208.29913836, 0.02233326},
				{30, 6209.22285506, 0.00351734},
				{50, 3137.64780251, 0.00016793}};

struct compAllTag{
	bool operator()(const int &x, const int &y) const {
		return numberPeopleTags[allTags[x]] > numberPeopleTags[allTags[y]];
	}
}compAllTags;

struct compTag{
	bool operator()(const int &x, const int &y) const {
		return people[x].numberTags > people[y].numberTags;
	}
}compTags;

int find(int x, int k) {
    if (parent[k][x]==x) return x;
    parent[k][x] = find(parent[k][x], k);
    return parent[k][x];
}

void merge(int x, int y, int l, int top = 3) {
    for (int j=0; j<min(top+1, l+1); j++) {
        int xx = find(x, j);
        int yy = find(y, j);
        if (xx==yy) continue;
        if (rk[j][xx]>rk[j][yy]) {
            parent[j][yy] = xx;
            siz[j][xx] += siz[j][yy];
        }
        else if (rk[j][xx]<rk[j][yy]) {
            parent[j][xx] = yy;
            siz[j][yy] += siz[j][xx];
        }
        else {
            rk[j][xx]++;
            parent[j][yy] = xx;
            siz[j][xx] += siz[j][yy];
        }
    }
}

int findPlace(int x, int *parentPlace) { 
    if (parentPlace[x]==x) return x;
    parentPlace[x] = findPlace(parentPlace[x], parentPlace);
    return parentPlace[x];
}

void mergePlaces(int x, int y, int p, int *parentPlace) {
    x = findPlace(x, parentPlace);
    y = findPlace(y, parentPlace);
    if (x==y) return;
    if (x==p) return;
    parentPlace[x] = y;
}

string makeStr(int x, int y) {
    string str = "";
    if (y==0) str += "0";
    while (y>0) {
        str += char(y%10+'0');
        y /= 10;
    }
    str += "|";
    if (x==0) str += "0";
    while (x>0) {
        str += char(x%10+'0');
        x /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

struct setComp {
  bool operator() (const pair<int,pair<int,int> >& lhs, const pair<int,pair<int,int> >& rhs) const {
    if (lhs.first==rhs.first) return lhs.second>rhs.second;
    return lhs.first<rhs.first;
  }
};


void insertSet1(set<pair<int,pair<int,int> > , setComp> &all, int x, int y, int h, int k) {
    if (x>y) swap(x,y);
    pair<int,int> p = make_pair(x,y);
	if ((int)all.size()<k) {
			all.insert(make_pair(h, p));
	}
	else {
		if ((*(all).begin()).first<h) {
				(all).erase((all).begin());
				(all).insert(make_pair(h, p));
		}
		else if ((*(all).begin()).first==h) {
			if (p < (*(all).begin()).second) {
					(all).erase((all).begin());
					(all).insert(make_pair(h, p));

			}
		}
	}
}

bool insertSet2(set<pair<int,pair<int,int> > , setComp> &all, set<pair<int,int> > &have, int x, int y, int h, int k) {
    if (x>y) swap(x,y);
    pair<int,int> p = make_pair(x,y);
	if ((int)all.size()<k) {
		if (have.find(p)==have.end()) {
			all.insert(make_pair(h, p));
			have.insert(p);
			return true;
		}
	}
	else {
		if ((*(all).begin()).first<h) {
			if (have.find(p)==have.end()) {
				have.erase((*(all).begin()).second);
				(all).erase((all).begin());
				(all).insert(make_pair(h, p));
				have.insert(p);
			}
		}
		else if ((*(all).begin()).first==h) {
			if (p < (*(all).begin()).second) {
				if (have.find(p)==have.end()) {
					have.erase((*(all).begin()).second);
					(all).erase((all).begin());
					(all).insert(make_pair(h, p));
					have.insert(p);
				}
			}
		}
	}
	return false;
}

int bfs(int p1, int p2, int k, int s, int *dist1, int *dist2, int *q, int &in, int &fn, int h = 100000000) {
	//if (k<0) return allDist[p1][p2];
	if (p1==p2) return 0;

    int t = 0, p;
    int l; 
    
    dist1[p1] = 1;
    q[fn++] = p1;
    dist2[p2] = 1;
    q[fn++] = p2;
    s-=2;
        
    while (in<fn) {
        p = q[in++]; 
        for (int i=people[p].numberEdges-1; i>=0; --i) {
            t = people[p].inEdges[i].v;

			l = people[p].inEdges[i].l;
            
            if (l>k) {
                if (!dist1[t] && dist1[p]) {
					if (!dist2[t]) {
						dist1[t] = 1 + dist1[p];
						q[fn++] = t;
						s--;
					}
					else dist1[t] = 1 + dist1[p];
                    //if (t==p2) return dist[t];
                }
                if (!dist2[t] && dist2[p]) {
					if (!dist1[t]) {
						dist2[t] = 1 + dist2[p];
						q[fn++] = t;
						s--;
					}
					else dist2[t] = 1 + dist2[p];
                    //if (t==p2) return dist[t];
                }
                if (dist1[t] && dist2[t]) {
					return dist1[t] + dist2[t] - 2;
				}
                if (2*dist1[t]-2>h || 2*dist2[t]-2>h) return -1;
                
                if (!s) return -1; 
            }
        }
    }

    return -1;
}

int bfs2(int p1, int p2, int *dist, int *q, int &in, int &fn, int h, int &s) {
	
	//s--;
	
	if (find(p1,0)!=find(p2,0)) return -1;
	
	int t = 0;
	bool done = 0;
	
    while (in<fn && dist[p2]==-1) {
        int p = q[in++]; 
        if (dist[p]>=h) break;
        if (s==0) break;
        for (int i=people[p].numberEdges-1; i>=0; --i) {

			t = people[p].inEdges[i].v;
            
			if (dist[t]==-1) {
				dist[t] = 1 + dist[p];
				q[fn++] = t;
				if (dist[t]>h) return dist[t];
				if (t==p2) done = 1;
				
				s--;
                if (s==0) return dist[p2];
			}
        }
        if (done) break;
    }
    return dist[p2];
}
void bfs4(int x, vector<vector<int> > &graph, int *dist, int *q, int &in, int &fn, long long *s, int size, long long best) {
	int t, p;
	size--;
	vector<int>::iterator it;
    while (in<fn) { 
        p = q[in++]; 
        
        if (s[x]+size*dist[p]>=best) {
			s[x] = best+10;
			return;
		}
        
        for (it=graph[p].begin(); it!=graph[p].end(); ++it) {

            t = *it; 
            
			if (!dist[t]) {
				dist[t] = 1 + dist[p];
				q[fn++] = t; 
				s[x] += dist[p];
				--size; 
				if (size==0) {
					return;
				}
			}
        }
    }	
    			
    return;
}

void bfs4v2(int x, vector<vector<int> > &graph, unsigned int *vis, int *q, int &in, int &fn, int *s, int size, int best) {
	unsigned int t, p;
	size--;
	vector<int>::iterator it;
	int d;
	for (int i=0; i<(numberPeople>>5)+1; i++) vis[i] = 0;
	vis[x>>5] |= ((unsigned int)1<<(x^((x>>5)<<5)));
    while (in<fn) { 
        p = q[in++]; 
        d = p>>20; 
        p = p ^ (d<<20); 
        ++d; 
        
        if (s[x]+size*d>=best) {
			s[x] = best+10;
			//for (int i=0; i<fn; i++) viss[q[i]] = 0;
			fn = 0;
			return;
		}
        
        for (it=graph[p].begin(); it!=graph[p].end(); ++it) {

            t = *it; 
			if ((vis[t>>5] & ((unsigned int)1<<(t^((t>>5)<<5)))) == 0 ) {
				vis[t>>5] |= ((unsigned int)1<<(t^((t>>5)<<5)));
				//viss[t] = 1;
				q[fn++] = t | (d<<20); 
				s[x] += d;
				//s[x] += dist[p] + 1;
				--size; 
				//if (s[x]+size*dist[p]>=best) {
					//s[x] = best+10;
					//return;
				//}
				if (size==0) {
					//for (int i=0; i<fn; i++) viss[q[i]] = 0;
					fn = 0;
					return;
				}
			}
        }
    }	
    
	fn = 0;
					
    return;
}

vector<pair<int,int> > L[10000];

int queryDistance(int a, int b) {
	int i=0, j=0;
	int d = 1000000;
	while (i<(int)L[a].size() && j<(int)L[b].size()) {
		if (i==(int)L[a].size()-1) j++;
		else if (L[a][i].first==L[b][j].first) {
			d = min(L[a][i].second+L[b][j].second, d);
			i++; j++;
		}
		else if (L[a][i].first<L[b][j].first) i++;
		else if (L[a][i].first>L[b][j].first) j++;
	}
	return d;
}

void prunedBFS(int p) {
	int q[10000];
	int P[10000];
	for (int i=0; i<10000; i++) P[i] = 100000;
	int in = 0, fn = 0;
	q[fn++] = p;
	P[p] = 0;
	int tot = 0;
	while(in<fn) {
		int u = q[in++];
		tot++;
		if (queryDistance(p, u) <= P[u]) {
			continue;
		}
		L[u].push_back(make_pair(p, P[u]));
		for (int i=0; i<people[u].numberEdges; i++) if (P[people[u].inEdges[i].v]==100000) {
			P[people[u].inEdges[i].v] = P[u] + 1;
			q[fn++] = people[u].inEdges[i].v;
		}
	}
	cout<<tot<<endl;
}

void preprocess2HopCoverIndex() {
	for (int i=0; i<10000; i++) {
		//cout<<i<<endl;
		prunedBFS(i);
	}
}

void solveDistQuery4(int p, vector<vector<int> > &graph, int *dist, int* distAprox, int* q, int &in, int &fn, int size) {
	int t = 0;
	size--;
    while (in<fn) {
        int p = q[in++]; 
        for (int i=(int)graph[p].size()-1; i>=0; --i) {

            t = graph[p][i]; 
            
			if (dist[t]==-1) {
				dist[t] = 1 + dist[p];
				distAprox[t] += dist[t];
				q[fn++] = t;
				
				size--; 
				if (size==0) return;
			}
        }
    }
    return;
}

void updateEdge(int a, int b) { 
	int lo = 0;
	int hi = people[a].numberEdges-1;
	int mi; 
	if (hi<0) return;
	if (b>people[a].inEdges[hi].v || b<people[a].inEdges[0].v) return;
	while (lo<hi) {
		mi = (lo+hi)>>1; 
		if (people[a].inEdges[mi].v<b) lo = ++mi;
		else hi = mi;
	}
	
	if (lo < people[a].numberEdges && people[a].inEdges[lo].v==b) {
		++people[a].inEdges[lo].l;
	}
}

void processEdge(int a, int b, int t) {
	int lo = 0;
	int hi = people[b].numberEdges-1;
	int mi;
	
	while (lo<hi) {
		mi = (lo+hi)>>1;
		if (people[b].inEdges[mi].v<a) lo = ++mi;
		else hi = mi;
	}
	
	if (lo < people[b].numberEdges && people[b].inEdges[lo].v==a) {
		int tmp = min( people[b].inEdges[lo].l, people[a].inEdges[t].l);
		people[a].inEdges[t].l = tmp;
		people[b].inEdges[lo].l = tmp;
	}
}

int searchTagId(string s) {
    int lo = 0;
    int hi = numberTagId-1;
    int mi;
    while (lo<hi) {
        mi = (lo+hi)>>1;
                
        if (tagId[mi].first<s) lo = mi+1;
        else hi = mi;
    }
    return tagId[lo].second;
}

int searchCreator(unsigned long long t, pair<unsigned long long,unsigned long long> *buffer, long long a, long long b, int mod = 1000000007) {
	int lo = a;
	int hi = b;
	int mi;
	while (lo<hi) {
		mi = (lo+hi)>>1;
		if (buffer[mi%mod].first<t) lo = mi+1;
		else hi = mi;
	}
	return buffer[lo%mod].second;
}

void *readComments(void *threadid) {
	
	//cout << GetCounter() <<"\n";
	
	string str = "comment_replyOf_comment.csv";
    ifstream reply((__DIR__ + str).c_str(),ios::in);
    
    str = "comment_hasCreator_person.csv";
    ifstream creator((__DIR__ + str).c_str(),ios::in);
    
    int m = 500000;
    
    pair<unsigned long long,unsigned long long> *buffer = new pair<unsigned long long,unsigned long long>[m];
    bool done = 0;
    char buf[100];
    unsigned long long a = 0, b = 0;
    
    reply.getline(buf, 100, '\n');
    creator.getline(buf, 100, '\n');
    
    pair<long long,long long> tmp = make_pair(-1,-1);
    
    char *p;
    
    while (true) {
		int tot = 0; 
		int k = 0;
		
		for (int j=0; j<m && creator.getline(buf, 100, '\n'); j++) {
			a = 0, b = 0;
			p = buf;
			while (*p!='|') {a = a*10 + (*p-'0'); ++p;}
			++p;
			while (*p) {b = b*10 + (*p-'0'); ++p;}
			
			buffer[tot++] = make_pair(a,b);
			
			//cout<<i<<endl;
			//cout<<a<<" "<<b<<" "<<tot<<endl;
		}

		if (done) {
			while ((int)buffer[k].first!=tmp.first) k++;
			a = buffer[k].second;
			b = searchCreator(tmp.second, buffer, 0, k-1);
			updateEdge(a,b);
			done = 0;
		}
		
		while (reply.getline(buf, 100, '\n')) {
			a = 0, b = 0;
			p = buf;
			while (*p!='|') {a = a*10 + (*p-'0'); ++p;}
			++p;
			while (*p) {b = b*10 + (*p-'0'); ++p;}
			
			if (a>buffer[tot-1].first) {
				tmp = make_pair(a, b);
				done = 1;
				break;
			}
			
			while (buffer[k].first!=a) k++;
			a = buffer[k].second;
			b = searchCreator(b, buffer, 0, k-1);
			updateEdge(a,b);
		}
		
		if (!done) break;
		
	}
	
	for (int i=0; i<numberPeople; i++) {
		for (int j=0; j<people[i].numberEdges; j++) {
			if (i<people[i].inEdges[j].v) {
				processEdge(i, people[i].inEdges[j].v, j);
				merge(i, people[i].inEdges[j].v, people[i].inEdges[j].l);
			}
		}
	}
	
	//cout << GetCounter() <<"\n";
	
	pthread_exit(NULL);
    
}

struct thread_data{
	long long lo, hi;
	long long size;
	char *creator, *comment;
};

void *parallelReadCommentsv2(void *threadarg) {
	
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	long long lo = my_data->lo;
	long long hi = my_data->hi; 
	
	char *creator = my_data->creator;
	char *comment = my_data->comment;
	comment = comment + lo;
	long long bytes = hi-lo+1;
		
	while (*comment!='\n') {comment++; bytes--;}
	comment++; bytes--;
	
	unsigned long long a = 0, b = 0, d = 0, c = 0;
	while (*comment!='|') {a = a*10 + (*comment-'0'); comment++; bytes--;}
	comment++; bytes--;
	while (*comment!='\n') {b = b*10 + (*comment-'0'); comment++; bytes--;}
	comment++; bytes--;
	a /= 10;
	b /= 10;	
	//lo = my_data->lo; 
	//hi = my_data->lo + 100000;
	lo = 0; 
	hi = my_data->size - 2;
	while (*(creator+lo)!='\n') lo++;
	lo++;
	while (*(creator+hi)!='\n') hi--;
	hi--;

	while (lo<hi) {
		long long mi = (lo+hi)>>1;
		long long t = mi;
		while (*(creator+mi)!='\n') mi--;
		mi++;
		c = 0, d = 0;
		while (*(creator+mi)!='|') {c = c*10 + (*(creator+mi)-'0'); mi++;}
		mi++;
		while (*(creator+mi)!='\n') {d = d*10 + (*(creator+mi)-'0');  mi++;}
		mi++;
		c /= 10;
		if (c<a) lo = mi;
		else hi = t;
	}

	int m = 500009;
	unsigned long long *buffer = new unsigned long long[m];
	char *buf = creator + max((lo-100000), 0LL);
	long long k = 0, tot = 0;
	
	if (*buf!='|' && (*buf<'0' || *buf>'9')) {while (*buf!='\n') {buf++;} buf++;}
	while (true) {
		c = 0, d = 0;
		while (*buf!='|') {c = c*10 + (*buf-'0'); buf++;}
		buf++;
		while (*buf!='\n') {d = d*10 + (*buf-'0');  buf++;}
		buf++;
		c /= 10;
		//buffer[k++] = make_pair(c,d);
		buffer[c%m] = d;
		tot++;
		if (k>=m) k -= m;
		if (c==a) {
			a = d;
			//b = searchCreator(b, buffer, max(tot-10000, 0LL), tot-1, m);
			b = buffer[b%m];
			updateEdge(a,b);
			break;
		}
	}
	
	
	char *p = comment;
	char *q = buf;
	
	while (bytes>0) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		a /= 10;
		b /= 10;
		while (true) {
			c = 0, d = 0;
			while (*q!='|') {c = c*10 + (*q-'0'); ++q; }
			++q; 
			while (*q!='\n') {d = d*10 + (*q-'0'); ++q; }
			++q;
			c /= 10;
			//buffer[k] = make_pair(c, d);
			buffer[c%m] = d;
			++tot;
			++k;
			if (k>=m) k -= m;
			if (c==a) break;
		}
				
		//a = buffer[(tot-1+m)%m].second;
		a = buffer[a%m];
		//b = searchCreator(b, buffer, max(tot-10000, 0LL), tot-1, m);
		b = buffer[b%m];

		updateEdge(a,b);
	} 
	
	pthread_exit(NULL);
}

void *parallelReadComments(void *threadarg) {
	
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	long long lo = my_data->lo;
	long long hi = my_data->hi; 
	
	char *creator = my_data->creator;
	char *comment = my_data->comment;
	comment = comment + lo;
	long long bytes = hi-lo+1;
		
	while (*comment!='\n') {comment++; bytes--;}
	comment++; bytes--;
	
	unsigned long long a = 0, b = 0, d = 0, c = 0;
	while (*comment!='|') {a = a*10 + (*comment-'0'); comment++; bytes--;}
	comment++; bytes--;
	while (*comment!='\n') {b = b*10 + (*comment-'0'); comment++; bytes--;}
	comment++; bytes--;
		
	lo = 0; 
	hi = my_data->size - 2;
	while (*(creator+lo)!='\n') lo++;
	lo++;
	while (*(creator+hi)!='\n') hi--;
	hi--;
	
	while (lo<hi) {
		long long mi = (lo+hi)>>1;
		long long t = mi;
		while (*(creator+mi)!='\n') mi--;
		mi++;
		c = 0, d = 0;
		while (*(creator+mi)!='|') {c = c*10 + (*(creator+mi)-'0'); mi++;}
		mi++;
		while (*(creator+mi)!='\n') {d = d*10 + (*(creator+mi)-'0');  mi++;}
		mi++;
		
		if (c<a) lo = mi;
		else hi = t;
	}
		
	int m = 500009;
	pair<unsigned long long, unsigned long long> *buffer = new pair<unsigned long long, unsigned long long>[m];
	char *buf = creator + max((lo-100000), 0LL);
	long long k = 0, tot = 0;
	
	if (*buf!='|' && (*buf<'0' || *buf>'9')) {while (*buf!='\n') {buf++;} buf++;}
	while (true) {
		c = 0, d = 0;
		while (*buf!='|') {c = c*10 + (*buf-'0'); buf++;}
		buf++;
		while (*buf!='\n') {d = d*10 + (*buf-'0');  buf++;}
		buf++;
		buffer[k++] = make_pair(c,d);
		tot++;
		if (k>=m) k -= m;
		if (c==a) {
			a = d;
			b = searchCreator(b, buffer, max(tot-10000, 0LL), tot-1, m);
			updateEdge(a,b);
			break;
		}
	}
	
	
	char *p = comment;
	char *q = buf;
	
	while (bytes>0) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		
		while (true) {
			c = 0, d = 0;
			while (*q!='|') {c = c*10 + (*q-'0'); ++q; }
			++q; 
			while (*q!='\n') {d = d*10 + (*q-'0'); ++q; }
			++q;
			
			buffer[k] = make_pair(c, d);
			++tot;
			++k;
			if (k>=m) k -= m;
			if (c==a) break;
		}
				
		a = buffer[(tot-1+m)%m].second;
		b = searchCreator(b, buffer, max(tot-10000, 0LL), tot-1, m);

		updateEdge(a,b);
		
		p += 100; bytes -= 100;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
	} 
	
	pthread_exit(NULL);
}

void readCommentsv2() {
	//cout << GetCounter() <<"\n";
	
	string str = "comment_hasCreator_person.csv";
	int creator = open((__DIR__ + str).c_str(), O_RDONLY);
	//int creator = shm_open((__DIR__ + str).c_str(), O_CREAT | O_EXCL | O_RDONLY, S_IRUSR | S_IWUSR);
    str = "comment_replyOf_comment.csv";
	int comment = open((__DIR__ + str).c_str(), O_RDONLY);
	
	//cout << GetCounter() <<"\n";
	
    long long size1 = lseek(creator, 0, SEEK_END);
    char *buf1 = (char *)mmap(NULL, size1, PROT_READ, MAP_SHARED, creator, 0); 
    long long size2 = lseek(comment, 0, SEEK_END);
    char *buf2 = (char *)mmap(NULL, size2, PROT_READ, MAP_SHARED, comment, 0); 
    
    int n = NUM_THREADS_QUERY1;
    thread_data *td = new thread_data[n];
    for (int i=0; i<n; i++) {
		// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		td[i].comment = buf2; 
		td[i].creator = buf1;
		td[i].lo = (i*size2)/n;
		td[i].hi = ((i+1)*size2)/n-1;
		td[i].size = size1;
		
		pthread_create(&threads[i], NULL, parallelReadCommentsv2, (void *) &td[i]);
	}
	
	for (int i=0; i<n; i++) {
		pthread_join (threads[i], NULL); 
	}
	
	close(creator);
	close(comment);
    munmap(buf1, size1); 
    munmap(buf2, size2); 
    
    //cout << GetCounter() <<"\n";
    
    //cerr << GetCounter() <<"\n"; 
    
    for (int i=0; i<numberPeople; i++) {
		for (int j=0; j<people[i].numberEdges; j++) {
			if (i<people[i].inEdges[j].v) {
				processEdge(i, people[i].inEdges[j].v, j);
				merge(i, people[i].inEdges[j].v, people[i].inEdges[j].l);
			}
		}
	}

}

void *parallelReadForumHasMemberPerson(void *threadarg) {
	
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	long long lo = my_data->lo;
	long long hi = my_data->hi; 
	
	char *p = my_data->creator + lo;
	long long bytes = hi-lo+1;
	
	while (*p!='\n') {p++; bytes--;}
	p++; bytes--;
	
	unsigned long long a,b;
	while (bytes>0) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
		//forums[a/10].membersArray[forums[a/10].numberMembers++] = b;
		rep(it, forums[a/10].tagsArray) {
			people[b].tags.insert(*it);
		}
	} 
		
	
	pthread_exit(NULL);
}

void *parallelReadForumHasMemberPersonv2(void *threadarg) {
	
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	char *p = my_data->creator;
	
	long long _lo = 0;
	while (*(p+_lo)!='\n') {_lo++;}
	_lo++;
		
	for (int i=my_data->lo; i<my_data->hi; i++) if (forums[i].tagsArray.size()>0) {
		long long lo = _lo;
		//TODO
		long long hi = my_data->size-1;

		long long c = 0, d = 0;
		while (lo<hi) {
			long long mi = (lo+hi)>>1;
			long long t = mi;
			while (*(p+mi)!='\n') mi--;
			mi++;
			c = 0, d = 0;
			while (*(p+mi)!='|') {c = c*10 + (*(p+mi)-'0'); mi++;}
			mi++;
			while (*(p+mi)!='|') {d = d*10 + (*(p+mi)-'0');  mi++;}
			mi++;
			while (*(p+mi)!='\n') {mi++;}
			mi++;
			c /= 10;

			if (id[c]<i) lo = mi;
			else hi = t;
		}
		//cerr<<lo<<endl;
		//cerr<<id[c]<<" "<<i<<endl;
		//if (id[c]!=i) continue;
		//rep(it, forums[id[c]].tagsArray) {
		//	people[d].tags.insert(*it);
		//}
		//cerr<<id[c]<<" "<<d<<endl;
		long long t = lo;
		long long a,b;
		while (t<my_data->size-1) {
			a = 0, b = 0;
			while (*(p+t)!='|') {a = a*10 + (*(p+t)-'0'); ++t;}
			++t;
			while (*(p+t)!='|') {b = b*10 + (*(p+t)-'0');  ++t;}
			++t;
			while (*(p+t)!='\n') {++t;}
			++t;
			a /= 10;
			//cerr<<a<<endl;
			//cerr<<"---"<<id[a]<<" "<<b<<endl;
			if (id[a]!=i) break;
			//cerr<<"a   "<<id[a]<<endl;
			//forums[a/10].membersArray[forums[a/10].numberMembers++] = b;
			rep(it, forums[id[a]].tagsArray) {
				people[b].tags.insert(*it);
			}
		}
		_lo = lo;
	}
	
	//char *p = my_data->creator + lo;
	//long long bytes = hi-lo+1;
	
	//while (*p!='\n') {p++; bytes--;}
	//p++; bytes--;
	
	//unsigned long long a,b;
	//while (bytes>0) {
		//a = 0, b = 0;
		//while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		//++p; --bytes;
		//while (*p!='|') {b = b*10 + (*p-'0');  ++p; --bytes;}
		//++p; --bytes;
		//while (*p!='\n') {++p; --bytes;}
		//++p; --bytes;
		////forums[a/10].membersArray[forums[a/10].numberMembers++] = b;
		//rep(it, forums[a/10].tagsArray) {
			//people[b].tags.insert(*it);
		//}
	//} 
		
	
	pthread_exit(NULL);
}

void *parallelReadForumHasTag(void *threadarg) {
	
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	long long lo = my_data->lo;
	long long hi = my_data->hi; 
	
	char *p = my_data->creator + lo;
	long long bytes = hi-lo+1;
	
	while (*p!='\n') {p++; bytes--;}
	p++; bytes--;
	
	unsigned long long a,b;
	while (bytes>0) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		//forums[a/10].membersArray[forums[a/10].numberMembers++] = b;
		//if (a/10>2*numberPeople) cerr<<a<<endl;
		//if (!id[a/10]) id[a/10] = ++cnt;
		if (queryTags.find(b)!=queryTags.end()) forums[a/10].tagsArray.push_back(b); 
		//else forums[a/10].tagsArray.push_back(b);
		
		//cerr<<a/10<<" "<<id[a/10]<<endl;
	} 
		
	
	pthread_exit(NULL);
}

void readForumHasMemberPersonv3() {
	string str = "forum_hasMember_person.csv";
	int input = open((__DIR__ + str).c_str(), O_RDONLY);
	
	//cout << GetCounter() <<"\n";
	
    long long size = lseek(input, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, input, 0); 
    
    int n = NUM_THREADS;
    thread_data *td = new thread_data[NUM_THREADS];
    for (int i=0; i<NUM_THREADS; i++) {
		// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		td[i].creator = buf;
		td[i].lo = ((long long)(i)*numberForums)/n;
		td[i].hi = ((long long)((i)+1)*numberForums)/n-1;
		td[i].size = size;
		
		pthread_create(&threads[i], NULL, parallelReadForumHasMemberPersonv2, (void *) &td[i]);
	}
    
    //n = 1;
    //for (int i=1; i<2; i++) {
		//// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		//td[i].creator = buf;
		//td[i].lo = ((i-1)*size)/n;
		//td[i].hi = (((i-1)+1)*size)/n-1;
		
		//pthread_create(&threads[i], NULL, parallelReadForumHasMemberPerson, (void *) &td[i]);
	//}
	
	for (int i=0; i<NUM_THREADS; i++) {
		pthread_join (threads[i], NULL); 
	}
	
	close(input);
    munmap(buf, size); 

}

void readForumHasMemberPersonv2() {
	string str = "forum_hasTag_tag.csv";
	int input = open((__DIR__ + str).c_str(), O_RDONLY);
	
	//cout << GetCounter() <<"\n";
	
    long long size = lseek(input, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, input, 0); 
    
    int n = NUM_THREADS;
    thread_data *td = new thread_data[NUM_THREADS];
    for (int i=0; i<NUM_THREADS; i++) {
		// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		td[i].creator = buf;
		td[i].lo = ((i)*size)/n;
		td[i].hi = (((i)+1)*size)/n-1;
		
		pthread_create(&threads[i], NULL, parallelReadForumHasTag, (void *) &td[i]);
	}
	
	for (int i=0; i<NUM_THREADS; i++) {
		pthread_join (threads[i], NULL); 
	}
	
	close(input);
    munmap(buf, size); 
    
	str = "forum_hasMember_person.csv";
	input = open((__DIR__ + str).c_str(), O_RDONLY);
	
	//cout << GetCounter() <<"\n";
	
    size = lseek(input, 0, SEEK_END);
    buf = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, input, 0); 
    
    n = NUM_THREADS;
    for (int i=0; i<NUM_THREADS; i++) {
		// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		td[i].creator = buf;
		td[i].lo = ((i)*size)/n;
		td[i].hi = (((i)+1)*size)/n-1;
		td[i].size = size;
		
		pthread_create(&threads[i], NULL, parallelReadForumHasMemberPerson, (void *) &td[i]);
	}
    
    //n = 1;
    //for (int i=1; i<2; i++) {
		//// read file buf2 from (i*size2)/n to ((i+1)*size2)/n-1
		//td[i].creator = buf;
		//td[i].lo = ((i-1)*size)/n;
		//td[i].hi = (((i-1)+1)*size)/n-1;
		
		//pthread_create(&threads[i], NULL, parallelReadForumHasMemberPerson, (void *) &td[i]);
	//}
	
	for (int i=0; i<NUM_THREADS; i++) {
		pthread_join (threads[i], NULL); 
	}
	
	close(input);
    munmap(buf, size); 

}

void *test(void *threadid) {
	
	//cout << GetCounter() <<"\n";
	
	string str = "comment_hasCreator_person.csv";
	int creator = open((__DIR__ + str).c_str(), O_RDONLY);
    str = "comment_replyOf_comment.csv";
	int comment = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size1 = lseek(creator, 0, SEEK_END);
    char *buf1 = (char *)mmap(NULL, size1, PROT_READ, MAP_PRIVATE, creator, 0); 
    off_t size2 = lseek(comment, 0, SEEK_END);
    char *buf2 = (char *)mmap(NULL, size2, PROT_READ, MAP_PRIVATE, comment, 0); 
    
    int m = 500000;
    
    pair<unsigned long long,unsigned long long> *buffer = new pair<unsigned long long,unsigned long long>[m];
    unsigned long long a = 0, b = 0, c = 0, d = 0;
    
    char *p = buf2;
    char *q = buf1;
    
    int bytes = size2;
    int tot = 0;
    int k = 0;

	while (*p!='\n') {++p; --bytes;}
	++p; --bytes;
	while (*q!='\n') {++q;}
	++q; 
	
    while (bytes>0) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		
		while (true) {
			c = 0, d = 0;
			while (*q!='|') {c = c*10 + (*q-'0'); ++q; }
			++q; 
			while (*q!='\n') {d = d*10 + (*q-'0'); ++q; }
			++q;
			
			buffer[k] = make_pair(c, d);
			++tot;
			++k;
			if (k>=m) k -= m;
			if (c==a) break;
		}
				
		a = buffer[(tot-1+m)%m].second;
		b = searchCreator(b, buffer, max(tot-10000, 0), tot-1, m);
		//cout<<a<<" "<<b<<endl;
		updateEdge(a,b);
	} 
	
	close(creator);
	close(comment);
    munmap(buf1, size1); 
    munmap(buf2, size2); 
    
    //cout << GetCounter() <<"\n";
    
    for (int i=0; i<numberPeople; i++) {
		for (int j=0; j<people[i].numberEdges; j++) {
			if (i<people[i].inEdges[j].v) {
				processEdge(i, people[i].inEdges[j].v, j);
				merge(i, people[i].inEdges[j].v, people[i].inEdges[j].l);
			}
		}
	}
	
	pthread_exit(NULL);
    
}

void *readCommentReplyOfComment(void *threadid) {
	
	cout<<"START"<<endl;
	
	cout << GetCounter() <<"\n";
    
    string str = "comment_replyOf_comment.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0); 
    
    cout << GetCounter() <<"\n";

    
    int bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    unsigned long long b = 0; 
    int t1 = 0, tot = 0;
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
				
		a = commentCreator[a/10];
		b = commentCreator[b/10];
		updateEdge(a,b);
		tot++;

    } cout<<tot<<" "<<t1<<endl;
    close(f);
    munmap(buf, size); 
    
    cout << GetCounter() <<"\n";

	
	for (int i=0; i<numberPeople; i++) {
		for (int j=0; j<people[i].numberEdges; j++) {
			if (i<people[i].inEdges[j].v) {
				processEdge(i, people[i].inEdges[j].v, j);
				merge(i, people[i].inEdges[j].v, people[i].inEdges[j].l);
			}
		}
	}
	
	cout << GetCounter() <<"\n";

	cout<<"END"<<endl;
	
    pthread_exit(NULL);
}

void *readCommentHasCreatorPerson(void *threadid) {
	
    string str = "comment_hasCreator_person.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0); 
    
    cout<<size<<endl;
    
    int bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    unsigned long long b = 0; 
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
				
		commentCreator[a/10] = b;

    } 
    close(f);
    munmap(buf, size); 
	
    pthread_exit(NULL);
}

void readComment() {
	
    string str = "comment.csv";
    
    ifstream input2((__DIR__ + str).c_str(),ios::in);
    char buf[100000];
    input2.getline(buf, 100, '\n');
    cout<<buf<<endl;
    int t = 0;
    while (input2.getline(buf, 100000, '\n')) {
		char *p = buf;
		while (*p) p++;
		t++;
	}
	cout<<t<<endl;
	input2.close();
	input2.clear(); cout<<"hola"<<endl;
	
	//int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    //off_t size = lseek(f, 0, SEEK_END);
    //char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0); 
    
    //cout<<size<<endl;
    
    //int bytes = size;
    //char *p = buf;
    //while (*p!='\n') {++p; --bytes;}
    //++p; --bytes;
    //unsigned long long a = 0;
    //unsigned long long b = 0; 
    //while(bytes) {
		//while (*p!='\n') { ++p; --bytes;}
		//++p; --bytes;

    //} 
    //close(f);
    //munmap(buf, size); 
}

void *readPersonKnowsPerson(void *threadid) {
	
	//cout << GetCounter() <<"\n";

    for (int i=0; i<numberPeople; i++) {
        for (int j=0; j<4; j++) {
            parent[j][i] = i;
            siz[j][i] = 1;
            rk[j][i] = 0;
        }
    }
    
    //cout << GetCounter() <<"\n";
    
    string str = "person_knows_person.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    long long size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, f, 0); 
    
    long long bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    unsigned long long b = 0; 
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
				
		if (a<b) {
			people[a].inEdges.push_back(EDGE(b,0,0));
			people[b].inEdges.push_back(EDGE(a,0,0));
			people[a].numberEdges++;
			people[b].numberEdges++;
			//edges[++numberAllEdges-1] = EDGE(a,b,0);
			merge(a, b, 0, 0);
		}

    } 
    close(f); 
    munmap(buf, size); 
    
    //cout << GetCounter() <<"\n";

    //for (int i=0; i<numberPeople; ++i) people[i].allocateEdgesArray(); 
    
    //for (int i=0; i<numberAllEdges; ++i) { 
		//int v1 = edges[i].v;
		//int v2 = edges[i].l;
		////int l = checkEdge(v1, v2);
		////edges[i].level = l;
		////merge(v1,v2,l);
        //people[v1].inEdges[people[v1].numberEdges++] = EDGE(v2,0,0);
        //people[v2].inEdges[people[v2].numberEdges++] = EDGE(v1,0,0);
        ////merge(v1, v2, 0, 0);
    //}
    
    //for (int i=0; i<numberPeople; ++i) sort(people[i].inEdges, people[i].inEdges + people[i].numberEdges);
    for (int i=0; i<numberPeople; ++i) sort(people[i].inEdges.begin(), people[i].inEdges.end());
    
    //cout << GetCounter() <<"\n";

    pthread_exit(NULL);
}

void *readPersonHasInterestTag(void *threadid) {
	
    string str = "person_hasInterest_tag.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    long long size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, f, 0);

    long long bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    unsigned long long b = 0;
    numberTags = 0; 
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes; 
		
		if (!vis[b]) {
			allTags[numberTags++] = b;
			vis[b] = 1;
		}
		numberPeopleTags[b]++;
		people[a].numberTags++;
		people[a].tagsArray.push_back(b);
		peopleTags[b].push_back(a);
		//peopleTags[b][numberpeopleTags[b]++] = a;
		//people[a].tagsArray[people[a].numberTags++] = b;
		//tagsRelationsA[k] = a;
		//tagsRelationsB[k++] = b; 

    } 
    close(f);
    munmap(buf, size); 
	
	//for (int i=0; i<numberPeople; i++) {
		//cout<<i<<" "<<numberPeople<<endl;
		//people[i].allocateTagsArray(); 
	//}
	//for (int i=0; i<numberTags; i++) {
	//	int k = allTags[i];
	//	peopleTags[k] = new int[numberPeopleTags[k]];
	//	numberPeopleTags[k] = 0;
	//}
	
	//for (int i=0; i<k; i++) {
		//a = tagsRelationsA[i]; b = tagsRelationsB[i];  
		//peopleTags[b][numberPeopleTags[b]++] = a;
		//people[a].tagsArray[people[a].numberTags++] = b;
	//} 
	
	//sort(allTags, allTags+numberTags, compAllTags);
    
    for (int i=0; i<numberPeople; ++i) sort(people[i].tagsArray.begin(), people[i].tagsArray.end());
    
    pp = new int[numberPeople]; 
    for (int i=0; i<numberPeople; i++) pp[i] = i;
    sort(pp, pp + numberPeople, compTags);
    
    pthread_exit(NULL);
}

void *readPerson(void *arg) {

    string str = "person.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    long long size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    long long bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    int year, month, day;
    while(bytes) {
		a = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (!(*p>='0' && *p<='9') || !(*(p+1)>='0' && *(p+1)<='9') || !(*(p+2)>='0' && *(p+2)<='9')) {++p; --bytes;}
		int tot = 0;
		char * buffer = new char[11];
		while (*p!='|' && tot<10) {buffer[tot++] = *p; ++p; --bytes; }
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
		
		year = 0, month = 0, day = 0;
		year = (buffer[0]-'0')*1000 + (buffer[1]-'0')*100 + (buffer[2]-'0')*10 + (buffer[3]-'0');
		month = (buffer[5]-'0')*10 + (buffer[6]-'0');
		day = (buffer[8]-'0')*10 + (buffer[9]-'0');

		people[a].date = day + month*32 + year*13*32;
		
    }
    close(f);
    munmap(buf, size);
    pthread_exit(NULL);
}

void *readTag(void *arg) {
	
	string str = "tag.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    int bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0;
    numberTagId = 0;
    while(bytes) {
		a = 0;
		str = "";
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		int tot = 0;
		while (*p!='|') {tagName[a][tot++] = *p; str += *p; ++p; --bytes;}
		while (*p!='\n') { ++p; --bytes;}
		++p; --bytes;
		
		tagName[a][tot++] = '\n';
		tagId[numberTagId++] = make_pair(str, a);

    } 
    close(f);
    munmap(buf, size);

    sort(tagId, tagId+numberTagId);
    
    pthread_exit(NULL);
}

void *readPlaceIsPartOfPlace(void *arg) {

    string str = "place_isPartOf_place.csv";
    ifstream input((__DIR__ + str).c_str(),ios::in);
    char buf[200];
    unsigned int a = 0, b = 0;
    int i = 0;
    input.getline(buf, 100, '\n');
    while (input.getline(buf, 100, '\n')) {
		a = 0, b = 0; 
		i = 0;
		while (buf[i]!='|') {a = a*10 + (buf[i]-'0'); ++i;}
		++i;
		while (buf[i]) {b = b*10 + (buf[i]-'0'); ++i;}

		locConnections[locConnectionsNumber++] = make_pair(a,b);
	}

    pthread_exit(NULL);
}


int totalVisited;
void *readPlaces(void *arg) {
	char *buf2;
	
    string str = "organisation_isLocatedIn_place.csv";
    ifstream input((__DIR__ + str).c_str(),ios::in);
    char buf[100];
    unsigned int a = 0, b = 0;
    int i = 0;
    input.getline(buf, 100, '\n');
    while (input.getline(buf, 100, '\n')) {
		a = 0, b = 0; 
		i = 0;
		while (buf[i]!='|') {a = a*10 + (buf[i]-'0'); ++i;}
		++i;
		while (buf[i]) {b = b*10 + (buf[i]-'0'); ++i;}
		locOrganisation[a/10] = b;
		totalVisited++;
	}
	input.close();
	input.clear();

    str = "person_isLocatedIn_place.csv";
    ifstream input2((__DIR__ + str).c_str(),ios::in);
    input2.getline(buf, 100, '\n');
    while (input2.getline(buf, 100, '\n')) {
		a = 0, b = 0; 
		i = 0;
		while (buf[i]!='|') {a = a*10 + (buf[i]-'0'); ++i;}
		++i;
		while (buf[i]) {b = b*10 + (buf[i]-'0'); ++i;}
		personLoc[a] = b;
		totalVisited++;
	}
	input2.close();
	input2.clear();

    str = "person_studyAt_organisation.csv";
    int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size = lseek(f, 0, SEEK_END);
    buf2 = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    int bytes = size;
    char *p = buf2;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    a = 0, b = 0;
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
		
		personLocStudy[a].push_back(locOrganisation[b/10]);
		totalVisited++;
		
    }
    close(f);
    munmap(buf2, size);

	str = "person_workAt_organisation.csv";
	f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    size = lseek(f, 0, SEEK_END);
    buf2 = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    bytes = size;
    p = buf2;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    a = 0, b = 0;
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
		
		personLocWork[a].push_back(locOrganisation[b/10]);
		totalVisited++;
		
    }
    close(f);
    munmap(buf2, size);
	
    pthread_exit(NULL);
}

void *readPlace(void *arg) {
	string str = "place.csv";
    ifstream input((__DIR__ + str).c_str(),ios::in);
    
    char buf[500];
    unsigned int a = 0;
    int i = 0;
    input.getline(buf, 500, '\n');

	unsigned k = 0;
    while (input.getline(buf, 500, '\n')) {
		a = 0; 
		i = 0;
		string str;
		while (buf[i]!='|') {a = a*10 + (buf[i]-'0'); ++i;}
		++i;
		while (buf[i]!='|') {str += buf[i]; ++i;}
		
		if (placeId.find(str)==placeId.end()) {
			vector<int> v(1,a);
			placeId[str] = v;
		}
		else placeId[str].push_back(a);
		
		k = max(a, k);
	}

    pthread_exit(NULL);
}

void *readForumHasTagTag(void *arg) {
	
	string str = "forum_hasTag_tag.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    long long size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    long long bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0, b = 0;
    int cnt = 0; 
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		
		//forums[a/10].tagsArray[forums[a/10].numberTags++] = b;
		
		if (!id[a/10]) id[a/10] = ++cnt;
		if (queryTags.find(b)!=queryTags.end()) forums[id[a/10]].tagsArray.push_back(b); 
		
    }
    close(f);
    munmap(buf, size);

    //for (int i=0; i<numberForums; i++) { 
    //    sort(forums[i].tagsArray, forums[i].tagsArray+forums[i].numberTags);
    //}
    pthread_exit(NULL);
}

void *readForumHasMemberPerson(void *arg) {
	string str = "forum_hasMember_person.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    off_t size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    int bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    unsigned long long a = 0, b = 0;
    while(bytes) {
		a = 0, b = 0;
		while (*p!='|') {a = a*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {b = b*10 + (*p-'0');  ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;

		//forums[a/10].membersArray[forums[a/10].numberMembers++] = b;
		
    }
    close(f);
    munmap(buf, size);

    pthread_exit(NULL);
}


string tag2str(int x) {
    string a;
    int i = 0;
    while (true) {
        if (tagName[x][i]=='\n') break;
        a += tagName[x][i++];
    }
    return a;
}

bool tagNameOrder(int x, int y) {
    string a,b;
    a = tag2str(x);
    b = tag2str(y);
    return a>b;
}

int find2(int a, int *parent2) {
    if (a==parent2[a]) return a;
    parent2[a] = find2(parent2[a], parent2);
    return parent2[a];
}

void merge2(int a, int b, int *parent2, int *rk2, int *sz2) {
    a = find2(a, parent2);
    b = find2(b, parent2);
    if (a==b) return;
    if (rk2[a]<rk2[b]) {
        parent2[a] = b;
        sz2[b] += sz2[a];
    }
    else if (rk2[a]>rk2[b]) {
        parent2[b] = a;
        sz2[a] += sz2[b];
    }
    else {
		parent2[a] = b;
        sz2[b] += sz2[a];
        rk2[b]++;
    }
}

bool existEdge(int a, int b) {
	int lo = 0;
	int hi = people[a].numberEdges-1;
	int mi;
	while (lo<hi) {
		mi = (lo+hi)>>1;
		if (people[a].inEdges[mi].v<b) lo = mi+1;
		else hi = mi;
	}
	if (lo < people[a].numberEdges && people[a].inEdges[lo].v==b) return true;
	else return false;
}

//struct myclass {
  //bool operator() (const pair<int,int> &a, const pair<int,int> &b) const { 
	  //return a.first<b.first;
	//}
//};

vector<pair<pair<int,int>, pair<int,int> > > qq1;
vector<pair<int, pair<int,int> > > qq;
vector<pair<pair<int,int>, pair<int,int> > > qq2;
vector<int> ans;
int cur, cnt;
vector<vector<string> > ansvs;
vector<int> type;
vector<vector<pair<int,int> > > ansvp;
vector<string> query3Strings;
int allquerys3;
int query4Iterations;
int totalQuery, totalQuery1;
vector<int> OutputType;

bool checkTag(int id, int tag) {
    //Can do BS if neccessary
    //cout<<id<<" "<<forums[id].numberTags<<endl;
    //int lo = 0, hi = forums[id].numberTags-1, mi;
    //while (lo<hi) {
		//mi = (lo+hi)>>1;
		//if (forums[id].tagsArray[mi]<tag) lo = mi+1;
		//else hi = mi;
	//}
	//return forums[id].tagsArray[lo]==tag;
    //for (int i=0; i<forums[id].numberTags; ++i) { 
    //    if (forums[id].tagsArray[i]==tag) return true;
    //}
    return false;
}

int find4(int x, int *par) {
	if (x==par[x]) return x;
	par[x] = find4(par[x], par);
	return par[x];
}

void merge4(int x, int y, int *par, int *rk, int *siz) {
	x = find4(x, par);
	y = find4(y, par);
	if (x==y) return;
	if (rk[x]>rk[y]) {
		par[y] = x;
		siz[x] += siz[y];
	}
	else if (rk[x]<rk[y]) {
		par[x] = y;
		siz[y] += siz[x];
	}
	else {
		par[y] = x;
		siz[x] += siz[y];
		rk[x]++;
	}
	return;
}

void spanningTree(int p, vector<vector<int> > &graph, vector<vector<int> > &tree) {

	int q[10000];
	bool vis[10000];
	for (int i=0; i<10000; i++) vis[i] = 0;
	int in = 0, fn = 0;
	
	q[fn++] = p;
	vis[p] = 1;
	while (in<fn) {
		p = q[in++];
		for (int i=0; i<(int)graph[p].size(); i++) {
			int t = graph[p][i];
			if (!vis[t]) {
				vis[t] = 1;
				q[fn++] = t;
				tree[p].push_back(t);
				tree[t].push_back(p);
			}
		}
	}
	
}

int findCenter(int p, vector<vector<int> > &tree) {
	int d[10000];
	for (int i=0; i<10000; i++) d[i] = tree[i].size();
	
	int q[10000];
	int in = 0, fn = 0;
	
	for (int i=0; i<10000; i++) if (d[i]==1) q[fn++] = i;
	
	while (in<fn) {
		p = q[in++];
		d[p]--;
		for (int i=0; i<(int)tree[p].size(); i++) {
			if (d[tree[p][i]]>0) {
				d[tree[p][i]]--;
				if (d[tree[p][i]]==1) {
					q[fn++] = d[tree[p][i]];
				}
			}
		}
	}
	
	return p;

}

int distQ4(vector<vector<int> >&graph, int x, int y) {
	int *dist = new int[graph.size()];
	int *q = new int[graph.size()];
	for (int i=0; i<(int)graph.size(); i++) dist[i] = -1;
	int in = 0, fn = 0;
	dist[x] = 0;
	q[fn++] = x;
	while (in<fn) {
		int p = q[in++];
		if (p==y) return dist[y];
		for (int i=0; i<(int)graph[p].size(); i++) {
			int t = people[p].inEdges[i].v;
			t = graph[p][i];
			if (dist[t]==-1) {
				dist[t] = 1 + dist[p];
				q[fn++] = t;
			}
		}
	}
	return -1;
}

void query4(int tt, int K, int t, int *par, int *siz, int *rk, int *q, int *dist) {
	
	bool *hasTag = new bool[numberPeople];  
	
	for (int i=0; i<numberPeople; i++) hasTag[i] = 0;
	
	//cout<<forums[127].numberMembers<<endl;
	//cout<<numberForums<<endl;
	//for (int i=0; i<numberForums; ++i) {
		////cout<<"hola"<<endl;
		//if (checkTag(i,t)) {
			////cout<<"holafg"<<endl;
			//for (int j=0; j<forums[i].numberMembers; ++j) {
				////hasTag[forums[i].membersArray[j]] = 1;
				////cout<<i*10<<" "<<j<<" "<<forums[i].membersArray[j]<<endl;
				////cout<<forums[i].numberMembers<<endl;
			//}
		//}
	//} 
	
	int tot = 0;
	for (int i=0; i<numberPeople; i++) {
		if (people[i].tags.find(t)!=people[i].tags.end()) {
			hasTag[i] = 1;
			tot++;
		}
	}
	
	vector<vector<int> > graph(numberPeople, vector<int>());
	int *personEdges = new int[numberPeople];
	
	vector<int> tagged(tot, 0);
	tot = 0;
	for (int i=0; i<numberPeople; i++) if (hasTag[i]) tagged[tot++] = i;
	
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k];
		
		par[i] = i;
		siz[i] = 1;
		rk[i] = 0;
	}

	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k]; 
		personEdges[i] = 0;
	}
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k]; 
		for (int j=people[i].numberEdges-1; j>=0; --j) { 
			if (hasTag[people[i].inEdges[j].v]) {
				personEdges[i]++;
				//personEdges[people[i].inEdges[j].v]++;
			}
		}
	}
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k];  
		graph[i].resize(personEdges[i]);
	}
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k];  
		personEdges[i] = 0;
	}
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k];  
		for (int j=people[i].numberEdges-1; j>=0; --j) { 
			if (hasTag[people[i].inEdges[j].v]) {
				graph[i][personEdges[i]++] = people[i].inEdges[j].v; 
				//graph[people[i].inEdges[j].v][personEdges[people[i].inEdges[j].v]++] = i; 
				merge4(i, people[i].inEdges[j].v, par, rk, siz);
			}
		}
	} 
	
	//for (int k=0; k<tagged.size(); k++) cout<<tagged[k]<<" "; cout<<endl;
	
	long long *s = new long long[numberPeople];
	//for (int i=0; i<numberGraphPeople; i++) cout<<graphPeople[i]<<" "; cout<<endl;
	for (int k=(int)tagged.size()-1; k>=0; --k) {
		int i = tagged[k];
		s[i] = 0;
		dist[i] = 0;
	}
	
	
	//vector<vector<int> > connectedComponents;
	//map<int,int> compId;
	//int totalComps = 0;
	//vector<int> compSize;
	
	//for (int k=(int)tagged.size()-1; k>=0; --k) {
		//int i = tagged[k];
		
		//int comp = find4(i, par);
		
		//if (compId.find(comp)==compId.end()) {
			//compId[comp] = totalComps++;
			//connectedComponents.push_back(vector<int> ());
			//compSize.push_back(1);
			
			////connectedComponents[totalComps-1].push_back(i);
		//}
		//else {
			////connectedComponents[compId[comp]].push_back(i);
			
			//compSize[compId[comp]]++;
		//}
	//} 
	//for (int k=0; k<totalComps; k++) {
		//connectedComponents[k].resize(compSize[k]);
		//compSize[k] = 0;
	//}
	//for (int k=(int)tagged.size()-1; k>=0; --k) {
		//int i = tagged[k];
		
		//int comp = find4(i, par);
		
		//int compIndex = compId[comp];
		
		//connectedComponents[compIndex][compSize[compIndex]++] = i;

	//}
	
	//connectedComponents.clear();
	//connectedComponents.push_back(vector<int> (tagged.size(), 0));
	//int rr = 0;
	//for (int k=(int)tagged.size()-1; k>=0; --k) {
		//int i = tagged[k];
		//connectedComponents[0][rr++] = i;

	//}
	
	int in = 0, fn = 0;
	tot = 0;
	pair<long double, int> *allPeople = new pair<long double, int>[numberPeople];
	
	//int *weightedDegree = new int[numberPeople];
	
	//for (int i=0; i<numberPeople; i++) {
		//weightedDegree[i] = 0;
		//weightedDegree[i] = graph[i].size()*graph[i].size();
		//for (int j=graph[i].size()-1; j>=0; --j) weightedDegree[i] += graph[graph[i][j]].size()-1;
		//if (hasTag[i]) cout<<i<<" "<<graph.size()<<endl;
	//}
	
			
	//int *distAprox = new int[numberPeople];
	
	set<pair<long double, int> > all;
	
	//for (int t=(int)connectedComponents.size()-1; t>=0; t--) {  
	{
		
		//int size = siz[find4(connectedComponents[t][0], par)];
		int size;
		
		//vector<pair<int,int> > v(connectedComponents[t].size(), make_pair(0,0));
		vector<pair<int,int> > v(tagged.size(), make_pair(0,0));
		for (int k=(int)tagged.size()-1; k>=0; --k) { 
			int i = tagged[k]; 
			v[k] = make_pair(-graph[i].size(), i);
			
			
			//cout<<size<<" "<<distAprox[i]<<endl;
			
			//v[k] = make_pair(-tmp, i);
		} 
		sort(v.begin(), v.end());
		
		//cout<<size<<endl;
		
		//vector<vector<int> > tree(10000, vector<int>(0,0));
		
		//cout<<"START  "<<tt<<endl;
		
		//spanningTree(v[0].second, tree, graph);
		
		//int center = findCenter(v[0].second, tree);
		
		//for (int i=0; i<graph[center].size(); i++) cout<<graph[center][i]<<endl;
		
		long long best = 1LL<<60;

		///*New method*/
		//for (int j=(int)connectedComponents[t].size()-1; j>=0; --j) distAprox[connectedComponents[t][j]] = 0;
		//for (int j=(int)connectedComponents[t].size()-1; j>=0; --j) dist[connectedComponents[t][j]] = -1;
		
		//int iterations = 0;
		
		//iterations = min(iterations, size);
		
		//for (int k=0; k<iterations; k++) {
			
			//int p = v[k].second;
			
			//in = 0, fn = 0;
			
			//q[fn++] = p;
			
			//dist[p] = 0;
			
			//solveDistQuery4(p, graph, dist, distAprox, q, in, fn, size); 
			
			//for (int j=0; j<fn; j++) dist[q[j]] = -1;
			
		//}
		
		////vector<pair<double,int> > v(connectedComponents[t].size(), make_pair(0,0));
		//for (int k=(int)connectedComponents[t].size()-1; k>=0; --k) { 
			//int i = connectedComponents[t][k]; 
			////v[k] = make_pair(-graph[i].size(), i);
			
			//double tmp;
			//if (size>1 && iterations>0) tmp = 1.0 / ((1.0*size*distAprox[i]/iterations/(size-1.0)));
			//else tmp = 0.0;
			
			////cout<<size<<" "<<distAprox[i]<<endl;
			
			////v[k] = make_pair(-tmp, i);
		//} 
		////sort(v.begin(), v.end());
			
		//for (int j=(int)connectedComponents[t].size()-1; j>=0; --j) dist[connectedComponents[t][j]] = 0;
		
		//cerr<<"-----"<<endl;
		//cout<<K<<" "<<v.size()<<" ";
		int k;
		//int ma = 0;
		
		int iterations = 0;
		if (numberPeople<=1000) {
			iterations = 120 + K*sqrt(K)*5;
			iterations += max(numberYears, 0)*50;
		}
		else if (numberPeople<=10000) {
			if (v.size()<2000) {
				iterations = 800 + max(0, K-10)*20;
			}
			else {
				int x = v.size();
				for (int k=0; k<9; k++) {
					if (k==0 && K<data100[k][0]) {
						iterations = (int)(data100[k][1] + data100[k][2]*x) + 50;
					}
					else if (k==8 && K>data100[k][0]) {
						int t1 = (int)(data100[k][1] + data100[k][2]*x) + 50;
						int t2 = (int)(data100[k-1][1] + data100[k-1][2]*x) + 50;
						iterations = t1 + 1.0*(t1-t2)/20*(K-50)*sqrt(K-50) + 100;
					}
					else {
						if (data100[k][0]<K && data100[k+1][0]>K) {
							iterations = max((int)(data100[k][1] + data100[k][2]*x), (int)(data100[k+1][1] + data100[k+1][2]*x)) + 50;
						}
						else if (data100[k][0]==K) {
							iterations = (int)(data100[k][1] + data100[k][2]*x) + 50;
						} 
					}
				}
			}
			iterations = max(iterations, max(150, K*25));
			iterations += max(numberYears-3, 0)*100;
			iterations += 20;
		}	
		else if (numberPeople<=100000) {
			if (v.size()<2500) {
				iterations = 1200 + max(0, K-10)*50;
			}
			else {
				int x = v.size();
				for (int k=0; k<9; k++) {
					if (k==0 && K<data1000[k][0]) {
						iterations = (int)(data1000[k][1] + data1000[k][2]*x) + 50;
					}
					else if (k==8 && K>data1000[k][0]) {
						int t1 = (int)(data1000[k][1] + data1000[k][2]*x) + 50;
						int t2 = (int)(data1000[k-1][1] + data1000[k-1][2]*x) + 50;
						iterations = t1 + 1.0*(t1-t2)/20*(K-50)*sqrt(K-50) + 200;
					}
					else {
						if (data1000[k][0]<=K && data1000[k+1][0]>=K) {
							iterations = max((int)(data1000[k][1] + data1000[k][2]*x), (int)(data1000[k+1][1] + data1000[k+1][2]*x)) + 50;
						}
					}
				}
			}
			iterations = max(iterations, max(250, K*50));
			iterations += (numberYears-1)*250;
		}
		else {
			int x = v.size();
			for (int k=0; k<9; k++) {
				if (k==0 && K<data10000[k][0]) {
					iterations = (int)(data10000[k][1] + data10000[k][2]*x) + 500;
				}
				else if (k==8 && K>data10000[k][0]) {
					int t1 = (int)(data10000[k][1] + data10000[k][2]*x) + 500;
					int t2 = (int)(data10000[k-1][1] + data10000[k-1][2]*x) + 500;
					iterations = t1 + 1.0*(t1-t2)/20*(K-50)*sqrt(K-50) + 1000;
				}
				else {
					if (data10000[k][0]<=K && data10000[k+1][0]>=K) {
						iterations = max((int)(data10000[k][1] + data10000[k][2]*x), (int)(data10000[k+1][1] + data10000[k+1][2]*x)) + 500;
					}
				}
			}
			iterations = max(iterations, max(2000, K*150));
			iterations += (numberYears-1)*800;
			
//			iterations *= (double)numberPeople/1000000;
		}
		//cerr<<iterations<<endl;
		for (k=0; k<min(iterations, (int)v.size()); ++k) { 
			int i = v[k].second; 
			
			size = siz[find4(i, par)];
			
			if ((int)all.size()==K) 	
				best = min(best, (long long)(1.0*(size-1.0)*(size-1.0) / (*all.begin()).first / (tagged.size()-1.0)+0.1) + 1 );
			
			//if ((-1.0*v[0].first+v[k].first)/(-v[0].first)>0.33) {
				//cerr<<k<<endl;
				//break;
			//}
			
			//for (int j=(int)connectedComponents[t].size()-1; j>=0; --j) dist[connectedComponents[t][j]] = 0;
			dist[i] = 1;
			in = 0, fn = 0;
			q[fn++] = i;
			
			bfs4(i, graph, dist, q, in, fn, s, size, best);
			//bfs4v2(i, graph, vis, q, in, fn, s, size, best);
			
			for (int i=fn-1; i>=0; --i) dist[q[i]] = 0;
			
			if (s[i]==best+10) continue;
			
			//cout<<best<<endl;
			
			//cout<<i<<" "<<graph[i].size()<<" "<<s[i]<<" "<<r[i]<<" "<<size<<endl;
			
			
			//for (int j=(int)connectedComponents[t].size()-1; j>=0; --j) {
			//	cout<<dist[connectedComponents[t][j]]<<endl;
			//}
			
			//sleep(2);
			
			long double centrality = ((long double)(size-1.0)*(size-1.0));
			if (tagged.size()>1 && s[i]>0) centrality /= ((long double)(tagged.size()-1.0)*s[i]);
			else centrality = 0.0;
			
			//if (r[i]!=size) cout<<"ERROR "<<" "<<r[i]<<" "<<size<<endl;
			
			//cout<<i<<" "<<v[k].first<<" "<<centrality<<endl;
			
			//int tot = 0;
			
			//for (int j=0; j<graph[i].size(); j++) tot += graph[graph[i][j]].size();
			//cout<<tot<<endl;

			//cout<<graph[i]<<" "<<centrality<<" "<<s[graph[i]]<<" "<<r[graph[i]]<<endl;
			//cout<<numberGraphPeople<<endl;
			
			//allPeople[tot++] = make_pair(-centrality, i);
			if ((int)all.size()<K) {
				all.insert(make_pair(centrality, -i));
				if ((int)all.size()==K) best = min(best, (long long)(1.0*(size-1.0)*(size-1.0) / (*all.begin()).first / (tagged.size()-1.0)+0.1) + 1 );
			}
			else {
				//best = min(best, s[i]+1);
				if ((*all.begin())<make_pair(centrality, -i)) {
					//ma = k;
					//cerr<<" "<<k<<" "<<v[k].first<<" "<<v[0].first<<endl;
					//if ((-1.0*v[0].first+v[k].first)/(-v[0].first)>0.33) {
					//	cerr<<k<<" "<<(-1.0*v[0].first+v[k].first)/(-v[0].first)<<endl;
						//break;
					//}
					all.erase(all.begin());
					all.insert(make_pair(centrality, -i));
					best = min(best, (long long)(1.0*(size-1.0)*(size-1.0) / (*all.begin()).first / (tagged.size()-1.0)+0.1) + 1 );
				}
			}
		}
		//cerr<<ma<<endl;
		//cout<<ma<<" "<<(-1.0*v[0].first+v[ma].first)/(-v[0].first)<<" "<<-v[ma].first<<endl;
		v.clear();
		//cout<<k<<endl;
		
		//for (set<pair<double, int> >::iterator it = all.begin(); it!=all.end(); ++it)  allPeople[tot++] = make_pair(-(*it).first, -(*it).second);
		//all.clear();
	} 
	
	for (set<pair<long double, int> >::iterator it = all.begin(); it!=all.end(); ++it)  allPeople[tot++] = make_pair(-(*it).first, -(*it).second);
	
	sort(allPeople, allPeople+tot);
	
	//vector<int> w;
	
	for (int i=0; i<K; i++) {
		//pthread_mutex_lock(&running_mutex);
		if (i==tot) break;
		ansvp[tt].push_back(make_pair(allPeople[i].second, 0));
		//pthread_mutex_unlock(&running_mutex);
		//cout<<allPeople[i].second<<" "<<allPeople[i].first<<endl;
				
		//w.push_back(allPeople[i].second);
	}
	
	//cout<<"----"<<endl;
	//for (int i=1; i<w.size(); i++) {
		//cout<<graph[w[i]].size()<<endl;
		//int k = 0;
		//for (int j=0; j<graph[w[i]].size(); j++) k += graph[graph[w[i]][j]].size();
		//cout<<k<<endl;
		//for (int j=0; j<i; j++) {
			//cout<<i<<" "<<j<<" "<<distQ4(graph, w[j], w[i])<<endl;;
		//}
	//}
	
	//cout << "4:  " << GetCounter() <<"\n";

	delete [] personEdges;
	graph.clear();
	delete [] s;
}

bool checkPlace(int x, int p, int *parentPlace) { 
    if (findPlace(personLoc[x], parentPlace)==p) return true;
    for (int i=0; i<(int)personLocWork[x].size(); i++) {
        if (findPlace(personLocWork[x][i], parentPlace)==p) return true;
    }
    for (int i=0; i<(int)personLocStudy[x].size(); i++) {
        if (findPlace(personLocStudy[x][i], parentPlace)==p) return true;
    }
    return false;
}

int similarity(int x, int y) {
	int tot = 0;
	
	int i=0, j=0;
	
	while (i<people[x].numberTags && j<people[y].numberTags) {
		if (people[x].tagsArray[i] == people[y].tagsArray[j]) {
			tot++;
			++i; ++j;
		}
		else if (people[x].tagsArray[i] < people[y].tagsArray[j]) {
			++i; 
		}
		else if (people[x].tagsArray[i] > people[y].tagsArray[j]) {
			++j; 
		}
	}

	return tot;
}

int totQ3;

void findMatches0(set<pair<int,pair<int,int> > , setComp> &all, int x, int k, int h, int p, int *parentPlace, vector<int> (&interestTags)[16500], int *dist, int *q, int *A, int *possible, bool *vis) {
	
	//if ((int)all.size()==k && people[x].numberTags<(*(all).begin()).first) return;
	
    //google::sparse_hash_map<int,int> A;
    //google::dense_hash_map<int,int> A;
	//map<int,int> A;
	
    //Comprobar BFS
    //initBfs(x);
    
    int tot = 0;
    for (int i=people[x].numberTags-1; i>=0; --i) {
        for (int j=0; j<(int)interestTags[people[x].tagsArray[i]].size(); ++j) {
			//totQ3++;
			if ((int)all.size()==k && people[interestTags[people[x].tagsArray[i]][j]].numberTags<(*(all).begin()).first) {
				//while ((int)interestTags[people[x].tagsArray[i]].size()>j) interestTags[people[x].tagsArray[i]].pop_back();
				continue;
			}
			if (!vis[interestTags[people[x].tagsArray[i]][j]]) {
				possible[tot++] = interestTags[people[x].tagsArray[i]][j];
				vis[interestTags[people[x].tagsArray[i]][j]] = 1;
			}
            A[interestTags[people[x].tagsArray[i]][j]]++;
        }
    } 
    
    if (tot==0) return;
    
    int ss = siz[0][find(x, 0)] - 1; 

    int in = 0, fn = 0;
    //for (int i=0; i<10000; i++) dist[i] = -1;
    dist[x] = 0;
    q[fn++] = x;
    
    int val;
    int xx, yy;
    
    //int can = 0;
    
    for (int i=tot-1; i>=0; --i) {
		int t = possible[i];
		int r = A[t];
		
		if ((int)all.size()==k && r<(*(all).begin()).first) {
			A[t] = 0;
			vis[t] = 0;
			swap(possible[i], possible[tot-1]);
			tot--;
			continue;
		}
		
		xx = find(x, 0);
		yy = find(t, 0);
		if (xx!=yy) {
			A[t] = 0;
			vis[t] = 0;
			swap(possible[i], possible[tot-1]);
			tot--;
		}
    }  
    
    for (int i=0; i<tot; i++) {
		int t = possible[i];
		int r = A[t];
		//cout<<"hola  "<<endl;
		//cout<<x<<" "<<(*it).first<<" "<<bfs2(x, (*it).first, dist, q, in, fn, h, siz[find(x, 0)][0])<<endl;;
		//cout<<h<<" "<<(*it).second<<" "<<bfs(x, (*it).first)<<endl;
		
		A[t] = 0;
        vis[t] = 0;
		
		if ((int)all.size()==k && r<(*(all).begin()).first) continue;
		//if ((int)all.size()==k && (*it).second==(*(all).begin()).first && (*it).first>(*(all).begin()).second.first) continue;
		
		//if (can<=2) val = bfs(x, t, -1, ss, dist1, dist2, q, in, fn, h);
		//else val = bfs2(x, t, dist, q, in, fn, h, ss);
		
		
		if (tot>0) {
			val = bfs2(x, t, dist, q, in, fn, h, ss);
		}
		else {
			fn = 0;
			//ss = ss+1;
			//val = bfs(x, t, -1, ss, dist1, dist2, q, in, fn, h);
			//for (int i=0; i<fn; i++) dist1[q[i]] = 0;
			//for (int i=0; i<fn; i++) dist2[q[i]] = 0;
			fn = 0;
		}
		//in = 0, fn = 0;
		//int val = bfs(x, (*it).first, -1, ss, dist1, dist2, q, in, fn, h);
		
        if (val<=h && val!=-1) {
			insertSet1(all, x, t, r, k);
        }
        
    }      
    
	for (int i=0; i<fn; i++) dist[q[i]] = -1;

    
    //free(dist);
    //free(q);
}


void solveQuery3(set<pair<int,pair<int,int> > , setComp> &all, int k,int h,int p, int *parentPlace, vector<int> (&interestTags)[16500], int *A, bool *vis, int *possible, int *dist, int *q) {
	//Comprobar BFS
    //for (int i=0; i<1000; i++) dist[i] = -1;
    
    //(all).clear();
    
	for (int i=0; i<numberTags; i++) interestTags[allTags[i]].clear();
	
	for (int i=numberPeople-1; i>=0; i--) vis[i] = 0;
	for (int i=numberPeople-1; i>=0; i--) A[i] = 0;
    
    //int* dist1 = new int[numberPeople];
	//int* dist2 = new int[numberPeople];

	//for (int i=0; i<numberPeople; i++) dist1[i] = 0;
	//for (int i=0; i<numberPeople; i++) dist2[i] = 0;
    
    for (int i=0; i<numberPeople; i++) dist[i] = -1;

    for (int i=0; i<numberPeople; ++i) {

		if ((int)all.size()==k && people[pp[i]].numberTags<(*(all).begin()).first) break;
		
		if (!checkPlace(pp[i],p, parentPlace)) continue;
		
        findMatches0(all, pp[i], k, h, p, parentPlace,  interestTags, dist, q, A, possible, vis); 

        for (int j=people[pp[i]].numberTags-1; j>=0; --j) {
            interestTags[people[pp[i]].tagsArray[j]].push_back(pp[i]);
        }
    }
    
    //delete [] dist1;
    //delete [] dist2;
}


void solveQuery3v2(set<pair<int,pair<int,int> > , setComp> &all, int k,int h,int p, int *parentPlace) {
	//Comprobar BFS
    //for (int i=0; i<1000; i++) dist[i] = -1;
    
    //(all).clear();
    
	set<pair<int,int> > done;
	
	int* hasTag = new int[numberPeople];
	int* dist1 = new int[numberPeople];
	int* dist2 = new int[numberPeople];
	int* q = new int[numberPeople];
	int in = 0, fn = 0;
	for (int i=0; i<numberPeople; i++) dist1[i] = -1;
	for (int i=0; i<numberPeople; i++) dist2[i] = -1;
	
	for (int i=0; i<numberPeople; ++i) hasTag[i] = 0;

	for (int ii=0; ii<numberTags; ii++) { 
		int i = allTags[ii]; 
		
		for (int j=numberPeopleTags[i]-1; j>=0; --j) {
			hasTag[peopleTags[i][j]] = 1;
		}
		
		if (numberPeopleTags[i]>-1) {
			for (int j=numberPeopleTags[i]-1; j>=0; --j) if (checkPlace(peopleTags[i][j],p, parentPlace)) {
				
				if ((int)all.size()==k && people[peopleTags[i][j]].numberTags<(*(all).begin()).first) break;
				
				for (int k=j-1; k>=0; --k) if (peopleTags[i][k]<peopleTags[i][j] && checkPlace(peopleTags[i][k],p, parentPlace)){
					if (done.find(make_pair(peopleTags[i][j], peopleTags[i][k]))==done.end()) {
						//done.insert(make_pair(peopleTags[i][j], peopleTags[i][k]));
						
						totQ3++;
						
						if ((int)all.size()==k && people[peopleTags[i][k]].numberTags<(*(all).begin()).first) break;
						
						int val = similarity(peopleTags[i][j], peopleTags[i][k]);
						
						if ((int)all.size()==k && val<(*(all).begin()).first) break;
						
						in = 0, fn = 0;
						
						int d = bfs(peopleTags[i][j], peopleTags[i][k], -1, siz[0][find(peopleTags[i][j], 0)], dist1, dist2, q, in, fn, h); 
							
						for (int t=0; t<fn; t++) {
							dist1[q[t]] = -1;
							dist2[q[t]] = -1;
						} 
						
						//cout<<peopleTags[i][j]<<" "<<peopleTags[i][k]<<" "<<d<<" "<<h<<endl;

						if (d>h || d==-1) continue;
						
						//if (peopleTags[i][j]==1814 && peopleTags[i][k]==230) cout<<val<<" "<<d<<endl;

						insertSet1(all, peopleTags[i][j], peopleTags[i][k], val, k);
					}
					
				}
			} 
		}
		else {
			for (int j=numberPeopleTags[i]-1; j>=0; --j) if (checkPlace(peopleTags[i][j],p, parentPlace)) {
				for (int k=people[peopleTags[i][j]].numberEdges-1; k>=0; --k) if (peopleTags[i][j]>people[peopleTags[i][j]].inEdges[k].v) {
					if (hasTag[people[peopleTags[i][j]].inEdges[k].v] && checkPlace(people[peopleTags[i][j]].inEdges[k].v,p, parentPlace) ) {
						if (done.find(make_pair(peopleTags[i][j], people[peopleTags[i][j]].inEdges[k].v))==done.end()) {
							done.insert(make_pair(peopleTags[i][j], people[peopleTags[i][j]].inEdges[k].v));
							
							int d = bfs(peopleTags[i][j], people[peopleTags[i][j]].inEdges[k].v, -1, siz[0][find(peopleTags[i][j], 0)], dist1, dist2, q, in, fn, h);
							
							for (int t=0; t<fn; t++) {
								dist1[q[t]] = -1;
								dist2[q[t]] = -1;
							} 
							in = 0, fn = 0;

							if (d>h || d==-1) continue;
							
							int val = similarity(peopleTags[i][j], people[peopleTags[i][j]].inEdges[k].v);
							
							insertSet1(all, peopleTags[i][j], people[peopleTags[i][j]].inEdges[k].v, val, k);
							
						}
					}
				}
			} 
		}
	} 
}

void query3(int tt, int k, int h, int pp, int *parentPlace, int *dist, int *q, vector<int> (&interestTags)[16500], int *A, int *possible, bool *vis) {
	set<pair<int,pair<int,int> > , setComp> allTotal;
	
	vector<int> allPlaces = placeId[query3Strings[pp]]; 
			
	for (int ppp=0; ppp<(int)allPlaces.size(); ppp++) {
		int p = allPlaces[ppp]; 

		set<pair<int,pair<int,int> > , setComp> all;
			
		for (int i=0; i<16000; i++) parentPlace[i] = i;
		for (int i=0; i<locConnectionsNumber; i++) {
			//cout<<locConnections[i].first<<" "<<locConnections[i].second<<endl;
			//if (locConnections[i].first>52000 || locConnections[i].second>52000) cout<<i<<endl;
			mergePlaces(locConnections[i].first, locConnections[i].second, p, parentPlace);
		}
		solveQuery3(all, k, h, p, parentPlace, interestTags, A, vis, possible, dist, q);
		//cout<<totQ3<<endl;
		int K = k - all.size(); 
		if (K>0) {
			int *allPersonTmp = new int[numberPeople];
			set<pair<int,int> > have;
			rep(it, all) have.insert((*it).second);
			int cnt = 0;

			for (int i=0; i<numberPeople; ++i) { 
				if (checkPlace(i, p, parentPlace)) allPersonTmp[cnt++] = i;
			} 
			sort(allPersonTmp, allPersonTmp+cnt);
			
			//TODO
			int in = 0, fn = 0;
			for (int i=0; i<numberPeople; i++) dist[i] = -1;
			//for (int i=0; i<numberPeople; i++) dist2[i] = -1;
			
			for (int i=0; i<cnt; i++) {
				//initBfs(allPersonTmp[i]);
				
				dist[allPersonTmp[i]] = 0;
				q[fn++] = allPersonTmp[i];
				
				int ss = siz[0][find(allPersonTmp[i], 0)] - 1;
				
				for (int j=i+1; j<cnt; j++) {
					int val2 = bfs2(allPersonTmp[i], allPersonTmp[j], dist, q, in, fn, h, ss);
					//int val2 = bfs(allPersonTmp[i], allPersonTmp[j], -1, siz[0][find(allPersonTmp[i], 0)], dist1, dist2, q, in, fn);
					if (val2<=h && val2!=-1) {
						if (insertSet2(all, have, allPersonTmp[i],allPersonTmp[j],0,k)) K--;
					}
					if (K==0) {
						i = cnt+1;
						break;
					}
					
				}
				for (int i=0; i<fn; i++) {
					dist[q[i]] = -1;
					//dist2[q[i]] = -1;
				} 
				in = 0, fn = 0;
			}
			
		} 
		
		rep(it, all) allTotal.insert(*it);
		
		all.clear();
	}
	
	if (allTotal.size()!=0) {
		set<pair<int,pair<int,int> > >::iterator it = allTotal.end();
		--it;
		while (true) {
			ansvp[tt].push_back(make_pair((*it).second.first, (*it).second.second));
			k--;
			//printf("%d %d|%d\n", (*it).first, (*it).second.first, (*it).second.second);
			if (it==allTotal.begin() || k==0) break;
			else --it;
		}
	}
	allTotal.clear();
	
	//cout << "3:  " << GetCounter() <<"\n";
}

int dfs(int p, bool *vis, int* hasTag, unsigned int date) { 
	vis[p] = 1;
	
	long long t = 0;
	if (hasTag[p]) t += 1;
	
	for (int j=people[p].numberEdges-1; j>=0; --j) {
		int q = people[p].inEdges[j].v;
		if (!vis[q] && hasTag[q] && people[q].date>=date) {
			t += dfs(q, vis, hasTag, date);
		}
	}
	
	return t;
} 

int bfs5(int p, bool *vis, int *hasTag, int date, int *q, int &s) {
	
	//s--;
	
	int in = 0,fn = 0;
	q[fn++] = p;
	vis[p] = 1;
	s--;
	int t;
	
    while (in<fn) {
        int p = q[in++]; 
        if (s==0) break;
        for (int i=people[p].numberEdges-1; i>=0; --i) {

			t = people[p].inEdges[i].v;
			
			if ((int)people[t].date<date || !hasTag[t]) continue;
            
			if (!vis[t]) {
				q[fn++] = t;
				vis[t] = 1;
				
				s--;
				if (!s) break;
			}
        }
    }
    return fn;
}


void query2(int tt, unsigned int date, int K, int *hasTag, bool *vis, int *q) { 
	set<pair<int,int> > res;
	
	//int* parent2 = new int[numberPeople];
	//int* rk2 = new int[numberPeople];
	//int* sz2 = new int[numberPeople];
	
	for (int i=0; i<numberPeople; ++i) hasTag[i] = 0;
	for (int i=0; i<numberPeople; ++i) vis[i] = 0;

	//Seems like sorting tags by number people gives worse result
	for (int ii=0; ii<numberTags; ii++) { 
		int i = allTags[ii];
		//int i2 = i;
		//if (ii!=numberTags-1) i2 = allTags[ii+1];
		
		if (numberPeopleTags[i]==0) continue;
		
		if ((int)res.size()==K && (*res.begin()).first>numberPeopleTags[i]) continue;
		
		int tot = 0;
		for (int j=numberPeopleTags[i]-1; j>=0; --j) {
			if (people[peopleTags[i][j]].date>=date) {
				//parent2[peopleTags[i][j]] = peopleTags[i][j];
				//rk2[peopleTags[i][j]] = 0;
				//sz2[peopleTags[i][j]] = 1;
				hasTag[peopleTags[i][j]] = 1;
				tot++;
			}
			
			//if (i==416) cout<<" "<<peopleTags[i][j]<<" "<<people[peopleTags[i][j]].date<<" "<<date<<endl;
		}
		
		if ((int)res.size()==K && (*res.begin()).first>tot) {
			for (int j=numberPeopleTags[i]-1; j>=0; --j) {
				if (people[peopleTags[i][j]].date>=date) {
					hasTag[peopleTags[i][j]] = 0;
					vis[peopleTags[i][j]] = 0;
				}
			}
			continue;
		}
		int size = tot;
		tot = 0;
		
		//for (int j=numberPeopleTags[i]-1; j>=0; --j) {
		//	if (people[peopleTags[i][j]].date>=date) {
		//		hasTag[peopleTags[i][j]] += 1;
		//	}
		//}
		//for (int j=numberPeopleTags[i2]-1; j>=0; --j) {
			//if (people[peopleTags[i2][j]].date>=date) {
				//hasTag[peopleTags[i2][j]] += 2;
			//}
		//}
		
		//for (int j=numberPeopleTags[i]-1; j>=0; --j) if (people[peopleTags[i][j]].date>=date && !vis[peopleTags[i][j]]) {
			//long long tmp = dfs(peopleTags[i][j], vis, hasTag, date);
			//tot = max(tot, (int)(tmp/(1<<20)));
			//tot = max(tot, (int)(tmp%(1<<20)));
		//}
		//for (int j=numberPeopleTags[i2]-1; j>=0; --j) if (people[peopleTags[i2][j]].date>=date && !vis[peopleTags[i2][j]]) {
			//long long tmp = dfs(peopleTags[i2][j], vis, hasTag, date);
			//tot = max(tot, (int)(tmp/(1<<20)));
			//tot = max(tot, (int)(tmp%(1<<20)));
		//}
		//cout<<numberPeopleTags[i]<<" "<<tot<<" "<<(*res.begin()).first<<endl;
		

		//if (numberPeopleTags[i]<26) {
			//for (int j=numberPeopleTags[i]-1; j>=0; --j) if (people[peopleTags[i][j]].date>=date) {
				//for (int k=j-1; k>=0; --k) if (people[peopleTags[i][k]].date>=date) {

					//if (existEdge(peopleTags[i][j], peopleTags[i][k])) merge2(peopleTags[i][k], peopleTags[i][j], parent2, rk2, sz2); 
				//}
			//} 
		//}
		//else {
			//for (int j=numberPeopleTags[i]-1; j>=0; --j) if (people[peopleTags[i][j]].date>=date) {
				//for (int k=people[peopleTags[i][j]].numberEdges-1; k>=0; --k) if (hasTag[people[peopleTags[i][j]].inEdges[k].v] && people[people[peopleTags[i][j]].inEdges[k].v].date>=date) {
					//merge2(people[peopleTags[i][j]].inEdges[k].v, peopleTags[i][j], parent2, rk2, sz2); 
				//}
				////for (int k=j-1; k>=0; --k) if (people[peopleTags[i][k]].date>=date) {

				////	if (existEdge(peopleTags[i][j], peopleTags[i][k])) merge2(peopleTags[i][k], peopleTags[i][j], parent2, rk2, sz2); 
				////}
			//} 
		//}
		//CHECK THIS
		for (int j=numberPeopleTags[i]-1; j>=0; --j) if (people[peopleTags[i][j]].date>=date && !vis[peopleTags[i][j]]) {
			//tot = max(tot, sz2[peopleTags[i][j]]);
			//tot = max(tot, dfs(peopleTags[i][j], vis, hasTag, date));
			tot = max(tot, bfs5(peopleTags[i][j], vis, hasTag, date, q, size));
			//cout<<ii<<" "<<tot<<" "<<size<<endl;
			//cout<<K<<" "<<res.size()<<" "<<(*res.begin()).first<<endl;
			if ((int)res.size()==K && (*res.begin()).first>size) break;
		} 
		
		if ((int)res.size()<K) res.insert(make_pair(tot, i));
		else { 
			if ((*res.begin()).first<tot) { 
				set<pair<int,int> >::iterator p = res.begin();
				int index = (*res.begin()).second;
				rep(it, res) { 
					if (it==res.begin()) continue;
					if ((*it).first==(*res.begin()).first) {
						if (tagNameOrder((*it).second, index)) {
							index = (*it).second;
							p = it;
						}
					}
					else break;
				} 
				if (index!=-1) { 
					res.erase(p);
					res.insert(make_pair(tot, i)); 
				}
			}
			else if ((*res.begin()).first==tot) {
				set<pair<int,int> >::iterator p;
				int index = -1;
				rep(it, res) {
					if ((*it).first==tot) {
						if (tagNameOrder((*it).second, i)) {
							if (index==-1) {
								p = it;
								index = (*it).second;
							}
							else {
								if (tagNameOrder((*it).second, index)) {
									index = (*it).second;
									p = it;
								}
							}
						}
					}
					else break;
				}
				if (index!=-1) {
					res.erase(p);
					res.insert(make_pair(tot, i));
				}
			}
		}
		
		for (int j=numberPeopleTags[i]-1; j>=0; --j) {
			if (people[peopleTags[i][j]].date>=date) {
				hasTag[peopleTags[i][j]] = 0;
				vis[peopleTags[i][j]] = 0;
			}
		}
		//for (int j=numberPeopleTags[i2]-1; j>=0; --j) {
			//if (people[peopleTags[i2][j]].date>=date) {
				//hasTag[peopleTags[i2][j]] = 0;
				//vis[peopleTags[i2][j]] = 0;
			//}
		//}
	} 
	
	set<pair<int,string> > all;
	rep(it, res) {
		all.insert(make_pair(-(*it).first, tag2str((*it).second)));
	}
	rep(it, all) ansvs[tt].push_back((*it).second);
	//rep(it, all) cout<<(*it).first<<" "<<(*it).second<<endl;
	
	//cout << "2:  " << GetCounter() <<"\n";
	
	//delete [] parent2;
	//delete [] rk2;
	//delete [] sz2;
}

int curQ1;

vector<long> allThreads;
void *solveQuery1(void *arg) {
	
	int t;
	pthread_mutex_lock(&running_mutex);
	t = curQ1++;
	pthread_mutex_unlock(&running_mutex);
	
	int *dist1 = new int[numberPeople];
	int *dist2 = new int[numberPeople];
	int *q = new int[numberPeople];
	
	int in = 0, fn = 0;
	
    for (int i=0; i<numberPeople; i++) dist1[i] = 0;
    for (int i=0; i<numberPeople; i++) dist2[i] = 0;
    
    int res, p1, p2, k, x, y;

	for (int i=t; i<totalQuery1; i+=allThreads.size()) { 
		
		p1 = qq1[i].second.first;
		p2 = qq1[i].second.second;
		k = qq1[i].first.second;
		
		in = 0, fn = 0;

		res = 0;

		if (k<3) { 
			x = find(p1, k+1);
			y = find(p2, k+1);
			if (x!=y) res = -1;
			else res = bfs(p1, p2, k, siz[k+1][find(p1, k+1)], dist1, dist2, q, in, fn);
		}
		else res = bfs(p1, p2, k, numberPeople, dist1, dist2, q, in, fn);
		ans[qq1[i].first.first] = res;
		
		for (int j=0; j<fn; j++) {
			dist1[q[j]] = 0;
			dist2[q[j]] = 0;
		}
	}
	
	delete [] dist1;
	delete [] dist2;
	delete [] q;
	
	pthread_exit(NULL);
}

void *solveOthers(void *arg) { 
	int t;
	pthread_mutex_lock(&running_mutex);
	t = ++cur;
	pthread_mutex_unlock(&running_mutex);
	
	//Query2
	int* hasTag = new int[numberPeople];
	bool* vis = new bool[numberPeople];
	int* q = new int[numberPeople];
	
	//Query3
	int* parentPlace = new int[16000];
	int* dist = new int[numberPeople];
	vector<int> interestTags[16500];
	int* A = new int[numberPeople];
	int* possible = new int[numberPeople];
	
	//Query4
	int* par = new int[numberPeople];
    int* siz = new int[numberPeople];
    int* rk = new int[numberPeople];
    //unsigned int *vis2 = new unsigned int[numberPeople/32 + 1]; 

	for (int i=t; i<totalQuery; i+=NUM_THREADS-NUM_THREADS_QUERY1) { 
		//int hh = GetCounter();
		if (type[i]==2) { 
		
			int date = qq2[i].second.first;
			int K = qq2[i].first.second;
			
			query2(qq2[i].first.first, date, K, hasTag, vis, q);
		}
		else if (type[i] == 3) { 
			int h = qq2[i].second.first;
			int p = qq2[i].second.second;
			int k = qq2[i].first.second;

			query3(qq2[i].first.first, k, h, p, parentPlace, dist, q, interestTags, A, possible, vis);
		}
		else if (type[i] == 4) { 
			int t = qq2[i].second.first;
			int K = qq2[i].first.second;
			query4(qq2[i].first.first, K, t, par, rk, siz, q, dist);
		}
		//cerr<<type[i]<<endl;
		//cerr << GetCounter()-hh <<"\n";
	}
	
	delete [] hasTag;
	delete [] vis;
	//delete [] vis2;
	delete [] q;
	delete [] dist;
	delete [] parentPlace;
	delete [] A;
	delete [] possible;
	delete [] par;
	delete [] rk;
	delete [] siz;
	
	pthread_exit(NULL);
}

void *solve(void *arg) {
	int t;
	pthread_mutex_lock(&running_mutex);
	t = cur++;
	pthread_mutex_unlock(&running_mutex);
	
	int *dist1 = new int[numberPeople];
	int *dist2 = new int[numberPeople];
	int *q = new int[numberPeople];
	
	int in = 0, fn = 0;
	
    for (int i=0; i<numberPeople; i++) dist1[i] = -1;
    for (int i=0; i<numberPeople; i++) dist2[i] = -1;

	for (int i=t; i<cnt; i+=NUM_THREADS) { 
		if (OutputType[i]==1) {
			int p1 = qq1[i].second.first;
			int p2 = qq1[i].second.second;
			int k = qq1[i].first.second;
			
			in = 0, fn = 0;

			int res = 0;

			if (k<3) { 
				int x = find(p1, k+1);
				int y = find(p2, k+1);
				if (x!=y) res = -1;
				else res = bfs(p1, p2, k, siz[k+1][find(p1, k+1)], dist1, dist2, q, in, fn);
			}
			else res = bfs(p1, p2, k, numberPeople, dist1, dist2, q, in, fn);
			ans[qq1[i].first.first] = res;
			//cout<<res<<endl;
			
			for (int j=0; j<fn; j++) {
				dist1[q[j]] = -1;
				dist2[q[j]] = -1;
			}
		}
		else if (OutputType[i]==2) {
		
			//int date = qq2[i].second.first;
			//int K = qq2[i].first.second;

			//UPDATE IF USED
			//query2(qq2[i].first.first, date, K);
		}
		else if (OutputType[i] == 3) {
			//int h = qq2[i].second.first;
			//int p = qq2[i].second.second;
			//int k = qq2[i].first.second;

			//query3(qq2[i].first.first, k, h, p);
		}
		else if (OutputType[i] == 4) {
			//int t = qq2[i].second.first;
			//int K = qq2[i].first.second;
			//query4(qq2[i].first.first, K, t);
		}
	}
	
	pthread_exit(NULL);
}
void init() {

	string str = "person.csv";
	int f = open((__DIR__ + str).c_str(), O_RDONLY);
	
    long long size = lseek(f, 0, SEEK_END);
    char *buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, f, 0);

    long long bytes = size;
    char *p = buf;
    while (*p!='\n') {++p; --bytes;}
    ++p; --bytes;
    int lines = 0;
    int y = 0, m = 0;
    int lo = 10000000, hi = 0;
    while(bytes) {
		while (*p!='|') {++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {++p; --bytes;}
		++p; --bytes;
		while (*p!='|') {++p; --bytes;}
		++p; --bytes;
		y = 0, m = 0;
		while (*p!='-') {y=y*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='-') {m=m*10 + (*p-'0'); ++p; --bytes;}
		++p; --bytes;
		while (*p!='\n') {++p; --bytes;}
		++p; --bytes;
		++lines;
		m = y*12+m; 
		if (lo>m) lo = m;
		if (hi<m) hi = m;
    }
    close(f);
    munmap(buf, size); 
    
    int k = hi-lo;
    if (k%12>2) k = k/12 + 1;
    else k = k/12;
    
    numberYears = k;
    
    numberPeople = lines; 
    numberPeople = 2000000;
    numberForums = 25*numberPeople*k+numberPeople;
    
    if (lines<=1000) {
		query4Iterations = 120;
	}
	else if (lines<=10000) {
		query4Iterations = 250;
	}
	else if (lines<=100000) {
		query4Iterations = 600;
	} 
	else query4Iterations = 4000;
	
	
	people = new PERSON[numberPeople];
	//edges = new EDGE[numberPeople*NUMBER_EDGES_PER_PERSON];
	personLocWork = new vector<int>[numberPeople];
	personLocStudy = new vector<int>[numberPeople];
	personLoc = new int[numberPeople];
	for (int i=0; i<4; i++) {
		parent[i] = new int[numberPeople];
		rk[i] = new int[numberPeople];
		siz[i] = new int[numberPeople];
	}
	for (int i=0; i<numberPeople; i++) personLoc[i] = 0;
	forums = new FORUM[numberForums];
	//id = new int[2*numberForums];
	//NumberTagsPerPerson is a random number between 0 and 80
	//tagsRelationsA = new int[numberPeople*60];
	//tagsRelationsB = new int[numberPeople*60];
	
	//people = (PERSON*) malloc(numberPeople*sizeof(PERSON));
	//edges = (EDGE*) malloc(numberPeople*NUMBER_EDGES_PER_PERSON*sizeof(EDGE));
	//personLocWork = (vector<int>*) malloc(numberPeople*sizeof(vector<int>));
	//personLocStudy = (vector<int>*) malloc(numberPeople*sizeof(vector<int>));
	//personLoc = (int*) malloc(numberPeople*sizeof(int));
	//for (int i=0; i<4; i++) {
		//parent[i] = (int*) malloc(numberPeople*sizeof(int));
		//rk[i] = (int*) malloc(numberPeople*sizeof(int));
		//siz[i] = (int*) malloc(numberPeople*sizeof(int));
	//}
	//for (int i=0; i<numberPeople; i++) personLoc[i] = 0;
	//forums = (FORUM*) malloc(numberForums*sizeof(FORUM));
	////NumberTagsPerPerson is a random number between 0 and 80
	//tagsRelationsA = (int*) malloc(numberPeople*60*sizeof(int));
	//tagsRelationsB = (int*) malloc(numberPeople*60*sizeof(int));
}

void finish() {
	delete [] people;
	delete [] forums;
	delete [] edges;
	delete [] personLocWork;
	delete [] personLocStudy;
	delete [] personLoc;
	for (int i=0; i<4; i++) {
		delete [] parent[i];
		delete [] rk[i];
		delete [] siz[i];
	}
}

int main(int argc,char *argv[]) {

    StartCounter();
    
    if (argc>1) {
		__DIR__ = argv[1];
		freopen(argv[2],"r",stdin);
		//freopen("output.txt","w",stdout);
	}
	else {
		freopen("1k-queries.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	init();
	cerr << GetCounter() <<"\n";
	
	long t = 4;
	pthread_create(&threads[t], NULL, readTag, (void *)t);
	pthread_join (threads[4], NULL); 
	
	string query;
    cnt = 0;
    totalQuery1 = 0, totalQuery = 0;
    while (getline(cin,query)) { 
        if (query.length()<5) continue;
        int typ = query[5]-'0';
        query = query.substr(7, query.length()-8);
        for (int i=0; i<(int)query.length(); i++) if (query[i]==',') query[i] = ' ';
        stringstream ss(query);
        
        OutputType.push_back(typ);
        //OutputType[cnt] = typ;
        
        if (typ==1) {
			int p1, p2, k;
			ss>>p1>>p2>>k;
			qq1.push_back(make_pair(make_pair(cnt++,k), make_pair(p1,p2)));
			totalQuery1++;
		}
		else if (typ==2) {
			int K;
			string buf;
			ss>>K>>buf;

			int year = 0, month = 0, day = 0;
			year = (buf[0]-'0')*1000 + (buf[1]-'0')*100 + (buf[2]-'0')*10 + (buf[3]-'0');
			month = (buf[5]-'0')*10 + (buf[6]-'0');
			day = (buf[8]-'0')*10 + (buf[9]-'0');

			int date = day + month*32 + year*13*32;

			type.push_back(2);
			qq2.push_back(make_pair(make_pair(cnt++,K), make_pair(date,0)));
			totalQuery++;
		}
		else if (typ==3) {
			int k, h;
			string str;
			ss>>k>>h>>str;  
			//p = placeId[str]; 
			query3Strings.push_back(str);
			//query3Strings[allquerys3] = str;
			type.push_back(3);
			qq2.push_back(make_pair(make_pair(cnt++,k), make_pair(h, allquerys3++)));
			totalQuery++;
		}
		else if (typ==4) {
			int K, t;
			string str;
			ss>>K>>str;
			t = searchTagId(str);
			
			type.push_back(4);
			qq2.push_back(make_pair(make_pair(cnt++,K), make_pair(t,0)));
			totalQuery++;
			queryTags.insert(t);
		}
        //cout<<res<<endl;
    } 
    
    ans.resize(cnt);
    ansvs.resize(cnt);
    ansvp.resize(cnt);
    
    cerr << GetCounter() <<"\n";
    
    t = 0;
    pthread_create(&threads[0], NULL, readPersonKnowsPerson, (void *)t);
    
    pthread_create(&threads[3], NULL, readPerson, (void *)t);
    pthread_create(&threads[1], NULL, readPersonHasInterestTag, (void *)t);
	pthread_create(&threads[2], NULL, readPlaces, (void *)t);
	pthread_create(&threads[4], NULL, readPlaceIsPartOfPlace, (void *)t);
	pthread_create(&threads[5], NULL, readPlace, (void *)t);
	//pthread_create(&threads[6], NULL, readForumHasTagTag, (void *)t);
	pthread_join (threads[5], NULL); 
	pthread_join (threads[4], NULL); 
	pthread_join (threads[2], NULL); 
	pthread_join (threads[1], NULL); 
	pthread_join (threads[3], NULL); 
	pthread_join (threads[0], NULL); 
	//pthread_join (threads[6], NULL); 
	
	cerr << GetCounter() <<"\n";
	
	readForumHasMemberPersonv2();
	
	
	if (false) {
		for (int i=0; i<numberTags; i++) {
			int t;
			string str;
			t = allTags[i];
			OutputType.push_back(4);
			type.push_back(4);
			qq2.push_back(make_pair(make_pair(cnt++,6), make_pair(t,0)));
			totalQuery++;
			queryTags.insert(t);
		}
		ans.resize(cnt);
		ansvs.resize(cnt);
		ansvp.resize(cnt);
	}
	
	cur = -1;
	for (long i=NUM_THREADS_QUERY1; i<NUM_THREADS; i++) {	
		pthread_create(&threads[i], NULL, solveOthers, (void*)i);
	}
    
    cerr << GetCounter() <<"\n";
    //preprocess2HopCoverIndex();
    
    readCommentsv2();
    //pthread_create(&threads[t], NULL, test, (void *)t);
    //pthread_join (threads[0], NULL); 
    
    t = 0;
    //cout << GetCounter() <<"\n";
    //pthread_create(&threads[t], NULL, readCommentHasCreatorPerson, (void *)t);
    //pthread_join (threads[0], NULL); 		
    //cout << GetCounter() <<"\n";
    //pthread_create(&threads[t], NULL, readPersonKnowsPerson, (void *)t);
    //pthread_join (threads[0], NULL); 
    //cout << GetCounter() <<"\n";
    //pthread_create(&threads[t], NULL, readCommentReplyOfComment, (void *)t);
	//pthread_join (threads[0], NULL); 
	//cout<<"FINAL"<<endl;
	//cout << GetCounter() <<"\n";
	
	//cout << GetCounter() <<"\n";
	//pthread_join (threads[0], NULL); 
	
    //cout << GetCounter() <<"\n";
    //cout<<"Introduce queries:"<<endl;
    
    cerr << GetCounter() <<"\n";
    
    //for (long i=2; i<NUM_THREADS; i++) {	
	//	pthread_create(&threads[i], NULL, solveOthers, (void*)i);
	//}
	
	for (long i=0; i<NUM_THREADS_QUERY1; i++) {	
		allThreads.push_back(i);
	}
	for (long i=NUM_THREADS_QUERY1; i<NUM_THREADS; i++) {
		if(pthread_kill(threads[i], 0) == 0);
		else {
			allThreads.push_back(i);
		}
	}
	for (long i=0; i<(int)allThreads.size(); i++) {	
		pthread_create(&threads[allThreads[i]], NULL, solveQuery1, NULL);
	}
	
	//pthread_join (threads[0], NULL); 
	//cout << GetCounter() <<"\n";
	
	for (int i=0; i<NUM_THREADS; i++) {
		pthread_join (threads[i], NULL); 
	}
	//cout << GetCounter() <<"\n";
	//pthread_join (threads[0], NULL); 
	
	cerr << GetCounter() <<"\n";
	
	bool OUTPUT = 1;
	
	
	if (OUTPUT) {

		for (int i=0; i<cnt; i++) {
			if (OutputType[i]==1) {
				cout<<ans[i]<<"\n";
			}
			else if (OutputType[i]==2) {
				for (int j=0; j<(int)ansvs[i].size(); j++) {
					cout<<ansvs[i][j];
					if (j!=(int)ansvs[i].size()-1) cout<<" ";
				}
				cout<<"\n";
			}
			else if (OutputType[i]==3) {
				for (int j=0; j<(int)ansvp[i].size(); j++) {
					cout<<ansvp[i][j].first<<"|"<<ansvp[i][j].second;
					if (j!=(int)ansvp[i].size()-1) cout<<" ";
				}
				//if (ansvp[i].size()==0) cout<<totalVisited<<endl;
				cout<<"\n";
			}
			else if (OutputType[i]==4) {
				for (int j=0; j<(int)ansvp[i].size(); j++) {
					cout<<ansvp[i][j].first;
					if (j!=(int)ansvp[i].size()-1) cout<<" ";
				}
				cout<<"\n";
			}
		}
	} 

	//finish();
	
    return 0;

}
