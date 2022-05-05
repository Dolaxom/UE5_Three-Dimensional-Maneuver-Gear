#pragma once

#include "CoreMinimal.h"
#include "TDMGBaseCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS(Blueprintable)
class TDMG_API APlayerCharacter : public ATDMGBaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	
	// Player controller //
	virtual void MoveForward(float Value) override;
	virtual void MoveRight(float Value) override;
	virtual void Turn(float Value) override;
	virtual void LookUp(float Value) override;
	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	class USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDMG | Projectile")
	TSubclassOf<class ATDMGProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDMG | Projectile")
	FVector FiringOffsetOne = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDMG | Projectile")
	FVector FiringOffsetTwo = FVector::ZeroVector;

private:
	UFUNCTION()
	void ProcessHit(const FHitResult& HitResult, const FVector& Direction);
};
