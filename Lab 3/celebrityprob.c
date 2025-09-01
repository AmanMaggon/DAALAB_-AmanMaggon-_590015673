#include <stdio.h>
#define N 3

int Matrix[N][N] = {
    {0, 1, 1},
    {0, 0, 1},
    {0, 0, 0}
};

int knows(int x, int y)
{
    return Matrix[x][y];
}

int celebrityFinder(int n)
{
    int candidates[N], top = -1;

    for (int i = 0; i < n; i++)
    {
        candidates[++top] = i;
    }

    while (top > 0)
    {
        int p1 = candidates[top--];
        int p2 = candidates[top--];

        if (knows(p1, p2))
        {
            candidates[++top] = p2;
        }
        else
        {
            candidates[++top] = p1;
        }
    }

    if (top == -1)
    {
        return -1;
    }

    int cand = candidates[top];

    for (int j = 0; j < n; j++)
    {
        if (j != cand)
        {
            if (knows(cand, j) || !knows(j, cand))
            {
                return -1;
            }
        }
    }

    return cand;
}

int main()
{
    int result = celebrityFinder(N);

    if (result == -1)
    {
        printf("No Celebrity\n");
    }
    else
    {
        printf("Celebrity Found: %d\n", result);
    }

    return 0;
}
