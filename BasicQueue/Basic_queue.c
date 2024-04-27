#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *back;
} Queue;

void queue_enqueue(Queue *queue, int data) {

    //Crear un nodo nuevo
    Node *back_node = malloc(sizeof(Node));

    //Colocar dato a ingresar en el nodo en la posicion de atrás
    //Ya que es la ultima posicion,
    //Por lo tanto, no hay dato siguiente.
    back_node->data = data;
    //El subnodo siguiente será nulo, ya que no conecta otro nodo
    back_node->next = NULL;

    //Colocar ese nodo anterior en el nodo back de la cola en su posición ultima si no es nulo
    //De lo contrario, poner el nodo en la posicion frontal
    if (queue->back != NULL) {
        queue->back->next = back_node;
    } else {
        queue->front = back_node;
    }
    queue->back = back_node;
}

int queue_dequeue(Queue *queue) {

    int itemToBeRemoved = queue->front->data;

    //Almacenar en un nuevo nodo el nodo actual frontal
    Node *front_node = queue->front;

    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->back = NULL;
    }

    free(front_node);


    return itemToBeRemoved;
}

int queue_front(const Queue *queue) {
    return queue->front->data;
}

bool queue_is_empty(const Queue *queue){
    return queue->front == NULL && queue->back == NULL;
}

int main(void) {
    printf("QUEUE!\n");
    Queue *new_Queue = malloc(sizeof(Queue));
    if (new_Queue == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    new_Queue->front = NULL;
    new_Queue->back = NULL;

    queue_enqueue(new_Queue, 2);
    queue_enqueue(new_Queue, 3);
    queue_enqueue(new_Queue, 8);

    printf("last value: %d\n", new_Queue->back->data);

    int valueRemoved = queue_dequeue(new_Queue);
    printf("Value from front removed: %d\n", valueRemoved);

    int valueFromFront = queue_front(new_Queue);
    printf("Value from the front %d\n", valueFromFront);

    bool isEmpty = queue_is_empty(new_Queue);
    printf("The current queue is empty %s",  isEmpty ? "true" : "false");

    // Free queue
    free(new_Queue);

    return 0;
}



//Create a class named Queue with a generic T value that implements the iterable from c++ library

