#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song
{   
    char title[20];
    struct Song *lptr;
    struct Song *rptr;
};
struct Song *L = NULL,*R = NULL,*curr = NULL;

void addSong(char Title[])
{
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));

    strcpy(newSong->title,Title);

    if (R == NULL)
    {
        newSong->lptr = NULL;
        newSong->rptr = NULL;
        L = newSong;
        R = newSong;
        return;
    }
    newSong->rptr = NULL;
    newSong->lptr = R;
    R->rptr = newSong;
    R = newSong;

    curr = newSong;
}

void deleteSong(char Title[])
{
    struct Song *save = L;
    
    while (save != NULL)
    {
        if (strcmp(save->title,Title)==0)
        {
            if (L == R)
            {
                L = NULL;
                R = NULL;
            }else if (save == L)
            {
                L = L->rptr;
                L->lptr = NULL;
            }else if (save == R)
            {
                R = R->lptr;
                R->rptr = NULL;
                curr = R;
            }else{
                curr = save->rptr;
                save->lptr->rptr = save->rptr;
                save->rptr->lptr = save->lptr;
            }
            free(save);
        }
        save = save->rptr;
    }
}

void PlayNext()
{
    if (curr->rptr != NULL)
    {
        curr = curr->rptr;
        printf("%s is playing now on your playlist!\n",curr->title);
    }else{
        printf("Playlist does not have next song!\n");
    }
}

void ShowCurrent()
{
    if (curr != NULL)
    {
        printf("%s is playing now on your playlist!\n",curr->title);
    }else{
        printf("Playlist does not playing any song!\n");
    }
}

void PlayPrevious()
{
    if (curr->lptr != NULL)
    {
        curr = curr->lptr;
        printf("%s is playing now on your playlist!\n",curr->title);
    }else{
        printf("Playlist does not have previous song!\n");
    }
}

void Display()
{
    struct Song *save = L;

    if (L == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    while (save != NULL)
    {
        printf("%s\n",save->title);
        save = save->rptr;
    }
    printf("--------------------------------\n");
}

void main()
{
    int choice;
    char title[20];

    do
    {
        printf("1.Add a Song\n2.Delete a Song\n3.Show current playing song\n");
        printf("4.To play previous song\n5.To play next song\n6.Display playlist\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter title:");
            scanf(" %[^\n]",title);
            addSong(title);
            break;
        
        case 2:
            printf("Enter title to delete:");
            scanf(" %[^\n]",title);
            deleteSong(title);
            break;

        case 3:
            ShowCurrent();
            break;

        case 4:
            PlayPrevious();
            break;

        case 5:
            PlayNext();
            break;

        case 6:
            Display();
            break;

        default:
            printf("Invalid Choice!");
            break;
        }
    } while (choice < 7);
}