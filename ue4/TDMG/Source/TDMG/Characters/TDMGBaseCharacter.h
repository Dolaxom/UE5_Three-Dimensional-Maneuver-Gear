#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TDMGBaseCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class TDMG_API ATDMGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATDMGBaseCharacter();

	// Controller //
	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};
	virtual void StartFire() {};
	virtual void StopFire() {};

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
