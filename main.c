#include <stdio.h>
#include <string.h>

// Función para verificar si el código del producto está en la lista de descuentos

int tieneDescuento(char* codigo) {
    char* listaDescuentos[] = {"8949899430", "7653512593", "9383867373", "88392904209"}; 
    int numDescuentos = sizeof(listaDescuentos) / sizeof(listaDescuentos[0]);
    for (int i = 0; i < numDescuentos; i++) {
        if (strcmp(codigo, listaDescuentos[i]) == 0) {
            return 1; // Tiene descuento
        }
    }
    
    return 0; // No tiene descuento
}


// Función para verificar si el producto es elegible para la rifa
int esElegibleParaRifa(char* codigoProducto, char* codigoAlmacen) {
    char* listaRifa[] = {"894985943020763", "165331255320221", "248386737320130", "183923092220561"};
    int numRifa = sizeof(listaRifa) / sizeof(listaRifa[0]);
    
    char codigoConcatenado[30];
    sprintf(codigoConcatenado, "%s%s", codigoProducto, codigoAlmacen);
    
    for (int i = 0; i < numRifa; i++) {
        if (strcmp(codigoConcatenado, listaRifa[i]) == 0) {
            return 1; // Es elegible para la rifa
        }
    }
    
    return 0; // No es elegible para la rifa
}

int main() {
    char codigoProducto[11];
    char codigoAlmacen[6];

    printf("Ingrese el código de barra del producto (10 dígitos): ");
    scanf("%s", codigoProducto);
    
    printf("Ingrese el código del almacén (debe comenzar con '20'): ");
    scanf("%s", codigoAlmacen);

    if (strlen(codigoProducto) != 10 || strlen(codigoAlmacen) != 5 || strncmp(codigoAlmacen, "20", 2) != 0) {
        printf("Error: Los códigos ingresados no son válidos.\n");
    } else {
        if (tieneDescuento(codigoProducto)) {
            printf("El producto tiene un descuento del 20 por ciento.\n");
        } else {
            printf("El producto no tiene descuento.\n");
        }

        if (esElegibleParaRifa(codigoProducto, codigoAlmacen)) {
            printf("El producto es elegible para la rifa del vehículo.\n");
        } else {
            printf("El producto no es elegible para la rifa del vehículo.\n");
        }
    }
    return 0;
}