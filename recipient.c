// recipient_module.c
#include <stdio.h>
#include <string.h>
#include "recipient.h"

#define MAX_RECIPIENTS 100

typedef struct {
    char name[50];
    char blood_group[5];
    int urgency; // lower = more urgent
} Recipient;

Recipient heap[MAX_RECIPIENTS];
int heap_size = 0;

const char *valid_blood_groups[] = {
    "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"
};

int is_valid_blood_group(const char *bg) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(bg, valid_blood_groups[i]) == 0)
            return 1;
    }
    return 0;
}

void swap(Recipient *a, Recipient *b) {
    Recipient temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[parent].urgency > heap[index].urgency) {
        swap(&heap[parent], &heap[index]);
        heapify_up(parent);
    }
}

void register_recipient(const char *name, const char *blood_group, int urgency) {
    if (!is_valid_blood_group(blood_group)) {
        printf(" Invalid blood group. Registration failed.\n");
        return;
    }

    if (heap_size >= MAX_RECIPIENTS) {
        printf("Recipient list full.\n");
        return;
    }

    strcpy(heap[heap_size].name, name);
    strcpy(heap[heap_size].blood_group, blood_group);
    heap[heap_size].urgency = urgency;

    heapify_up(heap_size);
    heap_size++;

    printf("Registered: %s | %s | Urgency: %d\n", name, blood_group, urgency);
}

void search_recipient(const char *name) {
    int found = 0;
    for (int i = 0; i < heap_size; i++) {
        if (strcmp(heap[i].name, name) == 0) {
            printf("Found: %s | %s | Urgency: %d\n",
                   heap[i].name, heap[i].blood_group, heap[i].urgency);
            found = 1;
        }
    }
    if (!found)
        printf("Recipient \"%s\" not found.\n", name);
}

void display_recipients() {
    if (heap_size == 0) {
        printf("No recipients in the system.\n");
        return;
    }

    printf("\nRecipients:\n");
    for (int i = 0; i < heap_size; i++) {
        printf(" %s | %s | Urgency: %d\n", heap[i].name, heap[i].blood_group, heap[i].urgency);
    }
}
