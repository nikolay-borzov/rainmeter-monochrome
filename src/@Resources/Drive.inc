[Variables]
ActivityFontColor=#FontColorDisabled#
ReadSpeedFontColor=#FontColorDisabled#
WriteSpeedFontColor=#FontColorDisabled#
RemainingLifeString=""

; --------------
; Display flags
; --------------

[RemainingLifeDisplay]
Measure=Calc
IfCondition=#DriveHWiNFORemainingLifeEntryId# <> -1
IfTrueAction=[!EnableMeasure MeasureRemainingLife]
UpdateDivider=-1

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

[MeasureDriveIdentifier]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#DriveHWiNFOSMARTSensorId#
HWiNFOSensorInstance=#DriveHWiNFOSensorInstance#
HWiNFOType=SensorName
RegExpSubstitute=1
Substitute="S.M.A.R.T.: ":"", " (\([^(]+\))$":""
UpdateDivider=-1

[MeasureRemainingLife]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#DriveHWiNFOSMARTSensorId#
HWiNFOSensorInstance=#DriveHWiNFOSensorInstance#
HWiNFOEntryId=#DriveHWiNFORemainingLifeEntryId#
HWiNFOType=CurrentValue
UpdateDivider=-1
Disabled=1
IfAboveValue=0
IfAboveAction=[!SetVariable "RemainingLifeString" "#CRLF##LabelDriveRemainingLife#: [MeasureRemainingLife]%"]

; Use "LogicalDisk" in order to track logical disk parameters
[MeasureActivity]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=% Disk Time
Name=#Drive#
MinValue=0
; Performance Monitor reports values > 100
MaxValue=100
IfCondition=MeasureActivity > 0
IfTrueAction=[!SetVariable "ActivityFontColor" #FontColor#][!Redraw]
IfFalseAction=[!SetVariable "ActivityFontColor" #FontColorDisabled#][!Redraw]

[MeasureTemperature]
Measure=Plugin
PlugIn=HWiNFO.dll
HWiNFOSensorId=#DriveHWiNFOSMARTSensorId#
HWiNFOSensorInstance=#DriveHWiNFOSensorInstance#
HWiNFOEntryId=#DriveHWiNFOTemperatureEntryId#
HWiNFOType=CurrentValue
MinValue=0
MaxValue=#TemperatureMax#
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
TooltipText="[MeasureDriveIdentifier]#CRLF##LabeDrivelTotal#: [&MeasureScriptAutoScaleSize:AutoScale([&MeasureFreeSpace:MaxValue], 2)]#RemainingLifeString#"
UpdateDivider=-1
DynamicVariables=1

; -----------
; Temperature
; -----------

[MeterTemperatureString]
Meter=String
MeasureName=MeasureTemperature
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
; Activity and Temperature labels
; ------------------------------------

[MeterActivityLabel]
Meter=String
MeterStyle=StringStyle | OffsetStyle | ContentHalfLeftLabel
Text=#LabelDriveActivity#
UpdateDivider=-1

[MeterReadWriteLabel]
Meter=String
MeterStyle=StringStyle | ContentHalfRightLabel
Text=#LabelDriveReadWrite#
UpdateDivider=-1

; -------------
; Activity
; -------------

[MeterActivityLine]
Meter=Line
MeasureName=MeasureActivity
MeterStyle=OffsetSmallStyle | LineMeterStyle | LineMeterHalfStyle

[MeterActivityLineContainer]
Meter=Shape
MeterStyle=LineMeterHalfContainerStyle
UpdateDivider=-1

[MeterActivityString]
Meter=String
MeterStyle=StringStyle | MeterPercentStringStyle | LineMeterContainerStringAlignLeftTopStyle
FontColor=#ActivityFontColor#
DynamicVariables=1
Text="[MeasureActivity:%,1]%"
Container=MeterActivityLineContainer

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
