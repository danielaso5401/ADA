from graphviz import Digraph
import heapq
dot= Digraph('dij', filename='dij.gv')
dot.attr(rankdir='LR')
dot_f = Digraph('dij_f', filename='dij_f.gv')
dot_f.attr(rankdir='LR')


def dijkstra(graph, starting_vertex):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[starting_vertex] = 0
    pq = [(0, starting_vertex)]
    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)
        if current_distance > distances[current_vertex]:
            continue
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
                
    return distances
    
    
grafo= {
    'A': {'B': 3, 'C': 1},
    'B': {'A': 3, 'C': 7, 'D': 5, 'E':1},
    'C': {'A': 1, 'B': 7, 'D': 2},
    'D': {'B': 5, 'C': 2, 'E': 7},
    'E': {'B': 1, 'D': 7},

}

claves=[]
claves2=[]
valores=[]
valores2=[]
for clave,valor in grafo.items():
    claves.append(clave)
    valores.append(valor)

for i in range(len(valores)):
    for clave2,valor2 in valores[i].items():
        claves2.append(clave2)
        valores2.append(valor2)

contador=0
for i in range(len(valores)):
    for j in range(len(valores[i])):
        dot.edge(claves[i], claves2[contador], label=str(valores2[contador]))
        dot_f.edge(claves[i], claves2[contador], label=str(valores2[contador]))
        contador=contador+1


r=dijkstra(grafo, 'D')
for clave,valor in r.items():
    dot_f.node(clave,label=clave+'\n'+str(valor),color="red")
dot.view()
dot_f.view()

