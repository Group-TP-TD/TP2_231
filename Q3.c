#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void D_inserer_fin(DNode** head, int value) {
    DNode* new_node = malloc(sizeof(DNode));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

void D_afficher(DNode* head) {
    printf("Liste : ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void D_trier(DNode* head) {
    if (!head) return;

    int E;
    DNode* p;
    DNode* l = NULL;

    do {
        E = 0;
        p = head;

        while (p->next != l) {
            if (p->data > p->next->data) {
                // Échange des données
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                E = 1;
            }
            p = p->next;
        }

        l = p;
    } while (E);
}

void D_insertion_tri(DNode** head, int data) {
    DNode* new_node = malloc(sizeof(DNode));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;

    if (!(*head) || (*head)->data >= data) {
        new_node->next = *head;
        if (*head)
            (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    DNode* current = *head;
    while (current->next && current->next->data < data)
        current = current->next;

    new_node->next = current->next;
    if (current->next)
        current->next->prev = new_node;

    current->next = new_node;
    new_node->prev = current;
}

int main() {
    DNode* head = NULL;
    int n, val, value;

    printf("Combien d’éléments voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l’élément %d : ", i + 1);
        scanf("%d", &val);
        D_inserer_fin(&head, val);
    }

    D_trier(head);
    
    printf("Entrez l'élément à insérer : ");
    scanf("%d",&value);
    D_insertion_tri(&head,value);
    
    printf("Liste triée : ");
    D_afficher(head);

    return 0;
}




