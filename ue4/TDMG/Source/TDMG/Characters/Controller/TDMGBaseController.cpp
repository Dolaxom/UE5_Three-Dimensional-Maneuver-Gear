#include "TDMGBaseController.h"

#include "TDMG/Characters/TDMGBaseCharacter.h"

void ATDMGBaseController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	CachedBaseCharacter = Cast<ATDMGBaseCharacter>(InPawn);
}

void ATDMGBaseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATDMGBaseController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATDMGBaseController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ATDMGBaseController::Turn);
	InputComponent->BindAxis("LookUp", this, &ATDMGBaseController::LookUp);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATDMGBaseController::Jump);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATDMGBaseController::PlayerStartFire);
	InputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ATDMGBaseController::PlayerStopFire);
}

void ATDMGBaseController::MoveForward(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(Value);
	}
}

void ATDMGBaseController::MoveRight(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(Value);
	}
}

void ATDMGBaseController::Turn(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Turn(Value);
	}
}

void ATDMGBaseController::LookUp(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(Value);
	}
}

void ATDMGBaseController::Jump()
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}

void ATDMGBaseController::PlayerStartFire()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->StartFire();
	}
}

void ATDMGBaseController::PlayerStopFire()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->StopFire();
	}
}
