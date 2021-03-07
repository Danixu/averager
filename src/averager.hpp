template <class T, int ITEMS_NUMBER>
averager<T, ITEMS_NUMBER>::averager() {
  clear();
}

template <class T, int ITEMS_NUMBER>
void averager<T, ITEMS_NUMBER>::append(T value) {
  for (int i = 1; i < ITEMS_NUMBER; i++) {
    _items[i - 1] = _items[i];
  }
  _items[ITEMS_NUMBER - 1] = value;
}

template <class T, int ITEMS_NUMBER>
T averager<T, ITEMS_NUMBER>::getAverage(bool ignoreEmpty) {
  // Double to avoid variable overload
  double total = 0;
  int count = 0;
  for (int i=0; i < ITEMS_NUMBER; i++) {
    if (!ignoreEmpty || _items[i] != 0) {
      total += _items[i];
      count++;
    }
  }

  if (count == 0) {
    return 0;
  }
  else {
    return (T)(total/count);
  }
}

template <class T, int ITEMS_NUMBER>
T averager<T, ITEMS_NUMBER>::getItem(int itemNumber) {
  if (itemNumber >= ITEMS_NUMBER) {
    return -1;
  }

  return _items[itemNumber];
}

template <class T, int ITEMS_NUMBER>
void averager<T, ITEMS_NUMBER>::clear() {
  for (int i=0; i < ITEMS_NUMBER; i++) {
    _items[i] = 0;
  }
}

template <class T, int ITEMS_NUMBER>
void averager<T, ITEMS_NUMBER>::updateExponentialMovingAverage(T newEMA) {
  _exponentialMovingAverage = (_exponentialMovingAverageAlpha * newEMA) + ((1 - _exponentialMovingAverageAlpha) * _exponentialMovingAverage);
}

template <class T, int ITEMS_NUMBER>
void averager<T, ITEMS_NUMBER>::setExponentialMovingAverageAlpha(float alpha) {
  _exponentialMovingAverageAlpha = alpha;
}

template <class T, int ITEMS_NUMBER>
T averager<T, ITEMS_NUMBER>::getExponentialMovingAverage() {
  return _exponentialMovingAverage;
}

template <class T, int ITEMS_NUMBER>
void averager<T, ITEMS_NUMBER>::clearExponentialMovingAverage() {
  _exponentialMovingAverage = 0;
}