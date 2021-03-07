# Averager

This simple module allows you to get the average of various numbers in a simple way. This library is intended to make the measurements on Analog pins smoother, keepeng the latest measures and getting the average in a simple way.

## How to use it

### Standard Average
To use the standard average, create an `averager` object with the variable type and number of items to keep as template arguments.

```bash
# Create an averager object with 10 double items
averager measurement<double, 10>;

# Create an averager object with 5 int items
averager measurement<int, 5>;
```

Append numbers to the object using the `append` method. Older items will be dropped when the max items number is reached.

```bash
# Append a float item
measurement.append(10.0);

# Append an int item
measurement.append(10);
```

Get the average of latest items.
```bash
# Get the average ignoring items with 0 as value
measurement.getAverage();

# Get the average including items with 0 as value
measurement.getAverage(true);
```

Also exists two functions to get an item, and to clear all.

```bash
# Get the item number 3
measurement.getItem(3);

# Clear all the items
measurement.clear();
```

### Exponential Moving Average
To use the exponential moving average, create an `averager` object with the variable type.

```bash
# Create an averager int object
averager measurement<double>;

# Create an averager float object
averager measurement<int>;
```

Update the exponential moving average using the `updateExponentialMovingAverage` method.

```bash
# Append a float item
measurement.updateExponentialMovingAverage(10.0);

# Append an int item
measurement.updateExponentialMovingAverage(10);
```

Get the exponential moving average value.
```bash
# Get the exponential moving average value
measurement.getExponentialMovingAverage();
```

Also you can reset the exponential moving average value with the `clearExponentialMovingAverage` method.

```bash
# Clear all the items
measurement.clearExponentialMovingAverage();
```