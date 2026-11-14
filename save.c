#include "inverted_search.h"
void save_database(hash *ht,filename *head)
{
    char name[FNAME_SIZE];
    char ch;
    int i;
    FILE *fp;
    mainnode *m;
    subnode *s;
    filename *f;
    printf("Enter the backup file name");
    if (scanf("%49s", name) != 1)
        return;
    clear_buffer();

    if (txt_file(name) == 0)
    {
        printf("ERROR: backup file should be a .txt file\n");
        return;
    }

    // backup file should not be one of the input files 
    for (f = head; f != NULL; f = f->link)
    {
        if (strcmp(f->filename, name) == 0)
        {
            printf("ERROR: %s is an input file, give another name\n", name);
            return;
        }
    }

    //if the file is present, take permission from the user to overwrite 
    fp = fopen(name, "r");
    if (fp != NULL)
    {
        fclose(fp);
        printf("File is already present. Do you want to overwrite? (y/n) : ");
        if (scanf(" %c", &ch) != 1 || (ch != 'y' && ch != 'Y'))
        {
            clear_buffer();
            printf("Save operation is stopped\n");
            return;
        }
        clear_buffer();
    }

    // if the file is not present it will be created 
    fp = fopen(name, "w");
    if (fp == NULL)
    {
        printf("ERROR: %s cannot be created\n", name);
        return;
    }

    for (i = 0; i < HASH_SIZE; i++)
    {
        m = ht[i].link;
        while (m != NULL)
        {
            fprintf(fp, "#%d;%s;%d", i, m->word, m->file_count);

            s = m->sub_link;
            while (s != NULL)
            {
                fprintf(fp, ";%s;%d", s->f_name, s->word_count);
                s = s->link;
            }
            fprintf(fp, ";#\n");        // after # go to the new line 
            m = m->link;
        }
    }

    fclose(fp);
    printf("Database is saved in %s\n", name);
}
