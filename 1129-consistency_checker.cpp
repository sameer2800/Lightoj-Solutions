 #include <bits/stdc++.h>
 #define ll long long
 #define null NULL
 #define MAX 100100
  
 using namespace std;
  
 vector <ll > vk;
 
struct node {
	int end;
	struct node* links[10];
};

struct node *head;

struct node* initilizer()
{
	struct node * naah = new node();
	naah -> end = -1;
	for(int i =0;i < 10;i++){
		naah -> links[i] = NULL;
	}
	return naah;
}

int addtotrie(struct node* curr, string s,int index)
{
	if(index == s.size())
	{
		if(curr -> end == 0 || curr -> end == 1)
			return 0;

		curr -> end = 1;
		return 1;
	}	

	if(curr -> end == 1)
		return 0;

	

	int num = s[index] - '0';

	if(curr -> links[num] == NULL){
		curr -> end = 0;
		curr -> links[num] = initilizer();
		return addtotrie(curr -> links[num],s,index+1);
	}else {

		return	addtotrie(curr -> links[num],s,index+1);
	}



}

void freememory(struct node* curr)
{
	if(curr != NULL){

		for(int i =0;i < 10;i++){
			if(curr -> links[i] != NULL)
				freememory(curr -> links[i]);
		}

		free(curr);
	}



}

 int main()
 {
     
 	
 	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
    
     cin >> t;
     ll cases = t;
  
  	string s,sa;

  	int flg = 0;

     while(t--){
  			cin >> n;

  			head = initilizer();

  			flg = 0;

  			for(i =0;i < n;i++) {
  				cin >> s;
  				k =addtotrie(head,s,0);
  				if(k == 0) {
  					//cout <<"Case " << cases-t <<  ": NO" << endl;
  					flg = 1;
  				}	
  			}
     	
     	if(flg == 0)
     		cout <<"Case " << cases-t <<  ": YES" << endl;
     		else
     		cout <<"Case " << cases-t <<  ": NO" << endl;
  						

     		freememory(head);

     }
  
  
  
     return 0;
 }
 					