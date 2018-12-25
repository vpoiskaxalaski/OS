Set WshShell = CreateObject ("WScript.Shell")

Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("E:\University\3k1s\OS\lab03\newfile.bat")
file.WriteLine("Copy E:\University\3k1s\OS\lab01\studentList.txt E:\University\3k1s\OS\lab03\")
file.Close
