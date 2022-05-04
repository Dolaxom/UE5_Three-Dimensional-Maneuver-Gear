#include "TDMGBaseCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TDMG/Characters/TDMGBaseCharacter.h"

void UTDMGBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ATDMGBaseCharacter>(), TEXT("UTDMGBaseCharacterAnimInstance::NativeBeginPlay() can be user only with ATDMGBaseCharacter"))
	CachedBaseCharacter = StaticCast<ATDMGBaseCharacter*>(TryGetPawnOwner());
}

void UTDMGBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(!CachedBaseCharacter.IsValid())
	{
		return;
	}

	const UCharacterMovementComponent* CharacterMovement = CachedBaseCharacter->GetCharacterMovement();

	Speed = CharacterMovement->Velocity.Size();
	bIsFalling = CharacterMovement->IsFalling();
}
