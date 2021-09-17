// Time complexity-Elogv
// Good in Sparse Graph

vector<ll>parent,siz;

ll findParent(ll v){
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v]);
}

void unionNodes(ll a, ll b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        if (siz[a] == siz[b])
            siz[a]++;
    }
}

void clearDsu(ll n){
    for(ll i=0;i<=n;i++){
        parent[i]=i;
        siz[i]=1;
    }
}

void kruskal(){
  
    // input is in kruskal function
    
    ll n,m,cost=0;
    cin>>n>>m;
    
    vector<vector<ll>> edges,result;
    for(ll i=0;i<m;i++){
        ll f,s,w;          
        cin>>f>>s>>w; 
        edges.pb({w,f,s});   
    }
    
    parent.resize(n+1);
    siz.resize(n+1);
    clearDsu(n);
    
    sort(edges.begin(), edges.end());
    for(ll i=0;i<m;i++){
        if(findParent(edges[i][1]) != findParent(edges[i][2])){
            cost += edges[i][0];
            unionNodes(edges[i][1], edges[i][2]);   
            result.pb({edges[i][0],edges[i][1],edges[i][2]});
        }
    }

    // 'cost' contain the total cost of MST
    // 'result' vector contain the MST
}
