A minimalistic monochrome skins for [Rainmeter](https://www.rainmeter.net/)

![Uptime skin image](images/skin_preview.png)

- [Requirements](#requirements)
- [Skins](#skins)
  - [Uptime](#uptime)
  - [CPU](#cpu)
  - [Memory](#memory)
  - [GPU](#gpu)
  - [Network](#network)
  - [I/O](#io)
  - [Drive](#drive)
  - [Player](#player)
- [Other meter specific configuration variables](#other-meter-specific-configuration-variables)
- [Common configuration](#common-configuration)
  - [Sizes](#sizes)
  - [Font](#font)
  - [Colors](#colors)
  - [Symbols](#symbols)
  - [Update dividers](#update-dividers)
- [Localization](#localization)
- [Issues](#issues)
  - [Wrong value for available GPU Dedicated Memory](#wrong-value-for-available-gpu-dedicated-memory)

## Requirements

- Windows 10
- [Rainmeter](https://www.rainmeter.net/) 4.3.1 or higher
- [HWiNFO](https://www.hwinfo.com/). Use version < 7.0.0 unless you have Pro subscription (e.g. [v6.42](https://www.fosshub.com/HWiNFO-old.html), [read why](https://docs.rainmeter.net/tips/hwinfo/)). Installer is preferable because Portable seems to have problems with autostart
- [JetBrains Mono](https://www.jetbrains.com/lp/mono/) font, unless you want use font of your choice

## Skins

Note that you can open `Config.inc` by clicking on "Open Config" item in the skin context menu

### Uptime

Displays computer uptime

![Uptime skin image](images/uptime.png)

<details>
  <summary>Configuration</summary>

See `Uptime` section in `Config.inc`

- `UptimeBorderTop`, `UptimeBorderRight`, `UptimeBorderBottom` and `UptimeBorderLeft` - Toggles skin border visibility
</details>

### CPU

Displays CPU usage/temperature values and values as line meter, processes count and 1-5 top processes. When "CPU" label is hovered the processor name is displayed as a tooltip

![CPU skin image](images/cpu.png)

<details>
  <summary>Configuration</summary>

See `CPU` section in `Config.inc`

- `HWiNFO_CPU0_SensorId` and `HWiNFO_CPU0_SensorInstance` - CPU Sensor ID and Instance (**Sensor Details** section in "HWiNFO Shared Memory Viewer") that provides CPU temperature value. See "Setting HWiNFO related values" section in `Config.inc` for more details
- `HWiNFO_CPU0_Temp` - CPU temperature Entry ID (**Entry Details** section)
- `CPUTopProcessesCount` - Number of top processes using CPU displayed. Setting value to `0` hides "Top processes" block
- `CPUBorderTop`, `CPUBorderRight`, `CPUBorderBottom` and `CPUBorderLeft` - Toggles skin border visibility
</details>

### Memory

Displays RAM usage and 1-5 top processes using RAM. When used memory bar is hovered a percent of used memory is displayed

![Memory skin image](images/memory.png)

<details>
  <summary>Configuration</summary>

See `Memory` section in `Config.inc`

- `MemoryTopProcessesCount` - Number of top processes using RAM displayed. Setting value to `0` hides "Top processes" block
- `MemoryBorderTop`, `MemoryBorderRight`, `MemoryBorderBottom` and `MemoryBorderLeft` - Toggles skin border visibility
</details>

### GPU

Displays GPU usage/temperature, fan speed, dedicated memory usage and 1-5 top processes using GPU. When used dedicated bar is hovered a percent of used memory is displayed. When "GPU" label is hovered the GPU name is displayed as a tooltip

![GPU skin image](images/gpu.png)

<details>
  <summary>Configuration</summary>

See `GPU` section in `Config.inc`

- `HWiNFO_GPU0_SensorId` and `HWiNFO_GPU0_SensorInstance` - GPU Sensor ID and Instance
- `HWiNFO_GPU0_Temp` - GPU Temperature Entry ID
- `HWiNFO_GPU0_Fan` - GPU Fan Entry ID
- `GPUTopProcessesCount` - Number of top processes using GPU displayed. Setting value to `0` hides "Top processes" block
- `GPU_Registry_GUID` - Registry key name where GPU name can be read. Value is displayed as a tooltip when "GPU" label is hovered
- `GPUBorderTop`, `GPUBorderRight`, `GPUBorderBottom` and `GPUBorderLeft` - Toggles skin border visibility
</details>

### Network

Shows Download/Upload speed in kB/s and connections count

![Network skin image](images/network.png)

<details>
  <summary>Configuration</summary>

See `Network` section in `Config.inc`

- `NetworkMaxDownloadMbits` and `NetworkMaxUploadMbits` - Maximum download/upload speed of your network. Use http://speedtest.net to get these values
- `NetworkInterface` - Network interface name. Set if default value doesn't match your network adapter
- `NetworkBorderTop`, `NetworkBorderRight`, `NetworkBorderBottom` and `NetworkBorderLeft` - Toggles skin border visibility
</details>

### I/O

Displays I/O information (file, network and device I/Os).

![I/O skin image](images/io.png)

<details>
  <summary>Configuration</summary>

See `I/O` section in `Config.inc`

- `IOTopProcessesCount` - Number of top processes using I/O displayed. Setting value to `0` hides "Top processes Read+Write" block
- `IOBorderTop`, `IOBorderRight`, `IOBorderBottom` and `IOBorderLeft` - Toggles skin border visibility
</details>

### Drive

Displays drive's free space, temperature, activity, read/write speed. When disk label is hovered a total size is displayed.

![Drive skin image](images/drive.png)

<details>
  <summary>Configuration</summary>

See `Drives` section in `Config.inc`

You might want to load `Drive_Header` skin to add header for drives skins

- `HWiNFO_SMART_SensorId` - S.M.A.R.T. Sensor ID (the same for all drives)
- `HWiNFO_SMART_DriveTemperature` - S.M.A.R.T. Drive Temperature Entry ID (the same for all drives)
- `Drive_1`...`Drive_5` - Drive's letter (e.g. `C:`)
- `Drive_1_HWiNFOSensorInstance`...`Drive_5_HWiNFOSensorInstance` - S.M.A.R.T. Sensor Instance
- `DrivesHeaderBorderTop`, `DrivesHeaderBorderRight`, `DrivesHeaderBorderBottom` and `DrivesHeaderBorderLeft` - Toggles Drives Header skin border visibility
- `Drive_1_BorderTop`...`Drive_5_BorderTop`, `Drive_1_BorderRight`...`Drive_5_BorderRight`, `Drive_1_BorderBottom`...`Drive_5_BorderBottom` and `Drive_1_BorderLeft`...`Drive_5_BorderLeft` - Toggles skin border visibility
</details>

### Player

Displays currently playing track information - track title, track artist and track duration. It has basic controls - previous track, pause/play. next track. When header label is clicked player is launched/closed

![Player skin image](images/player.png)

<details>
  <summary>Configuration</summary>

See `Player` section in `Config.inc`

- `PlayerName` - Player application name (see [supported players list](https://docs.rainmeter.net/manual/measures/nowplaying/#playerlist))
- `PlayerTitle` - Skin header text (e.g. "My Jukebox")
- `PlayerPath` - Player executable absolute path
- `PlayerBorderTop`, `PlayerBorderRight`, `PlayerBorderBottom` and `PlayerBorderLeft` - Toggles skin border visibility
</details>

## Other meter specific configuration variables

See `Temperature` section in `Config.inc`

- `TempUnit` - Temperature unit to use. `C` for Celsius, `F` for Fahrenheit, `K` for Kelvin
- `TempMax`- Maximum temperature. It's needed for line meter

## Common configuration

### Sizes

- `SkinWidth` - Skin width in pixels
- `BarHeight` - Height of a bar meter
- `LineMeterHeight` - Height of a line meter

### Font

[Default configuration](src/@Resources/Config.inc) contains adjustments for [JetBrains Mono](https://www.jetbrains.com/lp/mono/) font.

If you want to use another font you'll need to change some variables in `Config.inc`:

- `FontFace` - Font to use
- `FontTopPaddingFix` - Top offset for bar and short line meters (e.g. Drive free space)
- `LineMeterStringTopFix` - Bottom top offset for string located in the top of meter higher than one text row (e.g. CPU usage %).
- `LineMeterStringBottomFix` - Bottom offset for string located in the bottom of meter higher than one text row (e.g. Drive write speed)
- `FontSize` and `LineHeight` - Main font size and line height
- `FontSizeSmall` and `LineHeightSmall` - Smaller font size and line height
- `StringEffect` - Font effect type - `Border`, `Shadow` or `None`
- `FontEffectColor` - Font effect color
- `FontColor` - Default font color
- `FontColorDim` - Dimmed font color (less important information)
- `FontColorDisabled` - Font color for disabled label (not important information like zero write speed)

### Colors

- `SkinBackground` - Skin background color
- `MeterBackground` - Meter box background color
- `MeterColor` - Accent color
- `SeparatorColor` - Border color

### Symbols

- `WriteSpeedPrefix` and `ReadSpeedPrefix` - Symbols to use as prefixes for write/read speed

### Update dividers

- `UpdateDividerCPUTopProcess` - CPU Top processes update divider ([read more about dividers](https://docs.rainmeter.net/tips/update-guide/))
- `UpdateDividerMemoryTopProcess` - Memory Top processes update divider
- `UpdateDividerGPUTopProcess` - GPU Top processes update divider
- `UpdateDividerIOTopProcess` - I/O Top processes update divider
- `UpdateDividerTemp` - Temperature update divider
- `UpdateDividerFan` - Fan speed update divider
- `UpdateDividerMemory` - Used memory update divider
- `UpdateDividerDriveSpace` - Drive space update divider

## Localization

You can chose language to be used for labels by setting `Locale` variable in the config. Supported locales are "en" and "ru". Feel free to add other locales via PR

## Issues

### Wrong value for available GPU Dedicated Memory

Total available dedicated memory value is taken from [WinSAT](https://en.wikipedia.org/wiki/Windows_System_Assessment_Tool) registry key `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\WinSAT`. If there is no such key in your registry you need to run WinSAT formal check. For that open Command Prompt as administrator and type:

```
winsat formal
```

Wait till the check is done and refresh all skins.
