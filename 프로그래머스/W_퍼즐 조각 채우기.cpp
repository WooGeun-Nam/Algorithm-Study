#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 좌표 구조체
struct Point
{
    int x, y;
};

// 도형 저장 구조체
struct Shape
{
    vector<vector<int>> data;
    int size = 0;
};

// 회전체들이 담긴 구조체
struct Rotate
{
    vector<Shape> shapes;
    bool used = false;
};

// BFS 탐색후 Shape으로 반환
Shape BFS(int startX, int startY, vector<vector<int>>& board, int target)
{
    int n = board.size();
    vector<Point> points;
    queue<Point> q;
    
    int minX = startX, maxX = startX;
    int minY = startY, maxY = startY;
    
    // 시작 위치 큐에 추가
    q.push({startX, startY});
    // 방문 처리
    board[startX][startY] = 2;
    
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        points.push_back(cur);
        
        if (cur.x < minX) minX = cur.x; if (cur.x > maxX) maxX = cur.x;
        if (cur.y < minY) minY = cur.y; if (cur.y > maxY) maxY = cur.y;
        
        int x = cur.x;
        int y = cur.y;
        
        // 4방향 전파
        if (x-1 >= 0 && board[x-1][y] == target)
        {
            board[x-1][y] = 2;
            q.push({x-1, y});
        }
        if (x+1 < n && board[x+1][y] == target)
        {
            board[x+1][y] = 2;
            q.push({x+1, y});
        }
        if (y-1 >= 0 && board[x][y-1] == target)
        {
            board[x][y-1] = 2;
            q.push({x, y-1});
        }
        if (y+1 < n && board[x][y+1] == target)
        {
            board[x][y+1] = 2;
            q.push({x, y+1});
        }
    }
    
    // 도형 범위
    int row = maxX-minX+1;
    int col = maxY-minY+1;
    vector<vector<int>> shapeData(row, vector<int>(col, 0));
    
    for (int i=0; i<points.size(); i++)
    {
        // points 를 도형으로 변환
        shapeData[points[i].x-minX][points[i].y-minY] = 1;
    }
    
    // 도형크기와 좌표를 구조체로 반환
    Shape result;
    result.data = shapeData;
    result.size = points.size(); 
    return result;
}

// 회전체 생성 함수 (CreateRotate로 명칭 변경)
void CreateRotate(Shape shapeData, vector<Rotate>& rotates)
{
    Rotate addRotate;
    // 회전하기 전 도형 저장용
    Shape current = shapeData;

    // 원본 저장
    addRotate.shapes.push_back(current);
    
    // 90, 180, 270 회전 rotates에 저장
    for (int k=0; k<3; k++)
    {
        // 도형 크기
        int row = current.data.size();
        int col = current.data[0].size();
        vector<vector<int>> nextData(col, vector<int>(row));

        // 90도 회전
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                nextData[j][row-1-i] = current.data[i][j];
            }
        }
        current.data = nextData;
        addRotate.shapes.push_back(current);
    }

    rotates.push_back(addRotate);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    // game_board 행의 길이 = table 행의 길이
    int n = game_board.size();
    
    // 추출한 도형들 회전체 포함
    vector<Rotate> rotates; 
    int answer = 0;
    
    // table 에서 도형 추출
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            // 해당 위치가 사용안한 도형이면
            if (table[i][j] == 1)
            {
                // table 은 1 찾기
                Shape shapeData = BFS(i, j, table, 1);
                // 찾은 도형의 회전체를 shapes 에 저장
                CreateRotate(shapeData, rotates);
            }
        }
    }
    
    // game_board 에서 빈칸 추출
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            // 해당 위치가 사용안한 도형이면
            if (game_board[i][j] == 0)
            {
                // game_board 는 0 찾기
                Shape boardShape = BFS(i, j, game_board, 0);
                for (int z=0; z<rotates.size(); z++)
                {
                    // 맞는 도형을 찾았는지 체크
                    bool check = false;
                    // 비교할 도형이 사용하지 않은 도형이면서 크기가 같은지 비교
                    // 크기가 다르면 비교할 필요 X
                    if (rotates[z].used == false && rotates[z].shapes[0].size == boardShape.size)
                    {
                        // 회전체 까지 비교
                        for (int k=0; k<4; k++)
                        {
                            if (boardShape.data == rotates[z].shapes[k].data)
                            {
                                // 비교할 도형이 같으면 해당 도형을 사용 처리
                                rotates[z].used = true;
                                check = true;
                                // 도형 크기만큼 answer+
                                answer += rotates[z].shapes[0].size;
                                break;
                            }
                        }
                    }
                    // 이미 맞는 도형을 찾았다면 다른 도형 비교 X
                    if (check == true) break;
                }
            }
        }
    }
    
    return answer;
}