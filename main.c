#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <errno.h>
#include "conio2.h"
#include "mtb.h"

int main(){
    int result=mkdir("c:\\Movie Ticket Booking");
    if(result!=0 && errno!=17){
        printf("Sorry! Application can not run");
        printf("\nError code:%d,",errno);
        perror("Reason");
        return 1;
    }
    add_questions();
    set_master_admin();
    create_user("admin");
    int choice,resp,delete_account;
    user *ur;
    while(1){
        choice=enter_login_choice();
        if(choice==0)
            break;
        switch(choice){
            case 1:
                ur=login("admin");
                if(ur==NULL)
                    break;
                while(1){
                    choice=enter_choice(ur);
                    if(choice==0)
                        break;
                    switch(choice){
                        case 1:
                            add_theater();
                            break;
                        case 2:
                            show_theater();
                            break;
                        case 3:
                            resp=delete_theater();
                            if(resp==1){
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Theater Deleted Successfully",25,LIGHTGREEN);
                                getch();
                            }
                            break;
                        case 4:
                            add_movie();
                            break;
                        case 5:
                            show_movie();
                            break;
                        case 6:
                            resp=delete_movie();
                            if(resp==1){
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Movie Deleted Successfully",25,LIGHTGREEN);
                                getch();
                            }
                            break;
                        case 7:
                            change_contact_details(ur);
                            break;
                        case 8:
                            change_security_question(ur);
                            break;
                        case 9:
                            change_password(ur);
                            break;
                        case 10:
                            show_my_profile(ur);
                            break;
                        default:
                            print_char(' ',80,25,BLACK);
                            print_title_in_middle("invalid Choice! Try Again.",25,RED);
                            getch();
                            print_char(' ',80,25,BLACK);
                    }
                }
                if(choice==0)
                    break;
            case 2:
                ur=login("user");
                if(ur==NULL)
                    break;
                while(1){
                    choice=enter_choice(ur);
                    if(choice==0)
                        break;
                    switch(choice){
                        case 1:
                            show_movie();
                            break;
                        case 2:
                            booking(ur);
                            break;
                        case 3:
                            show_bookings_of_user(ur);
                            break;
                        case 4:
                            resp=cancel_bookings_of_user(ur);
                            if(resp==1){
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Booking Cancelled Successsfully",25,LIGHTGREEN);
                                getch();
                            }
                            break;
                        case 5:
                            change_contact_details(ur);
                            break;
                        case 6:
                            change_security_question(ur);
                            break;
                        case 7:
                            change_password(ur);
                            break;
                        case 8:
                            show_my_profile(ur);
                            break;
                        case 9:
                            delete_account=delete_my_account(ur);
                            if(delete_account==1){
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Account Deleted Successfully",25,LIGHTGREEN);
                                getch();
                            }
                            break;
                        default:
                            print_char(' ',80,25,BLACK);
                            print_title_in_middle("invalid Choice! Try Again.",25,RED);
                            getch();
                            print_char(' ',80,25,BLACK);
                    }
                   if(delete_account==1)
                       break;
                }
                if(delete_account==1)
                    break;
                if(choice==0)
                    break;
            case 3:
                create_user("user");
                break;
            default:
                print_char(' ',80,25,BLACK);
                print_title_in_middle("invalid Choice! Try Again.",25,RED);
                getch();
                print_char(' ',80,25,BLACK);
        }
    }
    return 0;
}
