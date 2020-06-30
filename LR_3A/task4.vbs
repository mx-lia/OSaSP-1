Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("D:\Study\OSaSP\open_Excel.bat")
file.WriteLine("start Excel.exe")
file.Close
Set WshShell = CreateObject ("WScript.Shell")
Set objEnv = WshShell.Environment("Process")
objEnv("MyCom")="D:\Study\OSaSP\open_Excel.bat"
WshShell.Run objEnv("MyCom"),1
