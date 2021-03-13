template <class T, int ITEMS_NUMBER = 5>
class averager {
   // Public stuff
   public:
      averager();

      // Functions Average
      void append(T);
      T getAverage(bool ignoreEmpty = true);
      T getItem(int);
      void clear();

      // Functions Exponential Moving Average
      void updateExponentialMovingAverage(T);
      void setExponentialMovingAverageAlpha(float);
      T getExponentialMovingAverage();
      void clearExponentialMovingAverage();
   
   // Internal stuff
   protected:
      T _items[ITEMS_NUMBER];
      double _exponentialMovingAverage = 0.0;
      float _exponentialMovingAverageAlpha = 0.1;
};

#include "averager.hpp"