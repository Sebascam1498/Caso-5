//Sebastian Campos
//Caso #5 -2 ver considencias entre 2 textos
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include "GrpPalabras.cpp"
#include <fstream>   
#include <sstream> 
#include <tuple> 


using namespace std;


std::vector<std::string> QuitarArticulos(std::vector<std::string> Texto){
    for (int i = 0; i < Texto.size(); i++)
    {
        if ((Texto[i].compare("a"))==0 || (Texto[i].compare("el")==0) || (Texto[i].compare("un")==0)
         || (Texto[i].compare("an")==0) || (Texto[i].compare("los")==0) || (Texto[i].compare("unos")==0)
         || (Texto[i].compare("the")==0) || (Texto[i].compare("unas")==0))
        {
            Texto.erase( Texto.begin() + i );
            i--;
        }
        
    }
    
    return Texto;

}
std::vector<std::string> ParserText(std::string Texto){
    std::vector<std::string> textParseado{};
    std::string bufferTexto = "";
    int largoString = Texto.length();
    int i = 0;
    while (i < largoString)
    {   
        if ((Texto.at(i) == *" ") || (Texto.at(i) == *".") || (Texto.at(i) == *",") || (Texto.at(i) == *":") ||
         (Texto.at(i) == *"\n") || (Texto.at(i) == *";") || (Texto.at(i) == *"\"") || (Texto.at(i) == *"-") 
         || (Texto.at(i) == *"(") || (Texto.at(i) == *")") || (Texto.at(i) == *"'") || (Texto.at(i) == *"!") || (Texto.at(i) == *"?"))
        {   
            if (i == (largoString-1)){
                textParseado.push_back(bufferTexto);
                textParseado = QuitarArticulos(textParseado);
                return textParseado;
            }
            
            while ((Texto.at(i) == *" ") || (Texto.at(i) == *".") || (Texto.at(i) == *",") || (Texto.at(i) == *":") ||
         (Texto.at(i) == *"\n") || (Texto.at(i) == *";") || (Texto.at(i) == *"\"") || (Texto.at(i) == *"-") 
         || (Texto.at(i) == *"(") || (Texto.at(i) == *")") || (Texto.at(i) == *"'") || (Texto.at(i) == *"!") || (Texto.at(i) == *"?"))
            {
                i++;
                if (i == (largoString-1)){
                textParseado.push_back(bufferTexto);
                textParseado = QuitarArticulos(textParseado);
                return textParseado;
            }
            }
            
            textParseado.push_back(bufferTexto);
            bufferTexto = "";
        }
        bufferTexto+= Texto[i];
        i++;
    }
}

std::tuple<GrpPalabras*,int> radomPalabras(std::vector<std::string> Texto,std::string textoOrigen){

    std::tuple<GrpPalabras*, int> tupleRespuesta{};

    bool flag = true;
    int iteradorRandom = 0;
    int cantidadPalabras = 0;
    int indice = 0;
    int VerVar = Texto.size();
    std::vector<std::string> vectorPalabras={};

    while (flag==true)
    {
        //Random de la cantidad de palabras en el vector
        srand (time(NULL)+rand());
        cantidadPalabras = 2+rand() % 4;
        iteradorRandom = rand() % Texto.size();
        if ((cantidadPalabras+iteradorRandom)<=Texto.size())
        {
            while (indice<cantidadPalabras)
            {
                vectorPalabras.push_back(Texto[iteradorRandom]);
                iteradorRandom++;
                indice++;
            }
            flag = false;
        }
    }
    GrpPalabras* palabra1 = new GrpPalabras("textoOrigen",cantidadPalabras,vectorPalabras);
    tupleRespuesta = make_tuple(palabra1,cantidadPalabras);
    return tupleRespuesta;
    
    



}

int comparadorVectores(std::vector<std::string> pTexto1,std::vector<std::string> pTexto2){
    int contadorVect1 = 0;

    
    while (contadorVect1<pTexto1.size())
    {
        if(pTexto1[contadorVect1]!=pTexto2[contadorVect1]){
            return 0;
        }
        contadorVect1++;

    }
    return 1;
    
}

int Texto1yTexto2(){

    std::vector<std::string> indiceVector{};
	int indice;

    std::ifstream inFile;
    inFile.open("Texto1.txt");

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string textoLeido = buffer.str();

    std::ifstream inFile2;
    inFile2.open("Texto2.txt");

    std::stringstream buffer2;
    buffer2 << inFile2.rdbuf();
    std::string textoLeido2 = buffer2.str();

    std::vector<std::string> vectorPalabras1 = ParserText(textoLeido);
    std::vector<std::string> vectorPalabras2 = ParserText(textoLeido2);
    int contadorTexto1 =(vectorPalabras1.size())*(0.5);
    int contadorTexto2 =(vectorPalabras2.size())*(0.5);
    int indice10P =0;
    int aux=0;
    int iguales2Pala = 0;
    int iguales3Pala = 0;
    int iguales4Pala = 0;
    int iguales5Pala = 0;
    GrpPalabras* auxPalabra;
    //texto1 muestreo y separado por cantidad de palabras.
    std::vector<std::vector<std::string>> cant2Pa {};
    std::vector<std::vector<std::string>> cant3Pa {};
    std::vector<std::vector<std::string>> cant4Pa {};
    std::vector<std::vector<std::string>> cant5Pa {};
    //texto2 muestreo y separado por cantidad de palabras.
    std::vector<std::vector<std::string>> cant2PaTx2 {};
    std::vector<std::vector<std::string>> cant3PaTx2 {};
    std::vector<std::vector<std::string>> cant4PaTx2 {};
    std::vector<std::vector<std::string>> cant5PaTx2 {};

    std::tuple<GrpPalabras*, int> tupleRandom{};
    while (indice10P<contadorTexto1)
    {
        tupleRandom = radomPalabras(vectorPalabras1,"texto1");
        aux = std::get<1>(tupleRandom);
        auxPalabra = std::get<0>(tupleRandom);

        if (aux==2)
        {
            cant2Pa.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==3)
        {
            cant3Pa.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==4)
        {
            cant4Pa.push_back(auxPalabra->grupoPalabras);
        }

         if (aux==5)
        {
            cant5Pa.push_back(auxPalabra->grupoPalabras);
        }
        indice10P++;
    }
    indice10P=0;
    while (indice10P<contadorTexto2)
    {
        tupleRandom = radomPalabras(vectorPalabras2,"texto2");
        aux = std::get<1>(tupleRandom);
        auxPalabra = std::get<0>(tupleRandom);

        if (aux==2)
        {
            cant2PaTx2.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==3)
        {
            cant3PaTx2.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==4)
        {
            cant4PaTx2.push_back(auxPalabra->grupoPalabras);
        }

         if (aux==5)
        {
            cant5PaTx2.push_back(auxPalabra->grupoPalabras);
        }
        indice10P++;
    }
    

    int contV1 = 0;
    int contV2 = 0;
    int iguales2P =0;
    int iguales3P =0;
    int iguales4P =0;
    int iguales5P =0;
    double porcentajeIgual = 0;
    while (contV1<cant2Pa.size())
    {
        while (contV2<cant2PaTx2.size())
        {
            iguales2P+=comparadorVectores(cant2Pa[contV1],cant2PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }

    contV1 = 0;
    contV2 = 0;
    while (contV1<cant3Pa.size())
    {
        while (contV2<cant3PaTx2.size())
        {
            iguales3P+=comparadorVectores(cant3Pa[contV1],cant3PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    contV1 = 0;
    contV2 = 0;
    while (contV1<cant4Pa.size())
    {
        while (contV2<cant4PaTx2.size())
        {
            iguales4P+=comparadorVectores(cant4Pa[contV1],cant4PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    contV1 = 0;
    contV2 = 0;
    while (contV1<cant5Pa.size())
    {
        while (contV2<cant5PaTx2.size())
        {
            iguales5P+=comparadorVectores(cant5Pa[contV1],cant5PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    porcentajeIgual+= iguales2P*(double)2.5;
    porcentajeIgual+= iguales3P*(double)5;
    porcentajeIgual+= iguales4P*(double)10;
    porcentajeIgual+= iguales5P*(double)20;
    //cout<<porcentajeIgual<<endl;
    
    

    return porcentajeIgual;

}

int Texto1yTexto3(){

    std::vector<std::string> indiceVector{};
	int indice;

    std::ifstream inFile;
    inFile.open("Texto1.txt");

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string textoLeido = buffer.str();

    std::ifstream inFile3;
    inFile3.open("Texto3.txt");

    std::stringstream buffer3;
    buffer3 << inFile3.rdbuf();
    std::string textoLeido3 = buffer3.str();

    std::vector<std::string> vectorPalabras1 = ParserText(textoLeido);
    std::vector<std::string> vectorPalabras2 = ParserText(textoLeido3);
    int contadorTexto1 =(vectorPalabras1.size())*(0.5);
    int contadorTexto2 =(vectorPalabras2.size())*(0.5);
    int indice10P =0;
    int aux=0;
    int iguales2Pala = 0;
    int iguales3Pala = 0;
    int iguales4Pala = 0;
    int iguales5Pala = 0;
    GrpPalabras* auxPalabra;
    //texto1 muestreo y separado por cantidad de palabras.
    std::vector<std::vector<std::string>> cant2Pa {};
    std::vector<std::vector<std::string>> cant3Pa {};
    std::vector<std::vector<std::string>> cant4Pa {};
    std::vector<std::vector<std::string>> cant5Pa {};
    //texto2 muestreo y separado por cantidad de palabras.
    std::vector<std::vector<std::string>> cant2PaTx2 {};
    std::vector<std::vector<std::string>> cant3PaTx2 {};
    std::vector<std::vector<std::string>> cant4PaTx2 {};
    std::vector<std::vector<std::string>> cant5PaTx2 {};

    std::tuple<GrpPalabras*, int> tupleRandom{};
    while (indice10P<contadorTexto1)
    {
        tupleRandom = radomPalabras(vectorPalabras1,"texto1");
        aux = std::get<1>(tupleRandom);
        auxPalabra = std::get<0>(tupleRandom);

        if (aux==2)
        {
            cant2Pa.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==3)
        {
            cant3Pa.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==4)
        {
            cant4Pa.push_back(auxPalabra->grupoPalabras);
        }

         if (aux==5)
        {
            cant5Pa.push_back(auxPalabra->grupoPalabras);
        }
        indice10P++;
    }
    indice10P=0;
    while (indice10P<contadorTexto2)
    {
        tupleRandom = radomPalabras(vectorPalabras2,"texto2");
        aux = std::get<1>(tupleRandom);
        auxPalabra = std::get<0>(tupleRandom);

        if (aux==2)
        {
            cant2PaTx2.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==3)
        {
            cant3PaTx2.push_back(auxPalabra->grupoPalabras);
        }
         if (aux==4)
        {
            cant4PaTx2.push_back(auxPalabra->grupoPalabras);
        }

         if (aux==5)
        {
            cant5PaTx2.push_back(auxPalabra->grupoPalabras);
        }
        indice10P++;
    }
    

    int contV1 = 0;
    int contV2 = 0;
    int iguales2P =0;
    int iguales3P =0;
    int iguales4P =0;
    int iguales5P =0;
    double porcentajeIgual = 0;
    while (contV1<cant2Pa.size())
    {
        while (contV2<cant2PaTx2.size())
        {
            iguales2P+=comparadorVectores(cant2Pa[contV1],cant2PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }

    contV1 = 0;
    contV2 = 0;
    while (contV1<cant3Pa.size())
    {
        while (contV2<cant3PaTx2.size())
        {
            iguales3P+=comparadorVectores(cant3Pa[contV1],cant3PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    contV1 = 0;
    contV2 = 0;
    while (contV1<cant4Pa.size())
    {
        while (contV2<cant4PaTx2.size())
        {
            iguales4P+=comparadorVectores(cant4Pa[contV1],cant4PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    contV1 = 0;
    contV2 = 0;
    while (contV1<cant5Pa.size())
    {
        while (contV2<cant5PaTx2.size())
        {
            iguales5P+=comparadorVectores(cant5Pa[contV1],cant5PaTx2[contV2]);
            contV2++;
        }
        contV1++;
        contV2=0;
    }
    porcentajeIgual+= iguales2P*(double)2.5;
    porcentajeIgual+= iguales3P*(double)5;
    porcentajeIgual+= iguales4P*(double)10;
    porcentajeIgual+= iguales5P*(double)20;
    //cout<<porcentajeIgual<<endl;
    
    

    return porcentajeIgual;

}


int main(){
    double promedio12 = 0;
    for (int i = 0; i < 10; i++)
    {
        promedio12+= Texto1yTexto2();
    }
    cout<< promedio12/5 <<endl;
    if (50<(promedio12/5))
    {
        cout<< "Alta probalidad de considencias"<<endl;
    }
    if ((promedio12/5)<50)
    {
        cout<< "Baja probalidad de considencias"<<endl;
    }
    double promedio23 = 0;
    for (int i = 0; i < 10; i++)
    {
        promedio23+= Texto1yTexto3();
    }
    cout<< promedio23/5 <<endl;
    if (50<(promedio23/5))
    {
        cout<< "Alta probalidad de considencias"<<endl;
    }
    if ((promedio23/5)<50)
    {
        cout<< "Baja probalidad de considencias"<<endl;
    }
    
}