#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;
	
int main(){
	

	//Parsing
	//
    int B,L,D;
	scanf("%d%d%d",&B,&L,&D);
	
	int scores[B];
	for(int i=0;i<B; ++i){
		scanf("%d",&scores[i]);
	}

	int libs[L][3];
	vector<int> books[L];
	int temp;
	for(int i=0; i<L;++i){
		scanf("%d%d%d",&libs[i][0],&libs[i][1],&libs[i][2]);
		//printf("%d\n",libs[i][0]);
		for(int j=0;j<libs[i][0];++j){
			//printf("j=%d\n",j);
			scanf("%d",&temp);
			books[i].push_back(temp);
		}
	}
	
	int indices[L];
	for(int i = 0; i< L;++i){
		indices[i] = i;
	}


   sort(indices, indices+L, [&libs](int i, int j){return libs[i][0]/libs[i][2] >libs[j][0] / libs[j][2];}); 

	for(int i : indices){
		cout << i << '|';
	}
	cout << endl;

	//Test

	printf("%d %d %d\n",B,L,D);
	for(auto score : scores){
		printf("%d ",score);
	}
	printf("\n");
	for(int i=0; i<L;++i){
		printf("%d %d %d\n",libs[i][0],libs[i][1],libs[i][2]);
		for(int j=0;j<libs[i][0];++j){
			printf("%d ",books[i][j]);
		}
		printf("\n");
	}


	return 0;
}
