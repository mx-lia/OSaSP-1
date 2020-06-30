Set WshShell = CreateObject ("WScript.Shell")
Set objEnv = WshShell.Environment("Process")
objEnv("MyCom")="xcopy D:\Study\OSaSP\LR_3A\task3\1.txt D:\Study\OSaSP\LR_3A\task3\2.txt"
WshShell.Run objEnv("MyCom"),1