#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    char d[10];
    int c,opt;
    DIR *dir;
    struct dirent *entry;
     
    printf("MENU\n1.create Dir\n2.Remove Dir\n3.Read Dir\nEnter your choice:");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:printf("Enter the dir name:");
               scanf("%s",d);
               c=mkdir(d);
               if(c==1)
                    printf("dir is not created");
               else
                    printf("dir is created");
                break;
        case 2:printf("Enter the dir name:");
               scanf("%s",d);
               c=rmdir(d);
               if(c==1)
                    printf("dir is not removed");
               else
                    printf("dir is created");
               break;
        case 3:printf("Enter the dir name:");
               scanf("%s",d);
               dir=opendir(d);
               if(dir == NULL)
                    perror("Error opening the dir");
               else
                    while ((entry = readdir(dir)) != NULL) {
                         printf("%s\n", entry->d_name);
                    }
              closedir(dir);
              break;
    }

    return 0;
}
