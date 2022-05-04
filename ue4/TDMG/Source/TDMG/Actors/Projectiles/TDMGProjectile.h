#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDMGProjectile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProjectileHit, const FHitResult&, HitResult, const FVector&, Direction);

UCLASS()
class TDMG_API ATDMGProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATDMGProjectile();
	
	UFUNCTION(BlueprintCallable)
	void LaunchProjectile(FVector Direction);
    
	UPROPERTY(BlueprintAssignable)
	FOnProjectileHit OnProjectileHitEvent;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	virtual void OnProjectileLaunched();

private:
	UFUNCTION()
	void OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
