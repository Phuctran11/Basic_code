#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 5
#define MAX_NUM_WORDS 100

struct Node {
    char word[MAX_WORD_LENGTH + 1];
    struct Node* next;
};

struct Graph {
    int num_vertices;
    struct Node** adjacency_list;
};

struct Node* createNode(char* word) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_list = (struct Node**)malloc(num_vertices * sizeof(struct Node*));

    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, char* src, char* dest) {
    struct Node* newNode = createNode(dest);
    int index = src[0] - 'a'; // Assuming lowercase English alphabet

    if (graph->adjacency_list[index] == NULL) {
        graph->adjacency_list[index] = newNode;
    } else {
        struct Node* temp = graph->adjacency_list[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int isOneCharacterDifference(char* word1, char* word2) {
    int diff_count = 0;
    int length = strlen(word1);

    for (int i = 0; i < length; i++) {
        if (word1[i] != word2[i]) {
            diff_count++;
            if (diff_count > 1) {
                return 0;
            }
        }
    }

    return 1;
}

void BFS(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;

    struct Node* queue[MAX_NUM_WORDS];
    int front = -1, rear = -1;
    queue[++rear] = graph->adjacency_list[vertex];

    while (front != rear) {
        struct Node* current_vertex = queue[++front];
        int adjacent_vertex = current_vertex->word[0] - 'a';
        
        if (!visited[adjacent_vertex]) {
            visited[adjacent_vertex] = 1;
            queue[++rear] = graph->adjacency_list[adjacent_vertex];
        }

        current_vertex = current_vertex->next;
        while (current_vertex) {
            adjacent_vertex = current_vertex->word[0] - 'a';
            
            if (!visited[adjacent_vertex]) {
                visited[adjacent_vertex] = 1;
                queue[++rear] = graph->adjacency_list[adjacent_vertex];
            }

            current_vertex = current_vertex->next;
        }
    }
}

int countConnectedComponents(struct Graph* graph) {
    int component_count = 0;
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));

    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            component_count++;
            BFS(graph, i, visited);
        }
    }

    free(visited);
    printf ("%d",component_count);
}

int main() {
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH + 1] = {"words", "wolds", "golds", "goads", "grads", "grade", "grape", "graph"};
    int num_words = sizeof(words) / sizeof(words[0]);

    struct Graph* graph = createGraph(num_words);

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (isOneCharacterDifference(words[i], words[j])) {
                addEdge(graph, words[i], words[j]);
                addEdge(graph, words[j], words[i]);
            }
        }
    }

    countConnectedComponents(words);

    return 0;
}

