#                  GRAPH

## WAY TO REPRESENT GRAPH

1. Adjacency List
2. Adjacency matrix
3. Adjacency map
4. Incidence matrix
5. Edge List
   
Note: one long way is made class of all entity like class for Node , for edges and for graph

## 1. Adjacency List 
- In this appraoch we represent graphs as a array of linked list
- array size : same as total number of node in graph
- what link list contain: it contain Nodes connect to directly that Nodes , order doesn't matter
- ith index represent neighbour of ith vertex
-  direct graph :connect list only store nodes that is connect through outgoing node 
-  weighted graph : link-list should store two value [node][weight]
-  
 ```
 0[]->⭕->⭕
 1[]->⭕->⭕
 2[]->⭕->⭕->⭕
 3[]->⭕->⭕
 4[]->⭕
 5[]->⭕->⭕
 6[]->⭕->⭕
 ```

## 2. Adjacency Map
- Here we graph in th ofrm of array of hashmap/unordered set
- you can visualize it similar to Adjacency List
  
  ## 3. Adjacency Matrix
  - In this appraoch we represent th graph in a 2-D array or matrix of V X V dimensions where v is the no. of vertices
  -  1 represent edge exsist and 0 represent edge not exitst
  -  weighted graph: Inplace of 1 and 0 we write edge's weight
  -  directed graph: row behaves as source and columan behaves as destinations vertex and we depicted source to destination , either by 0's and 1's or by weight of edge
  -  Note : Must use way to represent the graph
```
    v1   v2   v3
v1  0     1    0
 
v2  1     0    1

v3  0     1    0
```
## 4. Incidence Matrix
- In this approach we prepare a V X E matrix where V is the no of vertices and E is no. of edges
  
## 5. Edge List 
- Here We get a list of direct connect edges , in pair of tow vertices

## Graph Traversal
- To read any graph we have two major techniques
1. Depth First Search / traversal
2. Breadth First Traversal/search

## 1. Depth First Search (Recusrion)

- Let's take motivation Problem
- 1. In given graph Calculate all path between two  vertices
- 2. In gien graph check whether there is a pathh between two vertcies or not ?

## 2. Breadth First Search(level order traversal)
- can be used to find shortest path in unweighted graph
- 