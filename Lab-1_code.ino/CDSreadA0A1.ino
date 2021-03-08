void setup() {
  //The code to begin the serial communication with the Arduino!
  Serial.begin(9600);
}

void loop() {
  //Defining pins to variables to maintain modularity
  int pin_cds1 = A0;
  int pin_cds2 = A1;

  //Obtain 'Result' values from the ADC
  float cds1_value = analogRead(pin_cds1);
  float cds2_value = analogRead(pin_cds2);

  //Calculate weighted values
  float nm_1 = cds1_value/(cds1_value + cds2_value);
  float nm_2 = cds2_value/(cds1_value + cds2_value);

  //Print values to console
  Serial.println("Sensor 1 value: " + String(cds1_value));
  Serial.println("Sensor 2 value: " + String(cds2_value));
  Serial.println("nm 1 value: " + String(nm_1));
  Serial.println("nm 2 value: " + String(nm_2));
  Serial.println(" ");
  delay (1000);
}
