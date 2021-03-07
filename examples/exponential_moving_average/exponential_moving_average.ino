#include <averager.h>

averager<int> average_item;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  average_item.updateExponentialMovingAverage(random(0, 999));

  Serial.println(average_item.getExponentialMovingAverage());
}
