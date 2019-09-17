//
//  main.cpp
//  1251. 하나로
//
//  Created by carrot on 02/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll x[1001]; ll y[1001]; ll p[1001];
ll t; ll n; ll ans = 0; double e;

struct Edge {
    ll start, end, cost;
    bool operator < (const Edge &other) const { return cost<other.cost; }
};

ll Find(ll x) { return x==p[x]?x:p[x]=Find(p[x]); }
void Union(ll x,ll y) { p[Find(x)]=Find(y); }

ll dist(ll x1, ll y1, ll x2, ll y2) {
    ll tmp_X = abs(x1-x2); ll tmp_Y = abs(y1-y2);
    return tmp_X*tmp_X+tmp_Y*tmp_Y;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%lld",&t);
    for (ll tc = 1; tc<=t; tc++) {
        vector<Edge> a;
        scanf("%lld",&n);
        
        for (ll i=1; i<=n; i++) {
            scanf ("%lld", &x[i]);
        }
        
        for (ll i=1; i<=n; i++) {
            scanf ("%lld", &y[i]);
            p[i] = i;
        }
        
        scanf("%lf", &e);
        
        // 1 2 3 4
        // 1 -2 ,3, 4,
        // 2 -3, 4
        // 3 -4
        for (ll i=1; i<=n; i++) {
            for (ll j=i+1; j<=n; j++) {
                a.push_back({i,j,dist(x[i],y[i],x[j],y[j])});
            }
        }
        
        sort(a.begin(), a.end());
        
        ans = 0;
        ll m = a.size();
        for (ll i=0; i<m; i++) {
            Edge edge = a[i];
            ll x = Find(edge.start);
            ll y = Find(edge.end);
            if (x!=y) {
                Union(edge.start, edge.end);
                ans+=edge.cost;
            }
        }
        
        printf("#%lld %.0f\n", tc, ans*e);
    }
    
    return 0;
}
/*
 #include <cstdio>
 #include <vector>
 #include <algorithm>
 typedef long long ll;
 using namespace std;
 
 struct Edge
 {
 ll start,end,cost;
 bool operator < (const Edge &other) const { return cost<other.cost; }
 };
 
 ll t,n,m,ans,p[1001],x[1001],y[1001];
 double E;
 ll Find(ll x) { return x==p[x]?x:p[x]=Find(p[x]); }
 void Union(ll x,ll y) { p[Find(x)]=Find(y); }
 ll dist(ll x1,ll y1,ll x2,ll y2)
 {
 ll a=abs(x1-x2),b=abs(y1-y2);
 return a*a+b*b;
 }
 
 int main()
 {
 scanf("%lld",&t);
 for(ll k=1;k<=t;k++)
 {
 scanf("%lld",&n);
 for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
 for(ll i=1;i<=n;i++) scanf("%lld",&y[i]);
 scanf("%lf",&E);
 for(ll i=1;i<=n;i++) p[i]=i;
 vector<Edge> a;
 for(ll i=1;i<=n;i++) for(ll j=i+1;j<=n;j++)
 a.push_back({i,j,dist(x[i],y[i],x[j],y[j])});
 sort(a.begin(),a.end());
 m=a.size(),ans=0;
 for(ll i=0;i<m;i++)
 {
 Edge e=a[i];
 ll x=Find(e.start),y=Find(e.end);
 if(x!=y) Union(e.start,e.end),ans+=e.cost;
 }
 printf("#%lld %.0f\n",k,ans*E);
 }
 return 0;
 }
 Colored
 */
