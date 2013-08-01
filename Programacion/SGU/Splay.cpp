#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int inf=~0U>>1;

class splay
{
	int n;
	struct node
	{
		int k,s;
		bool d,rev;
		node*c[2],*p;
		
		node(){c[0]=c[1]=p=0;}
		
		void sc(node*_c,bool d)
		{
			c[d]=_c;_c->p=this;_c->d=d;
		}
	}*root,*Null,*Now,Data[130100];
	
	typedef node* Node;
	Node new_node(int k)
	{
		Now->c[0]=Now->c[1]=Null;
		Now->rev=false;Now->s=1;
		Now->k=k;return Now++;
	}
	
	void rev(Node t)
	{
		if(t==Null) return;
		t->rev^=1;
		swap(t->c[0],t->c[1]);
		t->c[0]->d=0;
		t->c[1]->d=1;
	}
	
	void pus(Node t)
	{
		if(t->rev)
		rev(t->c[0]),rev(t->c[1]);
		t->rev=false;
	}
	
	void upd(Node t)
	{
		t->s=t->c[0]->s+t->c[1]->s+1;
	}
	
	void rot(Node t)
	{
		Node p=t->p;
		pus(p);pus(t);bool d=t->d;
		p->sc(t->c[!d],d);
		p->p->sc(t,p->d);
		t->sc(p,!d);
		upd(p);upd(t);
		if(p==root) root=t;
	}
	
	void spl(Node x,Node f)
	{
		for(pus(x);x->p!=f;)
		{
			if(x->p->p==f) rot(x);
			else x->d==x->p->d?( rot(x->p),rot(x) ):( rot(x),rot(x) ); 
		} 
	}
	
	Node sel(int k)
	{
		int r;
		for(Node t=root;;)
		{ 
			pus(t);
			r=t->c[0]->s;
			if(r==k) return t;
			t=t->c[k>r];
			if(k>r) k-=r+1;
		}
	}
	
	void print(Node t)
	{
		if(t==Null||!t) return;
		pus(t);
		print(t->c[0]);
		if(t->k)printf("%d ",t->k);
		print(t->c[1]);
	}
	
	public:
	void out()
	{
		print(root);
	}
	
	splay(int n):n(n)
	{ 
		Now=Data;
		Null=new node;Null->s=0;
		root=new_node(0);root->p=Null;
		Node p,q=root;
		for(int i=1;i<=n;i++)
		{
			p=new_node(i);
			q->sc(p,1);
			q=p;
		}
		Node last=new_node(0);
		q->sc(last,1);
		spl(last,Null);
	}
	
	void reverse(int l,int r)
	{
		Node x,y;
		x=sel(l-1);
		spl(x,Null);
		y=sel(r+1);
		spl(y,root);
		rev(y->c[0]);
	}
}*sp;

int main()
{
	int n,m,l,r;cin>>n>>m;
	sp=new splay(n);
	while(m--)
	{
		scanf("%d %d",&l,&r);
		sp->reverse(l,r);
	}
	sp->out();
}
