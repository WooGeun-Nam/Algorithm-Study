#include <bits/stdc++.h>
using namespace std;

// 입력을 위한 노드 구조체
// 최소비용의 부모 노드 위치 하나만 저장하고
// 경로는 나중에 역추적하는 방식도 가능하지만, 여기서는 경로를 직접 저장하는 방식을 사용
struct Node
{
    int id;
    vector<pair<int, int>> edges; // (연결된 정점, 거리)

    // 경로 저장용 벡터
    vector<int> path;
};

// dijkstra 알고리즘 구현
// 시작지점과 모든 노드 간의 최단 경로를 계산
vector<pair<Node,int>> dijkstra(vector<Node> nodes, int sn)
{
    // dist 벡터를 (정점, 거리) 쌍의 벡터로 변환하여 반환
    vector<pair<Node,int>> result;

    // node 는 id 값으로 접근
    
    // 시작 노드 거리는 0, 나머지 노드 거리는 무한대
    vector<int> dist(nodes.size(), INT_MAX);
    dist[sn-1] = 0;

    // pair(거리, 정점) 형태로 priorty_queue 정의
    priority_queue<pair<int, int>> pq;

     // 시작 노드 삽입
    pq.push({0, sn-1});

    // 모든 노드를 방문하여 큐가 빌때까지 반복
    while(!pq.empty())
    {
        // 큐(pq) 에서 가장 적은 비용을 지닌 노드(u) 선택
        Node u = nodes[pq.top().second];
        pq.pop();

        // 선택된 노드(u)에서 이어진 모든 이웃 노드(v)로 향하는 거리 계산
        for (pair<int,int> edge : u.edges)
        {
            int v_id = edge.first - 1; // 정점 번호는 1부터 시작하므로 -1
            int toDist = edge.second;

            // 현재 노드(u)를 거쳐 이웃 노드(v)로 가는 거리 계산
            int newDist = dist[u.id - 1] + toDist;

            // 이웃 노드(v)로 향하는 거리가 이전보다 짧다면 그 거리로 갱신하고 큐
            if (newDist < dist[v_id])
            {
                dist[v_id] = newDist;
                // 경로 갱신
                nodes[v_id].path = u.path;
                nodes[v_id].path.push_back(u.id);
                pq.push({newDist, v_id}); // pq에 푸쉬
            }
        }
    }

    for (int i = 0; i < dist.size(); ++i)
    {
        result.push_back({nodes[i], dist[i]});
    }

    return result;
}

int main()
{
    // 입력값 예시
    /*
    노드개수 시작노드
    노드별 연결 정보(정점,거리)
    6 3 (6개 노드 중 3번 노드가 시작노드)
    2 2 3 5 4 1 (1번노드는 2번노드와 연결 거리 2, 3번노드와 연결 거리 5, 4번노드와 연결 거리 1)
    1 2 3 3 4 2
    1 5 2 3 4 3 5 1 6 5
    1 1 2 2 3 3 5 1
    3 1 4 1 6 2
    3 5 5 2
    */
    int nodeCount, startNode;
    // cin >> nodeCount >> startNode;
    
    // 노드별 연결 정보 입력
    /*for (int i = 0; i <= nodeCount; ++i)
    {
        nodes[i].id = i;
        int to, dist;
        while (cin >> to >> dist)
        {
            nodes[i].edges.push_back({to, dist});
            if (cin.peek() == '\n') break; // 한 줄의 끝에서 입력 종료
        }
    }*/
    // 예시 입력값
    nodeCount = 6;
    startNode = 3;

    // nodeCount 개의 노드 생성
    vector<Node> nodes(nodeCount);

    nodes[0].id = 1; nodes[0].edges = {{2,2}, {3,5}, {4,1}};
    nodes[1].id = 2; nodes[1].edges = {{1,2}, {3,3}, {4,2}};
    nodes[2].id = 3; nodes[2].edges = {{1,5}, {2,3}, {4,3}, {5,1}, {6,5}};
    nodes[3].id = 4; nodes[3].edges = {{1,1}, {2,2}, {3,3}, {5,1}};
    nodes[4].id = 5; nodes[4].edges = {{3,1}, {4,1}, {6,2}};
    nodes[5].id = 6; nodes[5].edges = {{3,5}, {5,2}};

    // 다익스트라 알고리즘 수행
    vector<pair<Node,int>> shortestPaths = dijkstra(nodes, startNode);
    // 결과 출력
    for (pair<Node,int> p : shortestPaths)
    {
        Node n = p.first;
        int distance = p.second;
        cout << "Node " << n.id << ": Distance = " << distance << ", Path = ";
        for (int nodeId : n.path)
        {
            cout << nodeId << " -> ";
        }
        cout << n.id << endl;
    }
}