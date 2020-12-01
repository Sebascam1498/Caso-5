//Sebastian Campos
//Buscar una W en una matriz de 0, falto implentacion solo esta la idea.
#include <vector>
#include <iostream>
#include <time.h>   


using namespace std;

//tamaño de la matriz


int resolver(std::vector<std::vector<int>> pMatriz){
    std::vector<std::vector<int>> matrizPivote{
        {0, 1, 1, 1, 0}, 
        {0, 1, 1, 1, 0}, 
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0}  
    };

    double dosCeros = 2/(double)13;
    double tresCeros = 3/(double)13;
    double cuatroCeros = 4/(double)13;
    double porSector0 = dosCeros;
    double porSector1 = porSector0+dosCeros;
    double porSector2 = porSector1+tresCeros;
    double porSector3 = porSector2+cuatroCeros;
    double porSector4 = porSector3+dosCeros;
    std::vector<double> porcetajesSector{0,porSector0,porSector1,porSector2,porSector3,porSector4};

    std::vector<double> proporcionPivote {dosCeros,dosCeros,tresCeros,cuatroCeros,dosCeros};

    //Conocer tamaño de la matriz
   int tamMatriz = pMatriz.size();
   int elemntosMatriz = tamMatriz*tamMatriz;
   //indice para verificar que encuentre ceros
   int indiceMax = 0;
   int vecesEncontro = 0;
   int MinX = 0;
   int MinY = 0;
   int MaxX = 0;
   int MaxY = 0;

   while (indiceMax<elemntosMatriz){
       //Buscar un cero en la matriz con un aleatorio en la matriz
       srand (time(NULL)+rand());
       int randomC = rand() % tamMatriz;
       int randomF = rand() % tamMatriz;
       
       cout<< randomC <<" ";
       cout<< randomF <<endl;
       std::vector<std::vector<int>> matrizW{{}};
       int matrizWsize = 0;
       int matrizWsizeMuestra = 0;
       int matrizWMin = 0;
       int porcentajeAciertoW = 0;
       int contCeroSector = 0;
       int elementosAMuestrar = 0;
       int contElementosAMuestrar = 0;
       int sectorActual =0;
       int randomCW =0;
       int randomFW =0;
       //si encuentro un cero ver si ver Max-yx  Min -yx.
       if (pMatriz[randomF][randomC]==0)
       {
           matrizW = encontrarExtremos();
           matrizWsize = matrizW.size();
           //10% de las muestras
           elementosAMuestrar = (matrizWsize*matrizWsize)*(float)0.1;
           matrizWsizeMuestra = (matrizWsize/(double)5);
           //Se hacen por sector dependiendo del tamaño se va a muestrar 10% de los elemntos y ver si hay probabilidad de W.
           while (sectorActual<5)
           {
               while (contElementosAMuestrar<elementosAMuestrar)
               {
                    //min + rand() % (( max + 1 ) - min)
                    srand (time(NULL)+rand());
                    //Genera un Random del sector
                    randomCW = matrizWMin + rand() % (( matrizWsizeMuestra + 1 ) - matrizWMin);
                    randomFW = matrizWMin + rand() % (( matrizWsizeMuestra + 1 ) - matrizWMin);
                    if (matrizW[randomCW][randomFW]==0)
                    {
                        contCeroSector++;
                    }
                    contElementosAMuestrar++;
               }
               if (porcetajesSector[i]<contCeroSector && contCeroSector<porcetajesSector[i+1])
               {
                   porcentajeAciertoW+=20;
               }
               
           }
           
           
       }
       

    }
    return porcentajeAciertoW;
}

//Encuentra las esquinas y dimenciones de los ceros posible W.y devuelve la matriz

std::vector<std::vector<int>> encontrarExtremos(std::vector<std::vector<int>> pMatriz,int pColumna,int pFila){

}

int main()
{

    
   

    return 0;

}