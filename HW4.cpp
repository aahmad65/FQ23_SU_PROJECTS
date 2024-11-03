#include<iostream>
#include<fstream>
#include "Graph.cpp"

using namespace std;

int main(int argc, char *file[]){
  ifstream file0(file[1]);
  ifstream file1(file[2]);
  ifstream file2(file[3]);
  ifstream file3(file[4]);

  cout << endl << "graph0.txt:" << endl;

  Graph graph0;
  graph0.load(file[1]);
  graph0.display();
  cout << endl << "DFS at vertex 0: ";
  graph0.displayDFS(0);
  cout << endl << "BFS at vertex 0: ";
  graph0.displayBFS(0);

  cout << endl << "graph1.txt:" << endl;

  Graph graph1;
  graph1.load(file[2]);
  graph1.display();
  cout << endl << "DFS at vertex 0: ";
  graph1.displayDFS(0);
  cout << endl << "BFS at vertex 0: ";
  graph1.displayBFS(0);

  cout << endl << "graph2.txt:" << endl;

  Graph graph2;
  graph2.load(file[3]);
  graph2.display();
  cout << endl << "DFS at vertex 0: ";
  graph2.displayDFS(0);
  cout << endl << "BFS at vertex 0: ";
  graph2.displayBFS(0);

  cout << endl << "graph3.txt:" << endl;

  Graph graph3;
  graph3.load(file[4]);
  graph3.display();
  cout << endl << "DFS at vertex 0: ";
  graph3.displayDFS(0);
  cout << endl << "BFS at vertex 0: ";
  graph3.displayBFS(0);


  cout << endl;

  return 0;
}