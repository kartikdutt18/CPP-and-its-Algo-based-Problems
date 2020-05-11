#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  bool isValid(int x, int y, vector<vector<int>> &image)
  {
    return x >= 0 && x < image.size() && y >= 0 && y < image[0].size();
  }
  void Fill(vector<vector<int>> &image, vector<vector<int>> &visited, int sr, int sc, int newColor)
  {
    if (!isValid(sr, sc, image))
      return;
    visited[sr][sc] = 1;
    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
      if (isValid(sr + dx[i], sc + dy[i], image) && !visited[sr + dx[i]][sc + dy[i]] &&
          image[sr + dx[i]][sc + dy[i]] == oldColor)
      {
        Fill(image, visited, sr + dx[i], sc + dy[i], newColor);
      }
    }
    return;
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    vector<vector<int>> visited(image.size(), vector<int>(image[0].size()));
    Fill(image, visited, sr, sc, newColor);
    return image;
  }
};

int main()
{
  return 0;
}