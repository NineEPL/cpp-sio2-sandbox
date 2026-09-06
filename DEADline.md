Oto **krótka, szkolna ściąga z algorytmiki (grafy)** – tak zrobiona, żeby można było szybko przypomnieć sobie algorytm na sprawdzianie lub olimpijce.

---

# 📌 ŚCIĄGA – ALGORYTMIKA (GRAFY)

## 1. DFS – Depth First Search (przeszukiwanie w głąb)

**Idea:**
Idziemy jak najgłębiej w grafie, dopóki się da, potem cofamy się.

**Zastosowania**

* spójne składowe
* sprawdzanie cyklu
* sortowanie topologiczne
* mosty i punkty artykulacji
* przechodzenie drzewa

**Złożoność**
[
O(n+m)
]

**Implementacja (rekurencyjna)**

```cpp
vector<int> adj[N];
bool vis[N];

void dfs(int v){
    vis[v] = true;

    for(int u : adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
```

**Schemat**

1. oznacz wierzchołek jako odwiedzony
2. przejdź po wszystkich sąsiadach
3. jeśli nieodwiedzony → DFS

---

# 2. BFS – Breadth First Search (przeszukiwanie wszerz)

**Idea:**
Odwiedzamy graf **warstwami**.

**Zastosowania**

* najkrótsza ścieżka w grafie nieważonym
* odległości od wierzchołka
* sprawdzanie dwudzielności grafu

**Złożoność**

[
O(n+m)
]

**Implementacja**

```cpp
queue<int> q;
bool vis[N];
int dist[N];

void bfs(int s){
    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u : adj[v]){
            if(!vis[u]){
                vis[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}
```

**Klucz**

* używa **kolejki**
* zawsze najpierw najbliższe wierzchołki

---

# 3. Spójne składowe

**Definicja**

Spójna składowa = maksymalny zbiór wierzchołków gdzie każdy jest osiągalny z każdego.

**Algorytm**

DFS/BFS z każdego nieodwiedzonego wierzchołka.

**Schemat**

```cpp
int comp = 0;

for(int i=1;i<=n;i++){
    if(!vis[i]){
        comp++;
        dfs(i);
    }
}
```

**Złożoność**

[
O(n+m)
]

---

# 4. Drzewa

**Definicja**

Graf jest drzewem gdy:

1️⃣ jest spójny
2️⃣ nie ma cykli

**Własności**

dla (n) wierzchołków:

[
m = n - 1
]

**Inne własności**

* istnieje dokładnie **jedna ścieżka** między każdą parą wierzchołków
* usunięcie krawędzi → graf niespójny
* dodanie krawędzi → powstaje cykl

---

# 5. Sortowanie topologiczne

Dotyczy **DAG** (Directed Acyclic Graph).

**Idea**

Ustawienie wierzchołków tak, żeby:

[
u \rightarrow v
]

oznaczało

[
u \text{ przed } v
]

---

## Metoda 1 – DFS

1. DFS
2. po wyjściu z wierzchołka dodaj do listy
3. odwróć kolejność

```cpp
vector<int> topo;

void dfs(int v){
    vis[v] = true;

    for(int u : adj[v]){
        if(!vis[u])
            dfs(u);
    }

    topo.push_back(v);
}
```

na końcu:

```cpp
reverse(topo.begin(), topo.end());
```

---

## Metoda 2 – Kahn (BFS)

Idea: bierzemy wierzchołki o **stopniu wejściowym = 0**

**Algorytm**

1. policz `inDegree`
2. wrzuć `0` do kolejki
3. zdejmuj z kolejki
4. zmniejsz stopnie sąsiadów

```cpp
queue<int> q;

for(int i=1;i<=n;i++)
    if(inDeg[i]==0)
        q.push(i);

while(!q.empty()){
    int v = q.front(); q.pop();

    for(int u:adj[v]){
        inDeg[u]--;
        if(inDeg[u]==0)
            q.push(u);
    }
}
```

---

# 6. Find & Union (Union-Find / DSU)

Struktura do obsługi:

* sprawdzania czy wierzchołki są w tej samej składowej
* łączenia zbiorów

**Operacje**

* `find(x)` – reprezentant zbioru
* `union(a,b)` – połączenie

**Złożoność**

amortyzowana:

[
O(\alpha(n))
]

(prawie stała)

---

## Implementacja

```cpp
int parent[N];
int rnk[N];

int find(int v){
    if(parent[v]==v)
        return v;

    return parent[v]=find(parent[v]);
}

void unite(int a,int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        if(rnk[a]<rnk[b])
            swap(a,b);

        parent[b]=a;

        if(rnk[a]==rnk[b])
            rnk[a]++;
    }
}
```

---

# 🔑 Szybkie porównanie

| Algorytm        | Zastosowanie                   | Struktura         |
| --------------- | ------------------------------ | ----------------- |
| DFS             | eksploracja grafu              | rekurencja / stos |
| BFS             | najkrótsze ścieżki (nieważone) | kolejka           |
| Spójne składowe | podział grafu                  | DFS/BFS           |
| Drzewa          | graf bez cykli                 | n-1 krawędzi      |
| Toposort        | DAG                            | DFS / Kahn        |
| Union-Find      | dynamiczne składowe            | tablice           |

---

✅ Jeśli chcesz, mogę też zrobić **drugą wersję tej ściągi – olimpijską**, z dodatkowymi rzeczami które często pojawiają się na **OI / potyczkach / konkursach szkolnych**, np:

* **LCA w drzewach**
* **mosty i punkty artykulacji**
* **BFS 0-1**
* **cykle w grafie**
* **Kruskal (MST)**

— to byłaby taka **ultimate ściąga grafowa na 1 stronę A4**.
