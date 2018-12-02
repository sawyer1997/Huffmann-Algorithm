// I'll Win, not immediately, but definetely.
#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=n-1;i>=0;--i)
#define range(i,p,q) for(ll i=p;i<=q;++i)
#define tci(i,v) for(auto i=v.begin();i!=v.end();++i)
#define tci1(i,v) for(auto i=v.rbegin();i!=v.rend();++i)
#define all(v) v.begin(),v.end()
#define all1(v) v.rbegin(),v.rend()
#define pb push_back
#define f first
#define s second
#define sz size()
#define in insert
#define ve vector
#define pr pair<ll,ll> 
#define el "\n"
#define ll long long int
#define ld long double
#define T() ll t;cin>>t;while(t--)
using namespace std;
ll inf=pow(10,9)+7;
struct minheap
{
	char c;
	ll frq;
	minheap *left;
	minheap *right;
	minheap(char c='$',ll frq=0)
	{
		left = right = NULL;
		this->c = c;
		this->frq = frq;
	}
};
struct cmp
{
	bool operator()(minheap *l,minheap *r)
	{ return l->frq > r->frq; }
};
map<char, string> encode;
map<string, char> decode;
void tree(minheap *node,string s)
{
	if(not node)return;
	if(node->c!='$')encode[node->c] = s,decode[s] = node->c;
	tree(node->left,s+"0");
	tree(node->right,s+"1");
}
void Huff(map<char, ll> &ma)
{
	minheap *left,*right,*top;
	priority_queue<minheap*,ve<minheap*>,cmp> heap;
	tci(i,ma)heap.push(new minheap(i->f,i->s));
	while(heap.sz!=1)
	{
		left = heap.top();
		heap.pop();
		if(heap.sz)
		{
			right = heap.top();
			heap.pop();
		}
		else right = NULL;
		top = new minheap('$',left->frq + right->frq);
		top->left = left;
		top->right = right;
		heap.push(top);
	}
	tree(heap.top(),"");
}
int main()
{
	sync;
	string s,es="";cin>>s;
	map<char, ll> ma;
	rep(i,s.sz)ma[s[i]]++;
	Huff(ma);
	cout<<s<<el;
	rep(i,s.sz)es+=encode[s[i]];
	string tmp;
	rep(i,es.sz)
	{
		tmp.pb(es[i]);
		if(decode.find(tmp)!=decode.end())
		{
			cout<<decode[tmp];
			tmp.clear();
		}
	}
	cout<<el;
	return 0;
}