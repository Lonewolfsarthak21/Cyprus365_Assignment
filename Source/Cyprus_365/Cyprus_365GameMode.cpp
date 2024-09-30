// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cyprus_365GameMode.h"
#include "Cyprus_365Character.h"
#include "UObject/ConstructorHelpers.h"

ACyprus_365GameMode::ACyprus_365GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
