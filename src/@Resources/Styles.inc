[StringStyle]
FontFace=#FontFace#
FontSize=#FontSize#
FontColor=#FontColor#
AntiAlias=1
StringEffect=#StringEffect#
FontEffectColor=#FontEffectColor#

[StringHeaderStyle]
X=#XCenter#
Y=#YStart#
StringAlign=CenterTop

[OffsetStyle]
X=#XStart#
Y=#YOffset#R

[OffsetSmallStyle]
X=#XStart#
Y=#YOffsetHalf#R

[AlignRightStyle]
X=#XEnd#
Y=0r
StringAlign=RightTop

[TopProcessValueStyle]
X=#XEnd#
Y=#YOffsetHalf#R
StringAlign=RightTop
FontSize=#FontSizeSmall#

[TopProcessNameStyle]
X=#XStart#
Y=0r
FontSize=#FontSizeSmall#
ClipString=1

[ContentHalfLeftLabel]
FontSize=#FontSizeSmall#

[ContentHalfRightLabel]
FontSize=#FontSizeSmall#
X=#XContentHalfStart#
Y=0r

; ---------
; Line meter
; ---------

[LineMeterStyle]
W=#ContentWidth#
H=#LineMeterHeight#
LineWidth=2
LineColor=#MeterColor#
SolidColor=#MeterBackground#
; For `Meter=Histogram`
PrimaryColor=#MeterColor#

[LineMeterHalfStyle]
W=#ContentHalfWidth#

[LineMeterHalfContainerStyle]
Shape=Rectangle 0,0,#ContentHalfWidth#,#LineMeterHeight# | StrokeWidth 0
X=0r
Y=0r

[LineMeterSmallHeightStyle]
H=#LineMeterHeightSmall#

[LineMeterSmallHeightContainerStyle]
Shape=Rectangle 0,0,#ContentWidth#,#LineMeterHeightSmall# | StrokeWidth 0
X=0r
Y=0r

[LineMeterContainerStringAlignLeftTopStyle]
X=0
Y=#LineMeterStringTopFix#
Padding=#PaddingSmall#,#PaddingSmall#,0,0
Padding=0,0,0,0
StringAlign=LeftTop

[LineMeterContainerStringAlignLeftBottomStyle]
X=0
Y=(#LineMeterHeight# + #LineMeterStringBottomFix#)
Padding=#PaddingSmall#,0,0,#PaddingSmall#
StringAlign=LeftBottom

[LineMeterSmallHeightContainerStringAlignLeftStyle]
X=0
Y=(#LineMeterHeightSmall# / 2)
Padding=#PaddingSmall#,#FontTopPaddingFix#,0,0
StringAlign=LeftCenter

; ---------
; Bar meter
; ---------

[BarStyle]
W=#ContentWidth#
H=#BarHeight#
BarOrientation=Horizontal
BarColor=#MeterColor#
SolidColor=#MeterBackground#

[BarFlipStyle]
W=#ContentWidth#
H=#BarHeight#
Flip=1
BarOrientation=Horizontal
BarColor=#MeterBackground#
SolidColor=#MeterColor#

[BarContainerStyle]
Shape=Rectangle 0,0,#ContentWidth#,#BarHeight# | StrokeWidth 0
X=0r
Y=0r

[BarContainerStringLeftStyle]
X=0
Y=(#BarHeight# / 2)
Padding=#PaddingSmall#,#FontTopPaddingFix#,0,0
StringAlign=LeftCenter

[BarContainerStringRightStyle]
X=#ContentWidth#
Y=(#BarHeight# / 2)
Padding=0,#FontTopPaddingFix#,#PaddingSmall#,0
StringAlign=RightCenter

; ----------
; Formatting
; ----------

[MeterBytesStringStyle]
NumOfDecimals=2
AutoScale=1k
; Use binary prefixes for size (e.g. GiB)
Text="%1iB"

[MeterBytesSpeedStringStyle]
NumOfDecimals=1
AutoScale=1k
Text="%1B/s"

[MeterTemperatureStringStyle]
; [\x00B0] - Degree Sign °
Text="%1[\x00B0]#TemperatureUnit#"

[MeterPercentStringStyle]
Text="%1%"

[BottomPaddingStyle]
X=0
Y=#Padding#R
UpdateDivider=-1

; Use 2px border to reduce Direct2D "aliasing" effect.
[BorderStyle]
; Top
Shape=Line 0,1, #CURRENTCONFIGWIDTH#,1 | StrokeWidth (#BorderTop# * 2) | Extend CommonModifiers
; Right
Shape2=Line (#CURRENTCONFIGWIDTH#-1),0, (#CURRENTCONFIGWIDTH#-1),#CURRENTCONFIGHEIGHT# | StrokeWidth (#BorderRight# * 2) | Extend CommonModifiers
; Bottom
Shape3=Line 0,(#CURRENTCONFIGHEIGHT#-1), #CURRENTCONFIGWIDTH#,(#CURRENTCONFIGHEIGHT#-1) | StrokeWidth (#BorderBottom# * 2) | Extend CommonModifiers
; Left
Shape4=Line 1,0, 1,#CURRENTCONFIGHEIGHT# | StrokeWidth (#BorderLeft# * 2) | Extend CommonModifiers
CommonModifiers=Stroke Color #SeparatorColor#
DynamicVariables=1
UpdateDivider=-1
