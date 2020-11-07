template <class T, int ITEMS_NUMBER = 5>
class averager {
   // Public stuff
   public:
      averager();

      // Functions
      void append(T);
      T getAverage();
      T getAverage(bool);
      T getItem(int);
      void clear();
   
   // Internal stuff
   protected:
      T _items[ITEMS_NUMBER];
};

#include "averager.hpp"