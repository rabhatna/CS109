/*
Graph.cpp
Hw2
Rabhatna
*/

#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include <ctime>
#include <random>
#include <cmath>


//Constructor
Graph::Graph(int n){ 
   adj.resize(n,vector<float>(n,0)); // range 0 to n (n noninclusive)
   nodeData.resize(n+1);
   vertices = n;
   edges = 0;
}

//Manipulation Functions

//Checks input and adds edge between valid indexs
void Graph::add(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      if(!this->adjacent(x,y)){
         this->adj[x][y] = 1.0;
      }
   }
}

//Checks input and removes edge between valid indexs
void Graph::remove(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      this->adj[x][y] = 0;
   }
}

//Generates a random graph
void Graph::randomGraph(float edgeDen, float distRange){
   //Random number generator
   default_random_engine generator(time(NULL));

   
   int edgeDensity = ceil(this->vertices * edgeDen);
   int totalEdges = edgeDensity * this->vertices;

   //Number generators with different ranges
   uniform_int_distribution<int> dis(0, edgeDensity);
   uniform_int_distribution<int> disN(0, this->vertices-1);  
   uniform_real_distribution<float> disR(1, distRange);

   //Loops through all nodes
   for(int i = 0; i < this->adj.size(); i++){
      int edgeNum = dis(generator);
      int j = 0; 

      //Runs till edge number has been met
      while(j <= ceil(edgeNum)){
         int node = disN(generator);
         if(0 <= node && node < this->vertices){
            if(!this->adjacent(i,node) && i != node){
               int counter = 0;
               vector<float> temp = this->neighbors(node);
               for(int k = 0; k < temp.size(); k++){
                  if(temp[k] > 0){
                     counter++;
                  }
               }

               //used to ensure a node does not end up with exessive connections maintains the avg
               if(counter < edgeDensity){
                  this->adj[i][node] = disR(generator);
                  j++;
               }
            }
         }
      }
   }
}

//Checks input and sets node value
void Graph::set_node_value(int x, int a){ 
   if(0 <= x && x < this->vertices){
      this->nodeData[x] = a;
   }
}

//Checks input and sets edge value
void Graph::set_edge_value(int x, int y, float v){
  if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
     this->adj[x][y] = v;
  }
}

//Prints graph
void Graph::printG(){  
   for(int i = 0; i < this->adj.size(); i++){
      for(int j = 0; j < this->adj[i].size(); j++){
         cout<< this->adj[i][j] << " ";
      }
      cout << "\n";
    }  
}


//Access Functions

//Checks input and if two nodes are connected
bool Graph::adjacent(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      if(this->adj[x][y] > 0){
         return true;
      }else if(this->adj[y][x]){
         return true;
      }
   }
  return false;  
}

//Checks input and returns the nodes row
vector<float> Graph::neighbors(int x){
   vector<float> temp(this->vertices);
   if(0 <= x && x < this->vertices){
      for(int j = 0; j < this->adj[x].size(); j++){
         temp[j] = this->adj[x][j];
      }
   }
    return temp;
}

//Returns number of vertices
int Graph::V(){
   return this->vertices;
}

//Returns number of edges
int Graph::E(){
   return this->edges;
}

//Checks input and returns node value
int Graph::get_node_value(int x){ 
   if(0 <= x && x < this->vertices){
      return this->nodeData[x];
   }
   return 0;
}

//Checks input and returns edge value
float Graph::get_edge_value(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
       if(this->adj[x][y] > 0){
          return this->adj[x][y];
       }else if(this->adj[y][x] > 0){
          return this->adj[y][x];
       }
   }
   return 0; 
}
