// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlayerGameGameMode.h"
#include "MultiPlayerGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiPlayerGameGameMode::AMultiPlayerGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
