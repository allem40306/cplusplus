#include <iostream>
#include <cmath>
using namespace std;
struct Node{
    long long v;
    Node *lc,*rc;
    Node():lc(NULL),rc(NULL){}
};
Node* ins(Node* h,long long x){         
    if(!h){
        h=new Node();
        h->v=x;
        return h;
    }
    if(h->v>x)
        h->lc=ins(h->lc,x);
    else
        h->rc=ins(h->rc,x);
    return h;
}
Node* f;
Node* Min(Node* h){
	if(h->lc)return Min(h->lc);
	return h;
}
Node* Max(Node* h){
	if(h->rc)return Max(h->rc);
	return h;
}
Node* del(Node* h,long long x){
//	if(h)cout<<h->v<<"*\n"; 
	if(h->v==x){
		if(!h->lc&&!h->rc){
			h=NULL;
		}else{
			Node* f;
			if(h->lc){
				f=Max(h->lc);
				if(f){
					h->v=f->v;
					h->lc=del(h->lc,f->v);
					}
				else
					h=NULL;
			}else if(h->rc){
				f=Min(h->rc);
				if(f){
					h->v=f->v;
					h->rc=del(h->rc,f->v);
					}
				else
					h=NULL;
			}else
				h=NULL;
		}
	}
	else if(h->v>x)
		h->lc=del(h->lc,x);
	else
		h->rc=del(h->rc,x);
	return h;
}
void dfs(Node* h){
	cout<<h->v<<' ';
	if(h->lc){
		cout<<'L';
		dfs(h->lc);
	}if(h->rc){
		cout<<'R';
		dfs(h->rc);
	}
}
long long ans,ansr;
void query(Node* h,long long x){
	if(!h)return;
	if(abs(h->v-x)<=abs(ans-x)){
		ansr=1+(abs(h->v-x)==abs(ans-x));
		ans=h->v;
	}
	if(h->v==x)
		return;
	if(h->v>x)
		query(h->lc,x);
	else
		query(h->rc,x);
	return;
}
long long n,x,i;
string s;
int main(){
    Node *h=NULL;
    for(cin>>n;i<n;i++){
    	cin>>s>>x;
    	if(s[0]=='i')
        	h=ins(h,x);
    	else if(s[0]=='d')
    		h=del(h,x);
    	else{
    		ans=10000000000;
    		query(h,x);
    		if(ansr==2)
    			cout<<x-abs(x-ans)<<' '<<x+abs(x-ans)<<endl;
    		else
    			cout<<ans<<endl;
		}
//    	dfs(h);cout<<endl;
	}
}
