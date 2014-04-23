// Method implementaiton
// operations.cpp

#include "vend.h"

VendingMachine::VendingMachine(int p, int q, int tt, int mt) {
    product_price = p;
    product_quantity = q;
    transaction_total = tt;
    machine_total = mt;
}