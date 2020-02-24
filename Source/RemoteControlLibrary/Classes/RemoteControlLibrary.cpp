#include <RemoteControlLibrary.h>

#include <Editor/UnrealEdEngine.h>
#include "UnrealEdGlobals.h"
#include <GameFramework/Actor.h>
#include <Kismet/GameplayStatics.h>
#include <Kismet2/DebuggerCommands.h>
#include <Kismet2/KismetEditorUtilities.h>
#include <LevelEditor.h>
#include <LevelEditorViewport.h>
#include <Modules/ModuleManager.h>

static UWorld* GetEditorWorld() {
    auto WorldContext = GUnrealEd->GetEditorWorldContext();
    return WorldContext.World();
}

static TSharedPtr<IAssetViewport> GetActiveLevelViewport() {
    FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
    return LevelEditorModule.GetFirstActiveViewport();
}

bool URemoteControlLibrary::IsRunning() {
    return true;
}

bool URemoteControlLibrary::StartPIE() {
    TSharedPtr<IAssetViewport> ActiveLevelViewport = GetActiveLevelViewport();

    if (ActiveLevelViewport.IsValid()) {
        GUnrealEd->RequestPlaySession(true, ActiveLevelViewport, false);
        return true;
    }

    return false;
}

FString URemoteControlLibrary::GetCurrentLevel() {
    UWorld* EditorWorld = GetEditorWorld();

    return EditorWorld->GetSelectedLevel(0)->GetName();
}