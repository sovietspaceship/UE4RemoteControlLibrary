# Unreal Engine Web Remote Control Library

This plugin implements some functions useful to interact with the Unreal Editor via
Web Remote Control. It also serves as a starter for writing your own blueprint function
library for remote control.

It provides the `URemoteControlLibrary` Blueprint function library. All methods
are callable via Web Remote Control. Clients that wish to interact with this object
must invoke it with path `/Script/RemoteControlLibrary.Default__RemoteControlLibrary`.

Check [Web Remote Control](https://docs.unrealengine.com/en-US/Engine/Editor/ScriptingAndAutomation/WebControl/index.html)
for instructions on how to enable the feature in your editor.

## Methods

All methods currently supported are declared in `Source/Classes/RemoteControlLibrary.h`.

## Client-side libraries

Check [ue4-remote-control](https://github.com/sovietspaceship/ue4-remote-control)
for a client-side implementation in TypeScript of the protocol, which also includes a class
for this library. See `tests/remote-control-library.js` for some examples.

## Extending

To extend, create a new UClass inheriting URemoteControlLibrary; all callable
methods must be `BlueprintCallable` and `public`.

## Contributing

I created this library as a base for my own projects, so it may not be very useful by itself without
adding more methods.
If you want some commonly useful methods to be included I'd be happy to consider any merge request!
