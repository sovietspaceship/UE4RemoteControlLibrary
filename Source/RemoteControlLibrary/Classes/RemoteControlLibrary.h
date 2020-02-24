#pragma once

#include <Kismet/BlueprintFunctionLibrary.h>

#include "RemoteControlLibrary.generated.h"

UCLASS(BlueprintType)
class URemoteControlLibrary : public UBlueprintFunctionLibrary {

    GENERATED_BODY()

public:

    // IMPORTANT NOTE: All methods must be BlueprintCallable and public to be callabie via remote control

    UFUNCTION(BlueprintCallable)
    static bool IsRunning();

    UFUNCTION(BlueprintCallable)
    static bool StartPIE();

    UFUNCTION(BlueprintCallable)
    static FString GetCurrentLevel();
};
