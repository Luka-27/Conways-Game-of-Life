#include "../includes/celula1.hpp"



inline int
celula1::getEstado() const
{
    return TiposCelula::CELL_TYPE_1;
}



std::ostream&
celula1::mostrar(std::ostream& out) const
{
    out << CHAR_CELL_TYPE_1;
    return out;
}



int
celula1::actualizarEstado()
{
    if (SURVIVE_TYPE_1) return CELL_TYPE_1;
    else return CELL_TYPE_0;
}