#include<iostream>
#include "Graph.h"
#include<fstream>
#include<queue>

using namespace std;

Graph::Graph(){
  spaces = nullptr;
}

void Graph::resize(int size){
  graph_size = size;
  spaces = new char *[graph_size];
  for(int i = 0; i < graph_size; i++){
    spaces[i] = new char[graph_size];
  }
  for(int i = 0; i < graph_size; i++){
    for(int j = 0; j < graph_size; j++){
      spaces[i][j] = '0';
    }
  }
}
Graph::~Graph(){
  for(int i = 0; i < graph_size; i++){
    delete[] spaces[i];
  }
  delete[] spaces;
}

int Graph::adjacent(int vert, int adj){
  if(spaces[vert][adj] == '1' && spaces[adj][vert] == '1'){
    return 1;
  }else{
    return 0;
  }
}

void Graph::load(char* filename){
  ifstream myfile;
  myfile.open(filename);
  string input;
  int count = 0;
  int vert1 = 0;
  int vert2 = 0;
  myfile >> input;
  int size = stoi(input);
  resize(size);
  while(myfile >> input){
    if(count == 0){
      vert1 = stoi(input);
      count++;
    }else if(count == 1){
      vert2 = stoi(input);
      spaces[vert1][vert2] = '1';
      spaces[vert2][vert1] = '1';
      count = 0;
    }
  }
  cout << endl;
}
void Graph::display(){
  for(int i = 0; i < graph_size; i++){
    for(int j = 0; j < graph_size; j++){
      cout << spaces[i][j] << " ";
    }
    cout << endl;
  }
}
void Graph::DFS(int vertex, bool* visited){
  visited[vertex] = true;
  cout << vertex << " ";
  for(int i = 0; i < graph_size; i++){
    if(!visited[i] && adjacent(vertex, i)){
      DFS(i, visited);
    }
  }
}
void Graph::displayDFS(int vertex){
  bool* visited = new bool[graph_size];
  for(int i = 0; i < graph_size; i++){
    visited[i] = false;
  }

  DFS(vertex, visited);

  delete[] visited;
}
void Graph::displayBFS(int vertex){
  bool* visited = new bool[graph_size];
  for(int i = 0; i < graph_size; i++){
    visited[i] = false;
  }

  queue<int> bfs;

  visited[vertex] = true;
  bfs.push(vertex);
  
  while(!bfs.empty()){
    vertex = bfs.front();
    cout << vertex << " ";
    bfs.pop();
    for(int i = 0; i < graph_size; i++){
      if(!visited[i] && adjacent(vertex, i)){
        visited[i] = true;
        bfs.push(i);
      }
    }
  }
  cout << endl;
  delete[] visited;
}