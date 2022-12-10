#include<bits/stdc++.h>

using namespace std;


int mat[1005][1005];  // assuming the max value of M and N to be 1000
bool vis[1005][1005]; // stores if the cell is visited or not

int dx[]={1,-1,0,0,-1,-1,1,1}; // directions to move to the adjacent cell in x-direction
int dy[]={0,0,-1,1,-1,1,-1,1}; // directions to move to the adjacent cell in y-direcion

int l,r,top,bottom; // stores the boundaries of the white patch




bool isvalid(int x,int y,int M,int N)  {   // checks if the current cell (x,y) is within the matrix
	if(x<0 || y<0 || x>=M || y>=N) return false;
	return true;
}



void dfs(int x,int y,int M,int N) {
	vis[x][y]=true;  
	l=min(l,y);   
	r=max(r,y);
	top=min(top,x);
	bottom=max(bottom,x);
	for(int i=0; i<8; i++) {
		int nx=x+dx[i]; // moving x in the x-direction by dx[i] units
		int ny=y+dy[i]; // moving y in the y-direction by dy[i] units
		if(isvalid(nx,ny,M,N) && !vis[nx][ny] && mat[nx][ny]==1) {  // if the adjacent cell is valid and not visited and the value is 1
			dfs(nx,ny,M,N);
		}
	}
}

typedef struct whitePatch {
	int centerX,centerY,width,height;
} whitePatch;



int main() {
	int M,N;
	cin>>M>>N;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			cin>>mat[i][j];
		}
	}
	vector<whitePatch> output;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			if(mat[i][j]==1 && !vis[i][j]) {
				l=INT_MAX;
				r=0;
				bottom=0;
				top=INT_MAX;
				dfs(i,j,M,N);
				whitePatch temp;
				temp.centerX=(l+r)/2;
				temp.centerY=(top+bottom)/2;
				temp.width=r-l+1;
				temp.height=bottom-top+1;
				output.push_back(temp);
			}
		}
	}
	for(auto patch: output) {
		cout<<patch.centerX<<" "<<patch.centerY<<" "<<patch.width<<" "<<patch.height<<endl;
	}

	return 0;
}
