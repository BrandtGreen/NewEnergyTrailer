echo off
rem cd /d %~dp0
cd SwcCELCmgr_autosar_rtw
echo on

FOR %%c in (*.c *.h) DO (
  echo %%c
  si co --overwriteChanged ..\..\g_code\%%c
  copy %%c ..\..\g_code\%%c
  
FOR %%c in (*.arxml) DO (
  echo %%c
  si co --overwriteChanged ..\..\arxml\%%c
  copy %%c ..\..\arxml\%%c
)


rem *** HACK ALERT: Sleep for 5 seconds ***
ping -n 5 127.0.0.1 > nul
exit

