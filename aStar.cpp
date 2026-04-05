#include <bits/stdc++.h>
using namespace std;

// 좌표 구조체
struct Pos
{
    int y, x;
    bool operator==(const Pos& o) const { return y == o.y && x == o.x; }
    Pos operator+(const Pos& o) const { return {y + o.y, x + o.x}; }
};

// 우선순위 큐용 노드 구조체
struct PQNode
{
    // F = G + H
	// F = 최종 점수(작을 수록 좋음)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	// H = 목적지에서 해당 좌표까지 이동하는데 드는 비용
    PQNode(int f, int g, Pos pos) : f(f), g(g), pos(pos) {}
    int f;
    int g;
    Pos pos;
    bool operator>(const PQNode& other) const { return f > other.f; }
};

// grid : 맵 정보 (0:빈칸, 1:시작, 2:목적지, 3:벽)
// startX, startY : 시작 좌표
// goalX, goalY : 목표 좌표
// closed : 닫힌 목록 (방문한 노드)
vector<pair<int,int>> aStar(const vector<vector<int>>& grid,
                            int sy,int sx,int gy,int gx,
                            unordered_map<int,bool>& closed)
{
    int n = grid.size();

    //  8방향 이동 및 비용
    Pos move[8] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1},
        {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
    };
    int cost[8] = {10,10,10,10,14,14,14,14};

    vector<vector<int>> best(n, vector<int>(n, INT_MAX));      // 5단계 F의 최소 기록용
    vector<vector<Pos>> parent(n, vector<Pos>(n, {-1,-1}));    // 부모 좌표 저장

    // 1. 우선순위 큐 정의
    priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

    // 2. F를 오름차순 우선순위 큐에 시작 노드를 삽입
    int g = 0;
    int h = 10 * (abs(gy - sy) + abs(gx - sx));
    pq.push(PQNode(g + h, g, {sy, sx}));
    best[sy][sx] = g + h;
    parent[sy][sx] = {sy, sx};

    // 7. 목표 노드에 도달할 때까지 반복
    while (!pq.empty())
    {
        // 3. 우선순위 큐에서 최우선(F 최소) 노드를 pop
        PQNode node = pq.top();
        pq.pop();

        int key = node.pos.y * n + node.pos.x;
        if (closed[key]) 
            continue;
        if (best[node.pos.y][node.pos.x] < node.f)
            continue;

        // 방문 확정
        closed[key] = true; 

        // 도착점
        if (node.pos.y == gy && node.pos.x == gx)
            break;

        // 4. 현재 노드에서 이동할 수 있는 이웃 노드를 찾음
        for (int dir = 0; dir < 8; dir++)
        {
            Pos next = node.pos + move[dir];

            // 경계 체크
            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
                continue;

            // 벽 체크 (3은 벽)
            if (grid[next.y][next.x] == 3)
                continue;

            // 이미 방문한 곳이면 스킵
            int nextKey = next.y * n + next.x;
            if (closed[nextKey])
                continue;

            // 5. 이웃 노드의 F를 계산 (G 갱신 + H 계산)
            int g = node.g + cost[dir];
            int h = 10 * (abs(gy - next.y) + abs(gx - next.x));

            if (best[next.y][next.x] <= g + h)
                continue; // 더 나쁜 경로면 스킵

            // 6. 더 좋은 경로면 오픈리스트와 부모를 갱신하고 우선순위 큐에 삽입
            best[next.y][next.x] = g + h;
            pq.push(PQNode(g + h, g, next));
            parent[next.y][next.x] = node.pos;
        }
    }

    // 목표에 도달한 뒤 최단 경로 복원: 목표→시작으로 부모를 따라가고 reverse
    vector<pair<int,int>> path;
    // 시작점과 도착점
    Pos pos = {gy, gx};

    // 부모를 따라가며 경로 기록
    while (true)
    {
        path.push_back({pos.y, pos.x});
        if (pos == parent[pos.y][pos.x])
            break;
        pos = parent[pos.y][pos.x];
    }

    // 도착지점 -> 출발지점을 reverse 하여 최단경로 완성
    reverse(path.begin(), path.end());
    return path;
}

void printMap(const vector<vector<int>>& grid,
              const unordered_map<int,bool>& closed,
              const vector<pair<int,int>>& path)
{
    int n = grid.size();
    vector<vector<char>> disp(n, vector<char>(n, '.'));

    for (int y=0; y<n; ++y)
        for (int x=0; x<n; ++x)
        {
            // 벽 노드 표시
            if (grid[y][x] == 3) disp[y][x] = '#';
            // 닫힌 노드 표시
            else if (closed.count(y * n + x)) disp[y][x] = '+';
        }

    // 최단 경로 표시
    for (pair<int,int> p : path)
    {
        int y = p.first;
        int x = p.second;
        disp[y][x] = '*';
    }

    for (int y=0; y<n; ++y)
    {
        for (int x=0; x<n; ++x)
            cout << disp[y][x];
        cout << "\n";
    }
}

int main()
{
    // map.txt 파일에서 맵 읽기
    ifstream file("map.txt");
    if (!file.is_open()) {
        cerr << "map.txt 파일을 열 수 없습니다.\n";
        return 1;
    }

    // 맵 크기 읽기
    int rows, cols;
    file >> rows >> cols;

    // 맵 데이터 및 시작/목적지 좌표 초기화
    vector<vector<int>> map(rows, vector<int>(cols));
    pair<int,int> start(-1,-1), goal(-1,-1);

    // 맵 데이터 읽기
    for (int y=0; y<rows; ++y)
        for (int x=0; x<cols; ++x)
        {
            file >> map[y][x];
            if (map[y][x] == 1) start = {y,x};
            else if (map[y][x] == 2) goal = {y,x};
        }

    file.close();

    // printmap 에서 사용할 closed 해시맵
    unordered_map<int,bool> closed;

    // 시작점과 목적점이 유효한지 확인
    if (start.first == -1 || goal.first == -1) {
        cerr << "시작점 또는 목적점이 맵에 없습니다.\n";
        return 1;
    }

    // A* 알고리즘
    auto path = aStar(map, start.first, start.second, goal.first, goal.second, closed);
    printMap(map, closed, path);
}
