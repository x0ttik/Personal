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

// PENDIENTES 
// - DESVIACIONES

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
    //int contador = 0;
    //int tamanioArreglo = 0;

    for(int i = 0; i < n; i++){
        int contador = 0;
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
    
    printf(" \n -------------------- \n ");
    printf("\n ALPHA = %.4f\n", alpha);
    printf(" \n -------------------- \n ");

    return alpha;
}

//
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
        printf("Alpha exacto encontrado en tabla: %.4f\n", alpha); 
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

    // CALCULAR ALPHA UTILIZANDO INTEGRAL
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
        return 1;
    }

    double x;
    for(x = -4; x <= 4; x += 0.01){
        fprintf(fp, "%.4f %.6f \n", x, normal(x));
    }

    fclose(fp);
    printf("Datos guardados en (CurvaNormal.txt) para graficar \n");

    // Encontrar el valor de z a paratir de un valor de alpha
    alpha = 0;
    int primerNumero;

    printf("Ingrese el valor de alpha: \n");
    scanf("%lf", &alpha);

    alpha = encontrarAlpha(alpha);

    encontrarZ(alpha);

    return 0;
}