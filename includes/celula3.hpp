#pragma once
#include "celula.hpp"
#define SURVIVE_TYPE_3 (nvivas_ == 1 || nvivas_ == 5)


class celula3 : public celula{

    public:
        celula3(int i, int j):
            celula(i,j){}

        inline int getEstado() const;
        int actualizarEstado();
        std::ostream& mostrar(std::ostream&) const;

};