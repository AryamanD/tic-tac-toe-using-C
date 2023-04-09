#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int evaluate(char(*p)[3],int j,char symbol)
{
    int evalflag=0,position1,position2,position3;
    for(int i=0;i<3&&evalflag==0;i++)
    {
        if(p[i][0]==p[i][1]&&p[i][0]==p[i][2]&&p[i][0]!=' ')
        {
            evalflag=1;
            position1=i*3+1;
            position2=position1+1;
            position3=position1+2;
        }
    }
    for(int i=0;i<3&&evalflag==0;i++)
    {
        if(p[0][i]==p[1][i]&&p[0][i]==p[2][i]&&p[0][i]!=' ')
        {
            evalflag=1;  
            position1=i+1;
            position2=position1+3;
            position3=position1+6;
        }
    }
    if(p[0][0]==p[1][1]&&p[0][0]==p[2][2]&&p[0][0]!=' '&&evalflag==0)
    {
        evalflag=1;   
        position1=1;
        position2=5;
        position3=9;  
    }
    if(p[0][2]==p[1][1]&&p[0][2]==p[2][0]&&p[0][2]!=' '&&evalflag==0)
    {
        evalflag=1;
        position1=3;
        position2=5;
        position3=7;
    }
    if(evalflag==1)
    {
        printf("\nPlayer %d has successfully created a row of %cs at positions:%d,%d and %d",j%2+1,symbol,position1,position2,position3);
        printf("\nPlayer %d has won! Congratulations!!",j%2+1);
        printf("\nPlayer %d, better luck next time!",++j%2+1);
        return 1;
    }
    return 0;
}
void Gameplay()
{
    printf("\n\t     TIC-TAC-TOE\n");
    printf("\nPlayer 1 is assigned symbol X and plays first");
    printf("\nPlayer 2 is assigned symbol O and plays second");
    printf("\n\nEnjoy!\n\n");
    char position[50],symbol;
    int b[9],integer;
    char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '},*ptr;
    int winflag=0;
    for(int i=-1;i<9;i++)
    {
        if(i!=-1)
        {
            printf("\nPlayer %d, Enter your position:",i%2+1);
            scanf("%s",position);
            if(position[0]<48||position[0]>57||position[1]!='\0')
            {
                printf("\nPlease enter a position from 1 to 9!\n");
                i--;
                continue;
            }
            if(position[0]==48)
            {
                winflag=2;
                break;
            }
            int k=0;
            int flag=0;
            while(k<i)
            {
                if(position[0]-48==b[k])
                {
                    printf("\nPosition already taken!Reenter your position!\n");
                    flag=1;
                }
                k++;
            }
            if(flag==1)
            {
                i--;
                continue;
            }
            b[i]=position[0]-48;
            ptr=&a[0][0];
            ptr=ptr+((position[0]-48)-1);
            if(i%2==0)
            {
                symbol='X';
                *ptr='X';
            }
            else
            {
                symbol='O';
                *ptr='O';
            }
            system("cls");
            printf("\n\t     TIC-TAC-TOE\n");
        }
        printf("---------------------------------------");
        printf("\n  Board:\t\tPositions:\n\n");
        for(int i=0,num=1;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j<2)
                {
                    printf("%c | ",a[i][j]);
                }
                else
                {
                    printf("%c",a[i][j]);
                }
            }
            printf("\t\t");
            for(int j=0;j<3;j++)
            {
                if(j<2)
                {
                    printf("%d | ",num++);
                }
                else
                {
                    printf("%d",num++);
                }
            }
            printf("\n");
            if(i<2)
            {
                printf("---------\t\t---------\n");
            }
        }
        printf("\n\nEnter 0 to Quit Game\n");
        printf("---------------------------------------\n\n");
        if(i>4)
        if(evaluate(a,i,symbol)==1)
        {
            winflag=1;
            break;
        }
    }
    if(winflag==2)
    {
        return;
    }
    if(winflag==0)
    {
        printf("\n\nThe game ended in a tie!");
    }
    int check=0;
    char choice[50];
    do
    {
        if(check!=0)
        {
            printf("\nPlease enter choice 1 or 2!");
        }
        printf("\n\n1) Play again!");
        printf("\n2) Return to Menu");
        printf("\nEnter your choice:");
        scanf("%s",choice);
        check=1;
    }
    while(choice[0]<49||choice[0]>50||choice[1]!='\0');
    if(choice[0]==49)
    {
        system("cls");
        Gameplay();
    }
    else if(choice[0]==50)
    {
        return;
    }
}
void Instructions()
{
    printf("\t\t     INSTRUCTIONS FOR TIC-TAC-TOE\n\n--------------------------------------------------------------------------\n1.The game is played on a grid that's 3 x 3 squares.\n  During the gameplay the Playing Board is placed on the left side.\n\n2.It is a two player game i.e, you must bring along \n  someone to play this game with you.\n\n3.You must decide amongst your playmate who is Player 1 \n  and who is Player 2. Player 1 is assigned symbol 'X' and starts the game \n  and Player 2 is assigned symbol 'O'.\n\n4.Both players are supposed to enter their symbols \n  turn by turn on the board by specifying the position number \n  of the space they want to fill. The position numbers for the corresponding \n  spaces are given in the board on the right side.\n\n5.The first player to get 3 of his/her symbols in a row \n  (up, down, across, or diagonally) is the winner and the game is over.\n\n6.When all 9 squares are full without a player having 3 symbols in a row, \n  the game ends in a tie.\n");
    printf("--------------------------------------------------------------------------");
    printf("\n\n-----------------------------------");
    printf("\nPRESS ANY KEY TO RETURN TO THE MENU");
    printf("\n-----------------------------------\n");
    getch();
}
void Facts()
{
    printf("\n\t           \t\tTIC-TAC-TOE");
    printf("\n\n--------------------------------------------------------------------------");
    printf("\nFUN FACTS ABOUT TIC-TAC-TOE:");
    printf("\n\n1.Most people have played this game in their school days \n  as a common passtime. Some Adults find it a way to kill time too!");
    printf("\n\n2.This game has many different names in different parts \n  of the world! It is known as Tic-Tac-Toe in American English,\n  noughts and crosses in British English, Xs and Os,\n  and zero kaata in Indian English.");
    printf("\n\n3.If 2 experienced players play the game,then the game will \n  always draw!");
    printf("\n\n4.There exist many different variations of the game today,\n  in different parts of the world.To name a few, Treble-cross,\n  Quantum Tic-Tac-Toe, Wild Tic-Tac-Toe, Quixo, \n  Notakto, 3D Tic-tac-toe.");
    printf("\n\n--------------------------------------------------------------------------");
    printf("\n\n-----------------------------------");
    printf("\nPRESS ANY KEY TO RETURN TO THE MENU");
    printf("\n-----------------------------------\n");
    getch();
}
void Credits()
{
    printf("\n\t    TIC-TAC-TOE");
    printf("\n\n-----------------------------------");
    printf("\nDevelopers:\n");
    printf("\n1.Aryaman Datta\tUSN - 1AT20CS011");
    printf("\n2.Joel Pinto\tUSN - 1AT20CS122");
    printf("\n3.Hajira Zuha\tUSN - 1AT20CS036");
    printf("\n4.Mahima V\tUSN - 1AT20CS052");
    printf("\n-----------------------------------");
    printf("\n\nIII Semester, Section CSE1");
    printf("\nYear - 2022");
    printf("\n\n-----------------------------------");
    printf("\nPRESS ANY KEY TO RETURN TO THE MENU");
    printf("\n-----------------------------------\n");
    getch();
}
void Exit()
{
    exit(0);
}
struct MENU
{
    char *name;
    void (*func)();
}menu[]={
            {"\n1) Play",Gameplay},
            {"\n2) Instructions",Instructions},
            {"\n3) Fun facts",Facts},
            {"\n4) Credits",Credits},
            {"\n5) Exit",Exit}
        };
void main()
{
    char choice[50];
    for(;;)
    {
        system("cls");
        printf("\n       WELCOME");
        printf("\n         TO");
        printf("\n     TIC-TAC-TOE");
        printf("\n--------------------");
        printf("\nMenu:");
        for(int i=0;i<5;i++)
        {
            printf("%s",menu[i].name);
        }
        printf("\n--------------------");
        printf("\nEnter your choice:");
        scanf("%s",choice);
        if(choice[0]<49||choice[0]>53||choice[1]!='\0')
        {
            printf("\nPlease enter a choice from 1 to 4!\n");
            getch();
            continue;
        }
        system("cls");
        menu[choice[0]-48-1].func();
    }        
}