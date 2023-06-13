/* -------------------------------------------------------------------------------
Creator: Gabriel Soares

Programa para simular um banco de dados em arquivo de texto que permite acesso de múltiplos usuários simultaneamente.
Ideia era fazer inspirado em CRUD de clientes, mas não consegui fazer tudo, então fiz o que deu tempo.
O ideal era ter dividido bem as funções que interagem com o DB entre GET, POST, DELETE e UPDATE pra simular uma API REST e um banco de dados.

------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// -------------------------------------------------------------------------------
// Constants ---------------------------------------------------------------------

#define TEXT_SIZE 30
#define CPF_SIZE 12
#define DB "db.txt"

// -------------------------------------------------------------------------------
// Structs -----------------------------------------------------------------------

typedef struct Date {
    int day, month, year;
} Date;

typedef struct Address {
    char neighborhood[TEXT_SIZE];
    char street[TEXT_SIZE];
    int number;
} Address;

typedef struct Client {
    char name[TEXT_SIZE];
    char cpf[CPF_SIZE];                                        // CPF format: 000.000.000-00
    Address address;
    Date birthDate;
    Date lastPurchaseDate;
    float totalPurchases;
    struct Client *next;
} Client;

// -------------------------------------------------------------------------------
// Prototypes --------------------------------------------------------------------

// DB
void createDB();                                // Create DB file if not exists

// DB REST API
void POST(Client *client);                      // Insert new client in DB 
void GET(char *cpf);                            // Get client by CPF
void DELETE(char *cpf);                         // Delete client by CPF

// GET for LIST
void GET_LIST();                                    // List all clients in DB
void GET_LIST_BY_PURCHASE_DATE(Date *date);         // List all clients in DB by purchase date
void GET_LIST_BY_NEIGHBORHOOD(char *neighborhood);  // List all clients in DB by neighborhood
void GET_LIST_BY_MOST_PURCHASES();                  // List all clients in DB by most purchases

// Client Helpers
void getNewClient(Client *client);              // Get new client data
void printClient(Client *client);               // Print client data

// Data Helpers
void getText(char *text);                       // Get text from user
void getCpf(char *cpf);                         // Get CPF from user
void getDate(Date *date, bool birthDate);       // Get date from user
void getAddress(Address *address);              // Get address from user
void getTotalPurchases(float *totalPurchases);  // Get total purchases from user
void getAddressNumber(int *number);             // Get address number from user

// Menu
bool menu();                                    // Show menu
int isOnlyNumbers(const char* str);

// -------------------------------------------------------------------------------
// Main --------------------------------------------------------------------------

int main() {
    createDB();                                 // Create DB file if not exists
    while(menu());                              // Show menu
}

// -------------------------------------------------------------------------------

bool menu() {
    int option;                                                 // Menu option

    printf("\n"
        "----------------------------------------\n"
        "------------------ MENU ----------------\n\n"
        "1 - Cadastrar cliente\n"
        "2 - Buscar cliente\n"
        "3 - Deletar cliente\n"
        "4 - Listar clientes\n"
        "5 - Listar cliente que comprou em X\n"                 // Informar CPF, nome e endereço
        "6 - Listar moradores do bairro X\n"                    // Informar bairro
        "7 - Cliente com maior valor em compras\n"
        "0 - Sair\n"
        "\n----------------------------------------\n\n"
        "Opcao: ");

    fflush(stdin);
    scanf("%d", &option);

    if( option > 1 ) {
        // Check if there is any user in DB
        FILE *db = fopen(DB, "r");
        int c = fgetc(db);
        if (c == EOF) {
            system("cls");
            printf("Nao ha clientes cadastrados!\n");
            fclose(db);
            return true;
        }
        fclose(db);
    }
    
    switch (option) {
        
        case 1: { 
            system("cls");

            Client *client = (Client*)malloc(sizeof(Client));
            getNewClient(client);
            POST(client);
            free(client);
            break;
        }
        case 2: { 
            system("cls");

            char cpf[CPF_SIZE];
            printf("CPF: ");
            getCpf(cpf);
            GET(cpf);
            break;
        }
        case 3: { 
            system("cls");

            char cpf[CPF_SIZE];
            printf("CPF: ");
            getCpf(cpf);
            DELETE(cpf);
            break;
        }
        case 4: { 
            system("cls");

            GET_LIST();
            break;
        }
        case 5: { 
            system("cls");

            Date *date = (Date*)malloc(sizeof(Date));
            getDate(date, true);
            GET_LIST_BY_PURCHASE_DATE(date);
            free(date);
            break;
        }
        case 6: { 
            system("cls");

            char neighborhood[TEXT_SIZE];
            getText(neighborhood);
            GET_LIST_BY_NEIGHBORHOOD(neighborhood);
            break;
        }
        case 7: { 
            system("cls");

            GET_LIST_BY_MOST_PURCHASES();
            break;
        }
        case 0:
            return false;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return true;
}

// -------------------------------------------------------------------------------

void createDB() {
    FILE *db = fopen(DB, "a");                  // Open/Create DB file in append mode
    fclose(db);
}

// -------------------------------------------------------------------------------
// API ---------------------------------------------------------------------------

void POST(Client* client) {
    FILE* db = fopen(DB, "a");
    
    // Check if file is empty
    int isEmpty = 1;
    int c = fgetc(db);
    if (c == EOF) {
        fprintf(db, "%s,", client->name);
        fprintf(db, "%s,", client->cpf);
        fprintf(db, "%s,", client->address.neighborhood);
        fprintf(db, "%s,", client->address.street);
        fprintf(db, "%d,", client->address.number);
        fprintf(db, "%d,", client->birthDate.day);
        fprintf(db, "%d,", client->birthDate.month);
        fprintf(db, "%d,", client->birthDate.year);
        fprintf(db, "%d,", client->lastPurchaseDate.day);
        fprintf(db, "%d,", client->lastPurchaseDate.month);
        fprintf(db, "%d,", client->lastPurchaseDate.year);
        fprintf(db, "%.2f\n", client->totalPurchases);
        
        fclose(db);
        return;
    } else {
        isEmpty = 0; // File is not empty
    }
    
    // File is not empty, check for existing CPF
    rewind(db); // Set file pointer to the beginning of the file
    Client* temp = (Client*)malloc(sizeof(Client));
    while (fscanf(db, "%[^,],", temp->name) == 1) {
        fscanf(db, "%[^,],", temp->cpf);
        fscanf(db, "%[^,],", temp->address.neighborhood);
        fscanf(db, "%[^,],", temp->address.street);
        fscanf(db, "%d,", &temp->address.number);
        fscanf(db, "%d,", &temp->birthDate.day);
        fscanf(db, "%d,", &temp->birthDate.month);
        fscanf(db, "%d,", &temp->birthDate.year);
        fscanf(db, "%d,", &temp->lastPurchaseDate.day);
        fscanf(db, "%d,", &temp->lastPurchaseDate.month);
        fscanf(db, "%d,", &temp->lastPurchaseDate.year);
        fscanf(db, "%f\n", &temp->totalPurchases);
        
        if (strcmp(temp->cpf, client->cpf) == 0) {
            printf("CPF already exists!\n");
            fclose(db);
            free(temp);
            return;
        }
    }
    
    if (isEmpty) {
        fprintf(db, "%s,", client->name);
        fprintf(db, "%s,", client->cpf);
        fprintf(db, "%s,", client->address.neighborhood);
        fprintf(db, "%s,", client->address.street);
        fprintf(db, "%d,", client->address.number);
        fprintf(db, "%d,", client->birthDate.day);
        fprintf(db, "%d,", client->birthDate.month);
        fprintf(db, "%d,", client->birthDate.year);
        fprintf(db, "%d,", client->lastPurchaseDate.day);
        fprintf(db, "%d,", client->lastPurchaseDate.month);
        fprintf(db, "%d,", client->lastPurchaseDate.year);
        fprintf(db, "%.2f\n", client->totalPurchases);
    } else {
        fprintf(db, "\n%s,", client->name);
        fprintf(db, "%s,", client->cpf);
        fprintf(db, "%s,", client->address.neighborhood);
        fprintf(db, "%s,", client->address.street);
        fprintf(db, "%d,", client->address.number);
        fprintf(db, "%d,", client->birthDate.day);
        fprintf(db, "%d,", client->birthDate.month);
        fprintf(db, "%d,", client->birthDate.year);
        fprintf(db, "%d,", client->lastPurchaseDate.day);
        fprintf(db, "%d,", client->lastPurchaseDate.month);
        fprintf(db, "%d,", client->lastPurchaseDate.year);
        fprintf(db, "%.2f\n", client->totalPurchases);
    }
    
    fclose(db);
    free(temp);
}


void GET(char* cpf) {
    FILE* db = fopen(DB, "r");
    Client* client = (Client*)malloc(sizeof(Client));

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        if (strcmp(client->cpf, cpf) == 0) {
            printClient(client);
            break;
        }
    }

    fclose(db);
}

void DELETE(char* cpf) {
    FILE* db = fopen(DB, "r");                                                  
    FILE* temp = fopen("temp.txt", "w");                                        
    Client* client = (Client*)malloc(sizeof(Client));

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        if (strcmp(client->cpf, cpf) != 0) {
            fprintf(temp, "%s,", client->name);
            fprintf(temp, "%s,", client->cpf);
            fprintf(temp, "%s,", client->address.neighborhood);
            fprintf(temp, "%s,", client->address.street);
            fprintf(temp, "%d,", client->address.number);
            fprintf(temp, "%d,", client->birthDate.day);
            fprintf(temp, "%d,", client->birthDate.month);
            fprintf(temp, "%d,", client->birthDate.year);
            fprintf(temp, "%d,", client->lastPurchaseDate.day);
            fprintf(temp, "%d,", client->lastPurchaseDate.month);
            fprintf(temp, "%d,", client->lastPurchaseDate.year);
            fprintf(temp, "%.2f\n", client->totalPurchases);
        }
    }

    fclose(db);
    fclose(temp);

    remove(DB);
    rename("temp.txt", DB);
}

// -------------------------------------------------------------------------------
// API GET LIST 

void GET_LIST() {
    FILE* db = fopen(DB, "r");
    Client* client = (Client*)malloc(sizeof(Client));

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        printClient(client);
    }

    fclose(db);
}

void GET_LIST_BY_PURCHASE_DATE(Date* date) {
    FILE* db = fopen(DB, "r"); 
    Client* client = (Client*)malloc(sizeof(Client));
    int count = 0;

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        if (client->lastPurchaseDate.year == date->year && client->lastPurchaseDate.month == date->month && client->lastPurchaseDate.day == date->day) {
            printClient(client);
            count++;
        }
    }

    if (count == 0) {
        printf("Nenhum cliente encontrado com a data de compra informada.\n");
    } else {
        printf("Total de clientes encontrados: %d\n", count);
    }

    fclose(db);
}

void GET_LIST_BY_NEIGHBORHOOD(char* neighborhood) {
    FILE* db = fopen(DB, "r");
    Client* client = (Client*)malloc(sizeof(Client));
    int count = 0;

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        if (strcmp(client->address.neighborhood, neighborhood) == 0) {
            printClient(client);
            count++;
        }
    }

    if (count == 0) {
        printf("Nenhum cliente encontrado no bairro %s\n", neighborhood);
    } else {
        printf("Total de clientes encontrados no bairro %s: %d\n", neighborhood, count);
    }

    fclose(db);
}

void GET_LIST_BY_MOST_PURCHASES() {
    FILE* db = fopen(DB, "r");
    Client* client = (Client*)malloc(sizeof(Client));
    Client* mostPurchases = (Client*)malloc(sizeof(Client));

    while (!feof(db)) {
        fscanf(db, "%[^,],", client->name);
        fscanf(db, "%[^,],", client->cpf);
        fscanf(db, "%[^,],", client->address.neighborhood);
        fscanf(db, "%[^,],", client->address.street);
        fscanf(db, "%d,", &client->address.number);
        fscanf(db, "%d,", &client->birthDate.day);
        fscanf(db, "%d,", &client->birthDate.month);
        fscanf(db, "%d,", &client->birthDate.year);
        fscanf(db, "%d,", &client->lastPurchaseDate.day);
        fscanf(db, "%d,", &client->lastPurchaseDate.month);
        fscanf(db, "%d,", &client->lastPurchaseDate.year);
        fscanf(db, "%f\n", &client->totalPurchases);

        if (client->totalPurchases > mostPurchases->totalPurchases) {
            mostPurchases = client;
        }
    }

    printClient(mostPurchases);

    fclose(db);
}

// -------------------------------------------------------------------------------

void getNewClient(Client* client) {
    printf("Nome: ");
    getText(client->name);
    printf("CPF: ");
    getCpf(client->cpf);

    getAddress(&client->address);

    printf("Data de nascimento: ");
    getDate(&client->birthDate, true);

    printf("Data da ultima compra: ");
    getDate(&client->lastPurchaseDate, false);

    printf("Total de compras: ");
    scanf("%f", &client->totalPurchases);

    printf("\n");
}

void printClient(Client* client) {
    printf("%s | ", client->name);
    printf("%s | ", client->cpf);
    printf("%s - ", client->address.neighborhood);
    printf("%s, ", client->address.street);
    printf("%d | ", client->address.number);
    printf("%d/%d/%d | ", client->birthDate.day, client->birthDate.month, client->birthDate.year);
    printf("%d/%d/%d | ", client->lastPurchaseDate.day, client->lastPurchaseDate.month, client->lastPurchaseDate.year);
    printf("%.2f\n", client->totalPurchases);
}

// -------------------------------------------------------------------------------
// Date Helpers ------------------------------------------------------------------

void getText(char *text) {
    fflush(stdin);
    fgets(text, TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; 

    // capital case
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (i == 0 || text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }
}

void getCpf(char *cpf) {
    fflush(stdin);
    fgets(cpf, CPF_SIZE, stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; 

    if(strlen(cpf) != 11 || !isOnlyNumbers(cpf)) {
        for (int i = 0; i < CPF_SIZE; i++) {
            printf("%c", cpf[i]);
        }
        printf("CPF invalido! Digite novamente: ");
        getCpf(cpf);
    }

} 

int isOnlyNumbers(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && !isblank(str[i])) {
            return 0;  // Not a number
        }
    }
    return 1;  // Contains only numbers
}

void getDate(Date *date, bool isBirthDate) {
    static Date currentBirthDate;               // Static variable to store the current birth date
    fflush(stdin);

    if( 3 != scanf("%d/%d/%d", &date->day, &date->month, &date->year)) {
        printf("Data invalida! Digite novamente: ");
        getDate(date, isBirthDate);
    }

    // Check if the date is valid
    if(date->day < 1 || date->day > 31 || date->month < 1 || date->month > 12 || date->year < 1900 || date->year > 2023) {
        printf("Data invalida! Digite novamente: ");
        getDate(date, isBirthDate);
    }

    // Check Bissextile
    if(date->year % 4 == 0 && (date->year % 100 != 0 || date->year % 400 == 0)) {
        if(date->month == 2 && date->day > 29) {    
            printf("Data invalida! Digite novamente: ");
            getDate(date, isBirthDate);
        }
    } else {
        if(date->month == 2 && date->day > 28) {
            printf("Data invalida! Digite novamente: ");
            getDate(date, isBirthDate);
        }
    }

    // Check if the buy date is after the birth date
    if(isBirthDate) {
        currentBirthDate = *date;
    } else {
        if(date->year < currentBirthDate.year) {
            printf("Data invalida! Digite novamente: ");
            getDate(date, isBirthDate);
        } else if(date->year == currentBirthDate.year) {
            if(date->month < currentBirthDate.month) {
                printf("Data invalida! Digite novamente: ");
                getDate(date, isBirthDate);
            } else if(date->month == currentBirthDate.month) {
                if(date->day < currentBirthDate.day) {
                    printf("Data invalida! Digite novamente: ");
                    getDate(date, isBirthDate);
                }
            }
        }
    }    
}

void getAddress(Address *address) {
    printf("Bairro: ");
    getText(address->neighborhood);

    printf("Rua: ");
    getText(address->street);

    printf("Numero: ");
    getAddressNumber(&address->number);

    // convert to capital case
    for (int i = 0; address->neighborhood[i] != '\0'; i++) {
        address->neighborhood[i] = tolower(address->neighborhood[i]);
    }
    for (int i = 0; address->neighborhood[i] != '\0'; i++) {
        if (i == 0 || address->neighborhood[i - 1] == ' ') {
            address->neighborhood[i] = toupper(address->neighborhood[i]);
        }
    }

    for (int i = 0; address->street[i] != '\0'; i++) {
        address->street[i] = tolower(address->street[i]);
    }
    for (int i = 0; address->street[i] != '\0'; i++) {
        if (i == 0 || address->street[i - 1] == ' ') {
            address->street[i] = toupper(address->street[i]);
        }
    }
}

void getAddressNumber(int *number) {
    fflush(stdin);
    scanf("%d", number);

    if(*number < 0) {
        printf("Numero invalido! Digite novamente: ");
        getAddressNumber(number);
    }
}

void getTotalPurchases(float *totalPurchases) {
    printf("Valor total das compras: ");
    fflush(stdin);
    scanf("%f", totalPurchases);

    if(*totalPurchases < 0) {
        printf("Valor invalido! Digite novamente: ");
        getTotalPurchases(totalPurchases);
    }
}
