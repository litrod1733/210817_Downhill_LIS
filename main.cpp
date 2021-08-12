//
// Created by 이인성 on 2021/08/12.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int M, N;
int cnt = 0;

void findRoute(vector<vector<int>> map, int idx1, int idx2, int n) {
  if((idx1 == 0) && (idx2 == 0)) {
    cnt++;
  }
  if((idx2 != 0) && (map[idx1][idx2-1] > map[idx1][idx2])) {
    findRoute(map, idx1, idx2-1, n);
  }
  if((idx1 != 0) && (map[idx1-1][idx2] > map[idx1][idx2])) {
    findRoute(map, idx1-1, idx2, n);
  }
  if((idx2 != n-1) && (map[idx1][idx2+1] > map[idx1][idx2])) {
    findRoute(map, idx1, idx2+1, n);
  }
}

int main() {
  cin >> M >> N;
  vector<vector<int>> map;
  map.resize(M);
  for(int i=0; i<M; i++) {
    map[i].resize(N);
  }
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      int num;
      scanf("%d", &num);
      map[i][j] = num;
    }
  }
//  for(int i=0; i<M; i++) {
//    for(int j=0; j<N; j++) {
//      printf("%d ", map[i][j]);
//    }
//    printf("\n");
//  }
  findRoute(map, M-1, N-1, N);
  cout << cnt << endl;
  return 0;
}