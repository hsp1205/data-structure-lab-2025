from collections import deque  # BFS 탐색을 위한 deque 사용

input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

def problem3(input):
    bear_size = 2           
    honeycomb_count = 0     
    time = 0
    bear_x, bear_y = 0, 0
    
    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치를 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j  
                forest[i][j] = 0       

    # 곰이 이동할 수 있는 방향 (상, 좌, 우, 하)
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    # BFS로 현재 위치에서 먹을 수 있는 가장 가까운 꿀벌집 찾기
    def bfs(x, y, size):
        visited = [[False]*N for _ in range(N)]  # 방문 여부 체크용 2차원 배열
        q = deque()
        q.append((x, y, 0))     # 큐에 (x좌표, y좌표, 이동 거리) 저장
        visited[x][y] = True
        candidates = []         # 먹을 수 있는 꿀벌집 후보들

        while q:
            cx, cy, dist = q.popleft()

            for d in range(4):  # 상하좌우 4방향으로 이동
                nx, ny = cx + dx[d], cy + dy[d]

                # 맵 범위 안이고 아직 방문하지 않았고, 곰이 지나갈 수 있는 칸일 때
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = True  # 방문 처리

                        # 먹을 수 있는 꿀벌집이면 후보에 추가
                        if 0 < forest[nx][ny] < size:
                            candidates.append((dist + 1, nx, ny))

                        # 이동 가능한 칸이면 큐에 넣기
                        q.append((nx, ny, dist + 1))

        # 후보 중 거리 → 위쪽 → 왼쪽 우선순위로 정렬
        candidates.sort(key=lambda x: (x[0], x[1], x[2]))

        # 먹을 꿀벌집이 있다면 가장 우선순위 높은 하나 반환
        return candidates[0] if candidates else None

    # 꿀벌집 먹는 루프: 더 이상 먹을 수 없을 때까지 반복
    while True:
        result = bfs(bear_x, bear_y, bear_size)

        if result is None:  # 더 이상 먹을 수 있는 꿀벌집이 없다면 종료
            break

        dist, nx, ny = result            # 거리와 꿀벌집 위치
        time += dist                     # 꿀을 먹기 위한 이동 시간 추가
        honeycomb_count += 1            # 꿀벌집 먹은 수 증가
        forest[nx][ny] = 0              # 꿀벌집 먹은 칸은 빈 칸으로 처리
        bear_x, bear_y = nx, ny         # 곰 위치 갱신

        # 꿀을 곰의 크기만큼 먹었으면 크기 증가
        if honeycomb_count == bear_size:
            bear_size += 1              # 곰 크기 1 증가
            honeycomb_count = 0         # 먹은 꿀 개수 초기화

    return time     # 꿀벌집 찾기 종료 후 총 이동 시간 반환

# 결과 출력
print(problem3(input))

result = problem3(input)

assert result == 14
print("정답입니다.")
