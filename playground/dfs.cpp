//-------- 12% 에서 틀림
#include <iostream>
#include <queue>
#include <algorithm>

int N;
int M;
int V;
std::vector <int> arr[1001];
std::queue <int> bfs_arr[1001];
std::queue <int> dfs_arr[1001];
std::queue <int> bfs_result;
int visited[1001] = {0 , };

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void my_queue_sort(int i)
{
    sort(arr[i].begin(), arr[i].end());
    for(size_t j = 0 ; j < arr[i].size() ; j++){
        dfs_arr[i].push(arr[i][j]);
        bfs_arr[i].push(arr[i][j]);
    }

}

void input()
{
    int x;
    int y;
    std::cin >> N >> M >> V;
    while (M--){
        std::cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    // queue 정렬
    for(int i = 1 ; i<=N ; i++)
        my_queue_sort(i);

}

void dfs(int V)
{
	if (V <= 0 || V > N)
		return ;
    printf("%d ", V);
    //std::cout << V;

    visited[V] = 1;

    int num = dfs_arr[V].size();
    for(int i = 0; i < num ; i++){
		int next = dfs_arr[V].front();
		if(visited[next] == 0){
			dfs(next);
		}
        dfs_arr[V].pop();
	}
}

void bfs(int V)
{
    // visited 초기화
    for (int i = 0; i < N + 1; i++) visited[i] = 0;

    bfs_result.push(V);
    visited[V] = 1;

    while(!bfs_result.empty()){
		int tmp = bfs_result.front();
		bfs_result.pop();
		std::cout << tmp << " ";
        while(!bfs_arr[tmp].empty()){
			if(visited[bfs_arr[tmp].front()] == 0){
				bfs_result.push(bfs_arr[tmp].front());
				visited[bfs_arr[tmp].front()] = 1;
			}
            bfs_arr[tmp].pop();
		}
	}
}

void print_val()
{
  dfs(V);
  printf("\n");
  bfs(V);
}

int main()
{
	input_faster();
	input();
	print_val();
	return (0);
}
