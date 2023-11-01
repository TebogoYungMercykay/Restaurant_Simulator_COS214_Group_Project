#ifndef ORDERDIRECTOR_H
#define ORDERDIRECTOR_H

#include "OrderBuilder.h"

class OrderDirector {
   private:
      OrderBuilder* builder;
   public:
      ~OrderDirector(){};
      void setOrderBuilder(OrderBuilder* newOrderBuilder);
      Order* getOrder();
      void constructOrder();
      void addExtras(string type, vector<string> removeItems);
      void reset();
};

#endif // ORDERDIRECTOR_H