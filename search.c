#include"inverted_search.h"

void search_database(hash *ht)
{
    char word[WORD_SIZE];
    int index;
    mainnode *temp;
    subnode *sub;
    printf("Enter the word to search:");
    if(scanf("%49s",word)!=1)
      return;
    clear_buffer();
     index=get_index(word[0]);
     temp=ht[index].link;
     while(temp!=NULL)
     {
        if(strcmp(temp->word,word)==0)
        {
            printf("\nWord %s is found in the database\n",word);
            printf("It is present in %d files \n",temp->file_count);
            sub=temp->sub_link;
            while(sub!=NULL)
            {
              printf("In file %s the word is present %d time(s)\n", sub->f_name, sub->word_count);
              sub=sub->link;  
            }
            printf("\n");
            return;
        }
        temp=temp->link;
     }
    printf("\nWord %s is not found in the database\n",word);
}