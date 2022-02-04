// Fill out your copyright notice in the Description page of Project Settings.


#include "VideoPlane.h"
#include "FileMediaSource.h"
#include "MediaPlayer.h"


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
		FString Path = "D:\\repo\\1984.mp4";
		UFileMediaSource * MediaSource = NewObject<UFileMediaSource>();
		MediaSource->FilePath = Path;
		MediaPlayer->OpenSource(MediaSource);
	}

}


