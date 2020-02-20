#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>


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

	int sum[L];
	int idx = 0;
	for(vector<int> v : books){
		for(int b_idx : v){
			sum[idx] += scores[b_idx];
		}
		idx++;
	}
	sort(indices, indices+L, [&sum, &libs](int i, int j){return sum[i]/libs[i][1] > sum[j]/libs[j][1];}); 


	vector<int> signed_up;
	vector<int> seen_books;

	int last_index = -1;
	int sup_remaining_t = 0;
	int score = 0;
	vector<pair<int,vector<int>>> actions;
	for(int d=0;d<D;++d){
		//Gere le signing_up
		if(sup_remaining_t == 0 && last_index+1 <L ){
			signed_up.push_back(indices[++last_index]);
			sup_remaining_t = libs[indices[last_index]][1];
			actions.push_back(pair<int,vector<int>>(indices[last_index],vector<int>()));
			sort(books[indices[last_index]].begin(),books[indices[last_index]].end(),[&scores](int i, int j){return scores[i] > scores[j];});
		}
		int ctr = 0;
		for(auto lib : signed_up){
			int i = 0;
			while(i<libs[lib][2] && !books[lib].empty()){
				int book = books[lib][0];
				books[lib].erase(books[lib].begin());
				if(!(find(seen_books.begin(),seen_books.end(),book)!=seen_books.end())){
					score+= scores[book];
					seen_books.push_back(book);
					++i;
					actions[ctr].second.push_back(book);
				}
			}
			++ctr;
		}

		--sup_remaining_t;			
	}

	cerr<< "Score: " << score<< endl;

	int count=0;
	for(auto act : actions){
		if(act.second.size() > 0){
			count++;
		}
	}

	printf("%ld\n",count);
	for(auto lib : actions){
		if(lib.second.size() > 0){
		printf("%d %d\n",lib.first, lib.second.size());
		for(auto book : lib.second){
			printf("%d ",book);
		}
		printf("\n");
		}
	}




/*
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
*/

	return 0;
}

