#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

 using namespace std;

 ll arr[200100];

 ll fcolor[200100];
 vector <pair <ll,ll> > v;

   set <ll > sets;

 struct sam {
 	int lazy;
 	int color;
};

struct sam nodes[1000100];

void initilize(int node)
{
	nodes[node].lazy = -1;
	nodes[node].color = -1;

}

void buildtree(int node,int start,int end,int val)
{

	if(start > end)
			return;

	if(start == end)
	{
			initilize(node);
			return;
	}
	int mid = start + end;
	mid /= 2;
	buildtree(node*2+1,start ,mid,val);
	buildtree(node*2+2,mid+1,end,val);

	initilize(node);
	return;
}

void update(int node,int start,int end,int qstr,int qend,int val)
{

	if(nodes[node].lazy != -1) {
		int temp = nodes[node].lazy ;

		if(start != end)
		nodes[node*2+1].lazy = temp, nodes[node*2+2].lazy = temp;

		nodes[node].color = temp;
		nodes[node].lazy = -1;
	}

	if(start > end)
		return;


	if(qend < start || qstr > end)
		return;



	if(qstr <= start and qend >= end) {
		int	temp = val;

		if(start != end)
		nodes[node*2+1].lazy = temp, nodes[node*2+2].lazy = temp;

		nodes[node].color = temp;
		nodes[node].lazy = -1;
		return;

	}



	int mid =start + end;
	mid /= 2;
	update(node*2 +1,start,mid,qstr,qend,val);
	update(node*2+2,mid+1,end,qstr,qend,val);


}

ll query(int node,int start,int end,int qstr,int qend)
{


	if(nodes[node].lazy != -1) {
		int temp = nodes[node].lazy ;

		if(start != end)
		nodes[node*2+1].lazy = temp, nodes[node*2+2].lazy = temp;

		nodes[node].color = temp;
		nodes[node].lazy = -1;
	}

	if(start > end)
		return INT_MAX;

	if(qend < start || qstr > end)
		return INT_MAX;



	if(qstr <= start and qend >= end) {
		return nodes[node].color;

	}

	int mid =start + end;
	mid /= 2;
	int left = query(node*2 +1,start,mid,qstr,qend);
	int right = query(node*2+2,mid+1,end,qstr,qend);

	return min(left ,right);

}

 int main()
 {

     ll i,j,k,n,m,t,cont,a,b;
     scanf("%lld",&t);

     ll cases = t;

     while(t--){

        scanf("%lld",&m);

        n = 2*m;

        memset(nodes,0,sizeof nodes);

        sets.clear();
        buildtree(0,0,n-1,0);


        for(i =0;i < m;i++) {

            scanf("%lld %lld",&a,&b);
            a--,b--;
            update(0,0,n-1,a,b,i+1);
        }

        for(i =0;i < n;i++) {
            fcolor[i] = query(0,0,n-1,i,i);
         //   cout << fcolor[i] << " ";
        }

        ll ans =0;

        for(i=0;i < n-1;i++) {

                    if(fcolor[i] != -1)
                        sets.insert(fcolor[i]);


        }

      ll yooo = sets.size() ;

        printf("Case %lld: %lld\n",cases-t,yooo);


     }




     return 0;
 }
