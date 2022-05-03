#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDMGBaseController.generated.h"

UCLASS()
class TDMG_API ATDMGBaseController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;
	
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	
	void Jump();
	void PlayerStartFire();
	void PlayerStopFire();
	
	TSoftObjectPtr<class ATDMGBaseCharacter> CachedBaseCharacter;	
	
};
