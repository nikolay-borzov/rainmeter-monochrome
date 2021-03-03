[Variables]
; Set your system specific variables here
; You can also override variables from `Variables.inc`

; -----------------------------
; Setting HWiNFO related values
; -----------------------------

; You will need update the HWiNFO IDs included in this skin to match the IDs for your system.  To do this:
; 1. Ensure HWiNFO is running, with sensors and shared memory active
; 2. Run the included "HWiNFOSharedMemoryViewer.exe" file
; 3. Find the sensor reading you need (CPU Usage for example) and make note of the sensor id, sensor instance and entry id
; 4. Edit the Config.inc file to replace the provided IDs with the IDs for your system
; 5. Refresh the skin

; HWiNFO references
; https://www.hwinfo.com/forum/threads/cpu_temp_sensors_explanation.5597/
; https://www.hwinfo.com/forum/threads/cpu_core_temperature_measuring_facts_fictions.148/
; https://forum.rainmeter.net/viewtopic.php?f=128&t=22169

; -------------
; Font settings
; -------------

FontFace=JetBrains Mono
FontSize=12
; Line height in pixels.
; Should be big enough to fit string with font size equal to FontSize
LineHeight=20
FontSizeSmall=10
; Should be big enough to fit string with font size equal to FontSizeSmall
LineHeightSmall=16
; Align string vertically if a font has offset
FontTopPaddingFix=1
; Align font string top inside line container
LineMeterStringTopFix=-3
; Align font string bottom inside line container
LineMeterStringBottomFix=5

; -----------
; Temperature
; -----------
; C, F, K
TempUnit=C
TempMax=100

; ---
; CPU
; ---
HWiNFO_CPU0_DTS_SensorId=0xf0000400
HWiNFO_CPU0_DTS_SensorInstance=0x0
HWiNFO_CPU0_DTS_CoreMax=0x10000ff
; 0-5
CPUTopProcessesCount=3

; ------
; Memory
; ------

; 0-5
MemoryTopProcessesCount=3

; ---
; GPU
; ---
HWiNFO_GPU0_SensorId=0xe0002000
HWiNFO_GPU0_SensorInstance=0x0
HWiNFO_GPU0_Temp=0x1000000
HWiNFO_GPU0_Fan=0x8000000

; GUID for GPU inside HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Class\
GPU_Registry_GUID={4D36E968-E325-11CE-BFC1-08002BE10318}

; 0-5
GPUTopProcessesCount=2

; -------
; Network
; -------

; Set these for sure. http://speedtest.net
NetMaxDownloadMbits=94.33
NetMaxUploadMbits=91.30
; Set this if needed. Default: Best
; NetInterface=

; ---
; I/O
; ---

; 0-5
IOTopProcessesCount=4

; ------
; Drives
; ------

; S.M.A.R.T. Same for all drives
HWiNFO_SMART_SensorId=0xf0000100
HWiNFO_SMART_DriveTemperature=0x1000000

Drive_1=C:
Drive_1_HWiNFOSensorInstance=0x3

Drive_2=D:
Drive_2_HWiNFOSensorInstance=0x0

Drive_3=G:
Drive_3_HWiNFOSensorInstance=0x2

Drive_4=H:
Drive_4_HWiNFOSensorInstance=0x1

Drive_5=O:
Drive_5_HWiNFOSensorInstance=0x4

; ------
; Player
; ------

; https://docs.rainmeter.net/manual/measures/nowplaying/#playerlist
PlayerName=
; Skin header
PlayerTitle=
PlayerPath=
