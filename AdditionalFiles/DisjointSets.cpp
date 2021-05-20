#include "DisjointSets.h"

DisjointSets::DisjointSets(int n) {
  this->n = n;
  parent = new int[n + 1];
  rank = new int[n + 1];

  for (int i = 0; i <= n; i++) {
    rank[i] = 0;
    parent[i] = i;
  }
}

int DisjointSets::find(int u) const
{
  if (u != parent[u])
    parent[u] = find(parent[u]);
  return parent[u];
}

void DisjointSets::merge(int x, int y) const
{
  x = find(x), y = find(y);

  if (rank[x] > rank[y])
    parent[y] = x;
  else
    parent[x] = y;

  if (rank[x] == rank[y])
    rank[y]++;
}
