

#include "checking_input.h"




int main()
{
    unsigned short int choice;

    while(1)
    {

        int i=0;

        for(i=0 ; i<100 ; i++)
            printf("%c",240);
        printf("\n");

        for(i=0 ; i<35 ; i++)
        printf("%c",177);

        printf("\tMain Manu \t");

        for(i=0 ; i<35 ; i++)
            printf("%c",177);
        printf("\n");

        for(i=0 ; i<100 ; i++)
            printf("%c",220);
        printf("\n\n");


        printf("1- Add new employee.\n"
               "2- load new employee.\n"
               "3- delete employee.\n"
               "4- search employee.\n"
               "5- save.\n"
               "6- exit.\n\n"
               "----> "
              );

        /* hi for short int */
        scanf("%hi", &choice);
        fflush(stdin);
        switch (choice)
        {
            case 1:
            {
                add_empolyee();
                break;
            }

            case 2:
            {
                load();
                printf("--------------------------\n");
                printf("Done loading \n");
                printf("--------------------------\n\n");
                break;
            }

            case 3:
            {
                delete_empolyee();
                check_saving();
                break;
            }

            case 4:
            {
                search_employee();;
                break;
            }


            case 5:
            {
                save();
                break;
            }

            case 6:
            {
                check_saving();
                exit(0);
        }

        default:
            break;
        }
    }

    return 0;

}


/***********************************************************************************************/
int check_name(char* name)
{
    int i=0;
    while( *(name+i) != '\0')
    {
        if( ( *(name+i) >= 'A' && *(name+i) <= 'Z' ) || ( *(name+i) >= 'a' && *(name+i) <= 'z'  )  || *(name+i) == ' ')
        {
            i++;
            continue;
        }

        printf("*****\n");
        printf("\awrong name.\n");
        printf("*****\n");
        return 1;
        break;
    }
    return 0;
}

/*************************************************************************************************/

int check_phone(char* phone)
{
    int falg = VALID_INPUT;
    int cnt = 0;

    while( cnt < 11 )
    {

        if( (phone[cnt] >= '0') && (phone[cnt] <= '9')  )
        {
            cnt++;
        }

        else
        {
            printf("*****\n");
            printf("\awrong phone number.\n");
            printf("*****\n");
            falg = INVALID_INPUT;
            break;
        }

    }

    return falg;
}

/*************************************************************************************************/

int check_mail(char* mail)
{
    int i=0;
    int x=0;
    int y=0;
    while( *(mail+i) != '\0')
    {
        if( !( (*(mail+i) >= 'A' && *(mail+i) <= 'Z') || (*(mail+i) >= 'a' && *(mail+i) <= 'z')  || (*(mail+i) >= '0' && *(mail+i) <= '9') ||*(mail+i) == '.' || *(mail+i) == '@') )
        {
            printf("*****\n");
            printf("\awrong mail.\n");
            printf("*****\n");
            return 1;
        }

        if((*(mail+0) >= '0' && *(mail+0) <= '9'))
        {
            printf("*****\n");
            printf("\awrong mail.\n");
            printf("*****\n");
            return 1;
        }

        if( *(mail+i) == '.')
            x=i;
        if( *(mail+i) == '@')
            y=i;
        //  printf("x= %d\ty= %d\n",x,y);

        i++;
    }
    if(x-y <= 1 || x==0 || y==0 )
    {
        printf("*****\n");
        printf("\awrong mail.\n");
        printf("*****\n");
        return 1;
    }
    return 0;
}


/*************************************************************************************************/

int check_birth_date(char* birth_date_orgin)
{
    char birth_date[50];
    strcpy(birth_date , birth_date_orgin);


    int i=0;
    int j=1;
    int day=0;
    int month=0;
    int year=0;


    char** arg;
    arg = (char**)malloc(5*sizeof(char*));

    while( *(birth_date+i) != '\0')
    {
        if( (*(birth_date+i) >= '0' && *(birth_date+i) <= '9') || *(birth_date+i) == '/' )
        {
            i++;
            continue;
        }

        printf("*****\n");
        printf("\awrong birth_date format.\n");
        printf("*****\n");
        return 1;
        break;
    }

    i=0;
    j=1;
    *arg = birth_date;
    while( *(birth_date+i) != '\0')
    {
        if(*(birth_date+i) == '/')
        {
            *(birth_date+i) = '\0';
            arg[j] = birth_date+i+1;
            j++;
        }
        i++;
    }
    arg[j] = '\0';
//   printf("%s\t%s\t%s\n",arg[0],arg[1],arg[2]);


    day = atoi(arg[0]);
    month = atoi(arg[1]);
    year = atoi(arg[2]);

    // printf("%d\t%d\t%d\n",day,month,year);

    if(year < 1980 || year > 2000)
    {
        printf("*****\n");
        printf("\ayear out of range, Range is 1980 : 2000 \n");
        printf("*****\n");
        free(arg[0]);
        free(arg[1]);
        free(arg[2]);
        return 1;
    }

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if(day > 31)
        {
            printf("*****\n");
            printf("\aday out of range it should be less than 31.\n");
            printf("*****\n");
            free(arg[0]);
            free(arg[1]);
            free(arg[2]);
            return 1;
        }
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if(day >= 30)
        {
            printf("*****\n");
            printf("\aday out of range it should be less than 30.\n");
            printf("*****\n");
            free(arg[0]);
            free(arg[1]);
            free(arg[2]);
            return 1;
        }
        break;
    }
    case 2:
    {
        if (((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0))
        {
            if(day >= 29)
            {
                printf("*****\n");
                printf("\aday out of range it should be less than 29.\n");
                printf("*****\n");
                free(arg[0]);
                free(arg[1]);
                free(arg[2]);
                return 1;
            }
            break;
        }

        else
        {
            if(day >= 28)
            {
                printf("*****\n");
                printf("\aday out of range it should be less than 28. \n");
                printf("*****\n");
                free(arg[0]);
                free(arg[1]);
                free(arg[2]);
                return 1;
            }
            break;
        }
    }
    default:
    {
        printf("*****\n");
        printf("\amonth out of range.\n");
        printf("*****\n");
        free(arg[0]);
        free(arg[1]);
        free(arg[2]);
        return 1;
        break;
    }

    }

    free(arg[0]);
    free(arg[1]);
    free(arg[2]);
    return 0;

}

/*************************************************************************************************/
int check_job(char* job)
{
    FILE *JobTitle_fptr;
    char* Job_title;

    Job_title = (char*)malloc(25*sizeof(char));
    JobTitle_fptr = fopen("Job_titles.dat","r");

    while( (fgets(Job_title , 50*sizeof(char) , JobTitle_fptr)) != '\0')
    {
        clear_newline(Job_title);
        if(strcmp(Job_title,job) == 0)
        {
            fclose(JobTitle_fptr);
            free(Job_title);
            return 0;
            break;
        }

    }
    printf("*****\n");
    printf("\ajob title is not one of company's jobs please check job_titles' file.\n");
    printf("*****\n");
    fclose(JobTitle_fptr);
    free(Job_title);
    return 1;

}

/*************************************************************************************************/

void clear_newline(char* arr)
{
    int i=0;
    while(arr[i] != '\n')
        i++;
    arr[i] = '\0';
}

/*************************************************************************************************/




/*************************************************************************************************/

void check_saving(void)
{
    if(exit_flag == 1)
    {
        char c;
        printf("Do you want to save (Y / N) ?\n--> ");
        scanf("%c", &c);

        if(c == 'y' || c == 'Y')
        {
            save();
        }

        else //if(c == 'n' || c == 'n')
        {
            remove("temp.dat");
            remove("data_base_temp.dat");
        }
    }
    else
    {
        printf("There is no temporary data to save.\n");
    }

}

/*************************************************************************************************/

void load(void)
{
    char* line;
    char** arg;
    FILE *fptr;

    line = (char*)malloc(250*sizeof(char));
    arg = (char**)malloc(10*sizeof(char*));
    fptr = fopen("data_base.dat","r");


    if(fptr == '\0')
        printf("can't open file from load function.\n");



    int i=0;
    int j=0;
    int counter=0;
    int employee_number=1;


    *(arg+j) = line;

    while(!feof(fptr))
    {

        line[counter] = getc(fptr);

        if(line[counter] == '\n')
        {
            line[counter] = '\0';

            printf("\nemployee_number: %d\n",employee_number);
            /** for debugging */
           // printf("\nemployee_number: %d \n%s and counter is %d\n\n",employee_number, line, counter);

            employee_number++;
            counter = -1;

            i=0;
            while(*(line+i) != '\0')
            {
                if( line[i] == ',')
                {
                    line[i] = '\0';
                    j++;
                    arg[j] = line+i+1;
                    arg[j+1] = '\0';
                }
                i++;
            }


            /** for debugging */
//            int deb=0;
//            while(arg[deb] != '\0')
//            {
//                printf("arg[%d] is %s"   ,arg[deb] );
//                deb++;
//                getchar();
//                fflush(stdin);
//            }


                printf("-----------------------------------------------\n"
                        "--> name .............. %s \n--> phone ............. %s \n--> mail .............. %s\
                         \n--> birth_date ........ %s \n--> job ............... %s"
                        "\n-------------------------------------------------------------------------------------------------\n"\
                        ,arg[0], arg[1] , arg[2], arg[3], arg[4]);


                printf("press any key for next employee..... ");
                getchar();
                fflush(stdin);

            j=0;

        }
        counter++;
    }


    free(line);
    free(arg);
    fclose(fptr);

}

/*************************************************************************************************/

void search_employee(void)
{
    char* line ,*employee_name;
    char** arg;
    FILE *fptr;

    line = (char*)malloc(250*sizeof(char));
    employee_name = (char*)malloc(50*sizeof(char));
    arg = (char**)malloc(10*sizeof(char*));



    printf("please enter employee name: ");
    fgets(employee_name , 50*sizeof(char) , stdin);
    fflush(stdin);
    clear_newline(employee_name);

    fptr = fopen("data_base.txt","r");
    if(fptr == '\0')
        printf("can't open file from load function.\n");



    int i=0;
    int j=0;
    int counter=0;
    int employee_number=1;


    *(arg+j) = line;
    char found_flag=0;

    while(!feof(fptr))
    {

        line[counter] = getc(fptr);

        if(line[counter] == '\n')
        {
            line[counter] = '\0';

            /** for debugging */
           // printf("\nemployee_number: %d \n%s and counter is %d\n\n",employee_number, line, counter);

            employee_number++;
            counter = -1;

            i=0;
            while(*(line+i) != '\0')
            {
                if( line[i] == ',')
                {
                    line[i] = '\0';
                    j++;
                    arg[j] = line+i+1;
                    arg[j+1] = '\0';
                }
                i++;
            }


            /** for debugging */
//            printf("input %s and searching %s\n", employee_name ,arg[0]);

                if (strcmp(employee_name  , arg[0]) == 0)
                {
                     printf("-----------------------------------------------\n"
                        "--> name .............. %s \n--> phone ............. %s \n--> mail .............. %s\
                         \n--> birth_date ........ %s \n--> job ............... %s"
                        "\n-------------------------------------------------------------------------------------------------\n"\
                        ,arg[0], arg[1] , arg[2], arg[3], arg[4]);
                        found_flag = 1;
                        break;
                }

                else
                {
                    found_flag = 0;
                }

            j=0;

        }
        counter++;
    }


    if(found_flag == 0)
        printf("can't find employee !\n");

    free(line);
    free(arg);
    free(employee_name);
    fclose(fptr);

}


/*************************************************************************************************/

void delete_empolyee(void)
{
    exit_flag = 1;
    delete_flag = 1;
    char* line ,*employee_name;
    char** arg;
    FILE *fptr , *fptr_2;

    line = (char*)malloc(250*sizeof(char));
    employee_name = (char*)malloc(50*sizeof(char));
    arg = (char**)malloc(10*sizeof(char*));



    printf("please enter employee name: ");
    fgets(employee_name , 50*sizeof(char) , stdin);
    fflush(stdin);
    clear_newline(employee_name);

    fptr = fopen("data_base.dat","r");
    remove("data_base_temp.dat");
    fptr_2 = fopen("data_base_temp.dat","a");

    if(fptr == '\0' || fptr_2 == '\0')
        printf("can't open file from load function.\n");



    int i=0;
    int j=0;
    int counter=0;
    int employee_number=1;


    *(arg+j) = line;

    while(!feof(fptr))
    {

        line[counter] = getc(fptr);

        if(line[counter] == '\n')
        {
            line[counter] = '\0';

            /** for debugging */
           // printf("\nemployee_number: %d \n%s and counter is %d\n\n",employee_number, line, counter);

            employee_number++;
            counter = -1;

            i=0;
            while(*(line+i) != '\0')
            {
                if( line[i] == ',')
                {
                    line[i] = '\0';
                    j++;
                    arg[j] = line+i+1;
                    arg[j+1] = '\0';
                }
                i++;
            }


            /** for debugging */
//            printf("input %s and searching %s\n", employee_name ,arg[0]);

                if (strcmp(employee_name  , arg[0]) != 0)
                {

                    fprintf(fptr_2,"%s,%s,%s,%s,%s\n", arg[0],arg[1],arg[2],arg[3],arg[4]);
                }

            j=0;

        }
        counter++;
    }

    free(line);
    free(arg);
    free(employee_name);
    fclose(fptr);
    fclose(fptr_2);

}

/*************************************************************************************************/

void add_empolyee(void)
{
    exit_flag = 1;
    add_flag = 1;
    empolyee_TypeDef new_employee;


    while(1)
    {

        printf("please enter new employee name (only 15 chars) \n--> ");
        fgets(new_employee.name, 50*sizeof(char), stdin);
        fflush(stdin);
        clear_newline(new_employee.name);

        if ( check_name(new_employee.name) == VALID_INPUT )
            break;
    }

    while(1)
    {
        printf("please enter new employee phone (only 11 digit) \n--> ");
        fgets(new_employee.phone, 50*sizeof(char), stdin);
        fflush(stdin);
        clear_newline(new_employee.phone);

        if ( check_phone(new_employee.phone) == VALID_INPUT )
            break;
    }

    while(1)
    {
        printf("please enter new employee mail \n--> ");
        fgets(new_employee.mail, 50*sizeof(char), stdin);
        fflush(stdin);
        clear_newline(new_employee.mail);

        if ( check_mail(new_employee.mail) == VALID_INPUT )
            break;
    }

    while(1)
    {

        printf("please enter new employee birth_date (DD/MM/YYYY) \n--> ");
        fgets(new_employee.birth_date, 50*sizeof(char), stdin);
        fflush(stdin);
        clear_newline(new_employee.birth_date);

        if ( check_birth_date(new_employee.birth_date) == VALID_INPUT )
            break;
    }


    while(1)
    {
        printf("please enter new employee job (only 20 chars) \n--> ");
        fgets(new_employee.job, 50*sizeof(char), stdin);
        fflush(stdin);
        clear_newline(new_employee.job);

        if ( check_job(new_employee.job) == VALID_INPUT )
            break;
    }

    printf("\n-----------------------------------------------"
    "\ndata to add.");
    printf("\n-----------------------------------------------\n"
    "--> name .............. %s \n--> phone ............. %s \n--> mail .............. %s\
                         \n--> birth_date ........ %s \n--> job ............... %s"
    "\n-------------------------------------------------------------------------------------------------\n"\
    ,new_employee.name, new_employee.phone\
    , new_employee.mail, new_employee.birth_date, new_employee.job);



    save_temp(new_employee);
}

/*************************************************************************************************/

void save_temp(empolyee_TypeDef  empolyee)
{
    add_flag = 1;

    FILE* fptr;
    fptr = fopen("temp.dat","a");

    if(fptr == '\0')
        printf("can't open file from save_temp function.\n");

    fseek(fptr,0L,SEEK_END);
    fprintf(fptr,"%s,%s,%s,%s,%s\n",empolyee.name,empolyee.phone,empolyee.mail,empolyee.birth_date,empolyee.job);
    fclose(fptr);
}

/*************************************************************************************************/

void save(void)
{
    exit_flag = 0;
    FILE *fptr,*fptr_2;
    char* temp;

    temp = (char*)malloc(250*sizeof(char));

    if(delete_flag == 1)
    {

        delete_flag = 0;

        fptr = fopen("data_base.dat","w");
        fptr_2 = fopen("data_base_temp.dat","r");

        while( (fgets(temp,250*sizeof(char),fptr_2)) != '\0')
            fprintf(fptr,"%s",temp);

        fclose(fptr);
        fclose(fptr_2);
    }
    remove("data_base_temp.dat");


    if(add_flag == 1)
    {
        add_flag = 0;

        fptr = fopen("temp.dat","r");
        fptr_2 = fopen("data_base.dat","a");

        fseek(fptr,0L,SEEK_SET);
        fseek(fptr_2,0L,SEEK_END);

        if(fptr == '\0' || fptr_2 == '\0')
            printf("can't open file from save function.\n");


        while( (fgets(temp,250*sizeof(char),fptr)) != '\0')
            fprintf(fptr_2,"%s",temp);

        fclose(fptr);
        fclose(fptr_2);

    }
    remove("temp.dat");
    free(temp);
    printf("data has been saved.\n");
}





