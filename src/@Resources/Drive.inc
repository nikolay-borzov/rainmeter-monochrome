[Variables]
ActiveTimeFontColor=#FontColorDisabled#
ReadSpeedFontColor=#FontColorDisabled#
WriteSpeedFontColor=#FontColorDisabled#

; ========
; Measures
; ========

[MeasureFreeSpace]
Measure=FreeDiskSpace
Drive=#Drive#
UpdateDivider=#UpdateDividerDriveSpace#

[MeasureScriptAutoScaleSize]
Measure=Script
ScriptFile=#@#AutoScaleSize.lua
Disabled=1

[MeasureDriveLabel]
Measure=FreeDiskSpace
Drive=#Drive#
Label=1
UpdateDivider=-1

[MeasureIdleTime]
Measure=Plugin
Plugin=UsageMonitor
; For PhysicalDisk you have to specify index because "Name" would be like "3 C:"
Category=LogicalDisk
Counter=% Idle Time
Name=#Drive#
; Should fix the issue with counter retuning values > 100 (e.g. `100.042`)
Percent=1
MinValue=0
MaxValue=100

; Alternatively HWiNFO drive `Total Activity` can be used
[MeasureActiveTime]
Measure=Calc
Formula=(100 - MeasureIdleTime)
MinValue=0
MaxValue=100
IfCondition=MeasureActiveTime > 0
IfTrueAction=[!SetVariable "ActiveTimeFontColor" #FontColor#][!Redraw]
IfFalseAction=[!SetVariable "ActiveTimeFontColor" #FontColorDisabled#][!Redraw]

[MeasureTemp]
Measure=Plugin
PlugIn=HWiNFO.dll
HWiNFOSensorId=#HWiNFO_SMART_SensorId#
HWiNFOSensorInstance=#Drive_HWiNFOSensorInstance#
HWiNFOEntryId=#HWiNFO_SMART_DriveTemperature#
HWiNFOType=CurrentValue
MinValue=0
MaxValue=#TempMax#
UpdateDivider=#UpdateDividerTemp#

[MeasureReadSpeed]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Read Bytes/sec
Name=#Drive#
IfCondition=MeasureReadSpeed > 0
IfTrueAction=[!SetVariable "ReadSpeedFontColor" #FontColor#][!Redraw]
IfFalseAction=[!SetVariable "ReadSpeedFontColor" #FontColorDisabled#][!Redraw]

[MeasureReadSpeedScaled]
Measure=Calc
Formula=MeasureReadSpeed

[MeasureWriteSpeed]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Write Bytes/sec
Name=#Drive#
IfCondition=MeasureWriteSpeed > 0
IfTrueAction=[!SetVariable "WriteSpeedFontColor" #FontColor#][!Redraw]
IfFalseAction=[!SetVariable "WriteSpeedFontColor" #FontColorDisabled#][!Redraw]

[MeasureWriteSpeedScaled]
Measure=Calc
Formula=MeasureWriteSpeed

; ======
; Meters
; ======

; -----
; Label
; -----

[MeterDriveLabel]
Meter=String
MeasureName=MeasureDriveLabel
MeterStyle=StringStyle | OffsetStyle
Text="%1 (#Drive#)"
TooltipText="#LabelTotal#: [&MeasureScriptAutoScaleSize:AutoScale([&MeasureFreeSpace:MaxValue], 2)]"
UpdateDivider=-1
DynamicVariables=1

; -----------
; Temperature
; -----------

[MeterTempString]
Meter=String
MeasureName=MeasureTemp
MeterStyle=StringStyle | AlignRightStyle | MeterTemperatureStringStyle
UpdateDivider=#UpdateDividerTemp#

; ----------
; Free space
; ----------

[MeterFreeSpaceBar]
Meter=Bar
MeasureName=MeasureFreeSpace
MeterStyle=StringStyle | OffsetSmallStyle | BarFlipStyle
MouseOverAction=[!SetOption MeterFreeSpaceString Percentual 1][!SetOption MeterFreeSpaceString Text "%1%"][!UpdateMeter MeterFreeSpaceString][!Redraw]
MouseLeaveAction=[!SetOption MeterFreeSpaceString Percentual 0][!SetOption MeterFreeSpaceString Text "%1iB"][!UpdateMeter MeterFreeSpaceString][!Redraw]
UpdateDivider=#UpdateDividerDriveSpace#

[MeterFreeSpaceBarContainer]
Meter=Shape
MeterStyle=BarContainerStyle
UpdateDivider=-1

[MeterFreeSpaceString]
Meter=String
MeasureName=MeasureFreeSpace
MeterStyle=StringStyle | BarContainerStringRightStyle | MeterBytesStringStyle
Container=MeterFreeSpaceBarContainer
UpdateDivider=#UpdateDividerDriveSpace#

; ------------------------------------
; Active time and Temperature labels
; ------------------------------------

[MeterActiveTimeLabel]
Meter=String
MeterStyle=StringStyle | OffsetStyle | ContentHalfLeftLabel
Text=#LabelActiveTime#
UpdateDivider=-1

[MeterReadWriteLabel]
Meter=String
MeterStyle=StringStyle | ContentHalfRightLabel
Text=#LabelReadWrite#
UpdateDivider=-1

; -------------
; Active time
; -------------

[MeterActiveTimeLine]
Meter=Line
MeasureName=MeasureActiveTime
MeterStyle=OffsetSmallStyle | LineMeterStyle | LineMeterHalfStyle

[MeterActiveTimeLineContainer]
Meter=Shape
MeterStyle=LineMeterHalfContainerStyle
UpdateDivider=-1

[MeterActiveTimeString]
Meter=String
MeterStyle=StringStyle | MeterPercentStringStyle | LineMeterContainerStringAlignLeftTopStyle
FontColor=#ActiveTimeFontColor#
DynamicVariables=1
Text="[MeasureActiveTime:%,1]%"
Container=MeterActiveTimeLineContainer

; ----------------
; Read/Write Speed
; ----------------

[MeterReadWriteSpeedContainer]
Meter=Shape
MeterStyle=LineMeterHalfContainerStyle
X=#XContentHalfStart#
UpdateDivider=-1

[MeterReadSpeedString]
Meter=String
MeasureName=MeasureReadSpeedScaled
MeterStyle=StringStyle | LineMeterContainerStringAlignLeftTopStyle | MeterBytesSpeedStringStyle
DynamicVariables=1
Text="#ReadSpeedPrefix# %1B/s"
Padding=0,#PaddingSmall#,0,0
FontColor=#ReadSpeedFontColor#
Container=MeterReadWriteSpeedContainer

[MeterWriteSpeedString]
Meter=String
MeasureName=MeasureWriteSpeedScaled
MeterStyle=StringStyle | LineMeterContainerStringAlignLeftBottomStyle | MeterBytesSpeedStringStyle
DynamicVariables=1
Text="#WriteSpeedPrefix# %1B/s"
Padding=0,0,0,#PaddingSmall#
FontColor=#WriteSpeedFontColor#
Container=MeterReadWriteSpeedContainer

; -------

[MeterBottomPadding]
Meter=Shape
MeterStyle=BottomPaddingStyle

[MeterBorder]
Meter=Shape
MeterStyle=BorderStyle
