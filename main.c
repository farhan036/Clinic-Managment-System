#include <stdio.h>
#include <stdlib.h>
#include"clinic.h"

int main()
{
    int mode=-1;
    int adminpass=1234;
    int pass=-1;
    int tries=0;
    node *patient1=NULL;
    int UserChoice = 0;
    printf("-> Hello to Clinic Management System \n");
    printf("Admin mode -> 1\nUser mode -> 0\n");
    printf("Enter mode : ");
    scanf("%i",&mode);
    while(mode<0||mode>1)
    {
        printf("Enter mode 0 or 1 : ");
        scanf("%i",&mode);
    }
    if(mode==1)
    {
        while(tries<3||pass!=adminpass)
        {
            printf("Enter password : ");
            scanf("%i",&pass);
            if(pass==adminpass)
            {
                printf("===============================\n");
                printf("Welcome Admin\n");
                while(1)
                {

                    printf("\n");
                    printf("===============================\n");
                    printf("-> 1) add_new_patient \n");
                    printf("-> 2) reserve_slot \n");
                    printf("-> 3) edit_information\n");
                    printf("-> 4) cancel reservation \n");
                    printf("-> 5) become user \n");
                    printf("-> 6) Quit from application \n");
                    printf("===============================\n");
                    printf("\n");
                    printf("UserChoice : ");
                    scanf("%i", &UserChoice);

                    switch(UserChoice)
                    {
                    case 1:
                        add_new_patient(&patient1);
                        break;
                    case 2:
                        reserve_slot(patient1);
                        break;
                    case 3:
                        edit_information(patient1);
                        break;
                    case 4:
                        cancel(patient1);
                        break;
                    case 5:
                        printf("user \n");
                        mode=0;
                        if(mode==0)
                        {
                            while(1)
                            {

                                printf("\n");
                                printf("===============================\n");
                                printf("-> 1) print patients \n");
                                printf("-> 2) Quit from application \n");
                                printf("===============================\n");
                                printf("\n");
                                printf("UserChoice : ");
                                scanf("%i", &UserChoice);

                                switch(UserChoice)
                                {
                                case 1:
                                    print_patients(patient1);
                                    break;
                                case 2:
                                    printf("Quit from application \n");
                                    exit(1);
                                    break;
                                default:
                                    printf("User Choice out of range !!\n");
                                    break;
                                }
                            }



                        }
                        break;
                    case 6:
                        printf("Quit from application \n");
                        exit(1);
                        break;
                    default:
                        printf("User Choice out of range !!\n");
                        break;
                    }
                }
            }
            else
            {
                printf("Password is not correct\n");
                tries++;
                if(tries==3)
                {
                    exit(1);
                }
            }
        }
    }



    return 0;
}
