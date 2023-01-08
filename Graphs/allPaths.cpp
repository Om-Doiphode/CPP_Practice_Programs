#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// graph is represented as an adjacency list
vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3, 4}, {1, 2, 4}, {2, 3}};

void find_all_paths(int start, int end)
{
    queue<vector<int>> queue;
    unordered_set<int> visited;
    vector<int> path;

    // add the starting vertex to the queue, and mark it as visited
    queue.push({start});
    visited.insert(start);

    while (!queue.empty())
    {
        path = queue.front();
        queue.pop();
        int last_vertex = path.back();

        // check if we have reached the end vertex
        if (last_vertex == end)
        {
            cout << "Found a path: ";
            for (int i : path)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            // get the neighbors of the current vertex
            for (int neighbor : graph[last_vertex])
            {
                // only add the neighbor to the queue if it has not been visited
                if (visited.find(neighbor) == visited.end())
                {
                    vector<int> new_path(path);
                    new_path.push_back(neighbor);
                    queue.push(new_path);
                    visited.insert(neighbor);
                }
            }
        }
    }
}

int main()
{
    int start = 0;
    int end = 4;
    find_all_paths(start, end);
    return 0;
}
