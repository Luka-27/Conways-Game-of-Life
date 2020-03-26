#include "../includes/celula3.hpp"



inline int
celula3::getEstado() const
{
    return TiposCelula::CELL_TYPE_3;
}



std::ostream&
celula3::mostrar(std::ostream& out) const
{
    out << CHAR_CELL_TYPE_3;
    return out;
}



int
celula3::actualizarEstado()
{
    if (SURVIVE_TYPE_3) return CELL_TYPE_3;
    else return CELL_TYPE_0;
}