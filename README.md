# Iruka (dolphin) Demo

This is a demo use of the [ReXGlue SDK](https://github.com/rexglue/rexglue-sdk) used to recompile Xbox 360 games to run on PC.

TODO: Add more information about the demo, how to run it, and what it does. but for now this is all you need to know :)

## Building and Running

1. Clone the repository
1. Ensure the `REXSDK` environment variable is set (system or CMakeUserPresets)
1. Compile the project using CMake ``` cmake --preset [platform] && cmake --build --preset [platform] ``` where platform is `linux-amd64` or `win-amd64`
1. Extract the files from `assets.zip` into the assets directory (or wherever you want, just make sure to point to it in the next step)
1. Run the compiled executable passing the 'Assets' directory `./iruka /path/to/Assets`

