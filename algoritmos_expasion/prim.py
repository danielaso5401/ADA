from graphviz import Digraph
import sys
f = Digraph('prim', filename='prim.gv')
f.attr(rankdir='LR')
r = Digraph('grafo', filename='graf.gv')
r.attr(rankdir='LR')

class Grafo():

    def __init__(self, vertices):
        self.v = vertices
        self.grafo =[]
        
    def min_val(self,val,grafo):
        min=sys.maxsize
        for v in range(self.v):
            if val[v] < min and grafo[v]==False:
                min=val[v]
                min_index=v
        return min_index
    
    def prim(self):
        val=[sys.maxsize]*self.v
        parent = [None]*self.v
        val[0]=0
        grafo_a=[False]*self.v
        parent[0]=-1
        for i in range(self.v):
            u=self.min_val(val, grafo_a)
            grafo_a[u]=True
            for j in range(self.v):
                if self.grafo[u][j]>0 and grafo_a[j] == False and val[j]>self.grafo[u][j]:
                    val[j]=self.grafo[u][j]
                    parent[j]=u
        for i in range (1,self.v):
            f.edge(str(parent[i]),str(i), label=str(self.grafo[i][parent[i]]))
        f.view()
        
def gengrafo(g):
   for i in range(len(g.grafo)):
       for j in range(len(g.grafo[i])):
           if g.grafo[i][j]!=0:
               r.edge(str(i),str(j), label=str(g.grafo[i][j]))
   r.view()
    
g = Grafo(6)
g.grafo = [ [0, 9, 0, 0, 0, 4], 
            [9, 0, 5, 0, 3, 1], 
            [0, 5, 0, 8, 3, 0], 
            [0, 0, 8, 0, 7, 0],
            [0, 3, 3, 7, 0, 2],
            [4, 1, 0, 0, 2, 0]]



gengrafo(g)
g.prim()
