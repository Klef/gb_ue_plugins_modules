// Copyright Epic Games, Inc. All Rights Reserved.

#include "gb_modulesGameMode.h"
#include "gb_modulesCharacter.h"
#include "UObject/ConstructorHelpers.h"

Agb_modulesGameMode::Agb_modulesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
