/*
@ LeetCode

BFS 알고리즘 (Breadth-First Search)

그래프의 모양
   1
 2   3
4 5 6 7
8 9

ref : https://coding-factory.tistory.com/612
ref : https://hongku.tistory.com/156
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1050;

vector<int> v[MAX];
bool check_bfs[MAX];

void BFS(int start) {
    queue<int> q;              // Queue 생성
    q.push(start);             // 초기 시작점 저장
    check_bfs[start] = true;   // 초기 방문 체크

    while (!q.empty()) {
        // queue에 값이 있을 경우 계속하여 search
        // queue에 값이 있음 == 아직 방문하지 않은 노드가 존재함
        int current = q.front();
        q.pop();
        printf("%d ", current);

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];

            if (!check_bfs[next]) {
                // 방문하지 않은 노드라면
                check_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    // 1과 2를 연결
    v[1].push_back(2);
    v[2].push_back(1);

    // 1과 3을 연결
    v[1].push_back(3);
    v[3].push_back(1);

    // 2와 4를 연결
    v[2].push_back(4);
    v[4].push_back(2);

    // 2와 5을 연결
    v[2].push_back(5);
    v[5].push_back(2);

    // 4와 8을 연결
    v[4].push_back(8);
    v[8].push_back(4);

    // 5와 9를 연결
    v[5].push_back(9);
    v[9].push_back(5);

    // 3과 6을 연결
    v[3].push_back(6);
    v[6].push_back(3);

    // 3과 7을 연결
    v[3].push_back(7);
    v[7].push_back(3);

    BFS(1);
    return 0;
}