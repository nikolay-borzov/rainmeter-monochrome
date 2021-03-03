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
- [Other configuration variables](#other-configuration-variables)
- [Configuring font](#configuring-font)

## Requirements

- [Rainmeter](https://www.rainmeter.net/) 4.3.1 or higher
- [HWiNFO](https://www.hwinfo.com/). Installer is preferable because Portable seems to have problems with autostart
- [JetBrains Mono](https://www.jetbrains.com/lp/mono/) font, unless you want use font of your choice

## Skins

### Uptime

Displays computer uptime

![Uptime skin image](images/uptime.png)

### CPU

Displays CPU usage/temperature values and values as line meter, processes count and 1-5 top processes. When "CPU" label is hovered the processor name is displayed as a tooltip

![CPU skin image](images/cpu.png)

<details>
  <summary>Configuration</summary>

  See `CPU` section in `Config.inc`

  - `HWiNFO_CPU0_DTS_SensorId` and `HWiNFO_CPU0_DTS_SensorInstance` - CPU DTS Sensor ID and Instance (**Sensor Details** section in "HWiNFO Shared Memory Viewer"). See "Setting HWiNFO related values" section in `Config.inc` for more details
  - `HWiNFO_CPU0_DTS_CoreMax` - CPU DTS Core Max Entry ID (**Entry Details** section)
  - `CPUTopProcessesCount` - Number of top processes using CPU displayed. Setting value to `0` hides "Top processes" block
</details>

### Memory

Displays RAM usage and 1-5 top processes using RAM. When used memory bar is hovered a percent of used memory is displayed

![Memory skin image](images/memory.png)

<details>
  <summary>Configuration</summary>

  See `Memory` section in `Config.inc`

  - `MemoryTopProcessesCount` - Number of top processes using RAM displayed. Setting value to `0` hides "Top processes" block
</details>

### GPU

Displays GPU usage/temperature, fan speed, dedicated memory usage and 1-5 top processes using GPU. When used dedicated bar is hovered a percent of used memory is displayed. When "GPU" label is hovered the GPU name is displayed as a tooltip

![GPU skin image](images/gpu.png)

<details>
  <summary>Configuration</summary>

  See `GPU` section in `Config.inc`

  - `HWiNFO_GPU0_SensorId` and `HWiNFO_GPU0_SensorInstance` - GPU  Sensor ID and Instance
  - `HWiNFO_GPU0_Temp` - GPU Temperature Entry ID
  - `HWiNFO_GPU0_Fan` - GPU Fan Entry ID
  - `GPUTopProcessesCount` - Number of top processes using GPU displayed. Setting value to `0` hides "Top processes" block
  - `GPU_Registry_GUID` - Registry key name where GPU name can be read. Value is displayed as a tooltip when "GPU" label is hovered
</details>

### Network

Shows Download/Upload speed in kB/s and connections count

![Network skin image](images/network.png)

<details>
  <summary>Configuration</summary>

  See `Network` section in `Config.inc`

  - `NetMaxDownloadMbits` and `NetMaxUploadMbits` - Maximum download/upload speed of your network. Use http://speedtest.net to get these values
  - `NetInterface` - Network interface name. Set if default value doesn't match your network adapter
</details>

### I/O

Displays I/O information (file, network and device I/Os).

![I/O skin image](images/io.png)

<details>
  <summary>Configuration</summary>

  See `I/O` section in `Config.inc`

  - `IOTopProcessesCount` - Number of top processes using I/O displayed. Setting value to `0` hides "Top processes Read+Write" block
</details>

### Drive

Displays drive's free space, temperature, activity, read/write speed

![Drive skin image](images/drive.png)

<details>
  <summary>Configuration</summary>

  See `Drives` section in `Config.inc`

  You might want to load `Drive_Header` skin to add header for drives skins

  - `HWiNFO_SMART_SensorId` - S.M.A.R.T. Sensor ID (the same for all drives)
  - `HWiNFO_SMART_DriveTemperature` - S.M.A.R.T. Drive Temperature Entry ID (the same for all drives)
  - `Drive_1`...`Drive_5` - Drive's letter (e.g. `C:`)
  - `Drive_1_HWiNFOSensorInstance`...`Drive_5_HWiNFOSensorInstance` - S.M.A.R.T. Sensor Instance
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
</details>

## Other configuration variables

See `Temperature` section in `Config.inc`

- `TempUnit` - Temperature unit to use. `C` for Celsius, `F` for Fahrenheit, `K` for Kelvin
- `TempMax`- Maximum temperature. It's needed for line meter

You can also override some variables from `Variables.inc` by copying them to `Config.inc`:

- `SkinWidth` - Skin width
- `BarHeight` - Height of a bar meter
- `LineMeterHeight` - Height of a line meter
- `LineMeterHeightSmall` - Height of a short line meter
- `FontColor` - Default font color
- `FontColorDim` - Dimmed font color (less important information)
- `FontColorDisabled` - Font color for disabled label (not important information like zero write speed)
- `StringEffect` and `FontEffectColor` - Text effect (`Border`, `Shadow` or `None`) and its color
- `SkinBackground` - Skin background color
- `MeterBackground` - Meter background color
- `MeterColor` - Skin accent color
- `SeparatorColor` - Skin border color
- `WriteSpeedPrefix` and `ReadSpeedPrefix` - Symbols to use as prefixes for write/read speed
- `UpdateDividerCPUTopProcess` - CPU Top processes update divider ([read more about dividers](https://docs.rainmeter.net/tips/update-guide/))
- `UpdateDividerMemoryTopProcess` - Memory Top processes update divider
- `UpdateDividerGPUTopProcess` - GPU Top processes update divider
- `UpdateDividerIOTopProcess` - I/O Top processes update divider
- `UpdateDividerTemp` - Temperature update divider
- `UpdateDividerFan` - Fan speed update divider
- `UpdateDividerMemory` - Used memory update divider
- `UpdateDividerDriveSpace` - Drive space update divider

## Configuring font

[Default configuration](src/@Resources/Config.inc) contains adjustments for [JetBrains Mono](https://www.jetbrains.com/lp/mono/) font.

If you want to use another font you'll need to change some variables in `Config.inc`:

- `FontFace` - Font to use
- `FontTopPaddingFix` - Top offset for bar and short line meters (e.g. Drive free space)
- `LineMeterStringTopFix` - Bottom top offset for string located in the top of meter higher than one text row (e.g. CPU usage %).
- `LineMeterStringBottomFix` - Bottom offset for string located in the bottom of meter higher than one text row (e.g. Drive write speed)
- `FontSize` and `LineHeight` - Main font size and line height
- `FontSizeSmall` and `LineHeightSmall` - Smaller font size and line height
