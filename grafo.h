#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <list>
#include <vector>

#include "AristaGrafo.h"
#include <limits>
#include <sstream>
#include <algorithm>
class Grafo {
public:
    Grafo(int v);
    Grafo(int v, std::vector<std::vector<int> > costes);
    ~Grafo();
    int coste(int v, int w);
    void inserta(int v, int w, int coste);
    int totalVertices();
    static Grafo prim(Grafo G);
    std::vector<AristaGrafo> viajanteComercioVecino(Grafo G, int v);
    std::vector<AristaGrafo> viajanteComercioPrim(Grafo G, int v);
    std::string imprime(std::string s);
    static std::string imprimeVector(std::string s,int* vector, int n);
    static const int INFINITO =std::numeric_limits<unsigned short int>::max();

    int getPos(int row,  int col) const{ //getCoste en i,j
        int index = row * vertices + col;
        return aristas[index];
    }
    void set(unsigned int row, unsigned int col, float value){

        int index = row * vertices + col;
        aristas[index] = value;

    }

    std::string imprime2(std::string s){
        std::stringstream ss;
        ss << "\n" << s << "\n";
        for (int i = 0; i < vertices; i++) {
            ss << "\n[" << (i + 1) << "] ";
            for (int j = 0; j < vertices; j++)
                if (getPos(i,j) == Grafo::INFINITO)
                    ss << " -- ";
                else {
                    if (getPos(i,j) < 10)
                        ss << "  " << getPos(i,j) << " ";
                    else
                        ss << " " <<getPos(i,j) << " ";
                }
        }
        ss << "\n";
        return ss.str();

    }
    bool esIgual(std::vector<int> a, std::vector<int>b){
        bool res = true;
        if(a.size() !=b.size()) res = false;
        else{
            std::sort(a.begin(),a.end());
            std::sort(b.begin(),b.end());
            if(a!=b){
                res = false;
            }
        }
        return res;
    }

    bool pertenece(std::vector<int> a, int b){
        bool res = false;
        for(unsigned int i = 0; i<a.size(); i++){
            if(a[i] == b) {
                res = true;
            }
        }
        return res;
    }
private:

    int vertices;
    std::vector<int> aristas;
    static void costeMinimoAristaMenor2(Grafo G, std::vector<int> U,std::vector<int>W,std::vector<int> D, int &u, int &w);


};
#endif // GRAFO_H
