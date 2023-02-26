import numpy as np
from itertools import permutations, product

import networkx as nx
import matplotlib.pyplot as plt 


def visualize(adjacency_matrix):
    G = nx.DiGraph() 

    for i in range(len(adjacency_matrix)):
        for j in range(len(adjacency_matrix)):
            if adjacency_matrix[i][j]:
                G.add_edge(i, j)

    pos = nx.spring_layout(G, seed=5000)
    
    nx.draw_networkx_nodes(G, pos, node_size=200)
    nx.draw_networkx_edges(G, pos, edgelist=G.edges(), edge_color='black')
    nx.draw_networkx_labels(G, pos)

    plt.show() 
 

# Переворачивает указанную дугу
# Возвращает модифицированную матрицу смежности
def reverse_arc(adjacency_matrix, arc):
    adjacency_matrix[arc[0]][arc[1]] = 0
    adjacency_matrix[arc[1]][arc[0]] = 1
    return adjacency_matrix


# Разрушат указанный контур в орграфе
# Возвращает матрицы смежности полученных орграфов
def destroy_circuit(adjacency_matrix, circuit):
    arcs = set()
    solutions = []

    for i in range(len(circuit)):
        v1 = circuit[i]
        v2 = circuit[(i + 1) % len(circuit)]
        arcs.add((v1, v2))
    
    for arc1 in arcs:
        for arc2 in arcs:
            if arc1 != arc2:
                modified_matrix = np.copy(adjacency_matrix)
                modified_matrix = reverse_arc(modified_matrix, arc1)
                modified_matrix = reverse_arc(modified_matrix, arc2)
                solutions.append(modified_matrix)
    return solutions


# Постоение транзитивного замыкания. Алгоритм Уоршелла
def complement_to_transitive_closure(adjacency_matrix):
    modified_matrix = np.copy(adjacency_matrix)

    for i in range(len(adjacency_matrix)):
        for j in range(len(adjacency_matrix)):
            if adjacency_matrix[i][j]:
                modified_matrix[i] = np.logical_or(modified_matrix[i], adjacency_matrix[j])

    return modified_matrix


# Возвращает источники орграфа G
def get_sources(G, nodes):
    in_degrees = dict((u, 0) for u in nodes)

    for v in nodes:
        for u in nodes:
            if G[v][u]:
                in_degrees[u] += 1
    
    sources = []
    for v in nodes:
        if in_degrees[v] == 0:
            sources.append(v)
    return sources


# Возвращает списки уровней вершин орграфа G
def sort_by_levels(G):
    nodes = set(range(len(G)))
    levels = []

    while len(nodes) != 0:
        level = get_sources(G, nodes)
        levels.append(level)
        nodes = nodes.difference(level)
    return levels


# Упорядочивание вершин бесконтурного ориентированного графа 
# согласно частичному порядку, заданному ребрами орграфа 
# на множестве его вершин.
# Возвращает все возможные варианты линейных порядков.
def complement_to_liniear_order(G):
    levels = sort_by_levels(G)
    p = [permutations(level) for level in levels]
    order = [x for x in list(product(*p))]
    result = []
    for x in order:
        result.append(x)
    return result


def main():
    adjacency_matrix = np.array([[0, 0, 1, 0, 0, 0],
                                 [1, 0, 0, 0, 0, 0],
                                 [0, 1, 0, 0, 0, 0],
                                 [0, 0, 1, 0, 1, 0],
                                 [0, 0, 0, 0, 0, 1],
                                 [0, 0, 0, 1, 0, 0]])
    
    circuits = [(1, 0, 2), (3, 4, 5)]
    
    visualize(adjacency_matrix)

    for circuit in circuits:
        adjacency_matrix = destroy_circuit(adjacency_matrix, circuit)[2]
    visualize(adjacency_matrix)
    
    adjacency_matrix = complement_to_transitive_closure(adjacency_matrix)
    visualize(adjacency_matrix)
    
    for order in complement_to_liniear_order(adjacency_matrix):
        result = []
        for t in order:
            for e in t:
                result.append(e)
        print(result)



if __name__ == '__main__':
    main()