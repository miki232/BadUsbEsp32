
/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;
int i = 0;
void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}
void loop() {
  if(bleKeyboard.isConnected()) {
    if (i == 0){
        Serial.println("Sending 'Hello world'...");
        //bleKeyboard.print("Hello world");
        delay(500);
        bleKeyboard.press(KEY_LEFT_GUI);
        //bleKeyboard.press(32);
        delay(100);
        bleKeyboard.releaseAll();
        //Serial.println("Sending Enter key...");
        delay(100);
        //bleKeyboard.print("Google Chrome");
        delay(100);
        bleKeyboard.write(KEY_RETURN);
        delay(100);
        bleKeyboard.releaseAll();
        delay(1000);
        Serial.println("Open RIk");
        bleKeyboard.print("tinyurl.com");
        delay(500);
        bleKeyboard.press(KEY_NUM_SLASH);
        bleKeyboard.print("4urbzm84");
        delay(200);
        bleKeyboard.write(KEY_RETURN);
    //    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        bleKeyboard.releaseAll();
        delay(1000);
    }
    i = 1;
   //
   // Below is an example of pressing multiple keyboard modifiers
   // which by default is commented out.
    /*
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.p  ress(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */
    int x = 0;
    while(x < 20)
    {
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      bleKeyboard.releaseAll();
      x++;
    }
  }
  Serial.println("Waiting 5 seconds...");
  delay(2000);
}
