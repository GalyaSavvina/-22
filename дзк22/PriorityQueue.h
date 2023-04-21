#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class PriorityQueue {
private:
    std::vector<int> heap;
    // Поднять элемент вверх до тех пор, пока не будет восстановлено свойство кучи
    void shift_up(int pos) {
        while (pos > 0) {
            int parentIndex = (pos - 1) / 2;
            if (heap[pos] > heap[parentIndex]) {
                std::swap(heap[pos], heap[parentIndex]);
                pos = parentIndex;
            }
            else {
                break;
            }
        }
    }
    // Опустить элемент вниз до тех пор, пока не будет восстановлено свойство кучи

    void shift_down(int pos) {
        while (true) {
            int leftChildIndex = 2 * pos + 1;
            int rightChildIndex = 2 * pos + 2;
            int largestIndex = pos;
            if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }
            if (largestIndex != pos) {
                std::swap(heap[pos], heap[largestIndex]);
                pos = largestIndex;
            }
            else {
                break;
            }
        }
    }

public:
    PriorityQueue() {}

    ~PriorityQueue() {}

    void push(int value, int priority) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (priority > heap[parentIndex]) {
                heap[index] = heap[parentIndex];
                index = parentIndex;
            }
            else {
                break;
            }
        }
        heap[index] = value;
    }

    void pop() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        shift_down(0);
    }

    int top() {
        if (heap.empty()) {
            return -1;
        }
        return heap[0];
    }

    void clear() {
        heap.clear();
    }

    void printAsArray() {
        for (int i = 0; i < heap.size(); i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }

    void printAsTree() {
        int level = 0;
        int i = 0;
        while (i < heap.size()) {
            for (int j = 0; j < (1 << level) && i < heap.size(); j++) {
                std::cout << heap[i] << " ";
                i++;
            }
            std::cout << std::endl;
            level++;
        }
    }
    
};
// Класс для представления графа
class Graph {
private:
    int V; // Количество вершин
    vector<pair<int, int>>* adj; // Указатель на массив смежности
public:
    Graph(int V); // Конструктор
    void addEdge(int u, int v, int w); // Функция для добавления ребра в граф
    void primMST(); // Функция для поиска минимального остова методом Прима
};
Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


void primMST(Graph* g) {
    int numVertices = g->getNumVertices();
    std::vector<bool> visited(numVertices, false);
    std::vector<int> key(numVertices, INT_MAX);
    std::vector<int> parent(numVertices, -1);

    key[0] = 0;
    parent[0] = -1;
    PriorityQueue pq(numVertices);
    pq.push(0, 0);

    while (!pq.empty()) {
        int u = pq.pop();
        visited[u] = true;

        for (int v : g->getNeighbors(u)) {
            int weight = g->getWeight(u, v);
            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(weight, v);
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        totalWeight += g->getWeight(i, parent[i]);
    }

    std::cout << "Weight of Minimum Spanning Tree: " << totalWeight << std::endl;
}