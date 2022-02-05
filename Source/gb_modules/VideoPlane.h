// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VideoPlane.generated.h"


class UMediaPlayer;

UCLASS()
class GB_MODULES_API AVideoPlane : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVideoPlane();
	
	UPROPERTY(EditAnywhere)
	UMediaPlayer * MediaPlayer;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void PlayVideo(FString Path);
};
