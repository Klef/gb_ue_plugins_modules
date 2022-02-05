// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MediaWidget.generated.h"


UCLASS()
class GB_MODULES_API UMediaWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

protected:

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* BrowseButton;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UImage* PreviewImage;
	
	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* MaterialForVideo;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UMediaPlayer* MediaPlayer;

private:

	UFUNCTION(BlueprintCallable)
	void Browse();
	
	UFUNCTION()
	void OnMediaOpened(FString OpenedUrl);
	
	bool bIsVideo = false;

};
