// Fill out your copyright notice in the Description page of Project Settings.


#include "MediaWidget.h"
#include "DesktopPlatformModule.h"
#include "FileMediaSource.h"
#include "IDesktopPlatform.h"
#include "Components/Button.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "MediaPlayer.h"
#include "Components/Image.h"
#include "MediaSoundComponent.h"

void UMediaWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BrowseButton)
	{
		BrowseButton->OnClicked.AddDynamic(this, &ThisClass::Browse);
	}
	if (MediaPlayer)
	{
		MediaPlayer->OnMediaOpened.AddDynamic(this, &UMediaWidget::OnMediaOpened);
	}
}

void UMediaWidget::Browse()
{
	bIsVideo = false;
	FString Path;

	IDesktopPlatform* Platform = FDesktopPlatformModule::Get();
	if (MediaPlayer)
	{
		if (MediaPlayer->IsPlaying())
		{
			MediaPlayer->Pause();
		}
	}
	if (Platform)
	{
		auto* ParentHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
		const FString FileTypes = "All Files (*.PNG, *.JPG, *.MP4)|*.PNG;*.JPG;*.MP4|"
											"Video Files (*.MP4)|*.MP4|"
											"Image Files (*.PNG, *.JPG)|*.PNG;*.JPG";
		TArray<FString> OutFiles;

		Platform->OpenFileDialog(ParentHandle, "Choose media: ", "", "", FileTypes, 0, OutFiles);
		if (OutFiles.Num() > 0)
		{
			Path = OutFiles[0];
			//пахнет костылем
			if (Path.Contains("mp4"))
			{
				bIsVideo = true;
			}
			if (bIsVideo)
			{
				UFileMediaSource* MediaSource = NewObject<UFileMediaSource>();
				MediaSource->FilePath = Path;
				MediaPlayer->OpenSource(MediaSource);
				PreviewImage->SetBrushFromMaterial(MaterialForVideo);
				const auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
				if (PlayerPawn)
				{
					UMediaSoundComponent* Sound = NewObject<UMediaSoundComponent>(PlayerPawn);
					Sound->SetMediaPlayer(MediaPlayer);
					Sound->RegisterComponent();
				}
			}
			else
			{
				UTexture2D* Texture = UKismetRenderingLibrary::ImportFileAsTexture2D(this, Path);
				if (Texture)
				{
					const int32 SizeX = Texture->GetSizeX();
					const int32 SizeY = Texture->GetSizeY();
					PreviewImage->SetBrushFromTexture(Texture);
					PreviewImage->SetBrushSize(FVector2D(SizeX,SizeY));
                }
            }
        }
    }
 }

void UMediaWidget::OnMediaOpened(FString OpenedUrl)
{
	if (MediaPlayer)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Yellow, OpenedUrl);
		const FVector2D MediaSize = MediaPlayer->GetVideoTrackDimensions(INDEX_NONE, INDEX_NONE);
		if (PreviewImage)
		{
			PreviewImage->SetBrushSize(FVector2D(MediaSize.X, MediaSize.Y));
		}
		MediaPlayer->Play();
	}
}
