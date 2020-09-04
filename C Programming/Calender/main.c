#include <stdio.h>
#include <stdlib.h>

int shift(int);


int main()
{

    int i=0;
    char* day[7] = {"We","Th","Fr","Sa","Su","Mo","Tu"};
    char* month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int k=0;
    int standar_year=1919;
    int month_=0;
    int year_=0;
    int shift_year=0;
    int shift_leap_year=0;
    int final_shift=0;
    int temp=0;
    int error=0;

    /*  **************************************************************************************  */

//    printf("please enter how many times you want to shift :- ");
//    scanf("%d",&j);
//    j = j%7;

//    printf("j = %d\n",j);

    /*  **************************************************************************************  */

    printf("***************");
    while(1)
    {

        printf("\n--> please enter month and year with space between them (month year) :- ");
        scanf("%d %d",&month_,&year_);
        fflush(stdin);
        printf("========================\n\n");



        if(year_ < 1919)
        {
            printf("\aplease choose year > 1919 !\n");
            error = 1;
            continue;
        }

        if(month_ > 12)
        {
            printf("please enter month < 12");
            error = 1;
            continue;
        }



        if(error == 0)
        {
            shift_year = year_ - standar_year;
            shift_leap_year = (year_-1920)/4;
            if(year_%4 != 0)
                shift_leap_year++;

            final_shift = (shift_leap_year+shift_year);



            while(1)
            {

                temp = 0;
                for(i=0 ; i<month_-1 ; i++)
                    temp += mon[i];

                //    printf("temp = %d\n",temp);
                final_shift = (shift_leap_year+shift_year);
                final_shift = (final_shift + temp)%7;
                //    final_shift %= 7;

                printf("\t\t\t\t%s / %d",*(month+month_-1),year_);
                printf("\t\n--------------------------------------------------------------------------\n\n\t");
                for(i=0 ; i<7 ; i++)
                {
                    printf("%s\t",*(day + i));
                }

                printf("\n\n\t");
                k = shift(final_shift);
                //    printf("%d\n",k);
                if (month_ == 2)
                {
                    if(year_%4 == 0)
                        mon[month_-1]++;
                }
                for(i=1 ; i<=mon[month_-1] ; i++)
                {


                    printf("%d\t",i);
                    if((i+k-1)%7 == 0)
                        printf("\n\n\t");
                }
                printf("\t\n---------------------------------------------------------------------------\n");

                fflush(stdin);
                char c;
                printf("\tpress n for next or p for previous.");
                printf("if you want to insert new date press a.\n");
                printf("\t\t\tany other key you will exit .... \n");
                printf("=============================================\n");
                scanf("%c",&c);

                switch (c)
                {
                case 'n':
                {
                    month_++;
                    if(month_ > 12)
                    {
                        month_ = 1;
                        year_++;
                    }

                    continue;
                }
                case 'p':
                {
                    month_--;
                    if(month_ < 1)
                    {
                        month_ = 12;
                        year_--;
                    }
                    continue;
                }
                case 'a':
                {
                    system("CLS");
                    break;
                }
                default:
                    exit(0);
                }
                if(c == 'a')
                    break;

            }
        }
    }
}


int shift(int j)
{
    int k=0;
    while(k<=j)
    {
        printf("\t");
        if(k%7 == 0)
            printf("\n\t");
        k++;
    }
    return k;
}
