#ifndef ARISTAGRAFO_H
#define ARISTAGRAFO_H
class AristaGrafo {
public:
 int v, w, coste;
 AristaGrafo(int v1, int v2, int c) {
 v = v1;
 w = v2;
 coste = c;
 }
};
#endif // ARISTAGRAFO_H
