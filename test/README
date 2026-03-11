# Aquarium Controller (PlatformIO)

This project is now organized for PlatformIO in VS Code.

## Project Layout
- `platformio.ini` - board/build/dependency configuration
- `src/` - `.cpp` source files (entry point is `main.cpp`)
- `include/` - shared headers and hardware pin map (`setup.h`)

## Build & Upload (VS Code)
1. Open this folder in VS Code.
2. Open PlatformIO sidebar.
3. Select environment: `esp32-s3-devkitc-1`.
4. Run **Build**, then **Upload**.
5. Open **Monitor** at `115200` baud.

## Notes
- TFT_eSPI is configured by forcing `include/setup.h` via `build_flags`.
- Keep all pin definitions in `include/setup.h` as the single source of truth.
