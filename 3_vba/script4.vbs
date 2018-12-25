Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("E:\University\3k1s\OS\lab03\startExcel.bat")
file.WriteLine("start Excel.exe")
file.Close

