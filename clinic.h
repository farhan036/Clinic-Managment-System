#ifndef CLINIC_H
#define CLINIC_H
typedef struct nod
{
int id,age,slot;
int gender;
char name [50];
struct nod *next;
}node;
void add_new_patient(node **head);
void print_patients(node *head);
void edit_information(node *head);
void cancel(node *head);
void reserve_slot(node *head);






#endif // CLINIC_H
