#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TDMGBaseCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TDMG_API UTDMGBaseCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character animation", meta = (UIMin = 0.0f, UIMax = 1000.0f))
	float Speed = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character animation")
	bool bIsFalling = false;

private:
	TWeakObjectPtr<class ATDMGBaseCharacter> CachedBaseCharacter;
};
