#include "inverted_search.h"

// add a new file to the database 
void update_database(hash *ht, filename **head)
{
    char name[FNAME_SIZE];

    printf("Enter the new file name : ");
    if (scanf("%49s", name) != 1)
        return;
    clear_buffer();

    // should be .txt, present, not empty and not duplicate 
    if (validate_file(name, head) == FAILURE)
        return;

    // call the create function for the new file 
    index_file(name, ht);
}