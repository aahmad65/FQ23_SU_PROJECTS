#include<iostream>

using namespace std;

class Graph{
  private:
    char **spaces;
    int graph_size;
    void resize(int size);
    int adjacent(int vert, int adj);
    void DFS(int vertex, bool* visited);
  public:
    Graph();
    ~Graph();
    void load(char* filename);
    void display();
    void displayDFS(int vertex);
    void displayBFS(int vertex);
};