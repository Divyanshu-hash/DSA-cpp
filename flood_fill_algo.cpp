#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void dfs(int sr,int sc,vector<vector<int>>& ans,vector<vector<int>>& image,vector<int>& delrow,vector<int>& delcol,int newColor){
    ans[sr][sc]=newColor;
    for(int i=0;i<4;i++){
        int nsr=sr+delrow[i];
        int nsc=sc+delcol[i];
        if(nsr>=0 && nsr<image.size() && nsc>=0 && nsc<image[0].size() && image[nsr][nsc]==image[sr][sc] && ans[nsr][nsc]!=newColor){
            dfs(nsr,nsc,ans,image,delrow,delcol,newColor);
        }
    }
}

vector<vector<int>> FloodFill(vector<vector<int>>& image,int sr,int sc,int newColor) {
    int initialColor=image[sr][sc];
    vector<vector<int>> ans=image;
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    dfs(sr,sc,ans,image,delrow,delcol,newColor);
    return ans;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 0}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = FloodFill(image, sr, sc, newColor);

    cout << "Modified Image after Flood Fill:" << endl;
    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}