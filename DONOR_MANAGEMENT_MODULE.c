#include "BBMS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Donor* add_donor(Donor *head, int id, char *name, int age, char *blood_group, char *contact, char *location) {
    Donor *newDonor = (Donor *)malloc(sizeof(Donor));
    newDonor->id = id;
    strcpy(newDonor->name, name);
    newDonor->age = age;
    strcpy(newDonor->blood_group, blood_group);
    strcpy(newDonor->contact, contact);
    strcpy(newDonor->location, location);
    newDonor->next = NULL;

    if (head == NULL)
        return newDonor;

    Donor *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newDonor;

    return head;
}

void display_donors(Donor *head) {
    if (head == NULL) {
        printf("\nNo donors found.\n");
        return;
    }
    Donor *temp = head;
    printf("\nDonor List\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d | Blood: %s | Contact: %s | Location: %s\n",
               temp->id, temp->name, temp->age, temp->blood_group, temp->contact, temp->location);
        temp = temp->next;
    }
}

