#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 101

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct Graph {
  Node *adjacencyList[MAX_NODES];
  int visited[MAX_NODES];
} Graph;

typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

typedef struct Stack {
  Node *top;
} Stack;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void initGraph(Graph *graph) {
  int i;
  for (i = 0; i < MAX_NODES; i++) {
    graph->adjacencyList[i] = NULL;
    graph->visited[i] = 0;
  }
}

void addEdge(Graph *graph, int src, int dest) {
  Node *newNode = createNode(dest);
  newNode->next = graph->adjacencyList[src];
  graph->adjacencyList[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjacencyList[dest];
  graph->adjacencyList[dest] = newNode;
}

void initQueue(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

int isQueueEmpty(Queue *queue) { return queue->front == NULL; }

void enqueue(Queue *queue, int value) {
  Node *newNode = createNode(value);
  if (queue->rear == NULL) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

int dequeue(Queue *queue) {
  if (isQueueEmpty(queue)) {
    return -1;
  } else {
    int value = queue->front->value;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
      queue->rear = NULL;
    }
    free(temp);
    return value;
  }
}

void initStack(Stack *stack) { stack->top = NULL; }

int isStackEmpty(Stack *stack) { return stack->top == NULL; }

void push(Stack *stack, int value) {
  Node *newNode = createNode(value);
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    return -1;
  } else {
    int value = stack->top->value;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
  }
}

void BFS(Graph *graph, int startNode) {
  Queue queue;
  initQueue(&queue);
  graph->visited[startNode] = 1;
  enqueue(&queue, startNode);

  while (!isQueueEmpty(&queue)) {
    int currentNode = dequeue(&queue);
    printf("%d ", currentNode);

    Node *temp = graph->adjacencyList[currentNode];
    while (temp != NULL) {
      int adjacentNode = temp->value;
      if (graph->visited[adjacentNode] == 0) {
        graph->visited[adjacentNode] = 1;
        enqueue(&queue, adjacentNode);
      }
      temp = temp->next;
    }
  }
}

void DFSUtil(Graph *graph, int currentNode) {
  graph->visited[currentNode] = 1;
  printf("%d ", currentNode);

  Node *temp = graph->adjacencyList[currentNode];
  while (temp != NULL) {
    int adjacentNode = temp->value;
    if (graph->visited[adjacentNode] == 0) {
      DFSUtil(graph, adjacentNode);
    }
    temp = temp->next;
  }
}

void DFS(Graph *graph, int startNode) {
  initStack(&stack);
  push(&stack, startNode);

  while (!isStackEmpty(&stack)) {
    int currentNode = pop(&stack);
    if (graph->visited[currentNode] == 0) {
      printf("%d ", currentNode);
      graph->visited[currentNode] = 1;
    }

    Node *temp = graph->adjacencyList[currentNode];
    while (temp != NULL) {
      int adjacentNode = temp->value;
      if (graph->visited[adjacentNode] == 0) {
        push(&stack, adjacentNode);
      }
      temp = temp->next;
    }
  }
}

int main() {
  int startNode, N, M;
  scanf("%d", &startNode);
  scanf("%d", &N);
  scanf("%d", &M);

  Graph graph;
  initGraph(&graph);

  int i;
  for (i = 0; i < M; i++) {
    int src, dest;
    scanf("%d", &src);
    scanf("%d", &dest);
    addEdge(&graph, src, dest);
  }

  BFS(&graph, startNode);
  printf("\n");

  initGraph(&graph);

  for (i = 0; i < M; i++) {
    int src, dest;
    scanf("%d", &src);
    scanf("%d", &dest);
    addEdge(&graph, src, dest);
  }

  DFSUtil(&graph, startNode);
  printf("\n");

  return 0;
}
