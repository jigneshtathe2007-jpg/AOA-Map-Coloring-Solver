#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int V, M;

int trials = 0;
int backtracks = 0;

/* Check whether color c is safe for vertex v */
int isSafe(int v, int c)
{
    int i;

    for (i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

/* Backtracking graph coloring */
int colorGraph(int v)
{
    int c;

    /* All vertices colored */
    if (v == V)
        return 1;

    /* Try colors 1 to M */
    for (c = 1; c <= M; c++)
    {
        trials++;

        if (isSafe(v, c))
        {
            color[v] = c;

            if (colorGraph(v + 1))
                return 1;

            /* Undo assignment - Backtracking */
            color[v] = 0;
            backtracks++;
        }
    }

    return 0;
}

/* Display graph */
void displayGraph()
{
    int i, j;

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf("%d ", graph[i][j]);

        printf("\n");
    }
}

/* Display coloring */
void displayColoring()
{
    int i;

    printf("\nValid Colour Assignment:\n");

    for (i = 0; i < V; i++)
        printf("Vertex %d -> Colour %d\n", i + 1, color[i]);

    printf("\nTrials      : %d", trials);
    printf("\nBacktracks  : %d\n", backtracks);
}

/* Clear graph and colors */
void clearGraph()
{
    int i, j;

    for (i = 0; i < MAX; i++)
    {
        color[i] = 0;

        for (j = 0; j < MAX; j++)
            graph[i][j] = 0;
    }

    trials = 0;
    backtracks = 0;
}

/* Create custom graph */
void createGraph()
{
    int E, i, u, v;

    clearGraph();

    printf("\nEnter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of colours M: ");
    scanf("%d", &M);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (u v):\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 1 || u > V || v < 1 || v > V || u == v)
        {
            printf("Invalid edge! Enter again: ");
            i--;
            continue;
        }

        /* Undirected graph */
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    printf("\nGraph created successfully!\n");
}

/* Create standard test graphs */
void testGraph()
{
    int choice, i, j;

    clearGraph();

    printf("\n===== TEST GRAPH =====\n");
    printf("1. Path Graph\n");
    printf("2. Cycle Graph\n");
    printf("3. Complete Graph\n");
    printf("4. Disconnected Graph\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of colours M: ");
    scanf("%d", &M);

    /* Path Graph */
    if (choice == 1)
    {
        for (i = 0; i < V - 1; i++)
        {
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }
    }

    /* Cycle Graph */
    else if (choice == 2)
    {
        for (i = 0; i < V - 1; i++)
        {
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }

        graph[0][V - 1] = 1;
        graph[V - 1][0] = 1;
    }

    /* Complete Graph */
    else if (choice == 3)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (i != j)
                    graph[i][j] = 1;
            }
        }
    }

    /* Disconnected Graph */
    else if (choice == 4)
    {
        for (i = 0; i < V / 2 - 1; i++)
        {
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }

        for (i = V / 2; i < V - 1; i++)
        {
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }
    }

    else
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("\nTest graph created successfully!\n");
}

/* Solve graph */
void solveGraph()
{
    int i;

    for (i = 0; i < V; i++)
        color[i] = 0;

    trials = 0;
    backtracks = 0;

    if (colorGraph(0))
    {
        printf("\n===== RESULT =====\n");
        printf("%d colours are SUFFICIENT.\n", M);

        displayColoring();
    }
    else
    {
        printf("\n===== RESULT =====\n");
        printf("%d colours are NOT SUFFICIENT.\n", M);
        printf("Graph cannot be coloured with %d colours.\n", M);

        printf("\nTrials     : %d", trials);
        printf("\nBacktracks : %d\n", backtracks);
    }
}

/* Main menu */
int main()
{
    int choice;

    do
    {
        printf("\n\n=================================");
        printf("\n      MAP COLORING SOLVER");
        printf("\n=================================");
        printf("\n1. Create Undirected Graph");
        printf("\n2. Display Graph");
        printf("\n3. Solve / Colour Graph");
        printf("\n4. Test Standard Graph");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                solveGraph();
                break;

            case 4:
                testGraph();
                break;

            case 5:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}