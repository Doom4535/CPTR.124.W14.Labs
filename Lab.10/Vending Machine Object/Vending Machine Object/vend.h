#ifndef _VEND_H_
#define _VEND_H_

class VendingMachine {
    //  The target value needed to serve the product (price of
    //  product)
    int product_price;
    
    //  The quantity of the product contained by this vending
    //  machine.
    int product_quantity;
    
    //  The total amount of money inserted during a particular
    //  transaction
    int transaction_total;
    
    //  The total amount of money held by the vending machine.
    int machine_total;
    
public:
    //----------------------------------------------------------
    //  The constructor accepts the vending machine product's
    //  price and its quanity.  The machine is set to its initial
    //  state.  Note that the product price cannot change
    //  for the life of this VendingMachine object, but the
    //  quantity of the product will decline as customers make
    //  purchases.
    VendingMachine(int price, int amount);
    
    //----------------------------------------------------------
    //  Input accepts coin values of the following
    //  amounts: 5, 10, 25.
    //  The function returns true if the amount the
    //  client provides is 5, 10, or 25; otherwise,
    //  the function returns false.  An unacceptable
    //  value does not change the state of the machine.
    //  Acceptable values accumulate funds toward a purchase
    //  of the product.
    //  This function does not change the quantity of the product.
    bool input(int amount);
    
    //----------------------------------------------------------
    //  A client calls the vend method in an attempt to purchase
    //  the product.
    //  The function can return a positive, negative, or zero
    //  result:
    //    - returns 0, if the accumulated amount of money for a
    //      transaction is equal to the price of the product; this
    //      means the product is served, and no change is due.
    //
    //    - returns a value greater than 0 when the amount entered
    //      during a transaction is greater than the price of the
    //      product.  In this case the return value represents the
    //      amount of change due to the customer.  In this case
    //      the vending machine serves the product and returns
    //      the change amount.
    //
    //    - returns a value less than 0  when the amount of money
    //      entered during a transaction has yet to reach the price
    //      of the product; this means the customer must insert more
    //      coins before the vending machine object can serve the
    //      product can be served.  In this case the return value
    //      represents what the customer still "owes" to get the
    //      product.
    //
    //  If the vending machine serves the product, the product's
    //  quantity decreases by one and the machine resets to its
    //  ready to begin a new transaction state.
    //
    //  The vending machine can serve only one product per
    //  transaction; for example, if the customer enters coins
    //  amounting to three times the price of the product, the
    //  machine would vend one product and return two times the
    //  product's price in change.
    int vend();
    
    //----------------------------------------------------------
    //  Resets the machine to its ready to begin a new transaction
    //  state.  The value returned is the accumulated amount during
    //  the current transaction; it represents the money that should
    //  be sent to the coin return.
    //  This function does not change the quantity of the product.
    int reset();
    
    //----------------------------------------------------------
    //  Returns the price of the product
    //  This function changes neither the accumulated customer
    //  funds nor the quantity of the product.
    int price() const;
    
    //----------------------------------------------------------
    //  Returns the quantity of the product currently held by this
    //  vending machine.
    //  This function changes neither the accumulated customer
    //  funds nor the quantity of the product.
    int quantity() const;
    
    //----------------------------------------------------------
    //  Returns the current amount of money held by the vending
    //  machine.
    //  This function changes neither the accumulated customer
    //  funds nor the quantity of the product.
    int total() const;
};


#endif
