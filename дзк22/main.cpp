#include "PriorityQueue.h"

int main()
{
    // ������� ������ ������ PriorityQueue
    PriorityQueue queue;

    // ��������� �������� � ������� ������ � �� ������������
    queue.push(10, 2);
    queue.push(20, 5);
    queue.push(30, 1);
    queue.push(40, 3);
    queue.push(50, 2);
    queue.push(60, 4);
    queue.push(70, 5);

    // ������� ������� � ��������� ����������� ��� ��� �������� �� �������
    std::cout << "Top element: " << queue.top() << std::endl;

    // ��������� ������� �� �������
    queue.pop();

    // ������� ������� � ���� �������
    std::cout << "Queue as array: ";
    queue.printAsArray();
    std::cout << std::endl;

    // ������� ������� � ���� ������
    std::cout << "Queue as tree: " << std::endl;
    queue.printAsTree();
//Graph
        Graph g(5);
        g.addEdge(0, 1, 2);
        g.addEdge(0, 3, 6);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 8);
        g.addEdge(1, 4, 5);
        g.addEdge(2, 4, 7);
        g.addEdge(3, 4, 9);

        primMST(&g);
    system("pause");
    return 0;
}