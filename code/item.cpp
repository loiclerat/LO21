#include "item.h"
#include "exceptions.h"

litterale& Item::getLitterale() const {
        if (lit==0) throw ComputerException("Item : tentative d'acces a une litterale inexistante");
        return *lit;
}
