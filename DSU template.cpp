struct DSU{
        int mx;
        vector<int> par,size;
        DSU(int n)
        {
            mx=1;
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i=1;i<=n;i++)
            {
                par[i]=i;
            }
        }
        int findpar(int x)
        {
           if(par[x]==x)
               return x;
            return (par[x]=findpar(par[x]));
        }
        void merge(int x,int y)
        {
            x=findpar(x);
            y=findpar(y);
            if(x==y)
                return;
            if(size[x]>size[y])
            {
                swap(x,y);
            }
            size[y]+=size[x];
            par[x]=y;
            mx=max(size[y],mx);
        }
    };
