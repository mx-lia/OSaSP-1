Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("D:\Study\OSaSP\info.txt")
'Processor Information

On Error Resume Next
Message =""
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")

For Each objItem in colItems
    Message=Message & "Частота: " & objItem.CurrentClockSpeed & vbCrLf  
    Message=Message & "Разрядность: " & objItem.DataWidth& vbCrLf
    Message=Message & "Описание: " & objItem.Description& vbCrLf
    Message=Message & "Семейство: " & objItem.Family& vbCrLf
    Message=Message & "Размер кэш: " & objItem.L2CacheSize& vbCrLf
    Message=Message & "Текущая загрузка: " & objItem.LoadPercentage& vbCrLf
    Message=Message & "Производитель: " & objItem.Manufacturer& vbCrLf
    Message=Message & "Номер процессора: " & objItem.ProcessorId& vbCrLf
   
Next
file.WriteLine Message
file.Close
