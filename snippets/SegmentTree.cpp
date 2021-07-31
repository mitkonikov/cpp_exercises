int pw = (1<<17);
vector<long long> seg(pw*2);
vector<long long> lz(pw*2);
long long get(int ind,int l,int r,int b,int e){
    if(l>=b&&r<=e) return lz[ind]*(r-l)+seg[ind];
    if(l>=e||r<=b) return 0;
    int lc=2*ind+1,rc=2*ind+2,m=(l+r)/2;
    lz[lc]+=lz[ind];lz[rc]+=lz[ind];lz[ind]=0;
    seg[ind]=get(lc,l,m,l,m)+get(rc,m,r,m,r);
    return get(ind*2+1,l,m,b,e)+get(ind*2+2,m,r,b,e);
}
void add(int ind,int l,int r,int b,int e, long long v){
    if(l>=b&&r<=e) {lz[ind]+=v;return;}
    if(l>=e||r<=b) return;
    int lc=2*ind+1,rc=2*ind+2,m=(l+r)/2;
    lz[lc]+=lz[ind];lz[rc]+=lz[ind];lz[ind]=0;
    add(lc,l,m,b,e,v);add(rc,m,r,b,e,v);
    seg[ind]=get(lc,l,m,l,m)+get(rc,m,r,m,r);
}
void sadd(int l, int r, long long v){add(0, 0, pw, l, r, v);}
long long sget(int l,int r){return get(0, 0, pw, l, r);}