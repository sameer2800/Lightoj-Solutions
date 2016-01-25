#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 ll mat[40][40];
 vector <pair <ll,ll> > v;
 ll n;

struct matrix
{
	ll arr[35][35];
};


 matrix identity()  
{
	matrix newm;
	for(int i =0;i < n;i++){
		for(int j =0; j < n;j++) {
			newm.arr[i][j] = 0;
		}
	}

	for(int i=0;i < n;i++)
		newm.arr[i][i] = 1;

	return newm;
}

matrix sum(matrix A,matrix B)  
{
	
	for(int i =0;i < n;i++){
		for(int j =0; j < n;j++) {
			A.arr[i][j] += B.arr[i][j];
		}
	}

	return A;
}

matrix matrix_mul(matrix m1,matrix m2)
{

	matrix temp;

	for(int i=0;i < 6;i++){
		for(int j=0;j < 6;j++){
			temp.arr[i][j] =0;
			for(int k = 0;k < 6;k++){

				temp.arr[i][j] += (m1.arr[i][k] * m2.arr[k][j]) ;
			}
		}
	}

	return temp;
}

matrix power_mat(matrix mt,ll powe)
{	
	

	if(powe == 1)
		return mt;

	matrix temp = power_mat(mt,powe/2);

	if(powe % 2 == 0)
		return matrix_mul(temp,temp);
	else
		return matrix_mul(mt,matrix_mul(temp,temp));

}



struct matrix matrix_pow(struct matrix node, ll k)
{

	if(k==0)
		return identity();

	if(k ==1)
		return node;

	if(k % 2 == 0)
		return matrix_mul(matrix_pow(node,k/2) , sum(identity() ,power_mat(node,k/2)));
	else {
		matrix tem = matrix_mul(matrix_pow(node,k/2) , sum(identity() ,power_mat(node,k/2)));
		return sum(tem,power_mat(node,k));
	}

}


int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,m,t,cont,a,b;
   
     cin >> t;
     
     ll cases = t;
 
     while(t--){
       
          cin >> n >> k;
          
          for(i=0;i<n;i++){
          	for(j=0;j<n;j++ ){
          		cin >> mat[i][j] ;
          	}
          }

          matrix hello;

           for(i=0;i<n;i++){
          	for(j=0;j<n;j++ ){
          		hello.arr[i][j]= mat[i][j] ;
          	}
          }

         matrix ans = matrix_pow(hello,k);

         cout << "Case " << cases-t << ": "  << endl;
 		
 		for(i =0;i < n;i++){
 			for(j=0;j < n;j++){
 				cout << ans.arr[i][j] <<" ";
 			}
 			cout << endl;
 		}
                     
       
     }
 
 
 
     return 0;
 }