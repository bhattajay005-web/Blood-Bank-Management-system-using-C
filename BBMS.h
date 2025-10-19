#ifndef BBMS_H
#define BBMS_H

typedef struct Donor {
    int id;
    char name[50];
    int age;
    char blood_group[5];
    char contact[20];
    char location[50];
    struct Donor *next;
} Donor;
Donor* add_donor(Donor *head, int id, char *name, int age, char *blood_group, char *contact, char *location);
void display_donors(Donor *head);
void search_donor_by_blood_group(Donor *head, char *blood_group);
Donor* edit_donor(Donor *head, int id);
Donor* delete_donor(Donor *head, int id);
void save_donors_to_file(Donor *head);
Donor* load_donors_from_file();

#endif