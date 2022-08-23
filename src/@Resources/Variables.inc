[Variables]

; -----
; Sizes
; -----
Padding=10
PaddingSmall=(#Padding# / 2)
SkinWidth=280
ContentWidth=(#SkinWidth# - 2 * #Padding#)
; Content divided into two columns
ContentHalfWidth=(#ContentWidth# / 2 - #PaddingSmall#)

; ---------
; Positions
; ---------
XCenter=(#SkinWidth# / 2)
XStart=#Padding#
XEnd=(#SkinWidth# - #Padding#)
YStart=#Padding#
; Second column content start
XContentHalfStart=(#XEnd# - #ContentHalfWidth#)

; --------------------
; Meter specific sizes
; ---------------------
BarHeight=20
LineMeterHeight=50
LineMeterHeightSmall=(#LineMeterHeight# / 2)

; ----------
; Distances
; ----------
YOffset=#Padding#
YOffsetHalf=(#Padding# / 2)

; -----
; Fonts
; -----
; Fira Code, Cascadia Code, JetBrains Mono or other font
FontFace=JetBrains Mono
FontSize=12
; Line height in pixels.
; Should be big enough to fit string with font size equal to FontSize
LineHeight=20
FontSizeSmall=10
; Should be big enough to fit string with font size equal to FontSizeSmall
LineHeightSmall=16
FontColor=255,255,255,255
FontColorDim=255,255,255,200
FontColorDisabled=255,255,255,150

; Border, Shadow or None
StringEffect=Border
FontEffectColor=34,34,34,255

; -------------------------
; Font specific adjustments
; -------------------------

; Align string vertically if a font has offset
FontTopPaddingFix=1
; Align font string top inside line container
LineMeterStringTopFix=-3
; Align font string bottom inside line container
LineMeterStringBottomFix=5

; ------
; Colors
; ------
SkinBackground=34,34,34,255
MeterBackground=50,50,50,255
MeterColor=150,150,150,255
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
UpdateDividerMemoryTopProcess=#UpdateDividerMemory#
UpdateDividerGPUTopProcess=1
UpdateDividerIOTopProcess=1

; -------------
; Top processes
; -------------
TopProcessSubstitute="":"---"
TopProcessIgnore=_Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc|WmiPrvSE

; -------------------
; Border toggle flags
;--------------------
; These ones are overridden per skin (see below)
; 0 - hide, 1 - show
BorderTop=0
BorderRight=1
BorderBottom=1
BorderLeft=1

; Default border flags pes skin

UptimeBorderTop=0
UptimeBorderRight=1
UptimeBorderBottom=1
UptimeBorderLeft=1

CPUBorderTop=0
CPUBorderRight=1
CPUBorderBottom=1
CPUBorderLeft=1

MemoryBorderTop=0
MemoryBorderRight=1
MemoryBorderBottom=1
MemoryBorderLeft=1

GPUBorderTop=0
GPUBorderRight=1
GPUBorderBottom=1
GPUBorderLeft=1

NetworkBorderTop=0
NetworkBorderRight=1
NetworkBorderBottom=1
NetworkBorderLeft=1

IOBorderTop=0
IOBorderRight=1
IOBorderBottom=1
IOBorderLeft=1

DrivesHeaderBorderTop=0
DrivesHeaderBorderRight=1
DrivesHeaderBorderBottom=1
DrivesHeaderBorderLeft=1

Drive1BorderTop=0
Drive1BorderRight=1
Drive1BorderBottom=1
Drive1BorderLeft=1

Drive2BorderTop=0
Drive2BorderRight=1
Drive2BorderBottom=1
Drive2BorderLeft=1

Drive3BorderTop=0
Drive3BorderRight=1
Drive3BorderBottom=1
Drive3BorderLeft=1

Drive4BorderTop=0
Drive4BorderRight=1
Drive4BorderBottom=1
Drive4BorderLeft=1

Drive5BorderTop=0
Drive5BorderRight=1
Drive5BorderBottom=1
Drive5BorderLeft=1

PlayerBorderTop=0
PlayerBorderRight=1
PlayerBorderBottom=1
PlayerBorderLeft=1
