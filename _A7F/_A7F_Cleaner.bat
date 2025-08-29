@echo off
set TID=_A7F
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /s /q /a .\RunTimeError.txt
del /f /s /q /a .\TimeLimitExceeded.txt
del /f /s /q /a .\WrongAnswer.txt
del /f /s /q /a .\_A7F_0*
del /f /s /q /a .\_A7F_1*
del /f /s /q /a .\_A7F_2*
del /f /s /q /a .\out.txt
del /f /s /q /a .\in.txt
del /f /s /q /a .\*.exe
del /f /s /q /a .\*.class
rd /s /q __pycache__
rd /s /q %TID%