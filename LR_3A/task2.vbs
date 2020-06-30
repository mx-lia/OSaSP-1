Set WshShell = CreateObject ("WScript.Shell")
Set objEnv = WshShell.Environment("Process")
objEnv("MyCom")="C:\Windows\notepad.exe D:\Result.txt"
WshShell.Run objEnv("MyCom"),1
