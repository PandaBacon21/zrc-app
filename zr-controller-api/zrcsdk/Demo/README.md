# Zoom Rooms Controller SDK Sample App

The is a sample app for Zoom Rooms Controller SDK. This demo app receives commands from commandline and demonstrates how to pair with a Zoom Rooms Client, start an instant meeting, mute audio, leave meeting and unpair with the Zoom Rooms Client.

## Prerequisites

- The Zoom Room must be logged in order for the ZRC SDK Sample App to connect. 
   
## Getting Started
### Download Zoom Rooms Controller SDK from developers.zoom.us

1. Please decompress the downloaded `zrcsdk.zip` and copy the files in the decompressed folder to these `Demo` folders
   1. copy `include` folder to `Demo/include/`
   2. `libZRCSdk.so` to `Demo/libs`
   3. `Windows Only` Put the `dll` folder along with your binary exe.
2. `Linux Only` Demo uses `libuv-1.9.1` as its run-loop. Get `libuv.a` to `Demo/libs`, copy `libuv` headers to  `Demo/include/libuv`.
3. Execute `cmake .`in `Demo/` folder. 
4. Execute `make` in `Demo/` folder to build.
5. Execute `./Demo` to run the Demo application.
6. `Windows Only` If Develop with Visual Studio, set configuration type to `Release x64`.

```
# Verify the file structure

Demo
├── CMakeLists.txt              # CMakeLists
├── include                     # DemoApp headers folder
│   ├── MyZRCSDKApp.h
│   ├── ZRCSDKSink.h
│   ├── include                 # ZRC SDK headers folder
│   │   ├── ServiceComponents
│   ├── libuv                   # libuv headers folder
│   │   └── include
│   └── sinks.h
├── libs                        # DemoApp libs folder
│   ├── libZRCSdk.so
│   └── libuv.a
└── src                         # DemoApp src folder
    ├── MyZRCSDKApp.cpp
    └── main.cpp
```

## Try the Demo
1. Input `pair xxxx-xxxx-xxxx-xxx` in commandline to pair the Zoom Room.
2. Input `startmeeting` in commandline to start an instant meeting.
3. Input `mute` in commandline to mute Zoom Room's audio in the meeting.
4. Input `endmeeting` in commandline to end current meeting.
5. Input `unpair` in commandline to unpair with Zoom Room.


## Documentation

Make sure to review our [document](https://developers.zoom.us/docs/zoom-rooms/zoom-rooms-controller/introduction/) as a reference when building your Zoom Rooms Controller Apps.
