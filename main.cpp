#include <iostream>
#include <vector>
#include "grafo.h"
#include "aristagrafo.h"
int main(){
    std::cout << "------------" << std::endl;
    std::cout << "PRUEBA CIUDADES: " <<std::endl;
    std::cout <<std::endl;

    std::vector <std::vector<int>> costes = {{0, 1118, 644, 535, 683, 995, 334, 609,1153,1010,340,738,473,763 ,947,676 ,961, 455, 411, 833},
                                             {1118, 0, 620, 583, 918, 908 ,784, 621, 997, 590 ,902,437 ,778, 529, 1046, 453, 349, 663 ,759 ,296},
                                             {644,620, 0, 158, 605, 795, 359, 395, 939, 796, 304, 159, 395, 119, 993, 257, 633, 280, 376, 324},
                                             {535,583,158,0, 447, 637 ,201, 237 ,781, 638, 322, 203, 237 ,232 ,775, 141 ,517 ,122,218, 287},
                                             {683,918,605,447,0 ,319 ,407, 297 ,506, 654, 525, 650, 210, 679, 264, 490, 636, 325, 272, 622},
                                             {995, 908, 795 ,637 ,319,0 ,733, 400, 187, 444 ,851, 807, 529, 869, 138, 631, 545, 578, 616, 725},
                                             {334, 784, 359, 201 ,407, 733,0 ,333, 877, 734, 118, 404, 197, 433, 671, 342, 685, 134, 135, 488},
                                             {609, 621, 395, 237, 297, 400, 333, 0 ,544, 401, 451, 407, 212, 469, 538, 231, 352, 193, 248, 325},
                                             {1153, 997, 939, 781, 506, 187 ,877, 544, 0, 407 ,995, 951, 756 ,1013, 219, 775, 648, 737, 792, 869},
                                             {1010, 590, 796, 638, 654, 444, 734, 401, 407, 0, 852, 714, 613, 807 ,534, 589, 241, 594, 649, 539},
                                             {340, 902, 304, 322, 525, 851 ,118, 451, 995, 852, 0, 463, 315, 423, 789, 463, 803, 252, 253, 604},
                                             {738, 437, 159, 203, 650, 807, 404, 407, 951, 714 ,463, 0 ,440, 92, 945, 176, 501, 325, 421, 175},
                                             {473, 778, 395, 237, 210 ,529, 197, 212, 756, 613, 315, 440, 0, 469, 474, 325, 564, 115, 62, 482},
                                             {763, 529 ,119, 232 ,679, 869, 433, 469 ,1013, 807 ,423, 92, 469,0, 1007, 268, 594, 354, 450, 268},
                                             {947, 1046, 993, 775, 264, 138, 671, 538, 219, 534, 789, 945, 474, 1007,0, 769 ,697, 589, 536 ,863},
                                             {676, 453, 257, 141, 490, 631, 342, 231, 775, 589, 463, 176, 325, 268, 769,0, 376, 210, 306, 157},
                                             { 961, 349, 633, 517, 636, 545, 685, 352 ,648, 241, 803, 501, 564, 594, 697, 376,0, 545 ,600, 326},
                                             {455, 663,280 ,122, 325, 578, 134, 193, 737, 594, 252 ,325, 115, 354, 589, 210, 545, 0, 96, 367},
                                             {411, 759, 376, 218, 272, 616, 135, 248 ,792, 649, 253, 421, 62, 450, 536, 306, 600 ,96 ,0, 463},
                                             {833, 296, 324, 287, 622, 725, 488, 325, 869, 539, 604, 175, 482, 268, 863, 157 ,326, 367, 463,0}};

    Grafo gr(20,costes);

    std::cout << gr.imprime("Grafo ciudades ");
    std::cout << std::endl;

    std::vector<std::string> ciudades={"A Coruna","Barcelona","Bilbao","Burgos","Caceres","Cordoba",
                                       "Leon","Madrid","Malaga","Murcia","Oviedo","Pamplona",
                                       "Salamanca","San Sebastian","Sevilla","Soria","Valencia","Valladolid",
                                       "Zamora","Zaragoza"};
    std::cout << std::endl;
    int costeTotal = 0;
    std::vector<AristaGrafo> recorrido =  gr.viajanteComercioVecino(gr, 0);
    for(AristaGrafo b : recorrido){
        int x = b.v;
        int y = b.w;
        costeTotal = costeTotal+ b.coste;
        std::cout << ciudades[x] << " -> " <<ciudades[y] << " --" <<" Coste [ " << b.coste << " ]"<< std::endl;


    }
    std::cout << std::endl;
    std::cout << "COSTE TOTAL: " << costeTotal << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "PRUEBAS CON OTROS RECORRIDOS" << std::endl;

    Grafo prueba1(3);
    prueba1.inserta(0,0,0);
    prueba1.inserta(0,1,10);
    prueba1.inserta(0,2,20);

    prueba1.inserta(1,0,10);
    prueba1.inserta(1,1,0);
    prueba1.inserta(1,2,5);

    prueba1.inserta(2,0,20);
    prueba1.inserta(2,1,5);
    prueba1.inserta(2,2,0);

    std::cout << prueba1.imprime("PRUEBA 1");
    std::cout << std::endl;
    std::vector<AristaGrafo> recorridoPrueba1 =  prueba1.viajanteComercioVecino(prueba1, 0);
    for(AristaGrafo a : recorridoPrueba1){
        std::cout << a.v + 1 << " -> " << a.w + 1  << " --" << " Coste [ " << a.coste << " ]" << std::endl;
    }


    Grafo prueba2(4);
    prueba2.inserta(0,0,0);
    prueba2.inserta(0,1,10);
    prueba2.inserta(0,2,20);
    prueba2.inserta(0,3,15);

    prueba2.inserta(1,0,10);
    prueba2.inserta(1,1,0);
    prueba2.inserta(1,2,5);
    prueba2.inserta(1,3,20);

    prueba2.inserta(2,0,20);
    prueba2.inserta(2,1,5);
    prueba2.inserta(2,2,0);
    prueba2.inserta(2,3,12);

    prueba2.inserta(3,0,15);
    prueba2.inserta(3,1,20);
    prueba2.inserta(3,2,12);
    prueba2.inserta(3,3,0);

    std::cout << prueba2.imprime("PRUEBA 2");
    std::cout << std::endl;
    std::vector<AristaGrafo> recorridoPrueba2 =  prueba2.viajanteComercioVecino(prueba2, 0);
    for(AristaGrafo a : recorridoPrueba2){
        std::cout << a.v + 1 << " -> " << a.w + 1  << " --" << " Coste [ " << a.coste << " ]" << std::endl;
    }



    return 0;
}
