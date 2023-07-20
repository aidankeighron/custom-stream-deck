#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

Adafruit_SSD1306 display1(OLED_RESET);
Adafruit_SSD1306 display2(OLED_RESET);

void setup() {
  // Start Wire library for I2C
  Wire.begin();
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {
  // Delay to allow sensor to stabalize
  delay(2000);
  TCA9548A(1);
  display1.clearDisplay();
  display1.setTextColor(WHITE);
  display1.setTextSize(2);
  display1.setCursor(0,10);
  display1.print("Test2"); 
  display1.display();
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextColor(WHITE);
  display2.setTextSize(2);
  display2.setCursor(0,10);
  display2.print("Test2"); 
  display2.display();
}

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

// void displayTemp(float tem){
//   // Clear the display
//   display1.clearDisplay();
//   //Set the color - always use white despite actual display color
//   display1.setTextColor(WHITE);
//   //Set the font size
//   display1.setTextSize(2);
//   //Set the cursor coordinates
//   display1.setCursor(0,10);
//   display1.print("T: "); 
//   display1.print(tem);
//   display1.print(" C");
// }

// void displayHumid(float hum){
//   // Clear the display
//   display2.clearDisplay();
//   //Set the color - always use white despite actual display color
//   display2.setTextColor(WHITE);
//   //Set the font size
//   display2.setTextSize(2);
//   //Set the cursor coordinates
//   display2.setCursor(0,10);
//   display2.print("H: "); 
//   display2.print(hum);
//   display2.print(" %");
// }

// void setup() {
//   // Start Wire library for I2C
//   Wire.begin();
  
//   // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C
//   TCA9548A(1);
//   display1.begin(SSD1306_SWITCHCAPVCC, 0x70);
 
//   // initialize OLED-1 with I2C addr 0x3C
//   TCA9548A(2);
//   display2.begin(SSD1306_SWITCHCAPVCC, 0x70);
// }

// void loop() {
//   // Delay to allow sensor to stabalize
//   delay(2000);
  
//   // Set multiplexer to channel 1 and display temperature
//   TCA9548A(1);
//   displayTemp(100.0);
//   display1.display();
  
//   // Set multiplexer to channel 2 and display temperature
//   TCA9548A(2);
//   displayHumid(10.0);
//   display2.display();
// }




// void setup()
// {
//   Wire.begin();

//   Serial.begin(9600);
//   while (!Serial);             // Leonardo: wait for serial monitor
//   Serial.println("\nI2C Scanner");
// }

// // int i = 0;

// void loop()
// {
//   byte error, address;
//   int nDevices;
// //   if (i > 10) {
// //     i = 0;
// //   }
//   Serial.println("Scanning... ");
// //   Serial.println(i);
// //   TCA9548A(i);
// //   i+=1;
//   nDevices = 0;
//   for(address = 1; address < 127; address++ ) 
//   {
//     // The i2c_scanner uses the return value of
//     // the Write.endTransmisstion to see if
//     // a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0)
//     {
//       Serial.print("I2C device found at address 0x");
//       if (address<16) 
//         Serial.print("0");
//       Serial.print(address,HEX);
//       Serial.println("  !");

//       nDevices++;
//     }
//     else if (error==4) 
//     {
//       Serial.print("Unknown error at address 0x");
//       if (address<16) 
//         Serial.print("0");
//       Serial.println(address,HEX);
//     }    
//   }
//   if (nDevices == 0)
//     Serial.println("No I2C devices found\n");
//   else
//     Serial.println("done\n");

//   delay(1000);           // wait 5 seconds for next scan
// }