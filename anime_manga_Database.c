#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//Saya belum mau mulai dari mana jadi, saya coba bikin gambaran yang sederhana

typedef struct animeDetails
{
    char animeTitle[50];
    int episodes;
    float animeScore;

    struct animeDetails *next;
} animeDetails;

typedef struct mangaDetails
{
    char mangaTitle[50];
    int volumes;
    int chapters;
    float mangaScore;

    struct mangaDetails *next;
} mangaDetails;

void showAnime()
{
    animeDetails animeGet[20];
    int listCount, itemCount = 0;

    FILE *fileAnime = fopen("animeList.txt", "r");

    while(!feof(fileAnime))
	{
		animeDetails copyAnime;

		fscanf(fileAnime, "%[^#]#%d#%f\n", copyAnime.animeTitle, &copyAnime.episodes, &copyAnime.animeScore);
		animeGet[itemCount] = copyAnime;
		itemCount++;
	}

	printf("\n-------------------------------------------------\n");
	printf("| No. | Title \t \t| Episodes | Rating |\n");
	printf("-------------------------------------------------\n");

	for(listCount = 0;listCount < itemCount;listCount++)
	{
		printf("| %d. | %s | %d | %.2f |\n", listCount + 1, animeGet[listCount].animeTitle, animeGet[listCount].episodes, animeGet[listCount].animeScore);
	}

	fclose(fileAnime);
}

void showManga()
{
	mangaDetails mangaGet[20];
	int listCount, itemCount = 0;

	FILE *fileManga = fopen("mangaList.txt", "r");

	while(!feof(fileManga))
	{
		mangaDetails copyManga;

		fscanf(fileManga, "%[^#]#%d#%d#%f\n", copyManga.mangaTitle, &copyManga.volumes, &copyManga.chapters, &copyManga.mangaScore);
		mangaGet[itemCount] = copyManga;
		itemCount++;
	}

	printf("\n-------------------------------------------------------\n");
    	printf("| No. | Title \t \t| Volumes | Chapters | Score |\n");
    	printf("-------------------------------------------------------\n");

	for(listCount = 0;listCount < itemCount;listCount)
	{
		printf("| %d. | %s | %d | %d | %.2f |\n", listCount + 1, mangaGet[listCount].mangaTitle, mangaGet[listCount].volumes, mangaGet[listCount].chapters, mangaGet[listCount].mangaScore);
	}

	fclose(fileManga);
}

void favoriteAnime()
{
	animeDetails animeNew;

	printf("Title	: "); scanf(" %[^\n]", animeNew.animeTitle);
	printf("Episodes: "); scanf("%d", &animeNew.episodes);
	printf("Score	: "); scanf("%f", &animeNew.animeScore);

	printf("\nWant to save your favorite?\n");
	printf("1. Yes\n");
	printf("2. No\n");

	int decision;
	printf("Choice: ");
	scanf("%d", &decision);

	if(decision == 1) return;
	else if(desicion == 2) return;
	else return;
}

void favoriteManga()
{
	mangaDetails mangaNew;

	printf("Title	: "); scanf(" %[^\n]", mangaNew.mangaTitle);
	printf("Volumes	: "); scanf("%d", &mangaNew.volumes);
	printf("Chapter	: "); scanf("%d", &mangaNew.chapters);
	printf("Score	: "); scanf("%f", &mangaNew.mangaScore);

	printf("\nWant to save your favorite?\n");
	printf("1. Yes\n");
	printf("2. No\n");

	int decision;
	printf("Choice: ");
	scanf("%d", &decision);

	if(decision == 1) return;
	else if(decision == 2) return;
	else return;
}

int main()
{
	animeDetails sendAnime;
	mangaDetails sendManga;
    int choice;

    do
    {
        printf("\n==========Menu==========\n");
        printf("1. Show anime list\n");
        printf("2. Show manga list\n");
	printf("3. Insert favorite anime\n");
	printf("4. Insert favorite manga\n");
        printf("(0) Exit\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

		switch(choice)
		{
			case 1: showAnime(); break;
			case 2: showManga(); break;
			case 3: favoriteAnime(); break;
			case 4: favoriteManga(); break;
			case 0: printf("Exiting Program...\n"); break;
			default: printf("Option not available\n");
		}
    } while(choice != 0);

    return 0;
}
