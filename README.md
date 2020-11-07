# Averager

This simple module allows you to get the average of various numbers in a simple way. This library is intended to make the measurements on Analog pins smoother, keepeng the latest measures and getting the average in a simple way.

## How to use it
Just create an `averager` object with the variable type and number of items to keep as template arguments.

```bash
# Create an averager object with 10 double items
averager measurement<double, 10>;

# Create an averager object with 5 int items
averager measurement<int, 5>;
```

Append numbers to the object using the `append` method. Older items will be dropped when the max items number is reached.

```bash
# Append a double item
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