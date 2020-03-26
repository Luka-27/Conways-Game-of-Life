#include "../includes/celula2.hpp"




inline int
celula2::getEstado() const
{
    return TiposCelula::CELL_TYPE_2;
}



std::ostream&
celula2::mostrar(std::ostream& out) const
{
    out << CHAR_CELL_TYPE_2;
    return out;
}



int
celula2::actualizarEstado()
{
    if (SURVIVE_TYPE_2) return CELL_TYPE_2;
    else return CELL_TYPE_0;
}