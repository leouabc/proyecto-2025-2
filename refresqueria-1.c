#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Borrador de estructuras

typedef struct {
    char sabor[50];
    char topping[50];
    char cono[50];
    char tamano[50];
    int precio;
} classe;
typedef struct {
    char clase[50];
    classe key;
} producto;

// Prototipos de funciones
int altas(producto Registro[100], int co);
/*int bajas();
void consultas();
int modificaciones();*/

// Menu principal
int main() {
    producto Registro[100];
    int co = 0;
    int opcion;
    do {
        printf("\nMenu\n");
        printf("1. Altas\n");
        printf("2. Bajas\n");
        printf("3. Consultas\n");
        printf("4. Modificaciones\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                co = altas(Registro, co);
                break;
            /*case 2:
                bajas();
                break;
            case 3:
                consultas();
                break;
            case 4:
                modificaciones();
                break;
            case 5:
                break; */
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);
    return 0;
}

// Funciones
int altas(producto Registro[100], int co) {
    FILE *binario;
    int opc, opc2, opc3;
    char opc4[50];
    int selection;
    binario = fopen("datos.dat", "ab");
    //POSIBLE OPTIMIZACON
    do {
        //Dar de alta y se lleva a seleccion de sabor
        puts("Ingrese que tipo de producto quiere agregar: ");
        puts("1: Paleta, 2: Nieve, 3: Agua ");
        scanf("%d", &selection);
        fflush(stdin);
        //Aqui se copia el tipo de producto a la estructura
        if (selection == 1) {
            strcpy(opc4, "Paleta"); 
        }
        else if (selection == 2) {
            strcpy(opc4, "Nieve");
        }
        else if (selection == 3) {
            strcpy(opc4, "Agua");
        }
        strcpy(Registro[co].clase, opc4);
        //En case de ser tal cosa, hacer:
        switch (selection) {
            case 1:
                puts("Ingrese el sabor de la paleta: ");
                puts("Ingrese 1 para ver lista de sabores:");
                puts("Ingrese 2 para ingresar manualmente:");
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el sabor: ");
                        gets(Registro[co].key.sabor);
                        break;
                    case 1:
                        puts("1: Fresa, 2: Chocolate, 3: Vainilla"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro[co].key.sabor, "Fresa");
                                break;
                            case 2:
                                strcpy(Registro[co].key.sabor, "Chocolate");
                                break;
                            case 3:
                                strcpy(Registro[co].key.sabor, "Vainilla");
                                break;
                        }
                        break;
                }
                fflush(stdin);
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro[co].key.precio);
                break;
            case 2:
                while(getchar() != '\n');
                puts("Ingrese el sabor de la nieve manualmente: ");
                gets(Registro[co].key.sabor);
                puts("Ingrese el topping deseado: ");
                fflush(stdin);
                gets(Registro[co].key.topping);
                puts("Ingrese el tipo de cono deseado: ");
                fflush(stdin);
                gets(Registro[co].key.cono);
                puts("");
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro[co].key.precio);
                break;
            case 3:
                while(getchar() != '\n');
                puts("Ingrese el sabor de la agua manualmente: ");
                gets(Registro[co].key.sabor);
                puts("Ingrese el tamaño deseado: ");
                fflush(stdin);
                gets(Registro[co].key.tamano);
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro[co].key.precio);
                break;
            
        }
        fwrite(&Registro[co], sizeof(producto), 1, binario);
        co++;
        printf("\nGuardado exitoso\n");
        puts("Quieres ingresar otro articulo?");
        puts("1: Si, 2: No");
        scanf("%d", &opc);
    } while(opc != 2);
    fclose(binario);
    return co;
}