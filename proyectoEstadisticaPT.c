#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 100

// PENDIENTES 


// FUNCIONES

// Funcion para que el usuario introduzca un archivo existente
int leerArchivoNumeros(char* filename, float arreglo[], int *cantidad) {
    FILE *fptr;
    char linea[1000];
    *cantidad = 0;
    int suma = 0;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("No ha sido posible abrir el archivo %s\n", filename);
        return 0;
    }

    if (fgets(linea, sizeof(linea), fptr) != NULL) {
        size_t len = strlen(linea);
        if (linea[len - 1] == '\n')
            linea[len - 1] = '\0';

        char *token = strtok(linea, ",");
        while (token != NULL && *cantidad < MAX_NUMEROS) {
            float num = atof(token);  // atof para float
            arreglo[*cantidad] = num;
            (*cantidad)++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fptr);

    if (*cantidad == 0) {
        printf("No se encontraron números válidos.\n");
        return 0;
    }

    return 1;  // Éxito
}

// Funcion Ciclo Burbuja
void funcionCicloBurbuja(float arreglo[], int n){
    for (int i = 0; i < n - 1; i++) {
        // Últimos i elementos ya están en su lugar
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                float temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// Funcion para que el usuario ingrese los datos 
float funcionValoresManuales(float arreglo[], int n){
    float suma = 0;
    

    for (int i = 0; i < n; i++){
        printf("Ingrese el valor: \n");
        scanf("%f" , &arreglo[i]);

        suma = suma + arreglo[i];
    }

    printf("\n ---- Valores ingresados ---- \n");

    printf("\n");

    for ( int i = 0; i < n ; i++){
        printf(" %.2f - ", arreglo[i]);
    }

    printf(" \n -------------------- ");

    return suma;
}

// Funcion MODA
void funcionMODA(float arreglo[], int n){
    // Arreglo para guardar cantidad de veces de numero
    int arregloCantidad[100];
    int contador = 0;
    //int tamanioArreglo = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(arreglo[i] == arreglo[j]){
            contador++; 
            }
        } 
        arregloCantidad[i] = contador; 
    }

    // Buscar el índice del valor más frecuente (moda)
    int maxFrecuencia = 0;
    int indiceModa = 0;

    for (int i = 0; i < n; i++) {
        if (arregloCantidad[i] > maxFrecuencia) {
            maxFrecuencia = arregloCantidad[i];
            indiceModa = i;
        }
    }


    printf(" \n -------------------- \n ");    
    printf("La moda es: %.2f \n", arreglo[indiceModa]);
}

// Funcion MEDIA
float funcionMedia(float suma, int n){
    float media = 0;

    media = suma / n;

    return media;
}

// Funcion MEDIANA
void funcionMediana(float arreglo[], int n){
    float mediana = 0;
    int variableTemp = 0;
    
    funcionCicloBurbuja(arreglo, n); // Llamamos a la funcion para acomodar el arreglo

    if( n % 2 == 0){

        // n es par ya que no hay residuo 
        variableTemp = n / 2;
        // printf(" --- %f --- %f y %f --- ", arreglo[1], arreglo[variableTemp] , arreglo[variableTemp + 1]);
        mediana = ( arreglo[variableTemp ] + arreglo[variableTemp - 1] ) / 2;
        printf("\n Mediana: %.2f \n", mediana);
    }

    else{
        variableTemp = (n / 2); // Como es valor entero automaticamente se redonde a la posicion correcta
        mediana = arreglo[variableTemp];
        printf("Mediana: %.2f \n", mediana);
    }    
}

// Funcion MEDIA RECORTADA
void funcionMediaRecortada(float arreglo[], int n, float suma){
    float mediaRecortada = 0, mediaRecortadaOriginal = 0, porcentaje = 0;

        int opcion = 0;

        printf(" -------- MEDIA RECORTADA -------- \n");
        printf(" -------------------- \n ");

        printf("Desea agregar:\n");
        printf("Porcentaje ----- [1] \n");
        printf("Cantidad ------- [2] \n");
        scanf("%d", &opcion);

        switch (opcion){
            int recorte = 0;
    
        case 1: // Recorte por medio de porcentaje 
            printf("Ingrese el porcentaje a recortar: \n");
            scanf("%d", &recorte);
            printf(" -------------------- \n ");
    
            porcentaje = (float)recorte / 100;
    
            mediaRecortadaOriginal = n * porcentaje; 
    
            int nTemporal = 0;
            nTemporal = n - mediaRecortadaOriginal; // Creamos variable de nuevo (n = tamanio del arreglo - valores a recortar)
    
            // TEMPORAL // Ver que media recortada se imprima bien 
            printf(" \n n temporal: %d \n", nTemporal);
    
            mediaRecortada = mediaRecortadaOriginal / 2;
    
            // Ciclo para eliminar el recorte del inicio del arreglo original
            printf(" -------------------- \n ");
            for(int i = 0; i < mediaRecortada; i++){
                arreglo[i] = 0;
            }
            printf(" -------------------- \n ");
    
            // Ciclo para eliminar el recorte del final del arreglo original
            for(int i = n - mediaRecortada; i <  n; i++){
                arreglo[i] = 0;
            }
    
            suma = 0; 
            // Hacemos la suma del nuevo arreglo;
            for(int i = 0; i < n; i++){
                suma = suma + arreglo[i];
            }
    
            // TEMPORAL // Ver que suma se imprima bien 
            printf(" \n Suma: %.2f \n", suma);
            
    
            // Verificamos que se guarde correctamente el arreglo
            for(int i = 0; i < n; i++){
                printf("%.2f - ", arreglo[i]);
    
            }
            mediaRecortada = 0;
    
            mediaRecortada = suma / nTemporal;
    
    
            printf(" \n -------------------- \n ");
            printf("La media recortada a un %d porciento es: %.2f \n" , recorte, mediaRecortada);
            break;
        
        case 2: // Recorte por medio de cantidad
            printf("Ingrese la cantidad a recortar: \n");
            scanf("%d", &recorte);
    
            mediaRecortada = recorte / 2;
    
            nTemporal = 0;
            nTemporal = n - recorte; // Creamos variable de nuevo n (n = tamanio del arreglo - valores a recortar)
    
    
            // Ciclo para eliminar el recorte del inicio del arreglo original
            printf(" -------------------- \n ");
            for(int i = 0; i < mediaRecortada; i++){
                arreglo[i] = 0;
            }
            printf(" -------------------- \n ");
    
            // Ciclo para eliminar el recorte del final del arreglo original
            for(int i = n - mediaRecortada; i <  n; i++){
                arreglo[i] = 0;
            }
    
            suma = 0; 
            // Hacemos la suma del nuevo arreglo;
            for(int i = 0; i < n; i++){
                suma = suma + arreglo[i];
            }
    
            // TEMPORAL // Ver que suma se imprima bien 
            printf(" \n Suma: %.2f \n", suma);
            
    
            // Verificamos que se guarde correctamente el arreglo
            for(int i = 0; i < n; i++){
                printf("%.2f - ", arreglo[i]);
    
            }
            mediaRecortada = 0;
    
            mediaRecortada = suma / nTemporal;
    
            printf(" \n -------------------- \n ");
            printf("La media recortada a un %d porciento es: %.2f \n" , recorte, mediaRecortada);
            break;
    
        default:
            printf("Valor invalido \n");
        }
}

// Funcion varianza poblacional 
float funcionVarianzaPoblacional(float arreglo[], float media, int n, int *contador){
    *contador = 0;
    float o = 0, suma = 0;
    media = 0; 

    for(int i = 0; i < n; i++){ // Hacemos un ciclo para sumar el valor de xi - media y el resultado al cuadrado
        o = arreglo[i] - media;
        o = pow(o, 2);
        suma = o + suma;

        *contador = *contador + 2; // Un contador que nos indique cuantos calculos se realizaron
    }

    o = 0;

    o = suma / n;
    *contador = *contador + 1;

    return o;
}

// Funcion varianza muestral
float funcionVarianzaMuestral(float arreglo[], float media, int n , int *contador){
    *contador = 0;
    float suma = 0, s = 0; 

    for(int i = 0; i < n; i++){ // Hacemos un ciclo para sumar el valor de xi - media y el resultado al cuadrado
        s = arreglo[i] - media;
        s = pow(s, 2);
        suma = s + suma;
        (*contador) += 2; // Un contador que nos indique cuantos calculos se realizaron
    }

    s = 0;

    s = suma / (n - 1); // N - 1 ya que asi es la formula muestral
    (*contador) += 1;
    return s;
}

// FALTAN LAS DESVIACIONES, POR ESO EL VALOR ESTANDAR NO DABA CORRECTAMENTE
// DESVIACION 

// DESVIACION 

// Funcion error estandar
float funcionErrorEstandar(float s, int n){
    float errorEstandar;
    errorEstandar = s / sqrt(n);
    return errorEstandar;
}

// Funcion intervalo de confianza
    // temporal: IC = MEDIA +- Z (VALOR DE CONFIANZA) * EE 
void funcionIntervaloConfianza(float media, float errorEstandar){
    float z = 1.96;
    float intervaloConfianzaUno, intervaloConfianzaDos;

    intervaloConfianzaUno = media - (z * errorEstandar);
    intervaloConfianzaDos = media + (z * errorEstandar);

    printf(" -------------------- \n ");
    printf("INTERVALO DE CONFIANZA");
    printf(" \n -------------------- \n ");
    printf("[%.2f , %.2f] \n", intervaloConfianzaUno, intervaloConfianzaDos);
}

int main(){

    // Variables
    int opcion = 0;
    int n = 0;
    float suma = 0;
    float arreglo[MAX_NUMEROS];

    // Primero realizaremos una opcion al usuario para ver si quiere ingresar un archivo de texto o ingresar los valores manualmente
    
    printf("---- ¿QUE DESEA REALIZAR? ---- \n");
    printf("Ingresar archivo de texto ---- [1] \n");
    printf("Ingresar los valores manualmente ---- [2] \n");
    scanf("%d", &opcion);

    if (opcion == 1){ // Ingresar archivo de texto
        char nombreArchivo[100];
        printf("Ingrese el nombre del archivo:\n");
        scanf("%s", nombreArchivo);

        if (leerArchivoNumeros(nombreArchivo, arreglo, &n)) {
            suma = 0;
            printf("Números leídos: ");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", arreglo[i]);
                suma += arreglo[i];
            }
            printf("\n");
        } 

        else {
            printf("Error leyendo archivo.\n");
        }
    }

    else { // Ingresar valores manualmente 
        printf("Ingrese la cantidad de valores a ingresar: \n");
        scanf("%d" , &n);

        suma = funcionValoresManuales(arreglo, n); // Funcion para guardar los valores
    }

    // Ya guardamos los valores en un arreglo ahora si podemos sacar los valores estadisticos.

     funcionMODA(arreglo, n); // Funcion para obtener moda

        // Media 
        float media; 

        media = funcionMedia(suma, n);

        printf(" -------------------- ");
        printf("\n La media es: %.2f \n", media);
        printf(" -------------------- \n");

        // Mediana 
        funcionMediana(arreglo,n);
        printf(" -------------------- \n ");
        printf(" -------------------- \n ");

        // Media Recortada
        funcionMediaRecortada(arreglo, n, suma);

        // Varianza poblacional
        float o;
        int contador = 0;
        clock_t start, end; // Variable para guardar inicio y fin del tiempo
        double cpu_time_used; // Variable tiempo usado

        start = clock(); // Inicio de la medicion del tiempo
        o = funcionVarianzaPoblacional(arreglo, media, n, &contador);

        printf(" \n -------------------- \n ");
        printf("La varianza poblacional es: %.2f \n", o);
        printf(" -------------------- \n ");

        
        o = sqrt(o); // Desviacion poblacional 

        contador = contador + 1;

        end = clock(); // Fin de la medicion del tiempo 

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Se utiliza "Clocks per sec" y se multiplica por 1000 para saberlo en milisegundos 

        printf(" \n -------------------- \n ");
        printf("La desviacion poblacional es: %.2f \n", o);
        printf(" -------------------- \n ");
        printf("Para obtener la varianza y desviacion poblacional \n");
        printf("\n Se utilizaron un total de %d calculos y con un tiempo utilizado por el procesador de %.2lf milisegundos \n", contador, cpu_time_used);
        printf(" -------------------- \n ");

        // Varianza muestral 
        start = 0;
        end = 0; 
        cpu_time_used = 0; 
        float s = 0;; 
        
        start = clock(); // Inicio de la medicion del tiempo

        contador = 0;

        s = funcionVarianzaMuestral(arreglo, media, n , &contador);
        printf(" \n -------------------- \n ");
        printf("La varianza muestral es: %.2f \n", s);
        printf(" -------------------- \n ");
        

        s = sqrt(s); // DESVIACION MUESTRAL
        contador = contador + 1;

        end = clock(); // Fin de la medicion del tiempo 

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Se utiliza "Clocks per sec" y se multiplica por 1000 para saberlo en milisegundos 

        printf(" \n -------------------- \n ");
        printf("La desviacion muestral es: %.2f \n", s);
        printf(" -------------------- \n ");
        printf("Para obtener la varianza y desviacion muestral \n");
        printf("\n Se utilizaron un total de %d calculos y con un tiempo utilizado por el procesador de %.2lf milisegundos \n", contador, cpu_time_used);

        // ERROR E INTERVALO DE CONFIANZA 

    // Variables
    
    opcion = 0;
    media = 0;
    s = 0;
    n = 0;
    float arregloDos[100];
    float errorEstandar;
    float desviacion;
    float varianza;
    
    printf(" \n -------------------- \n ");
    printf(" \n ERROR E INTERVALO DE CONFIANZA \n ");
    printf(" \n -------------------- \n ");
    printf("¿Como le gustaria obtenerlos? \n");
    printf(" \n -------------------- \n ");
    printf("Datos manualmente ----- [1] \n");
    printf("Ingresar archivo existente ---- [2] \n");
    printf("Ingresar los valores estadisticos --- [3] \n");
    scanf("%d", &opcion);

    switch (opcion){
    case 1: // Se utilizan las funciones para obtener los datos necesarios, y despues la funcion del valor estandar.
        printf("Ingrese la cantidad de datos a ingresar: \n");
        scanf("%d", &n);
        suma = funcionValoresManuales(arregloDos, n);
        media = funcionMedia(suma, n);
        varianza = funcionVarianzaMuestral(arregloDos, media, n, &contador);
        // TEMPORAL, FALTA HACERLO EN FUNCION
        desviacion = sqrt(varianza); 
        errorEstandar = funcionErrorEstandar(desviacion, n);
        printf("\n El valor estandar es: %.2f \n", errorEstandar);
        break;

    case 2:
        // ARCHIVO EXISTENTE
    

    case 3:
    printf(" \n -------------------- \n ");
        printf("Ingrese la media: \n");
        scanf("%f", &media);
        printf("Ingrese la desviacion estandar: \n");
        scanf("%f", &s);
        printf("Ingrese la cantidad de datos a ingresar: \n");
        scanf("%d", &n);
        printf(" \n -------------------- \n ");

        // Error estandar
        errorEstandar = funcionErrorEstandar(s,n);

        printf("El valor estandar es: %.2f \n", errorEstandar);
        
    default:
        break;
    }

    // INTERVALO DE CONFIANZA
    funcionIntervaloConfianza(media, errorEstandar);
    return 0;
}