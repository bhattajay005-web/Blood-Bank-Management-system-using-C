#include "BBMS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void save_donors_to_file(Donor *head) {
    FILE *fp = fopen("donors.txt", "w");
    if (fp == NULL) {
        printf("Error opening donors.txt for writing!\n");
        return;
    }
    Donor *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d,%s,%d,%s,%s,%s\n",
                temp->id,
                temp->name,
                temp->age,
                temp->blood_group,
                temp->contact,
                temp->location);
        temp = temp->next;
    }
    fclose(fp);
    printf("\nDonor records saved to donors.txt\n");
}

Donor* load_donors_from_file() {
    FILE *fp = fopen("donors.txt", "r");
    if (fp == NULL) {
        printf("No existing donor file found — starting fresh...\n");
        return NULL;
    }
    Donor *head = NULL;
    int id, age;
    char name[50], blood_group[5], contact[20], location[50];
    while (fscanf(fp, "%d,%49[^,],%d,%4[^,],%19[^,],%49[^\n]\n",
                  &id, name, &age, blood_group, contact, location) == 6) {
        head = add_donor(head, id, name, age, blood_group, contact, location);
    }
    fclose(fp);
    printf("\nDonor records loaded successfully from donors.txt\n");
    return head;
}