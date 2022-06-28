class segtree
{
public:
	vector<int> seg;
	
	segtree(int n)
	{
		seg.resize(4*n+1);
	};
	
	void build(int ind,int l,int h,int a[])
{
	if(l==h)
	{
		seg[ind]=a[l];
		return;
	}
	int mid=(l+h)>>1;
	build(2*ind+1,l,mid,a);
	build(2*ind+2,mid+1,h,a);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	return;
}
int query(int ind,int l,int h,int low,int high)
{
	if(h<low||l>high)
	{
		return INT_MAX;
	}
	if(l>=low&&h<=high)
	{
		return seg[ind];
	}
	int mid=(l+h)>>1;
	int left =query(2*ind+1,l,mid,low,high);
	int right=query(2*ind+2,mid+1,h,low,high);
	
	return min(left,right);
	
	
}
void update(int ind,int l,int r,int i,int val)
{
	if(l==r)
	{
		
		seg[ind]=val;
		
		return;
	}
	int mid=(l+r)>>1;
	if(i<=mid)
		update(2*ind+1,l,mid,i,val);
	else
		update(2*ind+2,mid+1,r,i,val);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	return;
}
	
};

