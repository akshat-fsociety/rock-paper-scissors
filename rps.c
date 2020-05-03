#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }
    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}
int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("Welcome to the Rock Paper Scissors\n");
   
    for (int i = 0; i < 3; i++)
    {
        // Take player input
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n");
        printf("Player's turn:\n ");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf(" -----------------\n");
        printf(" You choose: %c   \n", playerChar);
        printf(" -----------------\n");
        //computer generate
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n");
        printf("Computer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf(" --------------------\n");
        printf(" Computer choose: %c \n", compChar);
        printf(" --------------------\n");
        // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
            printf("Computer won\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
            printf("It's a draw. Both got 1 point!\n");
        }
        else
        {
            playerScore++;
            printf("You Got It!\n");
        }
        printf(" -------------\n");
        printf(" You: %d      \n", playerScore);
        printf(" Computer: %d \n", compScore);
        printf(" -------------\n");
        printf("===========================================================\n");
    }
    printf(" -----------------\n");
    printf("|   Final Score   |\n");
    printf(" -----------------\n");
    printf("|  You | Computer |\n");
    printf("|------|----------|\n");
    printf("|   %d  |    %d     |\n", playerScore, compScore);
    printf(" -----------------\n");
    // compare score
    if (playerScore > compScore)
    {
        printf(" -------------------\n");
        printf("| You Win the match |\n");
        printf(" -------------------\n");
    }
    else if (playerScore < compScore)
    {
        printf(" -----------------------\n");
        printf("| Computer Win the match |\n");
        printf(" ------------------------\n");
    }
    else
    {
        printf(" -------------\n");
        printf("| It's a draw |\n");
        printf(" -------------\n");
    }
    return 0;
}