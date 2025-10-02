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

void afficher(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void trier(Node* head) {
    if (!head) return;

    int temp;
    Node* i;
    Node* j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Échange des données
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insertion_tri(Node** head, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (!(*head) || (*head)->data >= data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* current = *head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
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
    
    printf("Liste avant tri : ");
    afficher(head);
    
    trier(head);
    
    printf("Liste après tri : ");
    afficher(head);
    
    printf("Entrez l'élément à insérer : ");
    scanf("%d",&val);
    
    insertion_tri(&head,val);
    
    printf("Liste après insertion : ");
    afficher(head);
    
    return 0;
    
}    