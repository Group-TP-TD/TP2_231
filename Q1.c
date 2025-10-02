#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserer_fin(Node** head, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void suppr_occurrences(Node** head, int value) {
    Node *temp, *prev = NULL;
    while (*head && (*head)->data == value) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node* current = *head;
    while (current) {
        if (current->data == value) {
            temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void afficher(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, val, value;
    
    printf("Combien d’éléments voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l’élément %d : ", i + 1);
        scanf("%d", &value);
        inserer_fin(&head, value);
    }
    
    printf("Liste avant suppression : ");
    afficher(head);

    printf("Entrez l’élément à supprimer : ");
    scanf("%d",&val);
    
    suppr_occurrences(&head, val);

    printf("Liste après suppression de %d : ", val);
    afficher(head);

    return 0;
}