#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000000000000LL
typedef long long ll;

typedef struct {
    int u, v;
    ll w;
    ll r;
} Edge;

int cmpEdge(const void *a, const void *b) {
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    if (ea->r < eb->r) return -1;
    if (ea->r > eb->r) return 1;
    return 0;
}

int parent[200005], rankArr[200005];

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankArr[a] < rankArr[b]) {
            int tmp = a; a = b; b = tmp;
        }
        parent[b] = a;
        if (rankArr[a] == rankArr[b])
            rankArr[a]++;
    }
}

typedef struct Node {
    int v;
    ll w;
    struct Node *next;
} Node;

Node *adj[200005];

void add_edge(int u, int v, ll w) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

typedef struct {
    int node;
    ll dist;
} HeapNode;

typedef struct {
    HeapNode *arr;
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heap_push(MinHeap *h, int node, ll dist) {
    h->size++;
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    int i = h->size;
    while (i > 1 && h->arr[i].dist < h->arr[i/2].dist) {
        swap(&h->arr[i], &h->arr[i/2]);
        i /= 2;
    }
}

int heap_empty(MinHeap *h) {
    return h->size == 0;
}

HeapNode heap_pop(MinHeap *h) {
    HeapNode top = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    int i = 1;
    while (1) {
        int left = i*2, right = i*2+1, smallest = i;
        if (left <= h->size && h->arr[left].dist < h->arr[smallest].dist)
            smallest = left;
        if (right <= h->size && h->arr[right].dist < h->arr[smallest].dist)
            smallest = right;
        if (smallest == i) break;
        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
    return top;
}

ll dijkstra(int n, int start, int end) {
    ll *dist = (ll*)malloc((n+1) * sizeof(ll));
    for (int i = 1; i <= n; i++) dist[i] = INF;

    MinHeap heap;
    heap.arr = (HeapNode*)malloc((2*n+5) * sizeof(HeapNode));
    heap.size = 0;

    dist[start] = 0;
    heap_push(&heap, start, 0);

    while (!heap_empty(&heap)) {
        HeapNode top = heap_pop(&heap);
        int u = top.node;
        ll d = top.dist;

        if (d != dist[u]) continue;
        if (u == end) break;

        for (Node *p = adj[u]; p != NULL; p = p->next) {
            int v = p->v;
            ll newDist = d + p->w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                heap_push(&heap, v, newDist);
            }
        }
    }

    ll ans = dist[end];
    free(dist);
    free(heap.arr);
    return ans;
}

void free_adj(int n) {
    for (int i = 1; i <= n; i++) {
        Node *p = adj[i];
        while (p) {
            Node *tmp = p;
            p = p->next;
            free(tmp);
        }
        adj[i] = NULL;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Edge *edges = (Edge*)malloc(M * sizeof(Edge));
        for (int i = 0; i < M; i++) {
            scanf("%d %d %lld %lld", &edges[i].u, &edges[i].v, &edges[i].w, &edges[i].r);
        }

        qsort(edges, M, sizeof(Edge), cmpEdge);

        make_set(N);
        ll minRisk = -1;
        for (int i = 0; i < M; i++) {
            union_sets(edges[i].u, edges[i].v);
            if (find_set(1) == find_set(N)) {
                minRisk = edges[i].r;
                break;
            }
        }

        if (minRisk == -1) {
            printf("-1\n");
            free(edges);
            continue;
        }

        for (int i = 0; i < M; i++) {
            if (edges[i].r <= minRisk) {
                add_edge(edges[i].u, edges[i].v, edges[i].w);
                add_edge(edges[i].v, edges[i].u, edges[i].w);
            } else {
                break;
            }
        }

        ll totalTime = dijkstra(N, 1, N);

        if (totalTime == INF)
            printf("-1\n");
        else
            printf("%lld %lld\n", minRisk, totalTime);

        free_adj(N);
        free(edges);
    }

    return 0;
}
