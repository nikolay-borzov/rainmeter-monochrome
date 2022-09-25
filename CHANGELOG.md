## v1.6.0 (2022-09-25)

- Drive: Apparently HWiNFO can't provide Disk activity for logical disks. Also old issue with PerfMon providing values > 100 is solved by setting `MinValue` and `MaxValue`
- Player: Fix Artist and Title wrapping
- GPU: Fade usage string when value is `0`

## v1.5.0 (2022-08-23)

- GPU: Get GPU usage value and allocated memory from HWiNFO
- GPU: Fix getting GPU total memory. Support GPU with > 4 GiB
- GPU: Allow setting GPU total memory as workaround when there is no total memory value in the registry
- GPU: Allow hiding GPU Fan
- GPU: Rename GPU "Dedicated memory" to less verbose "Memory"
- Drive: Get drive total activity from HWiNFO
- Drive: Display SSD remaining life in a tooltip
- Unify variables' names

## v1.4.0 (2022-03-20)

- Drive: how Drive identifier in tooltip
- Drive: Add separate variables for HWiNFO Drive S.M.A.R.T. Temperature Entry ID
- Add `Drive_6` skin

## v1.3.1 (2021-10-29)

- Memory, Drive, GPU: Use binary prefixes for memory values (e.g. GiB)

## v1.3.0 (2021-04-16)

- Add localization support. Available locales are "en" and "ru"
- Add context menu item "Open Config" that opens `Config.inc`

## v1.2.0 (2021-04-07)

-To keep user values on update copy all configurable variables from `Variables.inc` to `Config.inc`

- Highlight that HWiNFO < 7.0.0 must be used unless you have Pro subscription
- Network: Fix missing default value for `NetworkInterface`
- Drive: Add tooltip for Drive label displaying disk total size
- GPU: Remove `GPU_Registry_GUID` variable - take adapter name and total dedicated memory size (as reported by `dxdiag`) from WinSAT
- Network: Fade zero network In and Out values

## v1.1.0 (2021-03-21)

- Allow toggling skin borders visibility:

```ini
; 0 - hide, 1 - show
CPUBorderTop=1
CPUBorderRight=0
CPUBorderBottom=1
CPUBorderLeft=0
```

## v1.0.0 (2021-03-03)

- Initial public version updated
