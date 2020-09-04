

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define INVALID_INPUT   (1)
#define VALID_INPUT     (0)





/////////////////////////////////////////////////////
//
unsigned short int add_flag=0, exit_flag=0, delete_flag=0;


////////////////////////////////////////////////////

typedef struct
{
    char name[50];
    char phone[50];
    char mail[50];
    char birth_date[50];
    char job[50];

}empolyee_TypeDef;

////////////////////////////////////////////////////

int check_name(char* );
int check_phone(char* );
int check_mail(char* );
int check_birth_date(char* );
int check_job(char* );
void clear_newline(char* line);

void add_empolyee(void);
void load(void);
void delete_empolyee(void);
void search_employee(void);
void check_saving(void);
void save_temp(empolyee_TypeDef  empolyee);
void save(void);



