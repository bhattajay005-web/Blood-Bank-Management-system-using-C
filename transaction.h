// transaction_module.h
#ifndef TRANSACTION_MODULE_H
#define TRANSACTION_MODULE_H

void push_transaction(const char *type, const char *name, const char *blood_group, int units);
void view_last_transactions(int count);
void undo_last_transaction();

#endif
