#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bucket
{
    struct node *chainHead;
};

struct node
{
    char *word;
    struct node *next;
};

int hash(char *str)
{
    int n = strlen(str);

    if (n == 1)
    {
        return *str;
    }
    return (17 * hash(str + 1) % 10000 + *str) % 10000;
}

int main(int argc, char *argv[])
{

    struct bucket list[10000] = {NULL};
    char c[50];
    char d;
    char in[1024];
    char *string[500];
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    while (1)
    {

        fscanf(fp1, "%[^\n]", c);

        d = fgetc(fp1);

        if (feof(fp1))
        {
            break;
        }
        else
        {
            //printf("%s\n", c);

            int i = hash(strrev(c));

            //printf("%d\n", i);

            char *aWord = (char *)malloc(strlen(c) + 1);
            struct node *pointer = (struct node *)malloc(sizeof(struct node));
            
            pointer->word = aWord;
            pointer->next = NULL;
            strcpy(pointer->word, c);

            if (list[i].chainHead == NULL)
            {
                list[i].chainHead = pointer;
            }
            else
            {
                //Add node to end
                struct node *temp = list[i].chainHead;

                while (temp->next != NULL)
                {

                    //printf("%d\n", i);
                    //printf("%s\n", temp->word);
                    temp = temp->next;
                }
                //printf("Collsion found, word chained\n");
                temp->next = pointer;
                
                //Add node to beginning
                // pointer->next = list[i].chainHead;
                // list[i].chainHead = pointer;
            }
        }
    }

    fclose(fp1);

    
    char delimit[] = " /!@#$%^&*()+=[]{}|;:?.>,<~_1234567890\t\r\n\v\f";
    int i = 0, j = 0;
    while (1)
    {
        //fscanf(fp2, "%s", in);
        fgets(in, sizeof in, fp2);
        //printf("%s\n", in);
        if (feof(fp2))
        {
            //printf("End of File!\n");
            break;
        }
        else
        {
          
            string[i] = strtok(in, delimit); 
            while (string[i] != NULL)
            {
                //printf("string [%d]=%s\n", i, string[i]);
                int b = hash(strrev(string[i]));
                int x = 0;
                struct node *temp = list[b].chainHead;

                while (temp != NULL)
                {
                    // printf("%d\n", b);
                    // printf("%s\n", string[i]);
                    // printf("%s\n", temp->word);
                    if (strcmp(temp->word, string[i]) == 0)
                    {

                        x++;
                        break;
                    }
                    else
                    {

                        temp = temp->next;
                    }
                }
                if (x == 0)
                {
                    printf("The word that has been misspelled: %s\n", strrev(string[i]));
                }

                
                i++;
                string[i] = strtok(NULL, delimit);
            }
        }

    }
    fclose(fp2);
    return 0;
}