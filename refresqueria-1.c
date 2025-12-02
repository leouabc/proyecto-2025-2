#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Borrador de estructuras

typedef struct {
    char sabor[50];
    char topping[50];
    char cono[50];
    char tamano[50];
    int precio;
} classe;
typedef struct {
    int clave;
    char clase[50];
    char sabor[50];
    char top[50];
    char cono2[50];
    int cant;
    int pre;
    int total;
    int ultimo;
    char tam[50]; 
} factura;
typedef struct {
    char clase[50];
    classe key;
    factura F;
} producto;

// Prototipos de funciones
int altas(producto Registro, int co);
void consultas(producto Registro, int co);
void conclas(producto Registro, int co);
void ordenar(producto Registro, int co);
int ventafac(producto Registro, int co);
void consfact(producto Registro, int co);
int cancelar(producto Registro, int co);
// Menu principal
int main() {
    system("color 9F");
    producto Registro;
    int co = 0;
    int opcion;
    do {
        printf("\n---------------------Menu---------------------\n");
        printf("1   || Altas\n");
        printf("2   || Consulta ordenada\n");
        printf("3   || Consulta por clasificacion\n");
        printf("4   || Venta y generacion de factura\n");
        printf("5   || Consulta de facturas\n");
        printf("6   || Cancelar factura\n");
        printf("0   || Salir\n");
        puts("----------------------------------------------");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                co = altas(Registro, co);
                break;
            case 2: 
                ordenar(Registro, co); consultas(Registro, co);
                break;
            case 3:
                ordenar(Registro, co); conclas(Registro, co);
                break;
            case 4:
                ventafac(Registro, co);
                break;
            case 5:
                consfact(Registro, co);
                break;
            case 6:
                cancelar(Registro, co);
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 0);
    return 0;
}

// Funciones
int altas(producto Registro, int co) {
    FILE *binario;
    int opc, opc2, opc3;
    char opc4[50];
    int selection;
    binario = fopen("datos.dat", "ab");
    //POSIBLE OPTIMIZACON
    do {
        //Dar de alta y se lleva a seleccion de sabor
        puts("Ingrese que tipo de producto quiere agregar: ");
        puts("|| 1: Paleta || 2: Nieve || 3: Agua ||");
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
        strcpy(Registro.clase, opc4);
        //En case de ser tal cosa, hacer:
        switch (selection) {
            case 1:
                puts("Ingrese el sabor de la paleta: ");
                puts("|| 1 para ver lista de sabores || 2 para ingresar manualmente ||");
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el sabor: ");
                        gets(Registro.key.sabor);
                        break;
                    case 1:
                        do {
                        puts("|| 1: Fresa || 2: Chocolate || 3: Vainilla ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.sabor, "Fresa");
                                break;
                            case 2:
                                strcpy(Registro.key.sabor, "Chocolate");
                                break;
                            case 3:
                                strcpy(Registro.key.sabor, "Vainilla");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                fflush(stdin);
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro.key.precio);
                break;
            case 2:
                while(getchar() != '\n');
                puts("Ingrese el sabor de la nieve: ");
                puts("|| 1 para ver lista de sabores || 2 para ingresar manualmente ||");
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el sabor: ");
                        gets(Registro.key.sabor);
                        break;
                    case 1:
                        do {
                        puts("|| 1: Menta || 2: Chocolate || 3: Vainilla ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.sabor, "Menta");
                                break;
                            case 2:
                                strcpy(Registro.key.sabor, "Chocolate");
                                break;
                            case 3:
                                strcpy(Registro.key.sabor, "Vainilla");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                puts("Ingrese el topping deseado: ");
                puts("|| 1 para ver lista de toppings || 2 para ingresar manualmente ||");
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el topping: ");
                        gets(Registro.key.topping);
                        break;
                    case 1:
                        do {
                        puts("|| 1: Chispas de chocolate || 2: Nuez || 3: Gomitas ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.topping, "Chispas de chocolate");
                                break;
                            case 2:
                                strcpy(Registro.key.topping, "Nuez");
                                break;
                            case 3:
                                strcpy(Registro.key.topping, "Gomitas");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                fflush(stdin);
                puts("Ingrese el tipo de cono deseado: ");
                puts("|| 1 para ver lista de conos || 2 para ingresar manualmente ||");
                fflush(stdin);
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el cono: ");
                        gets(Registro.key.cono);
                        break;
                    case 1:
                        do {
                        puts("|| 1: Normal || 2: Waffle || 3: Chocolate ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.cono, "Normal");
                                break;
                            case 2:
                                strcpy(Registro.key.cono, "Waffle");
                                break;
                            case 3:
                                strcpy(Registro.key.cono, "Chocolate");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                fflush(stdin);
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro.key.precio);
                break;
            case 3:
                while(getchar() != '\n');
                puts("Ingrese el sabor de la agua: ");
                puts("|| 1 para ver lista de sabores || 2 para ingresar manualmente ||");
                fflush(stdin);
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        puts("Ingresa el sabor: ");
                        gets(Registro.key.sabor);
                        break;
                    case 1:
                        do {
                        puts("|| 1: Limon || 2: Frutas || 3: Agua Natural ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.sabor, "Limon");
                                break;
                            case 2:
                                strcpy(Registro.key.sabor, "Frutas");
                                break;
                            case 3:
                                strcpy(Registro.key.sabor, "Agua Natural");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                fflush(stdin);
                printf("Ingrese el tamano deseado: ");
                puts("|| 1 para ver lista de tamanos || 2 para ingresar manualmente ||");
                scanf("%d", &opc2);
                switch (opc2) {
                    case 2:
                        while(getchar() != '\n');
                        printf("Ingresa el tamano: ");
                        gets(Registro.key.tamano);
                        break;
                    case 1:
                        do {
                        puts("|| 1: 250ml || 2: 500ml || 3: 1L ||"); //Agregar mas
                        scanf("%d", &opc3);
                        switch (opc3) {
                            case 1:
                                strcpy(Registro.key.tamano, "250ml");
                                break;
                            case 2:
                                strcpy(Registro.key.tamano, "500ml");
                                break;
                            case 3:
                                strcpy(Registro.key.tamano, "1L");
                                break;
                            default:
                                puts("Opcion invalida");
                                break;
                        } 
                    } while (opc3 != 1 && opc3 != 2 && opc3 != 3);
                    break;
                }
                fflush(stdin);
                puts("Ingrese el precio que se le dara: ");
                scanf("%d", &Registro.key.precio);
                break;
            
        }
        fwrite(&Registro, sizeof(producto), 1, binario);
        co++;
        printf("\nGuardado exitoso\n");
        puts("Quieres ingresar otro articulo?");
        puts("|| 1: Si || 2: No ||");
        scanf("%d", &opc);
    } while(opc == 1);
    fclose(binario);
    return co;
}

void ordenar(producto Registro, int co) {
    FILE *binario;
    producto e, e2, aux;
    binario = fopen("datos.dat", "rb+");
    int x,y,n;

    if (binario == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    else {
        //Esto calcula cuantos registros hay
        fseek(binario, 0, SEEK_END);
        n = ftell(binario) / sizeof(producto);
        rewind(binario);

        //Ordenacion burbuja
        for (x = 0; x<n; x++) {
            for (y = 0; y<n; y++) {
                //
                fseek(binario, y*sizeof(producto), 0);
                fread(&e, sizeof(producto), 1, binario);
                fseek(binario, (y+1)*sizeof(producto), 0);
                fread(&e2, sizeof(producto), 1, binario);
                //Ordena por nombre de sabor
                if (strcmp(e.key.sabor, e2.key.sabor) > 0) {
                    aux = e;
                    e = e2;
                    e2 = aux;

                    fseek(binario, y*sizeof(producto), 0);
                    fwrite(&e, sizeof(producto), 1, binario);
                    fseek(binario, (y+1)*sizeof(producto), 0);
                    fwrite(&e2, sizeof(producto), 1, binario);
                }
                //Ordena por tipo
                if (strcmp(e.clase, e2.clase) > 0) {
                    aux = e;
                    e = e2;
                    e2 = aux;

                    fseek(binario, y*sizeof(producto), 0);
                    fwrite(&e, sizeof(producto), 1, binario);
                    fseek(binario, (y+1)*sizeof(producto), 0);
                    fwrite(&e2, sizeof(producto), 1, binario);
                }
            }    
        }
        fclose(binario);
    }
}

void consultas(producto Registro, int co) {
    FILE *binario; producto e;
    binario = (fopen("datos.dat", "rb"));
    if (binario == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    else {
        puts("---------------------Menu---------------------");
        printf("**************************\n");
        while (fread(&e, sizeof(producto), 1, binario)>0) {
            printf("|| Tipo: %s\n", e.clase);
            if (strcmp(e.clase, "Paleta") == 0) {
                printf("|| Sabor: %s\n", e.key.sabor);
                printf("|| Precio: %d\n", e.key.precio);
                printf("**************************\n");
            }
            else if (strcmp(e.clase, "Nieve") == 0) {
                printf("|| Sabor: %s\n", e.key.sabor);
                printf("|| Topping: %s\n", e.key.topping);
                printf("|| Cono: %s\n", e.key.cono);
                printf("|| Precio: %d\n", e.key.precio);
                printf("**************************\n");
            }
            else if (strcmp(e.clase, "Agua") == 0) {
                printf("|| Sabor: %s\n", e.key.sabor);
                printf("|| Tamano: %s\n", e.key.tamano);
                printf("|| Precio: %d\n", e.key.precio);
                printf("**************************\n");
            }
        }
        puts("---------------------------------------------");
        fclose(binario);
    }
}

void conclas(producto Registro, int co) {
    FILE *binario; producto e;
    int opc;
    binario = (fopen("datos.dat", "rb"));
    if (binario == NULL) {
        puts("Error al abrir el archivo");
        return;
    }
    else {
        printf("Ingresa la clase que quieres consultar: \n");
        puts("|| 1: Paletas || 2: Nieve || 3: Agua ||");
        //Esto solo sirve para el switch
        scanf("%d", &opc);
        puts("---------------------Menu---------------------");
        switch (opc) {
            case 1:
                puts("*****************");
                while (fread(&e, sizeof(producto), 1, binario)>0) {
                    if (strcmp(e.clase, "Paleta") == 0) {
                        printf("|| Tipo: %s\n", e.clase);
                        printf("|| Sabor: %s\n", e.key.sabor);
                        printf("|| Precio: %d\n", e.key.precio);
                        puts("*****************");
                    }
                }
                break;
            case 2:
                puts("*****************");
                while (fread(&e, sizeof(producto), 1, binario)>0) {
                    if (strcmp(e.clase, "Nieve") == 0) {
                        printf("|| Tipo: %s\n", e.clase);
                        printf("|| Sabor: %s\n", e.key.sabor);
                        printf("|| Topping: %s\n", e.key.topping);
                        printf("|| Cono: %s\n", e.key.cono);
                        printf("|| Precio: %d\n", e.key.precio);
                        puts("*****************");
                    }
                }
                break;
            case 3:
                puts("*****************");
                while (fread(&e, sizeof(producto), 1, binario)>0) {
                    if (strcmp(e.clase, "Agua") == 0) {
                        printf("|| Tipo: %s\n", e.clase);
                        printf("|| Sabor: %s\n", e.key.sabor);
                        printf("|| Tamano: %s\n", e.key.tamano);
                        printf("|| Precio: %d\n", e.key.precio);
                        puts("*****************");
                    }
                }
                break;
            default:
                puts("Opcion invalida");
                break;
        }
    }
}
int ventafac(producto Registro, int co)
{
    //apertura de archivos
   FILE *binario;
   FILE *fac;
   producto P;
   factura F;
   factura ultimo;
   //declaracion variables
   int opcion=0, bandera=0, a=1;
   int cant;
    
   binario = fopen("datos.dat", "rb");
   if (binario == NULL) {
        puts("Error al abrir el archivo");
        return 0;
    }
    
    fac = fopen("facturas.dat", "ab+");
    if (fac == NULL) {
        puts("Error al abrir el archivo");
        return 0;
    }
    
    printf("\n------------Menu de productos disponibles------------\n");
    
    //abre el archivo de altas para ver las opciones
    
    while(fread(&P, sizeof(producto), 1, binario) >0){
        if (strcasecmp(P.clase, "Paleta") == 0 || strcasecmp(P.clase, "Agua") == 0){
            printf("|| %d. %s - %s - $%d\n", a, P.clase, P.key.sabor, P.key.precio);
            a++;
        }
        else {
            printf("|| %d. %s - %s - %s - %s - $%d\n", a, P.clase, P.key.sabor, P.key.topping, P.key.cono, P.key.precio);
            a++;
        }
    }
    
    printf("\nSeleccione el numero del producto vendido: ");
    scanf("%d", &opcion);
    
    rewind(binario);
    a=1;
    
    //buscamos el producto elegido
    
    while(fread(&P, sizeof(producto), 1, binario) >0){
        
        if (a==opcion){
        bandera =1;
        break;
        }
        a++;
    }
    
    if(!bandera){
        printf("\nNo se encontro el producto (ERROR)\n");
        fclose(binario);
        fclose(fac);
        return 0;
    }
    
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &cant);
    
    //empezamos con la creacion de la factura 
    
    fseek(fac, 0, SEEK_END);
    long peso = ftell(fac);
    
    //validacion para ver si hay una factura creada o no
    if(peso == 0){
       P.F.clave=1; 
       fseek(fac, 0, SEEK_END);
    }

    //si ya hay una factura creada
    else {
        fseek(fac, -((long)sizeof(factura)), SEEK_END);  // ir a la última factura (- para leer el ultimo digito)
        fread(&ultimo, sizeof(factura), 1, fac); // lee la última factura
        P.F.clave = ultimo.clave + 1;                    // siguiente ID
    }
    
    strcpy(P.F.clase, P.clase);
    strcpy(P.F.sabor, P.key.sabor);
    strcpy(P.F.top, P.key.topping);
    strcpy(P.F.cono2, P.key.cono);
    P.F.cant = cant;
    P.F.pre = P.key.precio;
    P.F.total = P.F.pre * cant;
    
    //guarda la factura en el archivo
    fwrite(&P.F, sizeof(factura), 1, fac);
    
    //muestra la factura
    printf("\n------- FACTURA GENERADA -------\n");
    printf("|| ID Factura: %d\n", P.F.clave);
    printf("|| Producto: %s\n", P.F.clase);
    printf("|| Sabor: %s\n", P.F.sabor);

    if (strcmp(P.F.clase, "Nieve") == 0) {
        printf("|| Topping: %s\n", P.F.top);
        printf("|| Cono: %s\n", P.F.cono2);
    }
    if (strcmp(P.F.clase, "Agua") == 0) {
        printf("|| Tamano: %s\n", P.key.tamano);
    }

    printf("|| Cantidad: %d\n", P.F.cant);
    printf("|| Precio unitario: $%d\n", P.F.pre);
    printf("|| TOTAL: $%d\n", P.F.total);
    printf("-----------------------------\n");

    fclose(binario);
    fclose(fac);
    return 1;
    
}
void consfact(producto Registro, int co){
    FILE *binario;
    binario = (fopen("datos.dat", "rb"));
    if (binario == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    FILE *fac; 
    factura F;
    fac = (fopen("facturas.dat", "rb"));
    if (fac == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    else {
        puts("****************************************");
       
        //lee el archivo de facturas
        while (fread(&F, sizeof(factura), 1, fac)>0) {
          
            //aqui se imprime el producto, o sea la factura
            printf("|| ID de la factura: %d\n", F.clave);
            printf("|| Producto: %s\n", F.clase);
            
            if (strcmp(F.clase, "Paleta") == 0) {
                printf("|| Sabor: %s\n", F.sabor);
                printf("|| Precio: %d\n", F.pre);
            }  
            else if (strcmp(F.clase, "Nieve") == 0) {
                printf("|| Sabor: %s\n", F.sabor);
                printf("|| Topping: %s\n", F.top);
                printf("|| Cono: %s\n", F.cono2);
                printf("|| Precio: %d\n", F.pre);
            }
            else if (strcmp(F.clase, "Agua") == 0) {
                printf("|| Sabor: %s\n", F.sabor);
                printf("|| Tamano: %s\n", F.tam);
                printf("|| Precio: %d\n", F.pre);
            }
            printf("|| Cantidad: %d\n", F.cant);
            printf("|| Precio unitario: $%d\n", F.pre);
            printf("|| Total: $%d\n", F.total);
            puts("****************************************");
            }
            
    }  
    fclose(fac);
    fclose(binario); 
}    


int cancelar(producto Registro, int co){
    //abres archivos
    FILE *fac, *temporal;
    factura F;
    int pos=0,facturab;
    
    if( (fac = fopen("facturas.dat","rb"))==NULL){
      printf("Error al abrir el archivo");
      return 0;
    }
     
    
    temporal=fopen("t.dat","wb");
    if (temporal == NULL) {
        printf("Error al crear el archivo temporal\n");
        fclose(fac);
        return 0;
       }
    
    
    //buscas la factura que quieras borrar
    printf("Ingresa el ID o clave de la factura que buscar para eliminar: \n ");
    scanf("%d",&facturab);

    while(fread(&F, sizeof(factura), 1, fac)>0){

    if(facturab != F.clave){
        fwrite(&F, sizeof(factura), 1, temporal); 
        
    }
    //aqui se encuentra la factura 
    else{
        pos=1;
        printf("Factura clave %d: eliminada exitosamente...\n", F.clave);
        }
    }        
    //cierro archivos
    fclose(fac);
    fclose(temporal);
    
    //si no se encontro el ticket o factura
    if(!pos)
       printf("No se encontro la factura \n");
    else {
         remove("facturas.dat");
         rename("t.dat", "facturas.dat"); 
         remove("t.dat");
         return 1;
        }
        
}