#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//Saya belum mau mulai dari mana jadi, saya coba bikin gambaran yang sederhana

typedef struct animeDetails
{
    char animeTitle[50];
    int episodes;
    int animeScore;

    struct animeDetails *next;
} animeDetails;

typedef struct mangaDetails
{
    char mangaTitle[50];
    int chapters;
    int mangaScore;

    struct mangaDetails *next;
} mangaDetails;

int main()
{
    int choice;

    do
    {
        printf("\n==========Menu==========\n");
        printf("1. Show anime list\n");
        printf("2. Show manga list\n");
        printf("(0) Exit\n\n");

        printf("Choice: ");
        scanf("%d", &choice);
    } while(choice != 0);

    return 0;
}
