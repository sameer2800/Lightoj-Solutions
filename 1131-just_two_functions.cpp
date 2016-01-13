 #include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
  
 using namespace std;
  
 ll arr[100100]; 
 vector <ll > vk;
 
 ll matrix[6][6];
 ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,mod,q;


struct matrx {
	ll arr[6][6];
};	 


matrx matrx_mul(matrx m1,matrx m2)
{

	matrx temp;

	for(int i=0;i < 6;i++){
		for(int j=0;j < 6;j++){
			temp.arr[i][j] =0;
			for(int k = 0;k < 6;k++){

				temp.arr[i][j] += (m1.arr[i][k] * m2.arr[k][j]) % mod;
				temp.arr[i][j] %= mod;
			}
		}
	}

	return temp;
}

matrx power_mat(matrx mt,ll powe)
{	
	

	if(powe == 1)
		return mt;

	matrx temp = power_mat(mt,powe/2);

	if(powe % 2 == 0)
		return matrx_mul(temp,temp);
	else
		return matrx_mul(mt,matrx_mul(temp,temp));

}

 pair <ll,ll> calculate_fn(ll n)
 {
 	matrx mtx,mt;
 	for(int i =0;i < 6;i++) {
 		for(int j =0;j < 6;j++){
 			mtx.arr[i][j] = matrix[i][j];
 		}
 	}

 	if(n ==0)
 		return make_pair(f0,g0);

 	if(n ==1)
 		return make_pair(f1,g1);

 	if(n==2)
 		return make_pair(f2,g2);


 	 mt = power_mat(mtx,n-2);

 	ll fir = ((mt.arr[0][0]*f2) %mod + (mt.arr[0][1]*f1) % mod) % mod + (mt.arr[0][5]*g0) %mod ;
		fir += ((mt.arr[0][2]*f0) %mod + (mt.arr[0][3]*g2) % mod) % mod + (mt.arr[0][4]*g1) %mod ;		 	
 	fir %= mod;

 	ll sec = ((mt.arr[3][2]*f0) %mod + (mt.arr[3][3]*g2) % mod) %mod + (mt.arr[3][4]*g1) %mod ;
 		sec += ((mt.arr[3][0]*f2) %mod + (mt.arr[3][1]*f1) % mod) % mod + (mt.arr[3][5]*g0) %mod ;
 	sec %= mod;

 	return make_pair(fir,sec);

 }

 void matrix_init()
 {

 	for(int i =0;i < 6;i++) {
 		for(int j=0;j < 6;j++){
 			matrix[i][j] = 0;
 		}
 	}

 	matrix[0][0] = a1,matrix[0][1] = b1, matrix[0][5] = c1;
 	matrix[1][0] = 1,matrix[2][1] = 1,matrix[3][2]= c2;
 	matrix[3][3] = a2,matrix[3][4] = b2,matrix[4][3] = 1, matrix[5][4]=1; 

 }



 int main()
 {
     
 	#ifndef ONLINE_JUDGE
 	freopen("/home/placements2016/input.sam","r",stdin);
 	#endif
  
  
     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
    
     cin >> t;
     
     ll cases = t;
  
     while(t--){
  		
     		cin >> a1 >> b1 >> c1;
     		cin >> a2 >> b2 >> c2;

     		cin >> f0 >> f1 >> f2;
     		cin >> g0 >> g1 >> g2;



     		cin >> mod;

     		f0 %= mod,f1 %= mod,f2 %= mod;
     		g0 %= mod,g1 %= mod,g2 %= mod;
     		

     		cin >> q;

     		cout << "Case " << cases-t << ":" << endl;

     		matrix_init();

     		for(i=0;i < q;i++){
     			cin >> k;

     			pair <ll,ll> ans = calculate_fn(k);

     			cout << ans.first << " " << ans.second << endl;
     		}
 			    		
     	
     }
  
  
  
     return 0;
 }