# Algoritmo de Dijkstra em C++
![Sigismund Dijkstra](https://64.media.tumblr.com/a9d9949d02dd0faa5539e3112b248aba/tumblr_np1tvmtrsE1s3eqy0o1_400.gif)

*Sigismund Dijkstra do jogo The Witcher 3*


Este é um exemplo simples de implementação do algoritmo de Dijkstra em C++ para encontrar o caminho mais curto em um grafo não direcionado com pesos não negativos.

![Edsger Dijkstra](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Edsger_Wybe_Dijkstra.jpg/800px-Edsger_Wybe_Dijkstra.jpg)

*Edsger Dijkstra*
## Visão Geral

O código consiste em uma classe `Graph` que representa um grafo e possui métodos para adicionar arestas e executar o algoritmo de Dijkstra para encontrar as distâncias mais curtas a partir de um nó de origem específico.

## Implementação

O algoritmo de Dijkstra é utilizado para calcular as distâncias mais curtas de um nó de origem para todos os outros nós no grafo. Ele funciona de acordo com os seguintes passos:

1. Inicializa as estruturas de dados necessárias, como uma lista de adjacências para representar o grafo e uma fila de prioridade para armazenar os nós a serem processados.
2. Define a distância inicial do nó de origem como 0 e as distâncias dos demais nós como infinito (`INT_MAX`).
3. Itera por todos os nós adjacentes ao nó atual, atualizando as distâncias se um caminho mais curto for encontrado.
4. Após o processamento de todos os nós, exibe as distâncias mais curtas a partir do nó de origem para todos os outros nós no grafo.

## Uso

Para utilizar este código, basta criar um objeto `Graph`, adicionar arestas usando o método `addEdge` e chamar o método `dijkstra` com o nó de origem desejado.

Exemplo:

```cpp
int main() {
    int V = 5;
    Graph g(V);

    // Adiciona arestas
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 2);

    // Executa Dijkstra a partir do nó 0
    g.dijkstra(0);

    return 0;
}
