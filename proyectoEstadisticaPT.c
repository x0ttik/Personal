#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NUMEROS 100
#define PI 3.1416

    // MATRIZ DE TABLA Z
    double tablaZ[38][10] = {
        {0.5000, 0.5040, 0.5080, 0.5120, 0.5160, 0.5199, 0.5239, 0.5279, 0.5319, 0.5359},
        {0.5398, 0.5438, 0.5478, 0.5517, 0.5557, 0.5596, 0.5636, 0.5675, 0.5714, 0.5753},
        {0.5973, 0.5832, 0.5871, 0.5910, 0.5948, 0.5987, 0.6026, 0.6064, 0.6103, 0.6141},
        {0.6179, 0.6217, 0.6255, 0.6293, 0.6331, 0.6368, 0.6406, 0.6443, 0.6480, 0.6517},
        {0.6554, 0.6591, 0.6628, 0.6664, 0.6700, 0.6736, 0.6772, 0.6808, 0.6844, 0.6879},

        {0.6915, 0.6950, 0.6985, 0.7019, 0.7054, 0.7088, 0.7123, 0.7157, 0.7190, 0.7224},
        {0.7257, 0.7291, 0.7324, 0.7357, 0.7389, 0.7422, 0.7454, 0.7486, 0.7517, 0.7549},
        {0.7580, 0.7611, 0.7642, 0.7673, 0.7704, 0.7734, 0.7764, 0.7794, 0.7823, 0.7852},
        {0.7881, 0.7910, 0.7939, 0.7967, 0.7995, 0.8023, 0.8051, 0.8078, 0.8106, 0.8133},
        {0.8159, 0.8186, 0.8212, 0.8238, 0.8264, 0.8289, 0.8315, 0.8340, 0.8365, 0.8389},

        {0.8413, 0.8438, 0.8461, 0.8485, 0.8508, 0.8531, 0.8554, 0.8577, 0.8599, 0.8621},
        {0.8643, 0.8665, 0.8686, 0.8708, 0.8729, 0.8749, 0.8770, 0.8790, 0.8810, 0.8830},
        {0.8849, 0.8869, 0.8888, 0.8907, 0.8925, 0.8944, 0.8962, 0.8980, 0.8997, 0.9015},
        {0.9032, 0.9049, 0.9066, 0.9082, 0.9099, 0.9115, 0.9131, 0.9147, 0.9162, 0.9177},
        {0.9192, 0.9207, 0.9222, 0.9236, 0.9251, 0.9265, 0.9279, 0.9292, 0.9306, 0.9319},

        {0.9332, 0.9345, 0.9357, 0.9370, 0.9382, 0.9394, 0.9406, 0.9418, 0.9429, 0.9441},
        {0.9452, 0.9463, 0.9474, 0.9484, 0.9495, 0.9505, 0.9515, 0.9525, 0.9535, 0.9545},
        {0.9554, 0.9564, 0.9573, 0.9582, 0.9591, 0.9599, 0.9608, 0.9616, 0.9625, 0.9633},
        {0.9641, 0.9649, 0.9656, 0.9664, 0.9671, 0.9678, 0.9686, 0.9693, 0.9699, 0.9706},
        {0.9713, 0.9719, 0.9726, 0.9732, 0.9738, 0.9744, 0.9750, 0.9756, 0.9761, 0.9767},

        {0.9772, 0.9778, 0.9783, 0.9788, 0.9793, 0.9798, 0.9803, 0.9808, 0.9812, 0.9817},
        {0.9821, 0.9826, 0.9830, 0.9834, 0.9838, 0.9842, 0.9846, 0.9850, 0.9854, 0.9857},
        {0.9861, 0.9864, 0.9868, 0.9871, 0.9875, 0.9878, 0.9881, 0.9884, 0.9887, 0.9890},
        {0.9893, 0.9896, 0.9898, 0.9901, 0.9904, 0.9906, 0.9909, 0.9911, 0.9913, 0.9916},
        {0.9918, 0.9920, 0.9922, 0.9925, 0.9927, 0.9929, 0.9931, 0.9932, 0.9934, 0.9936},

        {0.9938, 0.9940, 0.9941, 0.9943, 0.9945, 0.9946, 0.9948, 0.9949, 0.9951, 0.9952},
        {0.9953, 0.9955, 0.9956, 0.9957, 0.9959, 0.9960, 0.9961, 0.9962, 0.9963, 0.9964},
        {0.9965, 0.9966, 0.9967, 0.9968, 0.9969, 0.9970, 0.9971, 0.9972, 0.9973, 0.9974},
        {0.9974, 0.9975, 0.9976, 0.9977, 0.9977, 0.9978, 0.9979, 0.9979, 0.9980, 0.9981},
        {0.9981, 0.9982, 0.9982, 0.9983, 0.9984, 0.9984, 0.9985, 0.9985, 0.9986, 0.9986},

        {0.9987, 0.9987, 0.9987, 0.9988, 0.9988, 0.9989, 0.9989, 0.9989, 0.9990, 0.9990},
        {0.9990, 0.9991, 0.9991, 0.9991, 0.9992, 0.9992, 0.9992, 0.9992, 0.9993, 0.9993},
        {0.9993, 0.9993, 0.9994, 0.9994, 0.9994, 0.9994, 0.9994, 0.9995, 0.9995, 0.9995},
        {0.9995, 0.9995, 0.9995, 0.9996, 0.9996, 0.9996, 0.9996, 0.9996, 0.9996, 0.9997},
        {0.9997, 0.9997, 0.9997, 0.9997, 0.9997, 0.9997, 0.9997, 0.9997, 0.9997, 0.9998},

        {0.9998, 0.9998, 0.9998, 0.9998, 0.9998, 0.9998, 0.9998, 0.9998, 0.9998, 0.9998},

        {0.99997, 0.99997, 0.99997, 0.99997, 0.99997, 0.99997, 0.99997, 0.99997, 0.99997, 0.99997},

        {0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997, 0.9999997}
        };

    // MATRIZ DE TABLA T
    double tablaT[30][7] = {
        {3.078,   6.314,   12.706,  31.821,  38.204,  50.923,  63.657},   // df = 1
        {1.886,   2.920,    4.303,   6.965,   7.650,   8.860,   9.925},   // df = 2
        {1.638,   2.353,    3.182,   4.541,   4.857,   5.392,   5.841},   // df = 3
        {1.533,   2.132,    2.776,   3.747,   3.961,   4.315,   4.604},   // df = 4
        {1.476,   2.015,    2.571,   3.365,   3.534,   3.810,   4.032},   // df = 5
        {1.440,   1.943,    2.447,   3.143,   3.288,   3.521,   3.707},   // df = 6
        {1.415,   1.895,    2.365,   2.998,   3.128,   3.335,   3.499},   // df = 7
        {1.397,   1.860,    2.306,   2.896,   3.016,   3.206,   3.355},   // df = 8
        {1.383,   1.833,    2.262,   2.821,   2.934,   3.111,   3.250},   // df = 9
        {1.372,   1.812,    2.228,   2.764,   2.870,   3.038,   3.169},   // df = 10
        {1.363,   1.796,    2.201,   2.718,   2.820,   2.891,   3.106},   // df = 11
        {1.356,   1.782,    2.179,   2.681,   2.780,   2.934,   3.055},   // df = 12
        {1.350,   1.771,    2.160,   2.650,   2.746,   2.896,   3.012},   // df = 13
        {1.345,   1.761,    2.145,   2.624,   2.718,   2.864,   2.977},   // df = 14
        {1.341,   1.753,    2.131,   2.602,   2.694,   2.837,   2.947},   // df = 15
        {1.337,   1.746,    2.120,   2.583,   2.673,   2.813,   2.921},   // df = 16
        {1.333,   1.740,    2.110,   2.567,   2.655,   2.793,   2.898},   // df = 17
        {1.330,   1.734,    2.101,   2.552,   2.639,   2.775,   2.878},   // df = 18
        {1.328,   1.729,    2.093,   2.539,   2.625,   2.759,   2.861},   // df = 19
        {1.325,   1.725,    2.086,   2.528,   2.613,   2.744,   2.845},   // df = 20
        {1.323,   1.721,    2.080,   2.518,   2.602,   2.732,   2.831},   // df = 21
        {1.321,   1.717,    2.074,   2.508,   2.591,   2.720,   2.819},   // df = 22
        {1.319,   1.714,    2.069,   2.500,   2.582,   2.710,   2.807},   // df = 23
        {1.318,   1.711,    2.064,   2.492,   2.574,   2.700,   2.797},   // df = 24
        {1.316,   1.708,    2.060,   2.485,   2.566,   2.692,   2.787},   // df = 25
        {1.315,   1.706,    2.056,   2.479,   2.559,   2.684,   2.779},   // df = 26
        {1.314,   1.703,    2.052,   2.473,   2.553,   2.676,   2.771},   // df = 27
        {1.313,   1.701,    2.048,   2.467,   2.547,   2.669,   2.763},   // df = 28
        {1.311,   1.699,    2.045,   2.462,   2.541,   2.663,   2.756},   // df = 29
        {1.282,   1.645,    1.960,   2.326,   2.394,   2.498,   2.576}    // df = infinito
    };

// PENDIENTES 
// - DESVIACIONES

// FUNCIONES

// Función para generar tallo y hoja para gráfico de barras
void generar_tallo_hoja_barras(float *arreglo, int n, const char *filename, int modo_tallo, int modo_hoja) {
    int conteo[100] = {0}; // hasta 100 tallos distintos (ajustable)

    for (int i = 0; i < n; i++) {
        int entero = (int)arreglo[i];
        int tallo, hoja;

        // Tallo
        if (modo_tallo == 1)      // Decenas
            tallo = entero / 10;
        else                      // Unidades
            tallo = entero % 10;

        // Hoja (no se usa para el gráfico de barras, pero puedes usarlo si quieres mostrar hojas exactas)
        if (modo_hoja == 1)       // Unidades
            hoja = entero % 10;
        else                      // Decimales
            hoja = (int)(fabs(arreglo[i] * 10)) % 10;

        conteo[tallo]++;
    }

    // Escribir archivo de datos para gnuplot
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("No se pudo crear el archivo");
        return;
    }

    for (int i = 0; i < 100; i++) {
        if (conteo[i] > 0) {
            fprintf(fp, "%d %d\n", i, conteo[i]);
        }
    }

    fclose(fp);
}

void graficar_tallo_hoja_gnuplot() {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Grafico de Tallo y Hoja (Simulado)'\n");
        fprintf(gnuplot, "set xlabel 'Frecuencia (Cantidad de hojas)'\n");
        fprintf(gnuplot, "set ylabel 'Tallo'\n");
        fprintf(gnuplot, "set style data histograms\n");
        fprintf(gnuplot, "set style fill solid 1.0 border -1\n");
        fprintf(gnuplot, "set boxwidth 0.9\n");
        fprintf(gnuplot, "set ytics rotate by 0\n");
        fprintf(gnuplot, "plot 'tallo_hoja.dat' using 2:xtic(1) title 'Hojas por Tallo' lc rgb 'orange'\n");
        pclose(gnuplot);
    }
}

void generar_puntos(float *arreglo, int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error al abrir puntos.dat");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[i]) {
                float temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%.2f 0\n", arreglo[i]);
    }

    fclose(fp);
}

void graficar_puntos_gnuplot() {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Grafica de puntos'\n");
        fprintf(gnuplot, "set xlabel 'Valor'\n");
        fprintf(gnuplot, "set ylabel 'Frecuencia (y=0)'\n");
        fprintf(gnuplot, "plot 'puntos.dat' using 1:2 with points pt 7 lc rgb 'blue' notitle\n");
        pclose(gnuplot);
    }
}

void histograma(float *arreglo, int n, int clases, const char *filename) {
    float min = arreglo[0], max = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] < min) min = arreglo[i];
        if (arreglo[i] > max) max = arreglo[i];
    }

    float rango = max - min + 1;
    float ancho = rango / clases;

    int *frecuencias = calloc(clases, sizeof(int));
    if (!frecuencias) {
        perror("Error al reservar memoria");
        return;
    }

    for (int i = 0; i < n; i++) {
        int clase = (int)((arreglo[i] - min) / ancho);
        if (clase >= clases) clase = clases - 1;
        frecuencias[clase]++;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error al abrir histograma.dat");
        free(frecuencias);
        return;
    }

    for (int i = 0; i < clases; i++) {
        float inicio = min + i * ancho;
        fprintf(fp, "%.2f %d\n", inicio, frecuencias[i]);
    }

    fclose(fp);
    free(frecuencias);
}

void graficar_histograma_gnuplot() {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Histograma'\n");
        fprintf(gnuplot, "set style data histograms\n");
        fprintf(gnuplot, "set style fill solid 1.0 border -1\n");
        fprintf(gnuplot, "set boxwidth 0.9\n");
        fprintf(gnuplot, "set xlabel 'Intervalos'\n");
        fprintf(gnuplot, "set ylabel 'Frecuencia'\n");
        fprintf(gnuplot, "plot 'histograma.dat' using 2:xtic(1) title 'Frecuencia' lc rgb 'green'\n");
        pclose(gnuplot);
    }
}







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
            while (*token == ' ') token++;
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
        printf("\n Ingrese el valor: \n");
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

void funcionMODA(float arreglo[], int n) {
    int arregloCantidad[100];

    // Contar frecuencia de cada valor
    for (int i = 0; i < n; i++) {
        int contador = 0;
        for (int j = 0; j < n; j++) {
            if (arreglo[i] == arreglo[j]) {
                contador++;
            }
        }
        arregloCantidad[i] = contador;
    }

    // Obtener la frecuencia máxima
    int maxFrecuencia = 0;
    for (int i = 0; i < n; i++) {
        if (arregloCantidad[i] > maxFrecuencia) {
            maxFrecuencia = arregloCantidad[i];
        }
    }

    // Verificar si todos tienen la misma frecuencia
    int mismaFrecuencia = 1;
    for (int i = 1; i < n; i++) {
        if (arregloCantidad[i] != arregloCantidad[0]) {
            mismaFrecuencia = 0;
            break;
        }
    }

    printf("\n--------------------\n");
    if (mismaFrecuencia || maxFrecuencia == 1) {
        printf("No hay moda, todos los valores tienen la misma frecuencia.\n");
    } else {
        printf("Moda(s): ");
        for (int i = 0; i < n; i++) {
            if (arregloCantidad[i] == maxFrecuencia) {
                int yaImpresa = 0;
                for (int j = 0; j < i; j++) {
                    if (arreglo[j] == arreglo[i]) {
                        yaImpresa = 1;
                        break;
                    }
                }
                if (!yaImpresa) {
                    printf("%.2f ", arreglo[i]);
                }
            }
        }
        printf("\n");
    }
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
float funcionVarianzaPoblacional(float arreglo[], float media, int n, int *contador) {
    *contador = 0;
    float suma = 0;
    float diferencia = 0;

    for (int i = 0; i < n; i++) {
        diferencia = arreglo[i] - media;
        suma += pow(diferencia, 2);
        *contador += 2; // resta y potencia
    }

    float varianza = suma / n;
    *contador += 1; // división

    return varianza;
}


// Funcion varianza muestral
float funcionVarianzaMuestral(float arreglo[], float media, int n, int *contador) {
    *contador = 0;
    float suma = 0;
    float diferencia = 0;

    for (int i = 0; i < n; i++) {
        diferencia = arreglo[i] - media;
        suma += pow(diferencia, 2);
        *contador += 2; // resta y potencia
    }

    float varianza = suma / (n - 1); // muestral usa n - 1
    *contador += 1; // división

    return varianza;
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

double normal(double x){
    double normal = 0;

    normal = exp(-0.5 * x * x) / sqrt(2 * PI);

    return normal;
}

double funcionIntegralTrapecio(double a, double b, int n){
    double h;
    double sumaDoble;

    h = (b - a) / n;
    sumaDoble = 0.5 * (normal(a) + normal(b));

    for(int i = 1; i < n; i++){
        sumaDoble += normal(a + i * h);
    }

    sumaDoble = sumaDoble * h;

    return sumaDoble;
}

double encontrarAlpha(double alpha){
    alpha = alpha / 2;
    alpha = 1 - alpha;

    return alpha;
}


void encontrarZ(double alpha) {
    int filaExacta = -1, colExacta = -1, filaInferior = -1, colInferior = -1, filaSuperior = -1, colSuperior = -1; // Se inicializan en -1 para que no haya confusion si no se encuentra nada
    int encontrado = 0; // Sirve para saber si se encontro algo (0 = no, 1 = si, codigo binario)
    double valor, z, zMenor, zMayor, zPromedio;
    

    for (int i = 0; i < 38; i++) {
        for (int j = 0; j < 10; j++) {
            valor = tablaZ[i][j]; // Usamos valor como un comodin

            if (valor == alpha) { // Si esta , se guarda la fila y columna donde se encuentra.
                filaExacta = i;
                colExacta = j;
                encontrado = 1;
                break;
            }

             // Si no esta exacta se buscan los valores aproximados
            if (valor < alpha) {
                if (filaInferior == -1 || valor > tablaZ[filaInferior][colInferior]) { // Si aun no guardamos ningun valor menor a alpha, o si valor es mayor que el que ya teniamos pero menor a alpha continua
                    filaInferior = i;
                    colInferior = j;
                }
            } else if (valor > alpha) { // Si aun no guardamos ningun valor mayor a alpha, o si el valor mayor nuevo es mas cercano a alpha que el valor mayor que teniamos continua
                if (filaSuperior == -1 || valor < tablaZ[filaSuperior][colSuperior]) {
                    filaSuperior = i;
                    colSuperior = j;
                }
            }
        }
        if (encontrado) break;
    }

    

    if (encontrado) { // Solo si es exacta sera verdadero 
        z = filaExacta * 0.10 + colExacta * 0.01;
        printf("Alpha exacto encontrado en tabla: %.4f \n", alpha); 
        printf("Z correspondiente: %.3f\n", z);

    } else if (filaInferior != -1 && filaSuperior != -1) { // Promedio entre los Z de los valores justo inferior y superior
        zMenor = filaInferior * 0.10 + colInferior * 0.01;
        zMayor = filaSuperior * 0.10 + colSuperior * 0.01;
        zPromedio = (zMenor + zMayor) / 2.0; //

        printf("Alpha %.4f no exacto, está entre %.4f y %.4f\n", alpha, tablaZ[filaInferior][colInferior], tablaZ[filaSuperior][colSuperior]);

        printf("Z aproximado (promedio): %.5f\n", zPromedio);
    } else {
        printf("Alpha %.4f está fuera del rango de la tabla.\n", alpha);
    }
}

double encontrarAlphaDesdeZ(double z) {
    int filaInferior = -1, colInferior = -1;
    int filaSuperior = -1, colSuperior = -1;

    double zActual;

    // Buscar z exacto o valores cercanos
    for (int i = 0; i < 38; i++) {
        for (int j = 0; j < 10; j++) {
            zActual = i * 0.10 + j * 0.01;

            if (zActual == z) {
                // Z exacto encontrado
                return tablaZ[i][j];
            }

            if (zActual < z) {
                if (filaInferior == -1 || zActual > (filaInferior * 0.10 + colInferior * 0.01)) {
                    filaInferior = i;
                    colInferior = j;
                }
            } else if (zActual > z) {
                if (filaSuperior == -1 || zActual < (filaSuperior * 0.10 + colSuperior * 0.01)) {
                    filaSuperior = i;
                    colSuperior = j;
                }
            }
        }
    }

    // Si podemos interpolar
    if (filaInferior != -1 && filaSuperior != -1) {
        double zInferior = filaInferior * 0.10 + colInferior * 0.01;
        double zSuperior = filaSuperior * 0.10 + colSuperior * 0.01;

        double alphaInferior = tablaZ[filaInferior][colInferior];
        double alphaSuperior = tablaZ[filaSuperior][colSuperior];

        // Interpolación lineal de alpha
        double alphaInterpolado = alphaInferior + (z - zInferior) * (alphaSuperior - alphaInferior) / (zSuperior - zInferior);

        return alphaInterpolado;
    }

    // Si z está fuera de rango
    return -1.0; // Indicar error o fuera de rango
}

// Funcion para encontrar t dado los grados de confianza y alpha
float encontrarT(double t){
    int gradoDeLibertad, alpha;
    
    printf("Ingrese los grados de libertad: \n ");
    scanf("%d", &gradoDeLibertad);
    printf("Valor de alpha: \n");
    printf("Alpha = 0.10 ----- [1] \n");
    printf("Alpha = 0.05 ----- [2]\n");
    printf("Alpha = 0.025 ----- [3]\n");
    printf("Alpha = 0.01 ----- [4]\n");
    printf("Alpha = 0.00833 ----- [5] \n");
    printf("Alpha = 0.00625 ----- [6] \n");
    printf("Alpha = 0.005 ----- [7] \n");
    scanf("%d", &alpha);

    float valor = 0;
    switch (alpha)
    {
    case 1:
        valor = 0.10;
        break;
    
    case 2:
        valor = 0.05;
        break;

    case 3:
        valor = 0.025;
        break;

    case 4:
        valor = 0.01;
        break;

    case 5:
        valor = 0.00833;
        break;

    case 6:
        valor = 0.00625;
        break;
    
    case 7:
        valor = 0.005;
        break;
    }
    

    printf("\n Grados de libertad: %d", gradoDeLibertad);
    printf("\n Valor de alpha: %.5f \n", valor);

    t = tablaT[gradoDeLibertad - 1][alpha - 1];

    return t;
}

// Funcion para encontrar los grados de confianza y alpha dado t
void encontrarConT(double t){
    int gradosDeConfianza;
    double alpha;
    double valoresAlpha[7] = {0.10, 0.05, 0.025, 0.01, 0.00833, 0.00625, 0.005};

    for(int i = 0; i <30; i++){
        for(int j = 0; j < 7; j++){
            if (fabs(t - tablaT[i][j]) < 0.0001){
                gradosDeConfianza = i;
                alpha = valoresAlpha[j];
                printf("Grado de confianza: %d \n", gradosDeConfianza);
                printf("Alpha: %.5lf \n", alpha);
                printf(" -------------------- \n ");
                return;
            }
        }
    }
}

// Cálculo conjunto de Sxx y Sxy
void calcularSxxSxy(float x[], float y[], float media_x, float media_y, int n, float *Sxx, float *Sxy) {
    *Sxx = 0.0;
    *Sxy = 0.0;
    for (int i = 0; i < n; i++) {
        float dx = x[i] - media_x;
        float dy = y[i] - media_y;
        *Sxx += dx * dx;
        *Sxy += dx * dy;
    }
}

// Función principal de regresión lineal
void regresionLineal(float x[], float y[], int n) {
    float suma_x = funcionValoresManuales(x, n);
    float suma_y = funcionValoresManuales(y, n);

    float media_x = funcionMedia(suma_x, n);
    float media_y = funcionMedia(suma_y, n);

    float Sxx, Sxy;
    calcularSxxSxy(x, y, media_x, media_y, n, &Sxx, &Sxy);

    float b = Sxy / Sxx;
    float a = media_y - b * media_x;

    printf("\n La ecuacion de la recta es: y = %.4f + %.4fx\n", a, b);
    printf("\n");
}

int main(){

    // Variables
    int opcionUno = 0;
    int modo_tallo;
    int modo_hoja;
    
    do{
        // MENU PARA SABER QUE SE DESEA HACER
        printf("\n Que desea realizar \n");
        printf("Graficar ----- [1] \n");
        printf("Estadisticos --- [2] \n");
        printf("Calcular alpha utilizando la integral --- [3] \n");
        printf("Encontrar z con el valor de alpha ---- [4]\n");
        printf("Encontrar alpha con el valor de z ---- [5] \n");
        printf("Encontrar t con los grados de libertad y alpha ---- [6] \n");
        printf("Encontrar los grados de libertad y alpha dado t --- [7]\n");
        printf("Regresion Lineal --- [8]\n");
        printf("Salir ------ [9] \n");
        scanf("%d", &opcionUno);

        int opcion = opcionUno;
        int n = 0;
        float suma = 0;
        float arreglo[MAX_NUMEROS];
        n = sizeof(arreglo) / sizeof(arreglo[0]);
        
        switch (opcion) {
        case 1: // Graficar
            printf("\n ---- QUE DESEA REALIZAR? ---- \n");
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

            int opcion;

            printf("\n Que grafico desea realizar: \n");
            printf("Tallo y hojas ---- [1] \n");
            printf("Grafica de puntos ---- [2] \n");
            printf("Histograma ---- [3] \n");
            scanf("%d", &opcion);

            switch (opcion){
            case 1:
                //int n = sizeof(arreglo) / sizeof(arreglo[0]);

                printf("=== Configuración de Tallo y Hoja ===\n");
                printf("Seleccione cómo desea calcular el tallo:\n");
                printf("1. Decenas \n");
                printf("2. Unidades \n");
                printf("Opción: ");
                scanf("%d", &modo_tallo);

                printf("\nSeleccione cómo desea calcular la hoja:\n");
                printf("1. Unidades \n");
                printf("2. Decimales \n");
                printf("Opción: ");
                scanf("%d", &modo_hoja);

                // Validar
                if (modo_tallo < 1 || modo_tallo > 2 || modo_hoja < 1 || modo_hoja > 2) {
                    printf("Opciones inválidas. Intenta nuevamente.\n");
                    break;
                }

                generar_tallo_hoja_barras(arreglo, n, "tallo_hoja.dat", modo_tallo, modo_hoja);
                graficar_tallo_hoja_gnuplot();
                break;
            
            case 2:
                generar_puntos(arreglo, n, "puntos.dat");
                graficar_puntos_gnuplot();
                break;
            
            case 3:{
                int clases;
                printf("\nIngrese el número de clases para el histograma: ");
                scanf("%d", &clases);

                histograma(arreglo, n, clases, "histograma.dat");
                graficar_histograma_gnuplot();
                break;
            }
            default:
                break;
            }

            break;
        
        // Todos los estadisticos (MODA, MEDIA, MEDIANA, MEDIA RECORTADA, VARIANZA Y DESVIACION)
        case 2: 
        // Primero realizaremos una opcion al usuario para ver si quiere ingresar un archivo de texto o ingresar los valores manualmente
            printf("\n ---- QUE DESEA REALIZAR? ---- \n");
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

            float arregloDos[100];
            for (int i = 0; i < 100; i++) {
                arregloDos[i] = arreglo[i];
            }
            // Media Recortada
            funcionMediaRecortada(arregloDos, n, suma);

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
            float s = 0;
            
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
            
                for (int i = 0; i < 10; i++) {
                    arregloDos[i] = 0;
                }

                float errorEstandar;
                float desviacion;
                float varianza;
                
                printf(" \n -------------------- \n ");
                printf(" \n ERROR E INTERVALO DE CONFIANZA \n ");
                printf(" \n -------------------- \n ");
                printf("Como le gustaria obtenerlos? \n");
                printf(" \n -------------------- \n ");
                printf("Datos manualmente ----- [1] \n");
                printf("Ingresar archivo existente ---- [2] \n");
                printf("Ingresar los valores estadisticos --- [3] \n");
                printf("Sin error estandar e intervalo de confianza --- [4] \n");
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
                    
                    // INTERVALO DE CONFIANZA
                    funcionIntervaloConfianza(media, errorEstandar);
                    break;
                case 4: 
                    break;
                }
                break;

        // CALCULAR ALPHA UTILIZANDO INTEGRAL
        case 3: { 
            double z, alpha;
            n = 100000;

            printf(" \n -------------------- \n ");
            printf("Ingrese el valor de Z: \n");
            scanf("%lf", &z);

            alpha = funcionIntegralTrapecio(-10, z , n);

            printf("El valor de alpha para z = %.2f es: %.4f \n", z, alpha);

            // Exportar datos para graficar
            FILE *fp = fopen("CurvaNormal.txt", "w");
            if (fp == NULL){
                printf("Error al crear archivo de datos \n");
                break;
            }

            double x;
            for(x = -4; x <= 4; x += 0.01){
                fprintf(fp, "%.4f %.6f \n", x, normal(x));
            }

            fclose(fp);
            printf("Datos guardados en (CurvaNormal.txt) para graficar \n");
            break;
        }

        // Encontrar z dado un valor alpha 
        case 4: {
            double alpha = 0;

            printf("Ingrese el valor de alpha: \n");
            scanf("%lf", &alpha);

            alpha = encontrarAlpha(alpha);
            encontrarZ(alpha); 
            break;
        }

        // Encontrar alpha dado un valor z
        case 5: {
            double z, alpha;
            printf("Ingrese el valor de z: \n");
            scanf("%lf", &z);

            alpha = encontrarAlphaDesdeZ(z);

            if (alpha >= 0) {
                printf("Z: %lf\n", z);
                printf("Alpha = %lf\n", alpha);
            }

            break;
        }

        // Encontrar T dado los grados de libertad y alpha
        case 6: { 
            float t;

            t = encontrarT(t);
            
            printf(" \n -------------------- \n ");
            printf("El valor de t es: %.3f \n", t);
        }

        // Encontrar los grados de libertad y alpha dado T
        case 7:{
            float t = 0;

            printf("Ingrese el valor de t: \n");
            scanf("%f", &t);

            printf(" \n -------------------- \n ");
            printf("Valor de t: %f", t);
            printf(" \n -------------------- \n ");


            encontrarConT(t);
            break;   
        }

        // Regresion lineal 
        case 8: { 

            opcion = 0;

            printf("--- Regresion Lineal --- \n ");
            printf("Desea: \n");
            printf("Agregar archivo de texto ----- [1] \n");
            printf("Agregar manualmente ----- [2] \n");
            scanf("%d", &opcion);

            switch (opcion) {
            case 1: { // Archivo existente
                break;
            }    

            case 2: { // Valores manualmente
                n = 0;
                float sumaUno, sumaDos;

                printf("Cuantos valores desea ingresar: \n");
                scanf("%d", &n);
                // Reiniciamos ambos arreglos
                for(int i = 0; i < 100; i++){
                    arreglo[i] = 0.0;
                }
                
                for(int i = 0; i < 100; i++){
                    arregloDos[i] = 0.0;
                }
                
                regresionLineal(arreglo, arregloDos, n);
                break;
            }
            default:
                break;
            }

            break;
        }

        }
    } while (opcionUno != 9);
    
    return 0;    
}
