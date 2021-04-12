/*
@ LeetCode

BFS �˰��� (Breadth-First Search)

�׷����� ���
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
    queue<int> q;              // Queue ����
    q.push(start);             // �ʱ� ������ ����
    check_bfs[start] = true;   // �ʱ� �湮 üũ

    while (!q.empty()) {
        // queue�� ���� ���� ��� ����Ͽ� search
        // queue�� ���� ���� == ���� �湮���� ���� ��尡 ������
        int current = q.front();
        q.pop();
        printf("%d ", current);

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];

            if (!check_bfs[next]) {
                // �湮���� ���� �����
                check_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    // 1�� 2�� ����
    v[1].push_back(2);
    v[2].push_back(1);

    // 1�� 3�� ����
    v[1].push_back(3);
    v[3].push_back(1);

    // 2�� 4�� ����
    v[2].push_back(4);
    v[4].push_back(2);

    // 2�� 5�� ����
    v[2].push_back(5);
    v[5].push_back(2);

    // 4�� 8�� ����
    v[4].push_back(8);
    v[8].push_back(4);

    // 5�� 9�� ����
    v[5].push_back(9);
    v[9].push_back(5);

    // 3�� 6�� ����
    v[3].push_back(6);
    v[6].push_back(3);

    // 3�� 7�� ����
    v[3].push_back(7);
    v[7].push_back(3);

    BFS(1);
    return 0;
}