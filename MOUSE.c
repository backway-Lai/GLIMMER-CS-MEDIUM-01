#include <stdio.h>
#include <stdbool.h>

// 定义简单队列结构用于 BFS
typedef struct {
    int pos;   // 当前节点编号 (0~15)
    int dist;  // 到达当前节点的最短步数
} Node;

int minStepsToCheese(int walls) {
    int start = 0;
    int target = 15;

    // 如果起点或终点本身是墙，直接不可达
    if ((walls & (1 << start)) || (walls & (1 << target))) {
        return -1;
    }

    // BFS 队列与访问位图
    Node queue[16];
    int front = 0, rear = 0;
    int visited = 0;

    // 起点入队并标记已访问 (请使用位运算)
    queue[rear++] = (Node){ start, 0 };
    visited |= (1 << start);

    // 上、下、左、右四个方向的节点偏移量
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    //请在TO DO 和END OF TO DO 行之间补全代码：
    //TO DO

    while (front < rear) {
        Node a = queue[front++];                                               //记录当前研究的节点

        if (a.pos == target) return a.dist;                                    //判断是否到了终点

        int r = a.pos / 4;                                                     //计算节点行列
        int c = a.pos % 4;

        for (int i = 0;i <= 3;i++) {                                           //向四个方向寻找next
            int nr = r + dr[i];                                                //计算next的行列
            int nc = c + dc[i];

            if (!((nr >= 0 && nr <= 3) && (nc >= 0 && nc <= 3))) continue;     //是否出格

            Node next;                                                         //定义next
            next.pos = nr * 4 + nc;
            next.dist = a.dist + 1;

            if (walls & (1 << next.pos)) continue;                             //是否是墙
            if (visited & (1 << next.pos)) continue;                           //是否来过

            visited |= (1 << next.pos);
            queue[rear++] = next;                                              //更新visited，加入队列
        }
    }

    //END OF TO DO

    return -1; // 无法到达
}

int main() {
    int walls = (1 << 5) | (1 << 10); // 5号和10号格子是墙
    int steps = minStepsToCheese(walls);
    printf("Minimum steps: %d\n", steps); // 应输出 6
    return 0;
}