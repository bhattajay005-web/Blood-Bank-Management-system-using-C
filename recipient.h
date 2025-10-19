// recipient_module.h
#ifndef RECIPIENT_MODULE_H
#define RECIPIENT_MODULE_H

void register_recipient(const char *name, const char *blood_group, int urgency);
void search_recipient(const char *name);
void display_recipients();
int is_valid_blood_group(const char *bg);

#endif
