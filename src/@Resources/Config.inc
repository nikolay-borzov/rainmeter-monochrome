[Variables]
; -----------------------------
; Setting HWiNFO related values
; -----------------------------

; You will need update the HWiNFO IDs included in this skin to match the IDs for your system. To do this:
; 1. Ensure HWiNFO is running, with sensors and shared memory active
; 2. Run the included "HWiNFOSharedMemoryViewer.exe" file
; 3. Find the sensor reading you need (CPU Usage for example) and make note of the sensor id, sensor instance and entry id
; 4. Edit the Config.inc file to replace the provided IDs with the IDs for your system
; 5. Refresh the skin

; HWiNFO references
; https://www.hwinfo.com/forum/threads/rainmeter-plug-in-for-hwinfo-3-2.2172/
; https://www.hwinfo.com/forum/threads/cpu_temp_sensors_explanation.5597/
; https://www.hwinfo.com/forum/threads/cpu_core_temperature_measuring_facts_fictions.148/
; https://forum.rainmeter.net/viewtopic.php?f=128&t=22169

; "en", "ru"
Locale="en"

; -----
; Sizes
; -----

SkinWidth=280
BarHeight=20
LineMeterHeight=50

; ----
; Font
; ----

FontFace=JetBrains Mono
FontSize=12
; Line height in pixels. Should be big enough to fit string with font size equal to FontSize
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
; Border, Shadow or None
StringEffect=Border
; String effect color
FontEffectColor=34,34,34,255
; Default font color
FontColor=255,255,255,255
; Dimmed font color (less important information)
FontColorDim=255,255,255,200
; Font color for disabled label (not important information like zero write speed)
FontColorDisabled=255,255,255,150

; -----
; Colors
; -----

SkinBackground=34,34,34,255
; Meter box background color
MeterBackground=50,50,50,255
; Accent color
MeterColor=150,150,150,255
; Border color
SeparatorColor=50,50,50,255

; -------
; Symbols
; -------

; Net in, disk write symbol ▼
WriteSpeedPrefix="[\x25BC]"
; Net out, disk read symbol ▲
ReadSpeedPrefix="[\x25B2]"

; ---------------
; Update dividers
; ---------------

UpdateDividerTemp=3
UpdateDividerFan=10
UpdateDividerMemory=5
UpdateDividerDriveSpace=30
UpdateDividerCPUTopProcess=1
UpdateDividerGPUTopProcess=1
UpdateDividerIOTopProcess=1

; -----------
; Temperature
; -----------

; C, F, K
TemperatureUnit=C
TemperatureMax=100

; ------
; Uptime
; ------

; 0 - hide, 1 - show
UptimeBorderTop=0
UptimeBorderRight=1
UptimeBorderBottom=1
UptimeBorderLeft=1

; ---
; CPU
; ---

CPUHWiNFOSensorId=0xf0000400
CPUHWiNFOSensorInstance=0x0
CPUHWiNFOTemperatureEntryId=0x10000ff
; 0-5
CPUTopProcessesCount=3
; 0 - hide, 1 - show
CPUBorderTop=0
CPUBorderRight=1
CPUBorderBottom=1
CPUBorderLeft=1

; ------
; Memory
; ------

; 0-5
MemoryTopProcessesCount=3
; 0 - hide, 1 - show
MemoryBorderTop=0
MemoryBorderRight=1
MemoryBorderBottom=1
MemoryBorderLeft=1

; ---
; GPU
; ---

GPUHWiNFOSensorId=0xe0002000
GPUHWiNFOSensorInstance=0x0
GPUHWiNFOTemperatureEntryId=0x1000000
; Set to -1 to disable
GPUHWiNFOFanEntryId=0x8000000
GPUHWiNFOCoreLoadEntryId=0x7000000
GPUHWiNFOMemoryAllocatedEntryId=0x80000fc
; "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\" key index (it goes 0000, 0001, 00002)
GPUIndex=0000
; GPU total memory in bytes.
; Set when `HardwareInformation.qwMemorySize` is missing in the registry (HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\#GPUIndex#).
; Set to -1 to use value from registry
GPUTotalMemory=-1
; 0-5
GPUTopProcessesCount=2
; 0 - hide, 1 - show
GPUBorderTop=0
GPUBorderRight=1
GPUBorderBottom=1
GPUBorderLeft=1

; -------
; Network
; -------

; Set these for sure. http://speedtest.net
NetworkMaxDownloadMbits=94.33
NetworkMaxUploadMbits=91.30
; Set this if needed. Default: Best
NetworkInterface=Best
; 0 - hide, 1 - show
NetworkBorderTop=0
NetworkBorderRight=1
NetworkBorderBottom=1
NetworkBorderLeft=1

; ---
; I/O
; ---

; 0-5
IOTopProcessesCount=4
; 0 - hide, 1 - show
IOBorderTop=0
IOBorderRight=1
IOBorderBottom=1
IOBorderLeft=1

; -------------
; Drives Header
; -------------

; 0 - hide, 1 - show
DrivesHeaderBorderTop=0
DrivesHeaderBorderRight=1
DrivesHeaderBorderBottom=1
DrivesHeaderBorderLeft=1

; ------
; Drives
; ------

; Common for all drives
DriveHWiNFOSMARTSensorId=0xf0000100

Drive1=C:
; Common for S.M.A.R.T. and Drive sensors
Drive1HWiNFOSensorInstance=0x0
Drive1HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive1HWiNFORemainingLifeEntryId=0x7000000
; 0 - hide, 1 - show
Drive1BorderTop=0
Drive1BorderRight=1
Drive1BorderBottom=1
Drive1BorderLeft=1

Drive2=D:
Drive2HWiNFOSensorInstance=0x1
Drive2HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive2HWiNFORemainingLifeEntryId=-1
; 0 - hide, 1 - show
Drive2BorderTop=0
Drive2BorderRight=1
Drive2BorderBottom=1
Drive2BorderLeft=1

Drive3=E:
Drive3HWiNFOSensorInstance=0x2
Drive3HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive3HWiNFORemainingLifeEntryId=-1
; 0 - hide, 1 - show
Drive3BorderTop=0
Drive3BorderRight=1
Drive3BorderBottom=1
Drive3BorderLeft=1

Drive4=F:
Drive4HWiNFOSensorInstance=0x3
Drive4HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive4HWiNFORemainingLifeEntryId=-1
; 0 - hide, 1 - show
Drive4BorderTop=0
Drive4BorderRight=1
Drive4BorderBottom=1
Drive4BorderLeft=1

Drive5=G:
Drive5HWiNFOSensorInstance=0x4
Drive5HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive5HWiNFORemainingLifeEntryId=-1
; 0 - hide, 1 - show
Drive5BorderTop=0
Drive5BorderRight=1
Drive5BorderBottom=1
Drive5BorderLeft=1

Drive6=H:
Drive6HWiNFOSensorInstance=0x5
Drive6HWiNFOTemperatureEntryId=0x1000000
; Only for SSD. Set to -1 to disable
Drive6HWiNFORemainingLifeEntryId=-1
; 0 - hide, 1 - show
Drive6BorderTop=0
Drive6BorderRight=1
Drive6BorderBottom=1
Drive6BorderLeft=1

; ------
; Player
; ------

; https://docs.rainmeter.net/manual/measures/nowplaying/#playerlist
PlayerName=
; Skin header
PlayerTitle=
PlayerPath=
; 0 - hide, 1 - show
PlayerBorderTop=0
PlayerBorderRight=1
PlayerBorderBottom=1
PlayerBorderLeft=1
