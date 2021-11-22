#include <iostream>

using namespace std;
const int MAX = 1000;
int arc[10][10];
int CreateGraph()
{
    int i, j, k;
    int weight;
    int vnum, arcnum;
    cout << "输入定点个数和边的个数:";
    cin >> vnum >> arcnum;
    for (i = 0; i < vnum; i++)
    {
        for (j = 0; j < vnum; j++)
        {
            arc[i][j] = MAX;
        }
    }
    for (k = 0; k < arcnum; k++)
    {
        cout << "输入边的两个顶点和权值:";
        cin >> i >> j >> weight;
        arc[i][j] = weight;
    }
    return vnum;
}

int BackPath(int n)
{
    int i, j, temp;
    int cost[n], path[n];
    for (i = 1; i < n; i++)
    {
        cost[i] = MAX;
        path[i] = -1;
    }
    cost[0] = 0;
    path[0] = -1;
    for (j = 1; j < n; j++)
    {
        for (i = j - 1; i >= 0; i--)
        {
            if (arc[i][j] + cost[i] < cost[j])
            {
                cost[j] = arc[i][j] + cost[i];
                path[j] = i;
            }
        }
    }
    cout << n - 1;
    i = n - 1;
    while (path[i] >= 0)
    {
        cout << "<-" << path[i];
        i = path[i];
    }
    return cost[n - 1];
}

int main()
{
    CreateGraph();
    BackPath(10);
    return 0;
}