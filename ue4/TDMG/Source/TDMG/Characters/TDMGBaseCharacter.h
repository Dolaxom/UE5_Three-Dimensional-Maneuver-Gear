#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TDMGBaseCharacter.generated.h"

UCLASS()
class TDMG_API ATDMGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATDMGBaseCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
