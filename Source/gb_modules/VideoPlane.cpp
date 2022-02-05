// Fill out your copyright notice in the Description page of Project Settings.


#include "VideoPlane.h"
#include "DesktopPlatformModule.h"
#include "FileMediaSource.h"
#include "IDesktopPlatform.h"
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "Kismet/KismetRenderingLibrary.h"


// Sets default values
AVideoPlane::AVideoPlane()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AVideoPlane::BeginPlay()
{
	Super::BeginPlay();
	if (MediaPlayer)
	{
		TArray<FString> OutFileNames;
		FString Path;
		IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
		if (DesktopPlatform)
		{
			FString FileTypes = "All Files(*.PNG;*.JPG;*.MP4)|*.PNG;*.JPG;*.MP4|"
							"Image Files(*.PNG;*.JPG;)|*.PNG;*.JPG;|"
							"Video Files(*.MP4)|*.MP4";
			uint32 SelectionFlag = 0;
			DesktopPlatform->OpenFileDialog(
				FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
				"Choose content", "", "", FileTypes, SelectionFlag, OutFileNames);

			if (OutFileNames.Num() > 0)
			{
				Path = OutFileNames[0];
				PlayVideo(Path);
			}
		}
	}

}

void AVideoPlane::PlayVideo(FString Path)
{
	UFileMediaSource * MediaSource = NewObject<UFileMediaSource>();
	MediaSource->FilePath = Path;
	MediaPlayer->OpenSource(MediaSource);
	UMediaSoundComponent * Comp = NewObject<UMediaSoundComponent>(this);
	Comp->SetMediaPlayer(MediaPlayer);
	Comp->RegisterComponent();
}


