# T12 Bitmap Group Exporter

Figma plugin that exports each selected group as a 1-bit monochrome C++ bitmap variable.

## Install locally

1. Open Figma desktop.
2. Go to **Plugins → Development → Import plugin from manifest…**.
3. Select `manifest.json` in this folder.
4. Select the groups, run the plugin, and click **Export PNGs**.

The plugin downloads one `t12_bitmaps.h` file containing dimensions, packed row-major pixel bytes, and a `Bitmap1bpp` descriptor for every selected node.
