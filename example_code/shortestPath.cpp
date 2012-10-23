#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// THE NUMBER OF VERTICES IN THE GRAPH
const int N = 6;

// adjacency is the adjacency matrix of the graph; source and target are 
// integers 0, ..., N - 1 indicating the source and target vertices (vertex 
// labels are identified with row and col entries for adjacency).
// NOTE: number of vertices must agree with N, defined above.
// NOTE: I am assuming that indicence is symmetric.
// NOTE: entries can be any positive integer (used as weights).
struct graphST
{
    int adjacency[N][N];
    int source;
    int target;
};

// distances keeps tract of shortest path from source to each target that has 
// been found so far (initialized to be full of upperBound).
// isDiscovered is full of 0's and 1's, to indicate whether a given vertex 
// has been visited yet.
struct atlas
{
    int distances[N];
    int isDiscovered[N];
};

void readGraph(int adjacency[N][N]);
void initializeAtlas(int upperBound, int source, atlas* search);
int min_int(int x, int y);
int arraySum(int list[], int len);
int nextVertex(graphST graph, atlas search, int upperBound);
int nearestPrecursor(graphST graph, atlas search, 
        int currentVertex, int upperBound);

int main()
{
    graphST graph;
    atlas search;
    int upperBound = 0; // Serves as ``infinity'' when initializing distances
    int currentVertex;
    vector<int> bestPath;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph.adjacency[i][j] = 0;
        }
    }

    readGraph(graph.adjacency);

    cout << "Here is the adjacency matrix: " << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph.adjacency[i][j] << " ";
            upperBound += graph.adjacency[i][j];
        }
        cout << endl;
    }

    cout << "Enter desired source vertex: ";
    cin >> graph.source;
    cout << "Enter desired target vertex: ";
    cin >> graph.target;

    initializeAtlas(upperBound, graph.source, &search);

    // Begin the search
    
    currentVertex = graph.source;

    while (arraySum(search.isDiscovered, N) < N)
    {
        for (int i = 0; i < N; i++)
        {
            if ((i != currentVertex) 
                    & (graph.adjacency[currentVertex][i] != 0)
                    & (search.isDiscovered[i] == 0))
            {
                // figuring out the new best known path to vertex i
                search.distances[i] = min_int(search.distances[currentVertex] 
                        + graph.adjacency[currentVertex][i], 
                        search.distances[i]);
            }
        }
        search.isDiscovered[currentVertex] = 1;
        currentVertex = nextVertex(graph, search, upperBound);
    }

    // Tracing shortest path back from target
    bestPath.push_back(graph.target);
    currentVertex = graph.target;
    while (currentVertex != graph.source)
    {
        currentVertex = nearestPrecursor(graph, search, 
                currentVertex, upperBound);
        bestPath.push_back(currentVertex);
    }

    while (!bestPath.empty())
    {
        if (bestPath.size() > 1)
            cout << bestPath.back() << " -> ";
        else
            cout << bestPath.back() << endl;
        bestPath.pop_back();
    }

    return 0;
}

void readGraph(int adjacency[N][N])
{
    ifstream fp_in;
    fp_in.open("graph.txt", ios::in);

    for (int i = 0; i < N*N; i++)
    {
        int n;
        char x = fp_in.get();
        n = (int)(x - '0');
        if (n != -38)
        {
            n = (int)(x - '0');
            adjacency[i/N][i%N] = n;
        }
        else
            i -= 1;
    }

    fp_in.close();   // close the streams when done
    return;
}

// returns the neighbor of currentVertex with the smallest associated distance.
int nearestPrecursor(graphST graph, atlas search, 
        int currentVertex, int upperBound)
{
    int bestGuess = 0;
    int bestDistance = upperBound;

    for (int i = 0; i < N; i++)
    {
        if (graph.adjacency[currentVertex][i] != 0
                & search.distances[i] < bestDistance)
        {
            bestGuess = i;
            bestDistance = search.distances[i];
        }
    }
    return bestGuess;
}

// returns the index of the nearest (smallest tentative distance) vertex to 
// the current vertex among unvisited neighbors
//
// The above is what this did before; it's not correct. We want the 
// undiscovered vertex with the smallest tentative distance from the source.
int nextVertex(graphST graph, atlas search, int upperBound)
{
    int bestCandidate = 0;
    int bestDistance = 2*upperBound;

    for (int i = 0; i < N; i++)
    {
        if (search.isDiscovered[i] == 0
                & search.distances[i] < bestDistance)
        {
            bestCandidate = i;
            bestDistance = search.distances[i];
        }
    }
    return bestCandidate;
}

// returns the sum of integers in array of length N
int arraySum(int list[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += list[i];
    return sum;
}


// returns the smaller of two integers
int min_int(int x, int y)
{
    if (x > y)
        return y;
    else
        return x;
}

void initializeAtlas(int upperBound, int source, atlas* search)
{
    for (int i = 0; i < N; i++)
    {
        (*search).distances[i] = upperBound;
        (*search).isDiscovered[i] = 0;
    }
    (*search).isDiscovered[source] = 1;
    (*search).distances[source] = 0;

    return;
}
