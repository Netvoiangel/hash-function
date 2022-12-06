#include <stdio.h>


struct person_data
{
    char login[20];
    int password;
};


int lenOfWord(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    return i;
}


void connection(char *str, char *stp)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    int j = 0;
    while (stp[j] != '\0')
    {
        str[i + j] = stp[j];
        j ++;
    }
    str[i + j] = '\0';
}


int Hash(char *key, size_t len)
{
    long long int hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % 100000;
}


void archieve(struct person_data b)
{
    FILE *fp;
    char *path = "/Users/w6itec6apel/Desktop/politex_programming/hash-function_2.0/base.txt";

    fp = fopen(path, "w+");
    if (fp == NULL)
    {
        printf("File not opened! Error!");
    }
    else
    {
        printf("File opened!\n");
    }

    fwrite(&b, sizeof(b), 1, fp);
}


void registration(char *login, int password)
{
    struct person_data personality;
    connection(personality.login, login);
    personality.password = password;
    
    printf("%s %d\n", personality.login, personality.password);
    
    archieve(personality);
}


void start_function()
{
    char login[30];
    char password_str[30];
    
    printf("Enter login: ");
    scanf("%s", login);
    
    printf("Enter password: ");
    scanf("%s", password_str);
    
    int lenOfPassword = lenOfWord(password_str);
    int password_hash = Hash(password_str, lenOfPassword);
    
    registration(login, password_hash);
}


int main()
{
//    char *password = "f6f7fdfg8ds";
//    int len = lenOfWord(password);
//
//    printf("%d\n", Hash(password, len));
    start_function();
    return 0;
}
