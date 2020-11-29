from collections import defaultdict
from graphviz import Digraph
f = Digraph('krus', filename='krus.gv')
f.attr(rankdir='LR')
class grafo:

	def __init__(self, vertices):
		self.V = vertices
		self.graph = []

	def conexion(self, a, b, c):
		self.graph.append([a, b, c])

	def busqueda(self, dest, i):
		if dest[i] == i:
			return i
		return self.busqueda(dest, dest[i])

	def union(self, dest, cob, x, y):
		i = self.busqueda(dest, x)
		y = self.busqueda(dest, y)
		if cob[i] < cob[y]:
			dest[i] = y
		elif cob[i] > cob[y]:
			dest[y] = i
		else:
			dest[y] = i
			cob[i] += 1

	def kruscal(self):

		result = []
		i = 0
		e = 0
		self.graph = sorted(self.graph, key=lambda item: item[2])
		dest = []
		cob = []

		for node in range(self.V):
			dest.append(node)
			cob.append(0)

		while e < self.V - 1:
			a, b, c = self.graph[i]
			i = i + 1
			x = self.busqueda(dest, a)
			y = self.busqueda(dest, b)
			if x != y:
				e = e + 1
				result.append([a, b, c])
				self.union(dest, cob, x, y)

		minimumCost = 0

		for a, b, peso in result:
			minimumCost += peso
			f.edge(str(a),str(b), label=str(peso))

# Driver code
g = grafo(5)
g.conexion(0,1,1)
g.conexion(0,2,3)
g.conexion(1,0,1)
g.conexion(1,2,7)
g.conexion(1,3,5)
g.conexion(1,4,10)
g.conexion(2,0,3)
g.conexion(2,1,7)
g.conexion(2,4,4)
g.conexion(3,1,5)
g.conexion(3,4,2)
g.conexion(4,1,10)
g.conexion(4,2,4)
g.conexion(4,3,2)

r = Digraph('graf2', filename='graf2.gv')
r.attr(rankdir='LR')
for i in range(len(g.graph)):
    r.edge(str(g.graph[i][0]),str(g.graph[i][1]),label=str(g.graph[i][2]))
r.view()
g.kruscal()
f.view()