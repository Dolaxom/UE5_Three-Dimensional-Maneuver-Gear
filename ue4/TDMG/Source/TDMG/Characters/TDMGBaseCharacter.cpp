#include "TDMGBaseCharacter.h"

ATDMGBaseCharacter::ATDMGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATDMGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATDMGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATDMGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

